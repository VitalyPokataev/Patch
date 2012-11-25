/*Автор: Семак 
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('100007', '0', '0', '0', '0', '0', '18', '0', '18', '0', 'npc arena-honor', 'arena-honor master', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'arena_honor_change', '1');
*/ 
class arena_honor_change : public CreatureScript
{
    public:
        arena_honor_change() : CreatureScript("arena_honor_change") { }
        
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
		char wh[255];
        char wh2[255];
        pPlayer->PlayerTalkClass->GetGossipMenu().ClearMenu();
        if (!pPlayer->GetSession()->IsPremium() && !pPlayer->isGameMaster())
		{
			pPlayer->CLOSE_GOSSIP_MENU();
			pCreature->MonsterTextEmote("Вы не являетесь Випом", 0, true);
			return true;
		}
            sprintf(wh, "Обменять Очки хонора %i на Очки арены %i", sWorld->getIntConfig(CONFIG_HONOR_CHANGE),sWorld->getIntConfig(CONFIG_ARENA_CHANGE));
            sprintf(wh2, "Обменять Очки арены %i на Очки чести %i", sWorld->getIntConfig(CONFIG_ARENA_CHANGE),sWorld->getIntConfig(CONFIG_HONOR_CHANGE));
            pPlayer->ADD_GOSSIP_ITEM( 10, wh, GOSSIP_SENDER_MAIN, 1);
            pPlayer->ADD_GOSSIP_ITEM( 10, wh2, GOSSIP_SENDER_MAIN, 3);
            
        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        switch(action)
        {
            case 1:
            {
                player->PlayerTalkClass->GetGossipMenu().ClearMenu();
                player->ADD_GOSSIP_ITEM( 10, "Да", GOSSIP_SENDER_MAIN, 2);
                player->ADD_GOSSIP_ITEM( 10, "Нет", GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5); 
                player->SEND_GOSSIP_MENU(1500017, creature->GetGUID()); 
                break;
            }
            case 2:
            {
                player->PlayerTalkClass->GetGossipMenu().ClearMenu();
                if(player->GetHonorPoints()>=sWorld->getIntConfig(CONFIG_HONOR_CHANGE))
                {
                    player->ModifyHonorPoints(-sWorld->getIntConfig(CONFIG_HONOR_CHANGE));
                    player->ModifyArenaPoints(sWorld->getIntConfig(CONFIG_ARENA_CHANGE));
                    creature->MonsterTextEmote("Обмен очков чести на очки арены закончен успешно !Diyvol-Server!.", LANG_UNIVERSAL, NULL);
                    player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5);
                    player->ADD_GOSSIP_ITEM( 10, "Закрыть меню", GOSSIP_SENDER_MAIN, 4);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
                else
                {
                    player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5);
                    player->ADD_GOSSIP_ITEM( 10, "Закрыть меню", GOSSIP_SENDER_MAIN, 4);        
                    player->SEND_GOSSIP_MENU(1500019, creature->GetGUID());
                }
                break;
            }
            case 3:
            {
                player->PlayerTalkClass->GetGossipMenu().ClearMenu();
                player->ADD_GOSSIP_ITEM( 10, "Да", GOSSIP_SENDER_MAIN, 6);
                player->ADD_GOSSIP_ITEM( 10, "Нет", GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5); 
                player->SEND_GOSSIP_MENU(1500017, creature->GetGUID()); 
                break;
            }
            case 6:
            {
                player->PlayerTalkClass->GetGossipMenu().ClearMenu();
                if (player->GetArenaPoints()>=sWorld->getIntConfig(CONFIG_ARENA_CHANGE))
                {
                    player->ModifyArenaPoints(-sWorld->getIntConfig(CONFIG_ARENA_CHANGE));
                    player->ModifyHonorPoints(sWorld->getIntConfig(CONFIG_HONOR_CHANGE));
                    creature->MonsterSay("Обмен очков арены на очки чесни закончен успешно!Diyvol-Server!.", LANG_UNIVERSAL, NULL);
                    player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5);
                    player->ADD_GOSSIP_ITEM( 10, "Закрыть меню", GOSSIP_SENDER_MAIN, 4);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    break;
                }
                else
                {
                    player->ADD_GOSSIP_ITEM( 10, "Вернуться в главное меню", GOSSIP_SENDER_MAIN, 5);
                    player->ADD_GOSSIP_ITEM( 10, "Закрыть меню", GOSSIP_SENDER_MAIN, 4); 
                    player->SEND_GOSSIP_MENU(1500021, creature->GetGUID());
                    break;
                }
                break;
            }
            case 4:
            {
                player->CLOSE_GOSSIP_MENU(); break;
            }
            case 5:
            {
				char wh[255];
                char wh2[255];
				sprintf(wh, "Обменять Очки хонора %i на Очки арены %i", sWorld->getIntConfig(CONFIG_HONOR_CHANGE),sWorld->getIntConfig(CONFIG_ARENA_CHANGE));
                sprintf(wh2, "Обменять Очки арены %i на Очки чести %i", sWorld->getIntConfig(CONFIG_ARENA_CHANGE),sWorld->getIntConfig(CONFIG_HONOR_CHANGE));
                player->PlayerTalkClass->GetGossipMenu().ClearMenu();
                player->ADD_GOSSIP_ITEM( 10, wh, GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM( 10, wh2, GOSSIP_SENDER_MAIN, 2);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                return true;
            }
        }
        return true;
    }
    
    bool GossipSelect_arena_honor_change(Player *player, Creature *_Creature, uint32 sender, uint32 action )
    {
        if (sender == GOSSIP_SENDER_MAIN)
        OnGossipSelect(player, _Creature, 0, action);

        return true;
    }
};

void AddSC_arena_honor_change()
{
    new arena_honor_change;
}