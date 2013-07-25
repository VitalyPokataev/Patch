/*
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('70001', '0', '0', '0', '0', '0', '18', '0', '18', '0', 'Cyon', 'Profession master', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_proff', '1');
*/

#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED	"Приветствуем вас на сервере Freedom-WoW!"

#define MSG_ERR_INCOMBAT "Вы находитесь в бою. Чтобы использовать данного Npc выйдите из него."

#define MSG_GOSSIP_TEXT_PROFFESION_SECON_MENU "[Меню Второстепенных профессий] ->"
#define MSG_GOSSIP_TEXT_MAIN_MENU "<- [Вернутся в Главное меню]"

#define MSG_GOSSIP_TEXT_ALCHEMY "Изучить Алхимию."
#define MSG_GOSSIP_TEXT_BLACKSMITHING "Изучить Кузнечное Дело."
#define MSG_GOSSIP_TEXT_ENCNANTING "Изучить Наложение Чар."
#define MSG_GOSSIP_TEXT_ENGINEERING "Изучить Инженерное дело."
#define MSG_GOSSIP_TEXT_HERBALISM "Изучить Травничество."
#define MSG_GOSSIP_TEXT_INSCRIPTION "Изучить Начертание."
#define MSG_GOSSIP_TEXT_JEWELCRAFTING "Изучить Ювелирное дело."
#define MSG_GOSSIP_TEXT_LEATHERWORKING "Изучить Кожевничество."
#define MSG_GOSSIP_TEXT_MINING "Изучить Горное дело."
#define MSG_GOSSIP_TEXT_SKINNING "Изучить Снятие шкур."
#define MSG_GOSSIP_TEXT_TAILORING "Изучить Портное дело."

#define MSG_GOSSIP_TEXT_COOKING	"Изучить Кулинарию."
#define MSG_GOSSIP_TEXT_FIRST_AID "Изучить Первую помощь."
#define MSG_GOSSIP_TEXT_FISHING	"Изучить Рыбную ловлю."

class npc_proff : public CreatureScript
{
    public: 
    npc_proff() : CreatureScript("npc_proff") { }
	
	void CompleteLearnProfession(Player *player, Creature * creature, SkillType skill) 
     { 
         if (PlayerAlreadyHasNineProfessions(player) && !IsSecondarySkill(skill)) 
            creature->MonsterWhisper("Вы уже выучили 2 професcии!", player->GetGUID()); 
         else 
         { 
             if (!LearnAllRecipesInProfession(player, skill)) 
                 creature->MonsterWhisper("Ошибка!", player->GetGUID()); 
         } 
     } 
   
   bool IsSecondarySkill(SkillType skill) const 
     { 
         return skill == SKILL_COOKING || skill == SKILL_FIRST_AID; 
     } 
   
   bool PlayerAlreadyHasNineProfessions(const Player *player) const 
     { 
         uint32 skillCount = 0; 

         if (player->HasSkill(SKILL_MINING)) 
             skillCount++; 
         if (player->HasSkill(SKILL_SKINNING)) 
             skillCount++; 
         if (player->HasSkill(SKILL_HERBALISM)) 
             skillCount++; 

         if (skillCount >= 2) 
             return true; 

         for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i) 
         { 
             SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(i); 
             if (!SkillInfo) 
                 continue; 

             if (SkillInfo->categoryId == SKILL_CATEGORY_SECONDARY) 
                 continue; 

             if ((SkillInfo->categoryId != SKILL_CATEGORY_PROFESSION) || !SkillInfo->canLink) 
                 continue; 

             const uint32 skillID = SkillInfo->id; 
             if (player->HasSkill(skillID)) 
                 skillCount++; 

             if (skillCount >= 2) 
                 return true; 
         } 

