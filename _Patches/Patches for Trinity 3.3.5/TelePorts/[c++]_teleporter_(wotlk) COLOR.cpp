/*
Script was Based on Rochet2's Teleportter
Modified by Lhorath for Use on DisintegrationWoW/RigormortisCore
*/

#include "ScriptPCH.h"

// Teleport data

struct Eric
{
	uint32 menu_id, next_menu_id;
	uint8 icon;
	std::string name;
	uint32 cost;
	uint8 level, faction; // 0 Both, 1 Horde, 2 Ally
	uint32 map;
	float x, y, z, o;
};
typedef struct Eric Rochet2;

//	{menu_id, next_menu_id, icon, name, cost, level, faction, map, x, y, z, o}
Rochet2 TeLe [] = // key = i & Key
{
	{1,	2,	2,	"|cff4169E1|TInterface\\icons\\Achievement_Leader_King_Varian_Wrynn:30|t Alliance Capital Cities|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	3,	2,	"|cffFF0000|TInterface\\icons\\Achievement_Leader_Sylvanas:30|t Horde Capital Cities|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	4,	2,	"|cffFFFF00|TInterface\\icons\\Temp:30|t Neutral Capital Cities|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	5,	9,	"|cffFF8C00|TInterface\\icons\\Achievement_FeatsOfStrength_Gladiator_10:30|t PvP Areas|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	6,	3,	"|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:30|t Open Dungeons|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	7,	3,	"|cffDA70D6|TInterface\\icons\\Achievement_Dungeon_Icecrown_IcecrownEntrance:30|t Open Raids|r",	0,	0,	0,	0,	0,	0,	0,	0},
	{1,	8,	7,	"|cff008000|TInterface\\icons\\Ability_Mount_RocketMount2:30|t Unique Disintegration Areas|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{2,	0,	2,	"Stormwind",	0,	0,	2,	0,	-8842.09f,	626.358f,	94.0867f,	3.61363f},
	{2,	0,	2,	"Darnassus",	0,	0,	2,	1,	9869.91f,	2493.58f,	1315.88f,	2.78897f},
	{2,	0,	2,	"Ironforge",	0,	0,	2,	0,	-4900.47f,	-962.585f,	501.455f,	5.40538f},
	{2,	0,	2,	"Exodar",	0,	0,	2,	530,	-3864.92f,	-11643.7f,	-137.644f,	5.50862f},
	{2,	0,	9,	"|cffFF0000Attack Stormwind|r",	0,	80,	1,	0,	-9449.06f,	64.8392f,	56.3581f,	3.07047f},
	{2,	0,	9,	"|cffFF0000Attack Darnassus|r",	0,	80,	1,	1,	9889.03f,	915.869f,	1307.43f,	1.9336f},
	{2,	0,	9,	"|cffFF0000Attack Ironforge|r",	0,	80,	1,	0,	-5603.76f,	-482.704f,	396.98f,	5.23499f},
	{2,	0,	9,	"|cffFF0000Attack Exodar|r",	0,	80,	1,	530,	-4192.62f,	-12576.7f,	36.7598f,	1.62813f},
	{2,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},

	{3,	0,	2,	"Orgrimmar",	0,	0,	1,	1,	1601.08f,	-4378.69f,	9.9846f,	2.14362f},
	{3,	0,	2,	"Thunder bluff",	0,	0,	1,	1,	-1274.45f,	71.8601f,	128.159f,	2.80623f},
	{3,	0,	2,	"Undercity",	0,	0,	1,	0,	1633.75f,	240.167f,	-43.1034f,	6.26128f},
	{3,	0,	2,	"Silvermoon city",	0,	0,	1,	530,	9738.28f,	-7454.19f,	13.5605f,	0.043914f},
	{3,	0,	9,	"|cffFF0000Attack Orgrimmar|r",	0,	80,	2,	1,	228.978f,	-4741.87f,	10.1027f,	0.416883f},
	{3,	0,	9,	"|cffFF0000Attack Thunder bluff|r",	0,	80,	2,	1,	-2473.87f,	-501.225f,	-9.42465f,	0.6525f},
	{3,	0,	9,	"|cffFF0000Attack Undercity|r",	0,	80,	2,	0,	2274.95f,	323.918f,	34.1137f,	4.24367f},
	{3,	0,	9,	"|cffFF0000Attack Silvermoon|r",	0,	80,	2,	530,	9024.37f,	-6682.55f,	16.8973f,	3.14131f},
	{3,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{4,	0,	2,	"Dalaran",	0,	67,	0,	571,	5809.55f,	503.975f,	657.526f,	2.38338f},
	{4,	0,	2,	"Shattrath",	0,	57,	0,	530,	-1887.62f,	5359.09f,	-12.4279f,	4.40435f},
	{4,	0,	2,	"Booty bay",	0,	30,	0,	0,	-14281.9f,	552.564f,	8.90422f,	0.860144f},
	{4,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{5,	0,	2,	"Gurubashi arena",	0,	30,	0,	0,	-13181.8f,	339.356f,	42.9805f,	1.18013f},
	{5,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{6,	9,	7,	"Classic Dungeons",	0,	0,	0,	0,	0,	0,	0,	0},
	{6,	10,	7,	"Burning Crusade Dungeons",	0,	0,	0,	0,	0,	0,	0,	0},
	{6,	11,	7,	"Wrath Dungeons",	0,	0,	0,	0,	0,	0,	0,	0},
	{6,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{7,	12,	7,	"Classic Raids",	0,	0,	0,	0,	0,	0,	0,	0},
	{7,	13,	7,	"Burning Crusade Raids",	0,	0,	0,	0,	0,	0,	0,	0},
	{7,	14,	7,	"Wrath Raids",	0,	0,	0,	0,	0,	0,	0,	0},
	{7,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{8,	0,	2,	"|cff008000Disintegration Town|r",	0,	0,	0,	723,	-8842.09f,	626.358f,	94.0867f,	3.61363f},
	{8,	1,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{9,	0,	2,	"Gnomeregan",	0,	25,	2,	0,	-5163.54f,	925.423f,	257.181f,	1.57423f},
	{9,	0,	2,	"The Deadmines",	0,	17,	2,	0,	-11209.6f,	1666.54f,	24.6974f,	1.42053f},
	{9,	0,	2,	"The Stockade",	0,	22,	2,	0,	-8799.15f,	832.718f,	97.6348f,	6.04085f},
	{9,	0,	2,	"Ragefire Chasm",	0,	15,	1,	1,	1811.78f,	-4410.5f,	-18.4704f,	5.20165f},
	{9,	0,	2,	"Razorfen Downs",	0,	34,	1,	1,	-4657.3f,	-2519.35f,	81.0529f,	4.54808f},
	{9,	0,	2,	"Razorfen Kraul",	0,	24,	1,	1,	-4470.28f,	-1677.77f,	81.3925f,	1.16302f},
	{9,	0,	2,	"Scarlet Monastery",	0,	32,	1,	0,	2873.15f,	-764.523f,	160.332f,	5.10447f},
	{9,	0,	2,	"Shadowfang Keep",	0,	18,	1,	0,	-234.675f,	1561.63f,	76.8921f,	1.24031f},
	{9,	0,	2,	"Wailing Caverns",	0,	17,	1,	1,	-731.607f,	-2218.39f,	17.0281f,	2.78486f},
	{9,	0,	2,	"Blackfathom Deeps",	0,	21,	0,	1,	4249.99f,	740.102f,	-25.671f,	1.34062f},
	{9,	0,	2,	"Blackrock Depths",	0,	53,	0,	0,	-7179.34f,	-921.212f,	165.821f,	5.09599f},
	{9,	0,	2,	"Blackrock Spire",	0,	57,	0,	0,	-7527.05f,	-1226.77f,	285.732f,	5.29626f},
	{9,	0,	2,	"Dire Maul",	0,	55,	0,	1,	-3520.14f,	1119.38f,	161.025f,	4.70454f},
	{9,	0,	2,	"Maraudon",	0,	45,	0,	1,	-1421.42f,	2907.83f,	137.415f,	1.70718f},
	{9,	0,	2,	"Scholomance",	0,	55,	0,	0,	1269.64f,	-2556.21f,	93.6088f,	0.620623f},
	{9,	0,	2,	"Stratholme",	0,	55,	0,	0,	3352.92f,	-3379.03f,	144.782f,	6.25978f},
	{9,	0,	2,	"Sunken Temple",	0,	47,	0,	0,	-10177.9f,	-3994.9f,	-111.239f,	6.01885f},
	{9,	0,	2,	"Uldaman",	0,	37,	0,	0,	-6071.37f,	-2955.16f,	209.782f,	0.015708f},
	{9,	0,	2,	"Zul'Farrak",	0,	35,	0,	1,	-6801.19f,	-2893.02f,	9.00388f,	0.158639f},
	{9,	6,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{10,	0,	2,	"Auchindoun",	0,	64,	0,	530,	-3324.49f,	4943.45f,	-101.239f,	4.63901f},
	{10,	0,	2,	"Caverns of Time",	0,	66,	0,	1,	-8369.65f,	-4253.11f,	-204.272f,	-2.70526f},
	{10,	0,	2,	"Coilfang Reservoir",	0,	62,	0,	530,	738.865f,	6865.77f,	-69.4659f,	6.27655f},
	{10,	0,	2,	"Hellfire Citadel",	0,	59,	0,	530,	-347.29f,	3089.82f,	21.394f,	5.68114f},
	{10,	0,	2,	"Magisters' Terrace",	0,	70,	0,	530,	12884.6f,	-7317.69f,	65.5023f,	4.799f},
	{10,	0,	2,	"Tempest Keep",	0,	70,	0,	530,	3100.48f,	1536.49f,	190.3f,	4.62226f},
	{10,	6,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{11,	0,	2,	"Azjol-Nerub",	0,	73,	0,	571,	3707.86f,	2150.23f,	36.76f,	3.22f},
	{11,	0,	2,	"The Culling of Stratholme",	0,	79,	0,	1,	-8756.39f,	-4440.68f,	-199.489f,	4.66289f},
	{11,	0,	2,	"Trial of the Champion",	0,	79,	0,	571,	8590.95f,	791.792f,	558.235f,	3.13127f},
	{11,	0,	2,	"Drak'Tharon Keep",	0,	74,	0,	571,	4765.59f,	-2038.24f,	229.363f,	0.887627f},
	{11,	0,	2,	"Gundrak",	0,	71,	0,	571,	6722.44f,	-4640.67f,	450.632f,	3.91123f},
	{11,	0,	2,	"Icecrown Citadel Dungeons",	0,	79,	0,	571,	5643.16f,	2028.81f,	798.274f,	4.60242f},
	{11,	0,	2,	"The Nexus Dungeons",	0,	71,	0,	571,	3782.89f,	6965.23f,	105.088f,	6.14194f},
	{11,	0,	2,	"The Violet Hold",	0,	75,	0,	571,	5693.08f,	502.588f,	652.672f,	4.0229f},
	{11,	0,	2,	"Halls of Lightning",	0,	79,	0,	571,	9136.52f,	-1311.81f,	1066.29f,	5.19113f},
	{11,	0,	2,	"Halls of Stone",	0,	77,	0,	571,	8922.12f,	-1009.16f,	1039.56f,	1.57044f},
	{11,	0,	2,	"Utgarde Keep",	0,	69,	0,	571,	1203.41f,	-4868.59f,	41.2486f,	0.283237f},
	{11,	0,	2,	"Utgarde Pinnacle",	0,	75,	0,	571,	1267.24f,	-4857.3f,	215.764f,	3.22768f},
	{11,	6,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	
	{12,	0,	2,	"Blackwing Lair",	0,	60,	0,	229,	152.451f,	-474.881f,	116.84f,	0.001073f},
	{12,	0,	2,	"Molten Core",	0,	60,	0,	230,	1126.64f,	-459.94f,	-102.535f,	3.46095f},
	{12,	0,	2,	"Ruins of Ahn'Qiraj",	0,	60,	0,	1,	-8409.82f,	1499.06f,	27.7179f,	2.51868f},
	{12,	0,	2,	"Temple of Ahn'Qiraj",	0,	60,	0,	1,	-8240.09f,	1991.32f,	129.072f,	0.941603f},
	{12,	0,	2,	"Zul'Gurub",	0,	60,	0,	0,	-11916.7f,	-1215.72f,	92.289f,	4.72454f},
	{12,	7,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{13,	0,	2,	"Black Temple",	0,	70,	0,	530,	-3649.92f,	317.469f,	35.2827f,	2.94285f},
	{13,	0,	2,	"Hyjal Summit",	0,	70,	0,	1,	-8177.89f,	-4181.23f,	-167.552f,	0.913338f},
	{13,	0,	2,	"Serpentshrine Cavern",	0,	70,	0,	530,	797.855f,	6865.77f,	-65.4165f,	0.005938f},
	{13,	0,	2,	"Gruul's Lair",	0,	70,	0,	530,	3530.06f,	5104.08f,	3.50861f,	5.51117f},
	{13,	0,	2,	"Magtheridon's Lair",	0,	70,	0,	530,	-336.411f,	3130.46f,	-102.928f,	5.20322f},
	{13,	0,	2,	"Karazhan",	0,	70,	0,	0,	-11118.9f,	-2010.33f,	47.0819f,	0.649895f},
	{13,	0,	2,	"Sunwell Plateau",	0,	70,	0,	530,	12574.1f,	-6774.81f,	15.0904f,	3.13788f},
	{13,	0,	2,	"Tempest Keep",	0,	70,	0,	530,	3088.49f,	1381.57f,	184.863f,	4.61973f},
	{13,	0,	2,	"Zul'Aman",	0,	70,	1,	530,	6851.78f,	-7972.57f,	179.242f,	4.64691f},
	{13,	7,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
	{14,	0,	2,	"Trial of the Crusader",	0,	80,	0,	571,	8515.61f,	714.153f,	558.248f,	1.57753f},
	{14,	0,	2,	"Icecrown Citadel",	0,	80,	0,	571,	5855.22f,	2102.03f,	635.991f,	3.57899f},
	{14,	0,	2,	"Naxxramas",	0,	80,	0,	571,	3668.72f,	-1262.46f,	243.622f,	4.785f},
	{14,	0,	2,	"Onyxia's Lair",	0,	80,	0,	1,	-4708.27f,	-3727.64f,	54.5589f,	3.72786f},
	{14,	0,	2,	"The Eye of Eternity",	0,	80,	0,	571,	3784.17f,	7028.84f,	161.258f,	5.79993f},
	{14,	0,	2,	"The Obsidian Sanctum",	0,	80,	0,	571,	3472.43f,	264.923f,	-120.146f,	3.27923f},
	{14,	0,	2,	"Ulduar",	0,	80,	0,	571,	9222.88f,	-1113.59f,	1216.12f,	6.27549f},
	{14,	0,	2,	"Vault of Archavon",	0,	80,	0,	571,	5453.72f,	2840.79f,	421.28f,	0.0f},
	{14,	7,	7,	"|cffffffffBack..|r",	0,	0,	0,	0,	0,	0,	0,	0},
	
//	{10,	0,	2,	"Teleport",	0,	0,	0,	map,	xf,	yf,	zf,	of},
//	{10,	1,	7,	"Back..",	0,	0,	0,	0,	0,	0,	0,	0},
};

// TextIDs from npc_text
enum eEnums
{
	TEXT_MAIN_H		=	400000,			//Horde main menu text
	TEXT_MAIN_A		=	400001,			//Alliance main menu text
	TEXT_DUNGEON	=	400002,			//Dungeon teleport menu texts
	TEXT_RAID		=	400003,			//Raid teleport menu text
	TEXT_AREA		=	400004,			//Area teleport location menu texts
	
	TELEPORT_COUNT	=	sizeof TeLe/sizeof(*TeLe),
};

#define ARE_YOU_SURE	"|cffffffffGetting a Move on to|r "
#define ERROR_COMBAT	"|cffff0000Kill Whatever that thing is first!|r"

bool Custom_FactCheck (uint32 Fact, unsigned char Key)
{
	bool Show = false;
	switch (TeLe[Key].faction)
	{
	case 0:
		Show = true;
		break;
	case 1:
		if (Fact == HORDE)
			Show = true;
		break;
	case 2:
		if (Fact == ALLIANCE)
			Show = true;
		break;
	}
	return (Show);
}

uint32 Custom_GetText (unsigned int menu, Player* pPlayer)
{
	uint32 TEXT = TEXT_AREA;
	switch (menu)
	{
	case 0:
		switch (pPlayer->GetTeam())
		{
		case ALLIANCE:
			TEXT = TEXT_MAIN_A;
			break;
		case HORDE:
			TEXT = TEXT_MAIN_H;
			break;
		}
	case 1:
	case 2:
	case 3:
		TEXT = TEXT_DUNGEON;
		break;
	case 4:
		TEXT = TEXT_RAID;
		break;
	}
	return (TEXT);
}

void Custom_GetMenu (Player* pPlayer, Creature* pCreature, uint32 Key)
{
	bool ENDMENU = false;
	for(uint32 i = 0; i < TELEPORT_COUNT; i++)
	{
		if (ENDMENU && TeLe[i].menu_id != Key)
			break;
		if (TeLe[i].menu_id == Key && pPlayer->getLevel() >= TeLe[i].level && Custom_FactCheck(pPlayer->GetTeam(), i))
		{
			if (TeLe[i].next_menu_id != 0)
				pPlayer->ADD_GOSSIP_ITEM_EXTENDED(TeLe[i].icon, TeLe[i].name, GOSSIP_SENDER_MAIN, i, "", TeLe[i].cost, false);
			else
				pPlayer->ADD_GOSSIP_ITEM_EXTENDED(TeLe[i].icon, TeLe[i].name, GOSSIP_SENDER_MAIN, i, ARE_YOU_SURE+TeLe[i].name, TeLe[i].cost, false);
			ENDMENU = true;
		}
	}
	pPlayer->PlayerTalkClass->SendGossipMenu(Custom_GetText(Key, pPlayer), pCreature->GetGUID());
}

class TeLe_gossip_codebox : public CreatureScript
{
	public:
	TeLe_gossip_codebox()
	: CreatureScript("TeLe_gossip_codebox")
	{
	}

	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		Custom_GetMenu(pPlayer, pCreature, 1);
		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus(); // clear the menu

		pPlayer->ModifyMoney(-1 * TeLe[uiAction].cost); // take cash
		uint32 Key = TeLe[uiAction].next_menu_id;
		if (Key == 0) // if no next_menu_id, then teleport to coords
		{
			if (!pPlayer->isInCombat())
			{
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(TeLe[uiAction].map, TeLe[uiAction].x, TeLe[uiAction].y, TeLe[uiAction].z, TeLe[uiAction].o);
				return true;
			}
			pPlayer->GetSession()->SendAreaTriggerMessage(ERROR_COMBAT);
			Key = TeLe[uiAction].menu_id;
		}

		Custom_GetMenu(pPlayer, pCreature, Key);
		return true;
	}
};

void AddSC_TeLe_gossip_codebox()
{
    new TeLe_gossip_codebox();
}