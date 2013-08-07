#include "ScriptPCH.h"

class npc_teleport : public CreatureScript
{
    public:
        npc_teleport() : CreatureScript("npc_teleport") { }

                bool OnGossipHello(Player *player, Creature *_creature)
                {
                        if (player->isInCombat())
                        {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Combat!", player->GetGUID());
                        return true;
                        }
                else
                        {
                                player->ADD_GOSSIP_ITEM( 0, "Wrath of the Lich King"         , GOSSIP_SENDER_MAIN, 1);
                                player->ADD_GOSSIP_ITEM( 0, "Cataclysm"                      , GOSSIP_SENDER_MAIN, 2);
                        }

                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
                return true;
                }

                bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
                {
                    if (player->isInCombat())
                    {
                                player->CLOSE_GOSSIP_MENU();
                                _creature->MonsterWhisper("Combat !", player->GetGUID());
                                return true;
                   }
                    if (sender == GOSSIP_SENDER_MAIN)
                    {
                         player->PlayerTalkClass->ClearMenus();
                      switch(uiAction)
                         {
                         case 1: //Wrath of the Lich King
                                player->ADD_GOSSIP_ITEM( 2, "Cities"                         , GOSSIP_SENDER_MAIN, 10);
                                player->ADD_GOSSIP_ITEM( 2, "Dungeons"                       , GOSSIP_SENDER_MAIN, 11);
                                player->ADD_GOSSIP_ITEM( 2, "Raids"                          , GOSSIP_SENDER_MAIN, 13);
                                player->ADD_GOSSIP_ITEM( 2, "Arenas"                         , GOSSIP_SENDER_MAIN, 14);
                                player->ADD_GOSSIP_ITEM( 2, "OutdoorPvP"                     , GOSSIP_SENDER_MAIN, 15);
                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                 , GOSSIP_SENDER_MAIN, 3);

                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

                                        case 10: //Cities
                                                player->ADD_GOSSIP_ITEM( 0, "Stormwind"                         , GOSSIP_SENDER_MAIN, 100);
                                                player->ADD_GOSSIP_ITEM( 0, "Ironforge"                         , GOSSIP_SENDER_MAIN, 101);
                                                player->ADD_GOSSIP_ITEM( 0, "Darnassus"                         , GOSSIP_SENDER_MAIN, 102);
                                                player->ADD_GOSSIP_ITEM( 0, "Exodar"                            , GOSSIP_SENDER_MAIN, 103);
                                                player->ADD_GOSSIP_ITEM( 0, "Orgrimmar"                         , GOSSIP_SENDER_MAIN, 104);
                                                player->ADD_GOSSIP_ITEM( 0, "Thunderbluff"                      , GOSSIP_SENDER_MAIN, 105);
                                                player->ADD_GOSSIP_ITEM( 0, "Undercity"                         , GOSSIP_SENDER_MAIN, 106);
                                                player->ADD_GOSSIP_ITEM( 0, "Silvermoon City"                   , GOSSIP_SENDER_MAIN, 107);
                                                player->ADD_GOSSIP_ITEM( 0, "Shattrath City"                    , GOSSIP_SENDER_MAIN, 108);
                                                player->ADD_GOSSIP_ITEM( 0, "Dalaran"                           , GOSSIP_SENDER_MAIN, 109);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"      , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                    , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                        case 11: //Dungeons I
                                                player->ADD_GOSSIP_ITEM( 0, "Azjol-Nerub: Ahn'kahet: The Old Kingdom"        , GOSSIP_SENDER_MAIN, 110);
                                                player->ADD_GOSSIP_ITEM( 0, "Azjol-Nerub: Azjol-Nerub"                       , GOSSIP_SENDER_MAIN, 111);
                                                player->ADD_GOSSIP_ITEM( 0, "Caverns of Time: The Culling of Stratholme"     , GOSSIP_SENDER_MAIN, 112);
                                                player->ADD_GOSSIP_ITEM( 0, "Crusaders' Coliseum: Trial of the Champion"     , GOSSIP_SENDER_MAIN, 113);
                                                player->ADD_GOSSIP_ITEM( 0, "Drak'Tharon Keep"                                 , GOSSIP_SENDER_MAIN, 114);
                                                player->ADD_GOSSIP_ITEM( 0, "Gundrak"                                          , GOSSIP_SENDER_MAIN, 115);
                                                player->ADD_GOSSIP_ITEM( 0, "Icecrown Citadel: Halls of Reflection"          , GOSSIP_SENDER_MAIN, 116);
                                                player->ADD_GOSSIP_ITEM( 0, "Icecrown Citadel: Pit of Saron"                   , GOSSIP_SENDER_MAIN, 117);
                                                player->ADD_GOSSIP_ITEM( 4, "[Page II] ->"                                            , GOSSIP_SENDER_MAIN, 12);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"               , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                                    , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                        case 12: //Dungeons II
                                                player->ADD_GOSSIP_ITEM( 0, "Icecrown Citadel: The Forge of Souls"          , GOSSIP_SENDER_MAIN, 120);
                                                player->ADD_GOSSIP_ITEM( 0, "The Nexus: The Nexus"                            , GOSSIP_SENDER_MAIN, 121);
                                                player->ADD_GOSSIP_ITEM( 0, "The Nexus: The Oculus"                          , GOSSIP_SENDER_MAIN, 122);
                                                player->ADD_GOSSIP_ITEM( 0, "The Violet Hold"                               , GOSSIP_SENDER_MAIN, 123);
                                                player->ADD_GOSSIP_ITEM( 0, "Ulduar: Halls of Lightning"                      , GOSSIP_SENDER_MAIN, 124);
                                                player->ADD_GOSSIP_ITEM( 0, "Ulduar: Halls of Stone"                          , GOSSIP_SENDER_MAIN, 125);
                                                player->ADD_GOSSIP_ITEM( 0, "Utgarde Keep: Utgarde Keep"                      , GOSSIP_SENDER_MAIN, 126);
                                                player->ADD_GOSSIP_ITEM( 0, "Utgarde Keep: Utgarde Pinnacle"                  , GOSSIP_SENDER_MAIN, 127);
                                        player->ADD_GOSSIP_ITEM( 4, "<- [Page I]"                                     , GOSSIP_SENDER_MAIN, 11);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"             , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                                  , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                         case 13: //Raids
                                                player->ADD_GOSSIP_ITEM( 0, "Crusaders' Coliseum: Trial of the Crusader"       , GOSSIP_SENDER_MAIN, 130);
                                                player->ADD_GOSSIP_ITEM( 0, "Icecrown Citadel"                                    , GOSSIP_SENDER_MAIN, 131);
                                                player->ADD_GOSSIP_ITEM( 0, "Naxxramas"                                          , GOSSIP_SENDER_MAIN, 132);
                                                player->ADD_GOSSIP_ITEM( 0, "Onyxia's Lair"                                      , GOSSIP_SENDER_MAIN, 133);
                                                player->ADD_GOSSIP_ITEM( 0, "The Nexus: The Eye of Eternity"                   , GOSSIP_SENDER_MAIN, 134);
                                                player->ADD_GOSSIP_ITEM( 0, "The Obsidian Sanctum"                                , GOSSIP_SENDER_MAIN, 135);
                                                player->ADD_GOSSIP_ITEM( 0, "Ulduar"                                              , GOSSIP_SENDER_MAIN, 136);
                                                player->ADD_GOSSIP_ITEM( 0, "Vault of Archavon"                                   , GOSSIP_SENDER_MAIN, 137);
                                        player->ADD_GOSSIP_ITEM( 0, "The Ruby Sanctum"                                    , GOSSIP_SENDER_MAIN, 138);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"                 , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                                      , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                        case 14: //Arenas
                                                player->ADD_GOSSIP_ITEM( 0, "Gurubashi Arena"                   , GOSSIP_SENDER_MAIN, 140);
                                                player->ADD_GOSSIP_ITEM( 0, "Dire Maul Arena"                   , GOSSIP_SENDER_MAIN, 141);
                                                player->ADD_GOSSIP_ITEM( 0, "Circle of Blood Arena"             , GOSSIP_SENDER_MAIN, 142);
                                                player->ADD_GOSSIP_ITEM( 0, "Nagrand Arena"                     , GOSSIP_SENDER_MAIN, 143);
                                                player->ADD_GOSSIP_ITEM( 0, "Zul'Drak Arena"                    , GOSSIP_SENDER_MAIN, 144);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"      , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                    , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                         case 15: //OutdoorPvP
                                                player->ADD_GOSSIP_ITEM( 0, "Wintergrasp"                               , GOSSIP_SENDER_MAIN, 150);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Wrath of the Lich King]"       , GOSSIP_SENDER_MAIN, 1);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                            , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                         case 2: //Cataclysm
                                player->ADD_GOSSIP_ITEM( 2, "Cities"                         , GOSSIP_SENDER_MAIN, 20);
                                player->ADD_GOSSIP_ITEM( 2, "Dungeons"                       , GOSSIP_SENDER_MAIN, 21);
                                player->ADD_GOSSIP_ITEM( 2, "Raids"                          , GOSSIP_SENDER_MAIN, 22);
                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                 , GOSSIP_SENDER_MAIN, 3);

