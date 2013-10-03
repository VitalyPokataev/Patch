/*
* Copyright (C) 2013 BattleCore <https://bitbucket.org/Vitasic/battle>
*/

#include "ScriptMgr.h"
#include "Common.h"
#include "Chat.h"
#include "Player.h"
#include "World.h"
#include "Config.h"
#include "WorldSession.h"
#include "Language.h"
#include "Log.h"
#include "SpellAuras.h"


class vip_commandscript : public CommandScript
{
public:
    vip_commandscript() : CommandScript("vip_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand vipCommandTable[] =
        {
            { "debuff",         SEC_PLAYER,         false, &HandleVipDebuffCommand,             "", NULL },
            { "bank",           SEC_PLAYER,         false, &HandleVipBankCommand,               "", NULL },
            { "repair",         SEC_PLAYER,         false, &HandleVipRepairCommand,             "", NULL },
            { "resettalents",   SEC_PLAYER,         false, &HandleVipResetTalentsCommand,       "", NULL },
            { "taxi",           SEC_PLAYER,         false, &HandleVipTaxiCommand,               "", NULL },
            { "home",           SEC_PLAYER,         false, &HandleVipHomeCommand,               "", NULL },
            { "capital",        SEC_PLAYER,         false, &HandleVipCapitalCommand,            "", NULL },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };


        static ChatCommand commandTable[] =
        {
            { "vip",            SEC_PLAYER,         false, NULL,                                "", vipCommandTable },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };
        return commandTable;
    }

	static bool HandleVipDebuffCommand(ChatHandler* handler, const char* /*args*/)
    {   
        Player *plr = handler->GetSession()->GetPlayer();

		if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_DEBUFF_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if(plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->RemoveAurasDueToSpell(15007);
        handler->GetSession()->GetPlayer()->RemoveAurasDueToSpell(26013);

        return true;
    }
	
	static bool HandleVipBankCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }
		
		if (!sWorld->getBoolConfig(CONFIG_VIP_BANK_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }
 
        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->SendShowBank(handler->GetSession()->GetPlayer()->GetGUID());

        return true;
    }

    static bool HandleVipRepairCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_REPAIR_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->DurabilityRepairAll(false, 0, false);
        handler->PSendSysMessage(LANG_YOUR_ITEMS_REPAIRED, handler->GetNameLink(handler->GetSession()->GetPlayer()).c_str());
        return true;
    }

    static bool HandleVipResetTalentsCommand(ChatHandler* handler, const char* /*args*/)
   {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_RESET_TALENTS_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        plr->resetTalents(true);
        plr->SendTalentsInfoData(false);
		handler->PSendSysMessage(LANG_RESET_TALENTS_ONLINE, handler->GetNameLink(handler->GetSession()->GetPlayer()).c_str());
        return true;
    }

    static bool HandleVipTaxiCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_TAXI_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        plr->SetTaxiCheater(true);
        handler->PSendSysMessage(LANG_YOU_GIVE_TAXIS, handler->GetNameLink(plr).c_str());
        if (handler->needReportToTarget(plr))
            ChatHandler(plr->GetSession()).PSendSysMessage(LANG_YOURS_TAXIS_ADDED, handler->GetNameLink().c_str());
            
		return true;
    }

    static bool HandleVipHomeCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_HOME_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        plr->RemoveSpellCooldown(8690,true);
        plr->CastSpell(plr,8690,false);

        return true;
    }

    static bool HandleVipCapitalCommand(ChatHandler* handler, const char* /*args*/)
  {
        Player *plr = handler->GetSession()->GetPlayer();

        if (!handler->GetSession()->IsPremium())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_VIP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sWorld->getBoolConfig(CONFIG_VIP_CAPITAL_COMMAND))
        {
            handler->SendSysMessage(LANG_VIP_COMMAND_DISABLED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->isInCombat() || plr->isInFlight() || plr->GetMap()->IsBattlegroundOrArena() || plr->HasStealthAura() || plr->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || plr->isDead())
        {
            handler->SendSysMessage(LANG_VIP_ERROR);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (plr->GetTeam() == HORDE)
			plr->CastSpell(plr,3567,true);
        else
            plr->CastSpell(plr,3561,true);
		
		return true;
    }	   
};

void AddSC_vip_commandscript()
{
    new vip_commandscript();
}