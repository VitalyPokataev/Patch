#include "ScriptPCH.h"
#include "Channel.h"
#include "Config.h"
#include "AccountMgr.h"
 
class System_Censure : public PlayerScript
{
public:
 System_Censure() : PlayerScript("System_Censure")
    {
        std::ifstream stream("/home/trinity/event/bin/ads.txt");
        std::string str;
 
        if (stream.is_open())
        {
            while (getline(stream, str))
            {
                bannedStrings.push_back(str);
            }

         }

        stream.close();
    }
        for (uint32 i = 0; i < bannedStrings.size(); i++)
        {
            if (bannedStrings[i].substr(bannedStrings[i].size() - 1, 1) == "\n")
                bannedStrings[i].erase(bannedStrings[i].size() - 1, 1);
        }
    }
 
    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg)
    {
        if (!CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL))
            PenaltyPlayer(player);
    }
 
    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
    {
        if (!CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL))
            PenaltyPlayer(player);
    }
 
    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group)
    {
        if (!CheckMessage(player, msg, lang, NULL, group, NULL, NULL))
            PenaltyPlayer(player);
    }
 
    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild)
    {
        if (!CheckMessage(player, msg, lang, NULL, NULL, guild, NULL))
            PenaltyPlayer(player);
    }
 
    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel)
    {
        if (!CheckMessage(player, msg, lang, NULL, NULL, NULL, channel))
            PenaltyPlayer(player);
    }
 
    bool CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
    {
        if (player->isGameMaster() || lang == LANG_ADDON || !sWorld->getBoolConfig(CONFIG_AD_ENABLE))
            return true;
 
        std::string lowedMsg = msg.c_str();
        std::transform(lowedMsg.begin(), lowedMsg.end(), lowedMsg.begin(), tolower);
 
        if (!bannedStrings.empty())
        {
            for(std::vector<std::string>::iterator it = bannedStrings.begin(); it != bannedStrings.end(); ++it)
            {
                if (lowedMsg.find(*it) != std::string::npos)
                {
                    msg = "";
                    return false;
                }
            }
        }
 
        if (!sWorld->getBoolConfig(CONFIG_AD_IP_ALLOW))
        {
            // clear msg spaces
            std::string::size_type n = 0;
            while((n = lowedMsg.find(L' ', n)) != lowedMsg.npos)
                lowedMsg.erase(n, 1);
 
            // parsing for IP
            std::stringstream ss(lowedMsg);
            std::string domainLvlStr;
            for(uint16 domainLvl = 0; std::getline(ss, domainLvlStr, '.'); ++domainLvl)
            {
                // upon get the full address
                if(domainLvl >= 3)
                {
                    msg = "";
                    return false;
                }
 
                // for string manipulation
                std::string tempStr;
 
                if(domainLvl == 0)
                {
                    // catch upper domain
                    std::string::reverse_iterator it;
                    for(it = domainLvlStr.rbegin(); it != domainLvlStr.rend(); ++it)
                    {
                        if(!isdigit((int)*it))
                            break;
 
                        tempStr.push_back(*it);
                    }
                    domainLvlStr.assign(tempStr.rbegin(), tempStr.rend());
                }
                else if(domainLvl == 3)
                {
                    // catch lower domain
                    std::string::iterator it;
                    for(it = domainLvlStr.begin(); it != domainLvlStr.end(); ++it)
                    {
                        if(!isdigit((int)*it))
                            break;
 
                        tempStr.push_back(*it);
                    }
                    domainLvlStr = tempStr;
                }
 
                // is not number or empty. isdigit(atoi(domainLvlStr.c_str())) is incorrect
                if(domainLvlStr.find_last_not_of("0123456789") != std::string::npos || domainLvlStr.empty())
                    domainLvl = 0;
            }
        }
 
        return true;
    }
 
    void PenaltyPlayer(Player* player)
    {
        switch (sWorld->getIntConfig(CONFIG_AD_PENALTY))
        {
            case 0:
                //nothing
                break;
            case 1://mute
                {
                    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
 
                    uint32 notSpeakTime = sWorld->getIntConfig(CONFIG_AD_MUTE_TIME);
                    std::string muteReasonStr = "Реклама";
 
                    int64 muteTime = time(NULL) + notSpeakTime * MINUTE;
                    player->GetSession()->m_muteTime = muteTime;
                    stmt->setInt64(0, muteTime);
                    ChatHandler(player).PSendSysMessage(LANG_YOUR_CHAT_DISABLED, notSpeakTime, muteReasonStr.c_str());
 
                    stmt->setUInt32(1, player->GetSession()->GetAccountId());
                    LoginDatabase.Execute(stmt);
                }
                break;
            case 2://kick
                player->GetSession()->KickPlayer();
                break;
            case 3://ban
                {
                    std::stringstream duration;
                    duration << sWorld->getIntConfig(CONFIG_AD_BAN_TIME) << "s";
                    std::string accountName;
                    AccountMgr::GetName(player->GetSession()->GetAccountId(), accountName);
                    std::stringstream banReason;
                    banReason << "Реклама";
 
                    sWorld->BanAccount(BAN_ACCOUNT, accountName, duration.str(), banReason.str(),"Server");
                }
                break;
            default:
                return;
        }
    }
 
    private:
        std::vector<std::string> bannedStrings;
};
 
void AddSC_System_Censure()
{
    new System_Censure();
}