/*
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('70000', '0', '0', '0', '0', '0', '18', '0', '18', '0', 'LordPsyan', 'Buffs master', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_buffer', '1');
*/

#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED	"Приветствуем вас на сервере Freedom-WoW!"

#define MSG_ERR_HONOR "У вас не достаточно хонора для совершения покупки!"
#define MSG_ERR_INCOMBAT "Вы находитесь в бою. Чтобы использовать данного Npc выйдите из него."

#define MSG_GOSSIP_TEXT_BUFF_POWER_WORD "[Бафнуть] Слово силы: Стойкость"
#define MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_KINGS "[Бафнуть] Благословение Королей"
#define MSG_GOSSIP_TEXT_BUFF_MARK_OF_THE_WILD "[Бафнуть] Знак дикой природы"
#define MSG_GOSSIP_TEXT_BUFF_ARCANE_BRILLIANCE "[Бафнуть] Чародейская гениальность Даларана"
#define MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_MIGHT "[Бафнуть] Великое Благословение могущества"
#define MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_WISDOM "[Бафнуть] Благословение мудрости"
#define MSG_GOSSIP_TEXT_BUFF_THORNS "[Бафнуть] Шипы"
#define MSG_GOSSIP_TEXT_BUFF_DIVINE_SPIRIT "[Бафнуть] Божественный дух"
#define MSG_GOSSIP_TEXT_BUFF_SHADOW_PROTECTION "[Бафнуть] Защита от темной магии"
#define MSG_GOSSIP_TEXT_BUFF_STAMINA "[Бафнуть] Выносливость"

#define MSG_GOSSIP_TEXT_SUPPER_BUFF_BERSERK "[Бафнуть] Берсерк. Стоимость 1 миллион хонора."
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_AEGIS_OF_RAGNAROS "[Бафнуть] Эгида Рагнароса. Стоимость 1 миллион хонора."
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_AEGIS_OF_NELTHARION "[Бафнуть] Защита Нелтариона. Стоимость 100 тысяч хонора"
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_BLESSING_ADALS "[Бафнуть] Благословение А'далла. Стоимость 100 тысяч хонора."
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_CRIT_SPELLS "[Бафнуть] Критическое срабатывание. Стоимость 100 тысяч хонора."
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_BLESSING_PINCHI "[Бафнуть] Благословение мистера Пинчи. Стоимость 100 тысяч хонора."
#define MSG_GOSSIP_TEXT_SUPPER_BUFF_TRANSPARENCY "[Бафнуть] Прозрачность. Стоимость 100 тысяч хонора."

#define MSG_GOSSIP_TEXT_BUFF_MENU "[Меню Баффов] ->"
#define MSG_GOSSIP_TEXT_SUPER_MENU "[Меню особых бафов] ->"
#define MSG_GOSSIP_TEXT_MAIN_MENU "<- [Вернутся в Главное меню]"

#define CONST_HONOR_1 1000000
#define CONST_HONOR_2 100000


class npc_buffer : public CreatureScript
{
    public: 
    npc_buffer() : CreatureScript("npc_buffer") { }