         return false; 
     } 

     bool LearnAllRecipesInProfession(Player *player, SkillType skill) 
     { 
         ChatHandler handler(player); 
         char* skill_name; 

         SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill); 
         skill_name = SkillInfo->name[handler.GetSessionDbcLocale()]; 

         if (!SkillInfo) 
         { 
             sLog->outError("Teleport NPC: received non-valid skill ID (LearnAllRecipesInProfession)"); 
             return false; 
         } 

         LearnSkillRecipesHelper(player, SkillInfo->id); 

         uint16 maxLevel = player->GetPureMaxSkillValue(SkillInfo->id); 
         player->SetSkill(SkillInfo->id, player->GetSkillStep(SkillInfo->id), maxLevel, maxLevel); 
         handler.PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name); 
          
         return true; 
     } 
     // See "static void HandleLearnSkillRecipesHelper(Player* player,uint32 skill_id)" from cs_learn.cpp  
     void LearnSkillRecipesHelper(Player *player, uint32 skill_id) 
     { 
         uint32 classmask = player->getClassMask(); 

         for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j) 
         { 
             SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j); 
             if (!skillLine) 
                 continue; 

             // wrong skill 
             if (skillLine->skillId != skill_id) 
                 continue; 

             // not high rank 
             if (skillLine->forward_spellid) 
                 continue; 

             // skip racial skills 
             if (skillLine->racemask != 0) 
                 continue; 

             // skip wrong class skills 
             if (skillLine->classmask && (skillLine->classmask & classmask) == 0) 
                 continue; 

             SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                continue; 

             player->learnSpell(skillLine->spellId, false); 
         } 
     } 
	 bool OnGossipHello(Player *player, Creature *creature)
	 {
		 player->PlayerTalkClass->ClearMenus();
		 creature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, player->GetGUID());
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ALCHEMY, GOSSIP_SENDER_MAIN, 2);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BLACKSMITHING, GOSSIP_SENDER_MAIN, 3);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ENCNANTING, GOSSIP_SENDER_MAIN, 4);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ENGINEERING, GOSSIP_SENDER_MAIN, 5);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_HERBALISM, GOSSIP_SENDER_MAIN, 6);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_INSCRIPTION, GOSSIP_SENDER_MAIN, 7);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_JEWELCRAFTING, GOSSIP_SENDER_MAIN, 8);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_MAIN, 9);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_MINING, GOSSIP_SENDER_MAIN, 10);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_SKINNING, GOSSIP_SENDER_MAIN, 11);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_TAILORING, GOSSIP_SENDER_MAIN, 12);
		 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_PROFFESION_SECON_MENU, GOSSIP_SENDER_MAIN, 13);
	     player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
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
		CompleteLearnProfession(player, creature, SKILL_ALCHEMY); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 3:
		CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 4:
		CompleteLearnProfession(player, creature,  SKILL_ENCHANTING); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 5:
		CompleteLearnProfession(player, creature, SKILL_ENGINEERING); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 6:
		CompleteLearnProfession(player, creature, SKILL_HERBALISM); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 7:
		CompleteLearnProfession(player, creature, SKILL_INSCRIPTION); 
		player->CLOSE_GOSSIP_MENU();
		break;
	case 8:
		CompleteLearnProfession(player, creature, SKILL_JEWELCRAFTING);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 9:
		CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 10:
		CompleteLearnProfession(player, creature, SKILL_MINING);
		player->CLOSE_GOSSIP_MENU();
	    break;
	case 11:
		CompleteLearnProfession(player, creature, SKILL_SKINNING);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 12:
		CompleteLearnProfession(player, creature, SKILL_TAILORING);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 13:
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_COOKING, GOSSIP_SENDER_MAIN, 14);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_FIRST_AID, GOSSIP_SENDER_MAIN, 15);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_FISHING, GOSSIP_SENDER_MAIN, 16);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 17);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
		break;
	case 14:
		CompleteLearnProfession(player, creature, SKILL_COOKING);
		player->CLOSE_GOSSIP_MENU();
		break;
	case 15:
		CompleteLearnProfession(player, creature, SKILL_FIRST_AID); 
		player->CLOSE_GOSSIP_MENU();
	    break;
	case 16:
		CompleteLearnProfession(player, creature, SKILL_FISHING); 
		player->CLOSE_GOSSIP_MENU();
	    break;
	case 17:
		OnGossipHello(player, creature);
		break;
	 }
		  return true;
	 }
	 
	};
 void AddSC_npc_proff()
{
    new npc_proff;
}