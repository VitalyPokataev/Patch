/* ScriptData
SDName: Example_Misc
SD%Complete: 100
EndScriptData */

#include "ScriptMgr.h"
#include "Player.h"

class go_teleport : public GameObjectScript
{
    public:

        go_teleport()
            : GameObjectScript("go_teleport")
        {
        }

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(530, 12947.4f,-6893.31f,5.68398f,3.09154f);
            return true;
        }
};
class go_cd : public GameObjectScript
{
    public:

        go_cd()
            : GameObjectScript("go_cd")
        {
        }

        bool OnGossipHello(Player* player, GameObject* /*go*/)
		{
		    if (player->isInCombat())
				(new ChatHandler(player->GetSession()))->PSendSysMessage("Вы в бою.");
            else
            {
              player->RemoveArenaSpellCooldowns();
              return false;
            }
			return true;
		}
};

class revive_player: public PlayerScript
{
public:
	revive_player():PlayerScript("revive_player"){}
	void OnPVPKill(Player* /*killer*/, Player* killed)
	{
		if(killed)
			if(killed->GetZoneId() == 4080)
			{
				killed->Relocate(12946.133789f,-6900.836426f,5.248318f); 
				killed->ResurrectPlayer(1.0f,false);
			}
			else if(killed->GetZoneId() == 618)
			{
				killed->Relocate(12143.391602f,-6811.582520f,9.067545f); 
				killed->ResurrectPlayer(1.0f,false);
			}
	}
};

void AddSC_PvP_Zone()
{
    new go_teleport();
    new go_cd();
	new revive_player();
}