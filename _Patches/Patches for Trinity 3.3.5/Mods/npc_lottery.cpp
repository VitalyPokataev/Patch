/*
DROP TABLE IF EXISTS `lottery_winners`;
CREATE TABLE `lottery_winners` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(12) NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `bet` longtext NOT NULL,
  `betPoints` int(10) unsigned NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `lottery_bets`;
CREATE TABLE `lottery_bets` (
  `id` int(10) unsigned NOT NULL DEFAULT '1',
  `name` varchar(12) NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `bet` longtext NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `lottery`;
CREATE TABLE `lottery` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `number_1` int(10) unsigned NOT NULL DEFAULT '0',
  `number_2` int(10) unsigned NOT NULL DEFAULT '0',
  `number_3` int(10) unsigned NOT NULL DEFAULT '0',
  `number_4` int(10) unsigned NOT NULL DEFAULT '0',
  `number_5` int(10) unsigned NOT NULL DEFAULT '0',
  `jackpot` int(10) unsigned NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

DELETE FROM game_event WHERE eventEntry = 132;
INSERT INTO game_event VALUES 
(132, "2011-01-31 20:00:00", "2020-12-31 06:00:00", 1440, 1, 0, "Lottery", 0);

DELETE FROM `creature_template` WHERE (`entry`=99013);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (99013, 0, 0, 0, 0, 0, 491, 491, 523, 523, '"Везунчик" Угрюмм', 'worldofwarcraft.by lottery', '', 0, 85, 85, 2, 35, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1.4, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1024, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_lottery', 1);

DELETE FROM `trinity_string` where `entry` IN ('11005', '11006', '11007');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11005', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот, который на данный момент составляет %f ед. золота, разыгран не был.|r');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11006', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот в %f единиц золота выигран игроком %s.|r');
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES ('11007', '', '|cffff0000[Сообщение лотареи]:Розыгрыш состоялся! Всего участвовало ставок: %u. Выигрышной оказалась комбинация %u %u %u %u %u. Джекпот в %f единиц золота разделило %u игроков.|r');
*/

#include "Config.h"

#define GOSSIP_BUY_TICKET           "Я хочу сделать ставку."
#define EVENT_LOTTERY               132

