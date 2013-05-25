/***A Trinity Core World Chat Script ****
*________________< >____________________*
*_______________________________________*
* People Contributed to this script     *
*                                       *
*  Edit & Release: Ghostcrawler336      *
*                                       *
*  Recoded & Edit: ak47sigh(AlexeWarr)  *
*                                       *
*****************************************
src/server/shared/Common.h View file @ b29aac4
...	...	 @@ -149,11 +149,16 @@ enum TimeConstants
149	149	  
150	150	  enum AccountTypes
151	151	  {
152	 	 -    SEC_PLAYER         = 0,
153	 	 -    SEC_MODERATOR      = 1,
154	 	 -    SEC_GAMEMASTER     = 2,
155	 	 -    SEC_ADMINISTRATOR  = 3,
156	 	 -    SEC_CONSOLE        = 4                                  // must be always last in list, accounts must have less security level always also
 	152	 +    SEC_PLAYER          = 0,
 	153	 +    SEC_VIP             = 1,
 	154	 +    SEC_MODERATOR       = 2,
 	155	 +    SEC_GAMEMASTER      = 3,
 	156	 +    SEC_EVENTM          = 4,
 	157	 +    SEC_HEADGM          = 5,
 	158	 +    SEC_DEVELOPER       = 6,
 	159	 +    SEC_ADMINISTRATOR   = 7,
 	160	 +    SEC_OWNER           = 8,
 	161	 +    SEC_CONSOLE         = 9                                  // must be always last in list, accounts must have less security level always also
157	162	  };
*/
 
#include "ScriptPCH.h"
#include "Chat.h"
#include "Common.h"
#include "World.h"
 
// Defined ranks
#define ADMINISTRATOR                   "Admin"
#define HEADGM                                  "Head GM"
#define GAMEMASTER                              "GM"
#define DEVELOPER                               "Developer"
#define MODERATOR                               "Moderator"
#define OWNER                                   "Owner"
#define VIP                                             "Vip"
#define PLAYER                                  "Player"
#define EVENTM                                  "Event Master"
#define CONSOLE                                 "Console"
// Defined colors
#define MSG_COLOR_ORANGE                "|cffFFA500"
#define MSG_COLOR_DARKORANGE    "|cffFF8C00"
#define MSG_COLOR_RED                   "|cffFF0000"
#define MSG_COLOR_LIGHTRED              "|cffD63931"
#define MSG_COLOR_ROYALBLUE             "|cff4169E1"
#define MSG_COLOR_LIGHTBLUE             "|cffADD8E6"
#define MSG_COLOR_YELLOW                "|cffFFFF00"
#define MSG_COLOR_GREEN                 "|cff008000"
#define MSG_COLOR_PURPLE                "|cffDA70D6"
#define MSG_COLOR_WHITE                 "|cffffffff"
#define MSG_COLOR_SUBWHITE              "|cffbbbbbb"
 
void _SendWorldChat(Player* player, std::string message)
{
        std::string rank, color;
        std::ostringstream chat_string;
 
        switch(player->GetSession()->GetSecurity())
        {
        case SEC_PLAYER:                rank = PLAYER;
                                                        color = MSG_COLOR_LIGHTBLUE;
                break;
        case SEC_VIP:                   rank = VIP;
                                                        color = MSG_COLOR_PURPLE;
                break;
        case SEC_MODERATOR:             rank = MODERATOR;
                                                        color = MSG_COLOR_ROYALBLUE;
                break;
        case SEC_GAMEMASTER:    rank = GAMEMASTER;
                                                        color = MSG_COLOR_YELLOW;
                break;
        case SEC_EVENTM:                rank = EVENTM;
                                                        color = MSG_COLOR_ORANGE;
                break;
        case SEC_HEADGM:                rank = HEADGM;
                                                        color = MSG_COLOR_GREEN;
                break;
        case SEC_DEVELOPER:             rank = DEVELOPER;
                                                        color = MSG_COLOR_ROYALBLUE;
                break;
        case SEC_ADMINISTRATOR: rank = ADMINISTRATOR;
                                                        color = MSG_COLOR_RED;
                break;
        case SEC_OWNER:                 rank = OWNER;
                                                        color = MSG_COLOR_RED;
                break;
        case SEC_CONSOLE:               rank = CONSOLE;
                                                        color = MSG_COLOR_RED;
                break;
        }
 
        chat_string << "[World]" << " [" << rank << "] " << "[" << color << player->GetName() << "|r]: " << message;
 
        char msg[1024];
 
        snprintf(msg, 1024, chat_string.str().c_str());
 
        if(message.length() >= 3)
                sWorld->SendGlobalText(msg, NULL);
        else
                player->GetSession()->SendNotification("Your message has to be at least 3 characters longer");
       
}
 
 
class World_Chat : public CommandScript
{
    public:
    World_Chat() : CommandScript("World_Chat") { }
 
    static bool HandleWorldChatCommand(ChatHandler * pChat, const char * msg)
    {
                if(!*msg)
                        return false;
 
                Player* pPlayer = pChat->GetSession()->GetPlayer();
 
                if (!pPlayer->CanSpeak())
                        pPlayer->GetSession()->SendNotification("You can't do that while your voice is disabled");
                else
                        _SendWorldChat(pChat->GetSession()->GetPlayer(), msg);
 
        return true;
    }
 
    ChatCommand * GetCommands() const
    {
            static ChatCommand HandleWorldChatCommandTable[] =
            {
                    { "world",        SEC_PLAYER,         true,     &HandleWorldChatCommand,               "",  NULL },
                    { NULL,              0,               false,    NULL,                                  "",  NULL }
            };
            return HandleWorldChatCommandTable;
    }
};
 
void AddSC_World_Chat()
{
        new World_Chat;
}