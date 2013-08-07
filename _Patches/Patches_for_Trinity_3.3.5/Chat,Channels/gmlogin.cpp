#include "ScriptPCH.h"
#include "TicketMgr.h"

class gm_login : public PlayerScript
{
public:
	gm_login() : PlayerScript("gm_login") { }

	void OnLogin(Player* player)
	{
		if (sWorld->getBoolConfig(CONFIG_GMLOGIN_ENABLED))
		{
			if (player->GetSession()->GetSecurity() >= SEC_MODERATOR)
			{
				ChatHandler handler(player);
				uint16 gmlvl = player->GetSession()->GetSecurity();
				std::string gmname = player->GetName();
				uint32 playeronline = sWorld->GetPlayerCount();
				std::string uptime = secsToTimeString(sWorld->GetUptime());
				std::string player_ip = player->GetSession()->GetRemoteAddress();
				uint16 tickets = sTicketMgr->GetOpenTicketCount();

				handler.PSendSysMessage("|cffff0000=================================|r");
				handler.PSendSysMessage("|cff00ff00Привет,|r %s", gmname.c_str());
				handler.PSendSysMessage("|cff00ff00Ваш уровень учетной записи:|r %u", gmlvl);
				handler.PSendSysMessage("|cff00ff00Ваш IP:|r %s", player_ip.c_str()); 
				handler.PSendSysMessage("|cff00ff00Сейчас|r %u |cff00ff00игроков онлайн|r", playeronline);
				handler.PSendSysMessage("|cff00ff00Открытие тикеты:|r %u", tickets);
				handler.PSendSysMessage("|cff00ff00Время работы сервера:|r %s", uptime.c_str());
				handler.PSendSysMessage("|cff00ff00Удачи и приятной игры|r");
				handler.PSendSysMessage("|cffff0000=================================|r");
				return;
			}
		}
	}
};

class gm_announce : public PlayerScript
{
public:
	gm_announce() : PlayerScript("gm_announce") { }

	void OnLogin(Player* player)
	{
		if (player->GetSession()->GetSecurity() == SEC_MODERATOR)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Аннонс входа]:|r Модератор %s зашел в игровой мир", player->GetName());
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
		}

		if (player->GetSession()->GetSecurity() == SEC_GAMEMASTER)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Аннонс входа]:|r Игровой мастер %s зашел в игровой мир", player->GetName());
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
		}

		if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Аннонс входа]:|r Администратор %s зашел в игровой мир", player->GetName());
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
		}
	}
};

void AddSC_gm_login()
{
	new gm_login();
	new gm_announce();
}