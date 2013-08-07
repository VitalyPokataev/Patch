/* Made by: aaddss A.K.A Deathsoul
   tested (in game)
*/
 
#include "ScriptPCH.h"
 
class item_teleport : public ItemScript
{
        public:
                item_teleport() : ItemScript("item_teleport") {}
               
        bool OnUse(Player * player, Item * /*item*/, SpellCastTargets const& /*targets*/)
        {
                if (player->isInCombat())
                {
                        player->GetSession()->SendNotification(" You are in combat!");
                }
 
                {
                        player->TeleportTo(0, 1234.00f, 4321.00f, 1242.00f, 4323.00f); // please change the map id , x , z , y , o (or it will not teleport where u want
                                return true;
                }
        }
};
 
void AddSC_item_teleport()
{
    new item_teleport();
}