#include "ScriptPCH.h"
#include "Config.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
/*
-- Boss kill history locales
DELETE FROM `trinity_string` WHERE `entry` IN (11008,11009);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11008, '%s - %s (Normal, %u peoples) defeated by guild \"%s\", in %u person(s).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s - %s (Обычный режим на %u человек) повержен гильдией \'%s\', составом в %u человек.'),
(11009, '%s - %s (Heroic, %u peoples) defeated by guild \"%s\", in %u person(s).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s - %s (Героический режим на %u человек) повержен гильдией \'%s\', составом в %u человек.');
*/
#define SQL_BOSS_KILL_HISTORY_LOG "INSERT INTO `character_boss_kill_history` (`GuildId`, `CreatureEntry`, `KillerCount`, `KillData`, `MapSpawnMode`, `MapId`, `MapRaid`, `CreatureName`, `MapName`) VALUES ('%u', '%u', '%u', '%s', '%u', '%u', '%u', '%s', '%s')"
#define DATA_SEPARATOR ":"
#define PEOPLE_SEPARATOR " "

class boss_kill_history_AllCreatureScript : public AllCreatureScript
{
    public:
        boss_kill_history_AllCreatureScript() : AllCreatureScript("boss_kill_history_AllCreatureScript") { }

    void AllCreatureJustDied(Creature* creature)
    {
        if (!sWorld->getBoolConfig(CONFIG_BOSS_KILL_HISTORY_ENABLE))
            return;

        if (creature->GetCreatureTemplate()->rank != CREATURE_ELITE_WORLDBOSS)
            return;

        Player* recipient = creature->GetLootRecipient();
        if (!recipient)
            return;

        Map* map = creature->GetMap();
        if (!map)
            return;

        uint32 Entry = creature->GetEntry();
        InstanceMap* instance = map->ToInstanceMap();
        std::string bossName(creature->GetNameForLocaleIdx(sObjectMgr->GetDBCLocaleIndex()));
        std::string mapName(creature->GetMap()->GetMapName());
        
        uint8 spawnMode = map->GetSpawnMode();
        uint32 GuildId = 0;
        bool IsGuildKill = true;
        uint32 KillerCount = 0;
        std::string TeamKill;

        if(Group *group = recipient->GetGroup())
        {
            for(GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* Temp = itr->getSource();

                if(!Temp)
                    continue;

                KillerCount++;
                uint32 playerGuildId = Temp->GetGuildId();
                std::ostringstream PeopleData;
                PeopleData << Temp->GetGUIDLow() << DATA_SEPARATOR;
                PeopleData << Temp->GetName() << DATA_SEPARATOR;
                PeopleData << uint32(Temp->getLevel()) << DATA_SEPARATOR;
                PeopleData << playerGuildId << DATA_SEPARATOR;
                PeopleData << uint32(Temp->isAlive()) << DATA_SEPARATOR;
                PeopleData << uint32(Temp->IsAtGroupRewardDistance(creature)) << PEOPLE_SEPARATOR;
                TeamKill += PeopleData.str();

                if (IsGuildKill)
                {
                    if (GuildId == 0)
                        GuildId = playerGuildId;

                    IsGuildKill = GuildId != 0 && playerGuildId == GuildId;
                }
            }
        }
        else
        {
            KillerCount = 1;
            GuildId = recipient->GetGuildId();
            IsGuildKill = GuildId != 0;

            std::ostringstream PeopleData;
            PeopleData << recipient->GetGUIDLow() << DATA_SEPARATOR;
            PeopleData << recipient->GetName() << DATA_SEPARATOR;
            PeopleData << uint32(recipient->getLevel()) << DATA_SEPARATOR;
            PeopleData << recipient->GetGuildId() << DATA_SEPARATOR;
            PeopleData << uint32(recipient->isAlive()) << DATA_SEPARATOR;
            PeopleData << uint32(1) << PEOPLE_SEPARATOR;
            TeamKill += PeopleData.str();
        }

        if (GuildId == 0 && IsGuildKill)
            IsGuildKill = false;

        if (!IsGuildKill)
            GuildId = 0;

        if (IsGuildKill)
        {
            int32 TextId = LANG_BOSS_KILL_HISTORY_NORMAL;
            uint32 mapMaxPlayers = instance ? instance->GetMaxPlayers() : 40;
            std::string guildName(sGuildMgr->GetGuildById(GuildId)->GetName());

            if (map->IsRaid())
            {
                if (spawnMode == RAID_DIFFICULTY_25MAN_HEROIC || spawnMode == RAID_DIFFICULTY_10MAN_HEROIC)
                    TextId = LANG_BOSS_KILL_HISTORY_HEROIC;
            }
            else if (spawnMode == DUNGEON_DIFFICULTY_HEROIC)
                    TextId = LANG_BOSS_KILL_HISTORY_HEROIC;

            sWorld->SendWorldText(TextId, mapName.c_str(), bossName.c_str(), mapMaxPlayers, guildName.c_str(), KillerCount);
        }

        CharacterDatabase.EscapeString(TeamKill);
        CharacterDatabase.EscapeString(bossName);
        CharacterDatabase.EscapeString(mapName);
        CharacterDatabase.PExecute(SQL_BOSS_KILL_HISTORY_LOG, GuildId, Entry, KillerCount, TeamKill.c_str(), spawnMode, map->GetId(), uint8(map->IsRaid()), bossName.c_str(), mapName.c_str());
    }
};

void AddSC_boss_kill_history()
{
    new boss_kill_history_AllCreatureScript();
}
