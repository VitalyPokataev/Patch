#include "ScriptPCH.h"

class Diablo_WoW : public PlayerScript
{
    public:
        Diablo_WoW() : PlayerScript("Diablo_WoW") {}

    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
        // Удаление персонажа после 5й смерти :3
              //  if (winner->GetZoneId() == 0 || winner->GetZoneId() == 41 || winner->GetZoneId() == 616)
               // {
			int n = looser->GetGUID();
			int i[n] = 0;
			if(looser)
				i[n]+=1;
			if(n=5)
			{
				looser->KickPlayer();
				CharacterDatabase.PExecute("DELETE FROM characters WHERE guid ='%u'", n);
			}
             //   }
    }
};

void AddSC_Diablo_WoW()
{
    new Diablo_WoW;
}