/*REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (1000001, 0, 0, 0, 0, 0, 21572, 0, 0, 0, 'ICC NPC', 'citadel_controller', 'Directions', 631, 71, 71, 0, 35, 35, 3, 1, 1.14286, 1.25, 1, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 138936390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1.56, 1.56, 1.56, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 'npc_icecrown_citadel_controller', 1);*/
/*NPC Контроллер Босов в ЦЛК .*/
/**/

#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "../../scripts\Northrend\IcecrownCitadel\icecrown_citadel.h"
#include "Spell.h"

#define GOSSIP_SENDER_ICC_PORT 631
class npc_icecrown_citadel_controller : public CreatureScript
{
    public:
        npc_icecrown_citadel_controller() : CreatureScript("npc_icecrown_citadel_controller") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (!pInstance || pInstance->instance->GetId() != 631) // ICC
            {
                pCreature->MonsterSay("You must be in ICC!", LANG_UNIVERSAL, pPlayer->GetGUID());
                pPlayer->CLOSE_GOSSIP_MENU();
                return false;
            }

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Marrowgar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+0);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Lady DeathWhisper", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Gunship Battle", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Saurfang", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Valithria", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Sindragossa", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Blood Council", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Queen Lana Thel", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Festergut", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Rotface", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Professor Putricide", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Lich King", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+11);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
        {
            InstanceScript* pInstance = pPlayer->GetInstanceScript();
            if(!pInstance)
                return false;

            for(uint8 i = 0; i < 12; ++i) // encounters count
            {
                if(uiAction == GOSSIP_ACTION_INFO_DEF + i)
                {
                    if(pInstance->GetData(i) != DONE)
                    {
                        pInstance->SetBossState(i, DONE);
                        pCreature->MonsterSay("Is done!", LANG_UNIVERSAL, pPlayer->GetGUID());
                    }
                    else
                    {
                        pInstance->SetBossState(i, NOT_STARTED);
                        pCreature->MonsterSay("Is activated!", LANG_UNIVERSAL, pPlayer->GetGUID());
                    }
                }
            }

            pPlayer->CLOSE_GOSSIP_MENU();
            return true;
    }
};

void AddSC_npc_icecrown_citadel_controller()
{

    new npc_icecrown_citadel_controller();
}