                               player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

                                        case 20: //Cities
                                                player->ADD_GOSSIP_ITEM( 0, "Kezan"                             , GOSSIP_SENDER_MAIN, 200);
                                                player->ADD_GOSSIP_ITEM( 0, "Gilneas City"                      , GOSSIP_SENDER_MAIN, 201);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Cataclysm]"                    , GOSSIP_SENDER_MAIN, 2);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                    , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                        case 21: //Dungeons
                                                player->ADD_GOSSIP_ITEM( 0, "Abyssal Maw: Throne of the Tides"                  , GOSSIP_SENDER_MAIN, 210);
                                                player->ADD_GOSSIP_ITEM( 0, "Blackrock Caverns"                                 , GOSSIP_SENDER_MAIN, 211);
                                                player->ADD_GOSSIP_ITEM( 0, "Firelands"                                         , GOSSIP_SENDER_MAIN, 212);
                                                player->ADD_GOSSIP_ITEM( 0, "Grim Batol"                                        , GOSSIP_SENDER_MAIN, 213);
                                                player->ADD_GOSSIP_ITEM( 0, "Halls of Origination"                              , GOSSIP_SENDER_MAIN, 214);
                                                player->ADD_GOSSIP_ITEM( 0, "Lost City of the Tol'vir"                          , GOSSIP_SENDER_MAIN, 215);
                                                player->ADD_GOSSIP_ITEM( 0, "The Stonecore"                                     , GOSSIP_SENDER_MAIN, 216);
                                                player->ADD_GOSSIP_ITEM( 0, "The Vortex Pinnacle"                               , GOSSIP_SENDER_MAIN, 217);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Cataclysm]"                                    , GOSSIP_SENDER_MAIN, 2);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                                    , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;

                                         case 22: //Raids
                                                player->ADD_GOSSIP_ITEM( 0, "Baradin Hold"                                        , GOSSIP_SENDER_MAIN, 220);
                                                player->ADD_GOSSIP_ITEM( 0, "Blackwing Descent"                           , GOSSIP_SENDER_MAIN, 221);
                                                player->ADD_GOSSIP_ITEM( 0, "The Bastion of Twilight"                     , GOSSIP_SENDER_MAIN, 222);
                                                player->ADD_GOSSIP_ITEM( 0, "Throne of the Four Winds"                    , GOSSIP_SENDER_MAIN, 223);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Cataclysm]"                              , GOSSIP_SENDER_MAIN, 2);
                                                player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                              , GOSSIP_SENDER_MAIN, 3);

                                                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                        break;


                         case 3: //<- [Main Menu]
                                player->ADD_GOSSIP_ITEM( 0, "Wrath of the Lich King"        , GOSSIP_SENDER_MAIN, 1);
                                player->ADD_GOSSIP_ITEM( 0, "Cataclysm"                      , GOSSIP_SENDER_MAIN, 2);

                               player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
                                break;

                         /********** Wrath of the Lich King - Cities **********/

                         case 100: //Stormwind
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -8831.029297, 623.342407, 94.074432, 3.939123);
                               break;
                         case 101: //Ironforge
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -4918.879883f, -940.406006f, 501.563995f, 5.423470f);
                               break;
                         case 102: //Darnassus
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, 9949.559570f, 2284.209961f, 1341.394165f, 1.525185f);
                               break;
                         case 103: //Exodar
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(530, -3965.699951f, -11653.599609f, -138.843994f, 6.192861f);
                               break;
                         case 104: //Orgrimmar
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, 1566.470459, -4398.960449, 16.259722, 0.548813);
                               break;
                         case 105: //Thunder Bluff
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -1277.369995f, 124.804001f, 131.287003f, 5.222740f);
                               break;
                         case 106: //Undercity
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, 1584.069946f, 241.987000f, -52.153400f, 0.049647f);
                               break;
                         case 107: //Silvermoon City
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(530, 9487.690430f, -7279.200195f, 14.286600f, 6.164780f);
                               break;
                         case 108: //Shattrath City
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(530, -1838.160034f, 5301.790039f, -12.428000f, 5.951700f);
                               break;
                         case 109: //Dalaran
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5804.149902f, 624.770996f, 647.767029f, 1.640000f);
                               break;

                         /********** Wrath of the Lich King - Dungeons I **********/
                        
                         case 110: //Azjol-Nerub: Ahn'kahet: The Old Kingdom 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3650.226562f, 2053.362305f, 1.787416f, 4.287086f);
                               break;
                         case 111: //Azjol-Nerub: Azjol-Nerub
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3707.860107f, 2150.229980f, 36.757530f, 2.629380f);
                               break;
                         case 112: //Caverns of Time: The Culling of Stratholme
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -8748.678711f, -4439.887207f, -199.603653f, 4.215156f);
                               break;
                         case 113: //Crusaders' Coliseum: Trial of the Champion
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 8516.581055f, 715.013245f, 558.247742f, 1.402019f);
                               break;
                         case 114: //Drak'Tharon Keep 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 4497.230957f, -2043.756714f, 160.823090f, 6.212611f);
                               break;
                         case 115: //Gundrak 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 6720.729492f, -4632.532715f, 450.067780f, 3.860390f);
                               break;
                         case 116: //Icecrown Citadel: Halls of Reflection
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5820.330566f, 2085.426758f, 636.065022f, 3.45f);
                               break;
                         case 117: //Icecrown Citadel: Pit of Saron
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5820.330566f, 2085.426758f, 636.065022f, 3.45f);
                               break;

                         /********** Wrath of the Lich King - Dungeons II **********/

                         case 120: //Icecrown Citadel: The Forge of Souls
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5820.330566f, 2085.426758f, 636.065022f, 3.45f);
                               break;
                         case 121: //The Nexus: The Nexus 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3881.024902f, 6984.152832f, 73.761024f, 0.012697f);
                               break;
                         case 122: //The Nexus: The Oculus
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3881.296631f, 6984.644531f, 106.320549f, 3.167648f);
                               break;
                         case 123: //The Violet Hold
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5696.196777f, 508.277527f, 653.127502f, 4.022903f);
                               break;
                         case 124: //Ulduar: Halls of Lightning
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 9122.863281f, -1328.542847f, 1060.774658f, 5.482558f);
                               break;
                         case 125: //Ulduar: Halls of Stone 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 8924.228516f, -1018.985535f, 1039.651245f, 1.616828f);
                               break;
                         case 126: //Utgarde Keep: Utgarde Keep 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 8924.228516f, -1018.985535f, 1039.651245f, 1.616828f);
                               break;
                         case 127: //Utgarde Keep: Utgarde Pinnacle 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 1256.970337f, -4854.426758f, 215.561264f, 3.395841f);
                               break;

                         /********** Wrath of the Lich King - Raids **********/

                         case 130: //Crusaders' Coliseum: Trial of the Crusader
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 8515.061523f, 682.271545f, 558.247864f, 1.640000f);
                               break;
                         case 131: //Icecrown Citadel
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5820.330566f, 2085.426758f, 636.065022f, 3.45f);
                               break;
                         case 132: //Naxxramas
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3670.364014f, -1279.799194f, 243.533768f, 1.540000f);
                               break;
                         case 133: //Onyxia's Lair 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -4681.220215f, -3709.275146f, 46.718338f, 3.510000f);
                               break;
                         case 134: //The Nexus: The Eye of Eternity
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3918.719971f, 7015.359863f, 161.330002f, 0.530000f);
                               break;
                         case 135: //The Obsidian Sanctum 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3452.629883f, 269.256989f, -113.580002f, 0.120000f);
                               break;
                         case 136: //Ulduar 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 9327.326172f, -1117.689819f, 1245.146606f, 0.080000f);
                               break;
                         case 137: //Vault of Archavon 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5475.004883f, 2840.206543f, 418.675812f, 6.240000f);
                               break;
                         case 138: //The Ruby Sanctum 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 3599.487793f, 198.751205f, -113.832062f, 5.338952f);
                               break;

                         /********** Wrath of the Lich King - Arenas **********/

                         case 140: //Gurubashi Arena 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -13309.700195f, 78.886703f, 22.289927f, 0.940000f);
                               break;
                         case 141: //Dire Maul Arena 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -3717.760010f, 1124.719971f, 132.315994f, 4.340000f);
                               break;
                         case 142: //Circle of Blood Arena 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(530, 2837.373535f, 5930.557129f, 11.215009f, 5.700000f);
                               break;
                         case 143: //Nagrand Arena 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(530, -1998.135498f, 6579.937988f, 11.166474f, 2.360000f);
                               break;
                         case 144: //Zul'Drak Arena 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 5767.081055f, -2998.182617f, 272.817322f, 3.875237f);
                               break;

                         /********** Wrath of the Lich King - Outdoor PvP **********/

                         case 150: //Wintergrasp 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(571, 4561.580078f, 2835.330078f, 389.790009f, 0.340000f);
                               break;

                         /********** Cataclysm - Cities **********/

                         case 200: //Kezan
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(648, -8266.549805f, 1497.969971f, 43.061401f, 4.676780f);
                               break;
                         case 201: //Gilneas City 
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -1747.245117f, 1371.754517f, 20.2067633f, 0.651257f);
                               break;

                         /********** Cataclysm - Dungeons **********/

                         case 210: //Abyssal Maw: Throne of the Tides
                                player->CLOSE_GOSSIP_MENU();
                               break;
                         case 211: //Blackrock Caverns
                                player->CLOSE_GOSSIP_MENU();
                               break;
                         case 212: //Firelands
                                player->CLOSE_GOSSIP_MENU();
                               break;
                         case 213: //Grim Batol
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -4068.742432f, -3453.749756f, 279.000641f, 0.342511f);
                               break;
                         case 214: //Halls of Origination
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -10205.358398f, -1838.916748f, 20.128099f, 3.202806f);
                               break;
                         case 215: //Lost City of the Tol'vir
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -10662.812500f, -1302.016236f, 15.354200f, 3.400734f);
                               break;
                         case 216: //The Stonecore
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(646, 1021.212585f, 649.178284f, 156.672363f, 4.961962f);
                               break;
                         case 217: //The Vortex Pinnacle
                                player->CLOSE_GOSSIP_MENU();
                               break;

                         /********** Cataclysm - Raids **********/

                         case 220: //Baradin Hold
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(732, -1259.285767f, 1049.690186f, 106.995003f, 3.102642f);
                               break;
                         case 221: //Blackwing Descent
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0, -7536.93359f, -1203.900635f, 477.725647f, 1.859162f);
                               break;
                         case 222: //The Bastion of Twilight
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(0,-4891, -4235, 829, 2);
                               break;
                         case 223: //Throne of the Four Winds
                                player->CLOSE_GOSSIP_MENU();
                                player->TeleportTo(1, -11354.738281f, 57.456497f, 723.884705f, 1.982325f);
                               break;

                         default:
                                 break;
                         }
                  }
                  return true;
          }
};

void AddSC_npc_teleport()
{
    new npc_teleport();
}