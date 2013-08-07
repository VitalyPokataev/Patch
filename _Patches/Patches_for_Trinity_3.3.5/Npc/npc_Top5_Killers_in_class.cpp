//AC-Web 
//Script Complete 100 %

// Rewritten by Rochet2

#include "ScriptPCH.h"

/*Class E_Menu*/
#define E_Warrior "View top 5 Warrior Killers"
#define E_Paladin "View top 5 Paladin Killers"
#define E_Hunter "View top 5 Hunter Killers"
#define E_Rogue "View top 5 Rogue Killers"
#define E_Priest "View top 5 Priest Killers"
#define E_Shaman "View top 5 Shaman Killers"
#define E_Mage "View top 5 Mage Killers"
#define E_Warlock "View top 5 Warlock Killers"
#define E_Druid "View top 5 Druid Killers"
#define E_Death_knight "View top 5 Death knight Killers"
/*Top 5 Message*/
#define M_Warrior "Here is the top 5 Warrior Killers"
#define M_Paladin "Here is the top 5 Paladin Killers"
#define M_Hunter "Here is the top 5 Hunter Killers"
#define M_Rogue "Here is the top 5 Rogue Killers"
#define M_Priest "Here is the top 5 Priest Killers"
#define M_Shaman "Here is the top 5 Shaman Killers"
#define M_Mage "Here is the top 5 Mage Killers"
#define M_Warlock "Here is the top 5 Warlock Killers"
#define M_Druid "Here is the top 5 Druid Killers"
#define M_Death_knight "Here is the top 5 Death knight Killers"

class Top5_Killers : public CreatureScript
{
public:
    Top5_Killers() : CreatureScript("Top5_Killers") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 9);
        player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 11);
        player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 6);
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return true; // wrong sender, something fisy

        switch(action)
        {
        case 1: ChatHandler(player->GetSession()).PSendSysMessage(M_Warrior);       break;
        case 2: ChatHandler(player->GetSession()).PSendSysMessage(M_Paladin);       break;
        case 3: ChatHandler(player->GetSession()).PSendSysMessage(M_Hunter);        break;
        case 4: ChatHandler(player->GetSession()).PSendSysMessage(M_Rogue);         break;
        case 5: ChatHandler(player->GetSession()).PSendSysMessage(M_Priest);        break;
        case 6: ChatHandler(player->GetSession()).PSendSysMessage(M_Death_knight);  break;
        case 7: ChatHandler(player->GetSession()).PSendSysMessage(M_Shaman);        break;
        case 8: ChatHandler(player->GetSession()).PSendSysMessage(M_Mage);          break;
        case 9: ChatHandler(player->GetSession()).PSendSysMessage(M_Warlock);       break;
        case 11: ChatHandler(player->GetSession()).PSendSysMessage(M_Druid);        break;
        default: return true; // invalid class, something fishy
        }

        QueryResult result = CharacterDatabase.PQuery("SELECT name, totalKills FROM characters WHERE class = %u ORDER BY totalKills DESC LIMIT 5", action);
        if(result)
        {
            do
            {
                Field * fields = result->Fetch();
                std::string name = fields[0].GetString();
                uint32 totalKills = fields[1].GetUInt32();
                ChatHandler(player->GetSession()).PSendSysMessage("Name: %s, With Total Kills : %u", name.c_str(), totalKills);
            } 
            while(result->NextRow());
        }
        OnGossipHello(player, creature); // return to main menu
        return true;
    }
};


void AddSC_Top5_Killers()
{
    new Top5_Killers();
}