class npc_lottery : public CreatureScript
{
public:
    npc_lottery() : CreatureScript("npc_lottery") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer && !pPlayer->isGameMaster() && sConfig->GetBoolDefault("Lottery.Enable", false))
        {
            if (pPlayer->getLevel() >= uint32(sConfig->GetIntDefault("Lottery.MinUserLVL", 60)) && pPlayer->GetMoney() >= uint32(sConfig->GetIntDefault("Lottery.BetCost", 500000)))
            {
                std::string wh = ("Здравствуй, незнакомец. Хочешь испытать удачу? О да, по глазам вижу чо хочешь. Всё очень просто: назови мне 5 чисел в диапазоне от 1 до " + 
                                    std::string(sConfig->GetStringDefault("Lottery.MaxNumber", "30")) + " (разделяя пробелами), заплати стоимость ставки и дождись розыгрыша. Всё очень просто.");
                pCreature->MonsterWhisper(wh.c_str(), pPlayer->GetGUID());
                pPlayer->PrepareGossipMenu(pCreature);
                pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_BUY_TICKET, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF, "", 0, true);
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            }
            else
            {
                std::string wh = ("У вас недостаточно денег (требуется " + std::string(sConfig->GetStringDefault("Lottery.BetCost", "500000"))+ "ед. меди) или ваш уровень недостаточно велик (требуется " + std::string(sConfig->GetStringDefault("Lottery.MinUserLVL", "60")) + ").");
                pCreature->MonsterWhisper(wh.c_str(), pPlayer->GetGUID());
            }
        }
        return true;
    }

    bool OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* code)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiSender == GOSSIP_SENDER_MAIN)
        {
            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF:
                {
                    char * charCode = (char*)code;
                    std::string strCode = (char*)code;
                    char * tmp;
                    int32 number[5];
                    std::string error = ("Вы ввели неверное число. Ваша ставка должна находится в пределах от 1 до " + std::string(sConfig->GetStringDefault("Lottery.MaxNumber", "30")));
                    std::string errordub = ("Вы уже делали ставку. Ожидайте розыграша и да благословит вас Элуна");
                    std::string numbers = ("Вы сделали ставку на номера:" + std::string(strCode));

                    tmp = strtok (charCode," ");
                    for (int8 n = 0; n < 5; ++n)
                    {
                        if (tmp != NULL)
                        {
                            number[n] = atoi(tmp);
                            if (number[n] < 0 || number[n] > sConfig->GetIntDefault("Lottery.MaxNumber", 30))
                            {
                                pCreature->MonsterWhisper(error.c_str(), pPlayer->GetGUID());
                                pPlayer->CLOSE_GOSSIP_MENU();
                                return false;
                            }
                            tmp = strtok (NULL, " ");
                        }
                        else
                        {
                            pCreature->MonsterWhisper(error.c_str(), pPlayer->GetGUID());
                            pPlayer->CLOSE_GOSSIP_MENU();
                            return false;
                        }
                    }

                    uint32 betMaxID;
                    QueryResult qbetMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");

                    if (qbetMaxID)
                        betMaxID = qbetMaxID->Fetch()->GetUInt32();
                    else
                        betMaxID = 0;
                        
                    uint32 rBetGuid;
                    QueryResult pBetGuid = WorldDatabase.Query("SELECT guid FROM lottery_bets");
                    
                    if (pBetGuid)
                        rBetGuid = pBetGuid->Fetch()->GetUInt32();
                    else
                        rBetGuid = 0;
                    
                    if (rBetGuid == pPlayer->GetGUID())
                    {
                        pCreature->MonsterWhisper(errordub.c_str(), pPlayer->GetGUID());
                        pPlayer->CLOSE_GOSSIP_MENU();
                        return false;
                    }

                    WorldDatabase.PExecute("INSERT INTO lottery_bets (id, name, guid, bet) VALUES ('%u', '%s', '%u', '%s')", betMaxID+1, pPlayer->GetName(), pPlayer->GetGUIDLow(), strCode.c_str());
                    pCreature->MonsterWhisper(numbers.c_str(), pPlayer->GetGUID());
                    pPlayer->ModifyMoney(-sConfig->GetIntDefault("Lottery.BetCost", 500000));

                    pPlayer->CLOSE_GOSSIP_MENU();

                    return true;
                }
            }
        }

        return false;
        }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lotteryAI (pCreature);
    }

    struct npc_lotteryAI : public ScriptedAI
    {
        npc_lotteryAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void UpdateAI(const uint32 diff)
        {
            if (IsEventActive(EVENT_LOTTERY))
            {
                if (me->IsVisible())
                {
                    QueryResult qMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");
                    if (!qMaxID)
                        return;

                    uint32 betMaxID = qMaxID->Fetch()->GetUInt32();
                    uint32 luckyNumber[5];
                    uint32 lotteryID;
                    uint32 jackpotWinners = 0;

                    QueryResult qlotteryID = WorldDatabase.Query("SELECT MAX(id) FROM lottery");
                    if (!qlotteryID)
                        lotteryID = 0;
                    else
                        lotteryID = qlotteryID->Fetch()->GetUInt32();

                    QueryResult qBets  = WorldDatabase.Query("SELECT guid, bet, name FROM lottery_bets");
                    if (qBets)
                    {
                        for (int8 n = 0; n < 5; ++n)
                        {
                            luckyNumber[n] = urand(1, sConfig->GetIntDefault("Lottery.MaxNumber", 30));
                        }

                        do
                        {
                            Field *fBets = qBets->Fetch();
                            uint32 guid = fBets[0].GetUInt32();
                            std::string bet = fBets[1].GetString();
                            std::string rBet = bet; 
                            std::string name = fBets[2].GetString();
                            uint32 points = 0;
                            uint32 cash;

                            int32 number[5];
                            char * tmp;

                            tmp = strtok ((char*)bet.c_str()," ");

                            for (int8 n = 0; n < 5; ++n)
                            {
                                if (tmp != NULL)
                                {
                                    number[n] = atoi(tmp);
                                    tmp = strtok (NULL, " ");
                                }
                            }

                            for (int8 n = 0; n < 5; ++n)
                            {
                                for (int8 i = 0; i < 5; ++i)
                                {
                                    if (number[n] == luckyNumber[i])
                                        ++points;
                                }
                            }

                            switch (points)
                            {
                                case 1:
                                {
                                    cash = uint32(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.005f);
                                    break;
                                }
                                case 2:
                                {
                                    cash = uint32(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.01f);
                                    break;
                                }
                                case 3:
                                {
                                    cash = uint32(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.05f);
                                    break;
                                }
                                case 4:
                                {
                                    cash = uint32(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.2f);
                                    break;
                                }
                                case 5:
                                {
                                    WorldDatabase.PExecute("INSERT INTO lottery_winners (id, name, guid, bet, betPoints) VALUES ('%u', '%s', '%u', '%s', '%u')", lotteryID+1, name.c_str(), guid, rBet.c_str(), points);
                                    ++jackpotWinners;
                                    continue;
                                }
                                default:
                                    continue;
                            }

                            Player *pWinner = sObjectMgr->GetPlayerByLowGUID(guid);
                            SQLTransaction trans = CharacterDatabase.BeginTransaction();
                            MailDraft("Выигрыш", "Поздравляем! Ваша комбинация чисел оказалась счастливой!")
                                .AddMoney(cash)
                                .SendMailTo(trans, MailReceiver(pWinner, GUID_LOPART(guid)), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                            CharacterDatabase.CommitTransaction(trans);

                            WorldDatabase.PExecute("INSERT INTO lottery_winners (id, name, guid, bet, betPoints) VALUES ('%u', '%s', '%u', '%s', '%u')", lotteryID+1, name.c_str(), guid, rBet.c_str(), points);
                        } while (qBets->NextRow());
                        uint64 jackpot;
                        uint64 rJackpot;
                        uint64 defJackpot = uint64(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.7f);
                        QueryResult qJackpot  = WorldDatabase.PQuery("SELECT jackpot FROM lottery WHERE id = '%u'", lotteryID);
                        if (qJackpot)
                            jackpot = qJackpot->Fetch()->GetUInt32();
                        else
                            jackpot = 0;

                        rJackpot = jackpot;

                        if (jackpotWinners > 0)
                        {
                            QueryResult qJackpotWinners = WorldDatabase.PQuery("SELECT guid FROM lottery_winners WHERE betPoints = '5' and id = '%u'", lotteryID+1);
                            QueryResult qJackpotWinnersName;
                            if (jackpotWinners == 1)
                                qJackpotWinnersName = WorldDatabase.PQuery("SELECT name FROM lottery_winners WHERE betPoints = '5' and id = '%u'", lotteryID+1);

                            if (qJackpotWinners)
                            {
                                jackpot = uint64(jackpot / jackpotWinners);
                                do
                                {
                                    Field *fJackpotWinners = qJackpotWinners->Fetch();
                                    uint32 JPguid = fJackpotWinners[0].GetUInt32();

                                    Player *pJPWinner = sObjectMgr->GetPlayerByLowGUID(JPguid);
                                    SQLTransaction trans = CharacterDatabase.BeginTransaction();
                                    MailDraft("Джекпот!", "Вау! Да Вы просто везунчик! Вам удалось сорвать джекпот! Примите поздравление от организаторов лотареи")
                                        .AddMoney(jackpot = 0 ? uint64(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.7f) : jackpot)
                                        .SendMailTo(trans, MailReceiver(pJPWinner, GUID_LOPART(JPguid)), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                                    CharacterDatabase.CommitTransaction(trans);
                                } while (qJackpotWinners->NextRow());
                            }

                            if (jackpotWinners == 1 && qJackpotWinnersName)
                            {
                                std::string wName = qJackpotWinnersName->Fetch()->GetString();
                                sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE_JACKPOT, betMaxID, luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], ((jackpot = 0 ? uint64(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.7f) : rJackpot) * 0.0001f), wName.c_str());
                            }
                            else
                                sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE_JACKPOT_M_PLAYERS, betMaxID, luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], ((jackpot = 0 ? uint64(betMaxID * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.7f) : rJackpot) * 0.0001f), jackpotWinners);

                            WorldDatabase.PExecute("INSERT INTO lottery (number_1, number_2, number_3, number_4, number_5, jackpot) VALUES ('%u', '%u', '%u', '%u', '%u', '%u')", luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], defJackpot);
                        }
                        else
                        {
                            sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE, betMaxID, luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], ((jackpot + defJackpot) * 0.0001f));
                            WorldDatabase.PExecute("INSERT INTO lottery (number_1, number_2, number_3, number_4, number_5, jackpot) VALUES ('%u', '%u', '%u', '%u', '%u', '%u')", luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], (jackpot + defJackpot));
                        }
                        WorldDatabase.PExecute("DELETE FROM lottery_bets");

                        me->SetVisible(false);
                    }
                }
            }
            else
            {
                if (!me->IsVisible())
                    me->SetVisible(true);
            }
        }
    };

};


void AddSC_npc_lottery()
{
    new npc_lottery;
}