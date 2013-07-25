#include "ScriptPCH.h"
#include "Config.h"
#include "AccountMgr.h"

class gm_enters : public PlayerScript
{
public:
    gm_enters() : PlayerScript("gm_enters") {}

    void OnLogin(Player* player)
    {
        if (sWorld->getBoolConfig(CONFIG_GM_ENTERS_GAME))
        {
            if (player && AccountMgr::IsGMAccount(player->GetSession()->GetSecurity()))
            {
                std::string sText = ("Игровой мастер " + std::string(player->GetSession()->GetPlayerName()) + " входит в игру.");
                sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());
            }
        }
    }
};

class gm_leaves : public PlayerScript
{
public:
    gm_leaves() : PlayerScript("gm_leaves") {}

    void OnLogout(Player* player)
    {
        if (sWorld->getBoolConfig(CONFIG_GM_ENTERS_GAME))
        {
            if (player && AccountMgr::IsGMAccount(player->GetSession()->GetSecurity()))
            {
                std::string sText = ("Игровой мастер " + std::string(player->GetSession()->GetPlayerName()) + " покидает игру.");
                sWorld->SendServerMessage(SERVER_MSG_STRING, sText.c_str());
            }
        }
    }
};

void AddSC_gm_monitoring()
{
    new gm_enters();
    new gm_leaves();
}
