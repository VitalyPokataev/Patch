#include "ScriptMgr.h"
class custom_TelePlayerOnLevel : public PlayerScript
{
public:
	custom_TelePlayerOnLevel() : PlayerScript("custom_TelePlayerOnLevel") { }
	void OnLevelChanged(Player* player, uint8 newLevel)
	{
		// Change 255 To the level u want to get them teleported to location.
		if(newLevel == 254)
		{
			if (player->isInFlight())
			{
				player->GetMotionMaster()->MovementExpired();
				player->CleanupAfterTaxiFlight();
			}
			// (mapid, X, Y, Z, O)
			if (player->TeamForRace(ALLIANCE)
			{
				player->TeleportTo(530, 4124.54, 2979.16, 352.515, 4.68821);
			}
			if (player->TeamForRace(HORDE)
			{
				player->TeleportTo(530, -2518.69, 7252.87, 17.866, 5.67535);
			}
		}
	}
};

void AddSC_custom_TelePlayerOnLevel()
{
	new custom_TelePlayerOnLevel();
}