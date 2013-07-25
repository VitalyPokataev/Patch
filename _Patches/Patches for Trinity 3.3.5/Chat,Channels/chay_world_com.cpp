#include "ScriptPCH.h"
#include "Chat.h"
#include "Common.h"
#include "World.h"
 
// Defined ranks
#define ADMINISTRATOR                   "Administration"
#define HEADGM                                  "Gl.GM"
#define GAMEMASTER                              "GM"
#define DEVELOPER                               "Developer"
#define MODERATOR                               "Moderator"
#define RP MAN                                   "RP MAN"
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
        case SEC_GLGM:                rank = GLGM;
                                                        color = MSG_COLOR_GREEN;
                break;
        case SEC_DEVELOPER:             rank = DEVELOPER;
                                                        color = MSG_COLOR_ROYALBLUE;
                break;
        case SEC_ADMINISTRATOR: rank = ADMINISTRATOR;
                                                        color = MSG_COLOR_RED;
                break;
        case SEC_RPMAN:                 rank = RPMAN;
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