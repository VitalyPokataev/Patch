#include "ScriptPCH.h"
 
class lich_kill : public PlayerScript
{
public:
        lich_kill() : PlayerScript("lich_kill") { }
       
       
        void OnCreatureKill(Player* player, Creature* creature)
        {
                if (player->GetGroup() && player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER) && creature->GetEntry() == 36597)
                {
                        char msg[255];
                        snprintf(msg, 255, "Король лич опять повержен героями во главе которых стоял %s", player->GetName());
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }
        }
}
 
void AddSC_lich_kill()
{
        new lich_kill();
}