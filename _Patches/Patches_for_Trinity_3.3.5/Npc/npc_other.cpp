/*
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('100006', '0', '0', '0', '0', '0', '18', '0', '18', '0', 'Акционер', '', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_other', '1');
*/

#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED	"Приветствуем вас на сервере WoW!"

#define MSG_ERR_AURA "Снятие дебафа 'Слабость после воскрешения' не возможна."
#define MSG_ERR_INCOMBAT "Вы находитесь в бою. Чтобы использовать данного Npc выйдите из него."
#define MSG_ERR_ARENA_POINT "У вас не достаточно Апа!"

#define MSG_COMPLETE_RENAME "Оплата Успешно Произведена Сделайте Логаут и Введите Новое Имя Персонажа.Не Забудьте После Смены Имени,Выйти Из Игры и Удалить Из Клиента Папку Cache!"
#define MSG_CUSTOMIZE_COMPLETE "Оплата Успешно Произведена Сделайте Логаут и Измените Внешность Персонажа.Не Забудьте После Смены Внешности,Выйти Из Игры и Удалить Из Клиента Папку Cache!"
#define MSG_CHANGE_FACTION_COMPLETE "Оплата Успешно Произведена Сделайте Логаут и Измените Фракцию Персонажа.Не Забудьте После Смены Внешности,Выйти Из Игры и Удалить Из Клиента Папку Cache!"

#define MSG_GOSSIP_TEXT_MAX_HEALTH "Вылечи меня!"
#define MSG_GOSSIP_TEXT_MAX_SKILL "Выучить все навыки оружия и защиты."
#define MSG_GOSSIP_TEXT_UNAURA_ALL "Снять бафы, дебафы, заклинания."
#define MSG_GOSSIP_TEXT_BAGS "Купить Сумки."
#define MSG_GOSSIP_TEXT_RIDING "Изучить Верховую Езду."

#define MSG_GOSSIP_TEXT_RENAME "Сменить Имя персонажа за 3 тысячи Апа."    // Thank Crispi
#define MSG_GOSSIP_TEXT_CUSTOM "Сменить Внешность персонажа за 3 тысячи Апа." // Thank Crispi
#define MSG_GOSSIP_TEXT_CHANGE_FACTION "Сменить Фракцию персонажа за 5 тысяч Апа."

#define MSG_GOSSIP_TEXT_A7_PRIEST_HEAL "Плечи А8 для Приста-хила {Дух}."
#define MSG_GOSSIP_TEXT_A7_PRIEST_DD "Плечи А8 для Приста на дд."
#define MSG_GOSSIP_TEXT_A7_DRUID_FERAL "Плечи А8 для Друида-ферала."
#define MSG_GOSSIP_TEXT_A7_DRUID_RESTOR "Плечи А8 для Друида-рестора."
#define MSG_GOSSIP_TEXT_A7_DRUID_BALANSE "Плечи А8 для Друида-баланса."
#define MSG_GOSSIP_TEXT_A7_WARRIOR "Плечи А8 для Воина."
#define MSG_GOSSIP_TEXT_A7_MAGE "Плечи А8 для Мага."
#define MSG_GOSSIP_TEXT_A7_HUNTER "Плечи А8 для Охотника."
#define MSG_GOSSIP_TEXT_A7_PALLADIN_HOLI "Плечи А8 для Палладина-хила."
#define MSG_GOSSIP_TEXT_A7_PALLADIN_DD "Плечи А8 для Палладина-дд."
#define MSG_GOSSIP_TEXT_A7_ROGUE "Плечи А8 для Разбойника."
#define MSG_GOSSIP_TEXT_A7_DK "Плечи А8 для Рыцаря Смерти."
#define MSG_GOSSIP_TEXT_A7_LOOK "Плечи А8 для Чернокнижника."
#define MSG_GOSSIP_TEXT_A7_SHAMAN_HOLI "Плечи А8 для Шамана-хила {Дух}." 
#define MSG_GOSSIP_TEXT_A7_SHAMAN_RDD "Плечи А8 для Шамана-рдд" 
#define MSG_GOSSIP_TEXT_A7_SHAMAN_DD "Плечи А8 для Шамана-дд."
 
