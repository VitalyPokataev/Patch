/*
	 _____           ____              
	|   __|_____ _ _|    \ ___ _ _ ___ 
	|   __|     | | |  |  | -_| | |_ -|
	|_____|_|_|_|___|____/|___|\_/|___|
			  -[EmuDevs.com]-
--------------------------------------------------------
-±-  Released under the GNU General Public License.  -±-
-±- (C) Nomsoftware, 2011-2013. All rights reserved. -±-
--------------------------------------------------------
························································
· Title: Global Chat             	 				   ·
· Description: A x-faction global chat w/ class color  ·
· Scripted by: Faded                 				   ·
························································
http://emudevs.com/showthread.php/74-Global-Chat-w-Class-Colors-EZ-Editing
*/

#include "ScriptPCH.h"
#include "Chat.h"

#define CUSTOM_ORANGE		"|cff873600"
#define CUSTOM_RED			"|cffA40000"
#define CUSTOM_BLUE			"|cff00479E"
#define CUSTOM_GREEN		"|cff065600"
#define CUSTOM_CYAN			"|cff005853"
#define CUSTOM_WHITE		"|cffffffff"
const char* CLASS_COLOR;
const char* FACTION_COLOR;
const char* FACTION_TXT;

class global_chat : public CommandScript
{
	public: global_chat() : CommandScript("global_chat"){}
		static bool HandleWorldChatCommand(ChatHandler* eChat, const char* msg)
		{
			if (!*msg)
				return false;
			Player * player = eChat->GetSession()->GetPlayer();
			char message[1024];
			
			switch (player->getClass())
			{
				case CLASS_WARRIOR:
					CLASS_COLOR = "|cffc79c6e";
					break;
				case CLASS_PALADIN:
					CLASS_COLOR = "|cfff58cBa";
					break;
				case CLASS_HUNTER:
					CLASS_COLOR = "|cffabd473";
					break;
				case CLASS_ROGUE:
					CLASS_COLOR = "|cfffff569";
					break;
				case CLASS_PRIEST:
					CLASS_COLOR = "|cffffffff";
					break;
				case CLASS_DEATH_KNIGHT:
					CLASS_COLOR = "|cffc41F3b";
					break;
				case CLASS_SHAMAN:
					CLASS_COLOR = "|cff0070de";
					break;
				case CLASS_MAGE:
					CLASS_COLOR = "|cff69ccf0";
					break;
				case CLASS_WARLOCK:
					CLASS_COLOR = "|cff9482c9";
					break;
				case CLASS_DRUID:
					CLASS_COLOR = "|cffff7d0a";
					break;
			}		

			switch (player->GetTeam())
			{
				case ALLIANCE:
					FACTION_COLOR = "|cff0070de";
					FACTION_TXT = "A";
					break;
				case HORDE:
					FACTION_COLOR = "|cffc41F3b";
					FACTION_TXT = "H";
					break;
			}
				
			switch(player->GetSession()->GetSecurity())
			{
				case SEC_PLAYER:
					snprintf(message, 1024, "(Chat)-[%s%s|r]-[%sPlayer|r] %s%s|r: %s%s|r", FACTION_COLOR, FACTION_TXT, CUSTOM_WHITE, CLASS_COLOR, player->GetName().c_str(), CUSTOM_WHITE, msg);
					sWorld->SendGlobalText(message, NULL);
				break;
			
				case SEC_MODERATOR:
					snprintf(message, 1024, "(Chat)-[%s%s|r]-[%sMod|r] %s%s|r: %s%s|r", FACTION_COLOR, FACTION_TXT, CUSTOM_BLUE, CLASS_COLOR, player->GetName().c_str(), CUSTOM_CYAN, msg);
					sWorld->SendGlobalText(message, NULL);
				break;

				case SEC_GAMEMASTER:
					snprintf(message, 1024, "(Chat)-[%s%s|r]-[%sGM|r] %s%s|r: %s%s|r", FACTION_COLOR, FACTION_TXT, CUSTOM_GREEN, CLASS_COLOR, player->GetName().c_str(), CUSTOM_GREEN, msg);
					sWorld->SendGlobalText(message, NULL);
				break;

				case SEC_ADMINISTRATOR:
					snprintf(message, 1024, "(Chat)-[%s%s|r]-[%sDev|r] %s%s|r: %s%s|r", FACTION_COLOR, FACTION_TXT, CUSTOM_ORANGE, CLASS_COLOR, player->GetName().c_str(), CUSTOM_ORANGE, msg);
					sWorld->SendGlobalText(message, NULL);
				break;

				case SEC_CONSOLE:
					snprintf(message, 1024, "(Chat)-[%s%s|r]-[%sAdmin|r] %s%s|r: %s%s|r", FACTION_COLOR, FACTION_TXT, CUSTOM_RED, CLASS_COLOR, player->GetName().c_str(), CUSTOM_RED, msg);
					sWorld->SendGlobalText(message, NULL);
				break;
			}
			return true;
		}

		ChatCommand * GetCommands() const
		{
            static ChatCommand HandleWorldChatCommandTable[] =
            {
                    { "global", SEC_PLAYER, true, &HandleWorldChatCommand, "", NULL},
					{ NULL, 0, false, NULL, "", NULL}
            };
            return HandleWorldChatCommandTable;
		}
};

void AddSC_global_chat()
{
	new global_chat();
}