	bool OnGossipHello(Player *player, Creature *creature)
		{ 
	    player->PlayerTalkClass->ClearMenus();
        creature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, player->GetGUID());
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_BUFF_MENU, GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_SUPER_MENU, GOSSIP_SENDER_MAIN, 13);
        player->SEND_GOSSIP_MENU (DEFAULT_GOSSIP_MESSAGE,creature->GetGUID()); 
        return true;
	}
             
	bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 action )
		{
		  if (!player->getAttackers().empty())
	{
		creature->MonsterWhisper(MSG_ERR_INCOMBAT, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
        return false;
		  }
    switch (action)
	{
	case 2:
        player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_POWER_WORD, GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_KINGS, GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_MARK_OF_THE_WILD, GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_ARCANE_BRILLIANCE, GOSSIP_SENDER_MAIN, 6);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_MIGHT, GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_BLESSING_OF_WISDOM, GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_THORNS, GOSSIP_SENDER_MAIN, 9);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_DIVINE_SPIRIT, GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_SHADOW_PROTECTION, GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BUFF_STAMINA, GOSSIP_SENDER_MAIN, 12);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 21);
	    player->SEND_GOSSIP_MENU (DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
		break;
	case 3:
		// Наложение стойкости (Исправлено)
	    player->CastSpell(player, 69377, true);
		player->CLOSE_GOSSIP_MENU();
	    break;
    case 4:
		 // Наложение Благословение Королей (Исправлено)
		player->CastSpell(player, 56525, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 5:
		 // Наложение Знак дикой природы
		player->CastSpell(player, 1126, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 6:
		 // Наложение Чародейской гениальности Даларана (Исправлено)
		player->CastSpell(player, 61316, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 7:
         // Наложение Благословение могущества (Исправлено)
		player->CastSpell(player, 29381, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 8:
		 // Наложение Благословение мудрости (Исправлено)
		player->CastSpell(player, 56521, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 9:
		 // Наложение Шипов (Исправлено)
		player->CastSpell(player, 66068, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 10:
		 // Наложение Божественный духа (Исправлено)
		player->CastSpell(player, 48074, true);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 11:
		 // Наложение Защиты от темной магии (Исправлено)
		player->CastSpell(player, 48170, true);
	    player->CLOSE_GOSSIP_MENU();
		break;
	case 12:
		player->CastSpell(player, 48102, true);
		player->CLOSE_GOSSIP_MENU();
		break;
    case 13:
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_BERSERK, GOSSIP_SENDER_MAIN, 14);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_AEGIS_OF_RAGNAROS, GOSSIP_SENDER_MAIN, 15);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_AEGIS_OF_NELTHARION, GOSSIP_SENDER_MAIN, 16);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_BLESSING_ADALS, GOSSIP_SENDER_MAIN, 17);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_CRIT_SPELLS, GOSSIP_SENDER_MAIN, 18);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_BLESSING_PINCHI, GOSSIP_SENDER_MAIN, 19);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, MSG_GOSSIP_TEXT_SUPPER_BUFF_TRANSPARENCY, GOSSIP_SENDER_MAIN, 20);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 21);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID()); 
        break;
	case 14:
	if (player->GetHonorPoints() < CONST_HONOR_1)
	    {
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение берсерка и отнятие 1 ляма хонора (Доработано)
		player->CastSpell(player, 41924, true);
		player->ModifyHonorPoints(-CONST_HONOR_1);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 15:
    if (player->GetHonorPoints() < CONST_HONOR_2)
	    {
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Эгиды Рагнароса(Доработано)
		player->CastSpell(player, 20620, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 16:
    if (player->GetHonorPoints() < CONST_HONOR_2)
	    {
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Защита Нелтариона(Доработано)
		player->CastSpell(player, 51512, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 17:
	if (player->GetHonorPoints() < CONST_HONOR_2)
		{
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Благословение А'дала
		player->CastSpell(player, 35076, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 18:
	if (player->GetHonorPoints() < CONST_HONOR_2)
		{
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Критического срабатывания положительных эффектов
		player->CastSpell(player, 31305, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 19:
	if (player->GetHonorPoints() < CONST_HONOR_2)
		{
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
	    player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Благословения мистера Пинчи
		player->CastSpell(player, 33053, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
				break;
	case 20:
        if (player->GetHonorPoints() < CONST_HONOR_2)
		{
		creature->MonsterWhisper(MSG_ERR_HONOR, player->GetGUID());
	    player->CLOSE_GOSSIP_MENU();
	}else{
		// Наложение Прозрачности
		player->CastSpell(player, 37802, true);
		player->ModifyHonorPoints(-CONST_HONOR_2);
        player->CLOSE_GOSSIP_MENU();
	}
		break;
	case 21:
		OnGossipHello(player, creature);
		break;

			}
				return true;
}

   };
void AddSC_npc_buffer()
{
    new npc_buffer;
}