#define CONST_ARENA_POINT_1 3000
#define CONST_ARENA_POINT_2 5000


        int bag = 21843;
        int warlockItem[1] =			{51540};
		int warriorItem[1] =			{51545};
		int druidRestorItem[1] =		{51424};
		int druidBalanceItem[1] =		{51424};
		int druidFeralItem[1] =			{51430};
		int priestDiscItem[1] =			{51486};
		int priestShadowItem[1] =		{51491};
		int mageItem[1] =				{51467};
		int hunterItem[1] =				{51462};
		int paladinHolyItem[1] =		{51473};
		int paladinMeleeItem[1] =		{51479};
		int rogueItem[1] =				{51496};
		int deathknightItem[1] =		{51418};
		int shamanMeleeItem[1] =		{51508};
		int shamanElementalItem[1] =	{51514};
		int shamanRestorItem[1] =		{51502};

class npc_other : public CreatureScript
{
    public: 
    npc_other() : CreatureScript("npc_other") { }

	void AddSet(Player* player, int massive[1])
	{
		for (int i = 0; i < 1; ++i)
			{
				player->AddItem(massive[i], 1);
			}
		player->CLOSE_GOSSIP_MENU();
	}

	bool OnGossipHello(Player *player, Creature *creature)
		{ 
        creature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, player->GetGUID());
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR , MSG_GOSSIP_TEXT_BAGS, GOSSIP_SENDER_MAIN, 2);
		int playerClass = player->getClass();
		switch (playerClass)
		{
		case CLASS_WARLOCK:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_LOOK, GOSSIP_SENDER_MAIN, 7);
		break;
		case CLASS_WARRIOR:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_WARRIOR, GOSSIP_SENDER_MAIN, 8);
		break;
		case CLASS_DRUID:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_RESTOR, GOSSIP_SENDER_MAIN, 9);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_BALANSE, GOSSIP_SENDER_MAIN, 10);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DRUID_FERAL, GOSSIP_SENDER_MAIN, 11);
		break;
		case CLASS_PRIEST:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PRIEST_HEAL, GOSSIP_SENDER_MAIN, 12);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PRIEST_DD, GOSSIP_SENDER_MAIN, 13);
		break;
		case CLASS_MAGE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_MAGE, GOSSIP_SENDER_MAIN, 14);
		break;
		case CLASS_PALADIN:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PALLADIN_HOLI, GOSSIP_SENDER_MAIN, 15);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_PALLADIN_DD, GOSSIP_SENDER_MAIN, 16);
		break;
		case CLASS_ROGUE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_ROGUE, GOSSIP_SENDER_MAIN, 17);
		break;
		case CLASS_DEATH_KNIGHT:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_DK, GOSSIP_SENDER_MAIN, 18);
		break;
		case CLASS_SHAMAN:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_DD, GOSSIP_SENDER_MAIN, 19);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_RDD, GOSSIP_SENDER_MAIN, 20);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_SHAMAN_HOLI, GOSSIP_SENDER_MAIN, 21);
		break;
		case CLASS_HUNTER:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, MSG_GOSSIP_TEXT_A7_HUNTER, GOSSIP_SENDER_MAIN, 22);
		break;
		}
		    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MAX_HEALTH, GOSSIP_SENDER_MAIN, 3);
		    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MAX_SKILL, GOSSIP_SENDER_MAIN, 4);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_UNAURA_ALL, GOSSIP_SENDER_MAIN, 5);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_RIDING, GOSSIP_SENDER_MAIN, 6);
		    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_RENAME, GOSSIP_SENDER_MAIN, 23);
		    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_CUSTOM, GOSSIP_SENDER_MAIN, 24);
		    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_CHANGE_FACTION, GOSSIP_SENDER_MAIN, 25);
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
			 player->AddItem(bag, 4);
			 player->CLOSE_GOSSIP_MENU();
			 break;
		  case 3:
			  player->SetHealth(player->GetMaxHealth());
		      player->CLOSE_GOSSIP_MENU();
			  break;
		  case 4:
			  player->UpdateSkillsToMaxSkillsForLevel();
		      player->CLOSE_GOSSIP_MENU();
			  break;
		  case 5:
			 if (player->HasAura(15007))
			 {
		creature->MonsterWhisper(MSG_ERR_AURA, player->GetGUID());
		player->CLOSE_GOSSIP_MENU();
		}else
			{
        player->RemoveAllAuras();
		player->CLOSE_GOSSIP_MENU();
		player->RemoveAllSpellCooldown();
		}
		      break;
		  case 6:
		      player->SetSkill(762, 6, 450, 450);
		      player->learnSpell(54197, true);
		      player->CLOSE_GOSSIP_MENU();
			  break;
		  case 7:
			  AddSet(player, warlockItem);
			  player->CLOSE_GOSSIP_MENU();
			  break;
		  case 8:
			  AddSet(player, warriorItem);
			  break;
		  case 9:
              AddSet(player, druidRestorItem);
			  break;
		  case 10:
			  AddSet(player, druidBalanceItem);
			  break;
		  case 11:
			  AddSet(player, druidFeralItem);
			  break;
		  case 12:
			  AddSet(player, priestDiscItem);
			  break;
		  case 13:
			  AddSet(player,  priestShadowItem);
			  break;
		  case 14:
			  AddSet(player,  mageItem);
			  break;
		  case 15:
			  AddSet(player,  paladinHolyItem);
			  break;
		  case 16:
			  AddSet(player,  paladinMeleeItem);
			  break;
		  case 17:
			  AddSet(player, rogueItem);
			  break;
		  case 18:
			  AddSet(player, deathknightItem);
			  break;
		  case 19:
			  AddSet(player, shamanMeleeItem);
			  break;
		  case 20:
			  AddSet(player, shamanRestorItem);
			  break;
		  case 21:
			  AddSet(player, shamanElementalItem);
			  break;
		  case 22:
			  AddSet(player, hunterItem);
		  case 23:
		if (player->GetArenaPoints() < CONST_ARENA_POINT_1)
		{
			  creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
	          player->CLOSE_GOSSIP_MENU();
		}else{
		      // Делаем Ренейм
		      player->SetAtLoginFlag(AT_LOGIN_RENAME);
		      player->ModifyArenaPoints(-CONST_ARENA_POINT_1);
              creature->MonsterWhisper(MSG_COMPLETE_RENAME, player->GetGUID());
              player->CLOSE_GOSSIP_MENU();
		      }
		      break;
		  case 24:
			  if (player->GetArenaPoints() < CONST_ARENA_POINT_1)
			  {
		      creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
		      player->CLOSE_GOSSIP_MENU();
	    }else{
		      // Делаем Смену внешности
		      player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		      player->ModifyArenaPoints(-CONST_ARENA_POINT_1);
              creature->MonsterWhisper(MSG_CUSTOMIZE_COMPLETE, player->GetGUID());
              player->CLOSE_GOSSIP_MENU();
			  }
			  break;
		  case 25:
			  if (player->GetArenaPoints() < CONST_ARENA_POINT_2)
			  {
		       creature->MonsterWhisper(MSG_ERR_ARENA_POINT, player->GetGUID());
		       player->CLOSE_GOSSIP_MENU();
	     }else{
		       // Делаем Смену фракции
		       player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		       player->ModifyArenaPoints(-CONST_ARENA_POINT_2);
               creature->MonsterWhisper(MSG_CHANGE_FACTION_COMPLETE, player->GetGUID());
               player->CLOSE_GOSSIP_MENU();
			  }
			  break; 
}
      return true;
}
	  };

	  void AddSC_npc_other()
{
	new npc_other;
}