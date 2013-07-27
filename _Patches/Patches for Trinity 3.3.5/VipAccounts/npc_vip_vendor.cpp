/* Copyright (C) 2012 for TrinityCore <http://trinity-core.ru/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* SQL
INSERT INTO `creature_template` VALUES ('993372', '0', '0', '0', '0', '0', '16634', '0', '0', '0', 'MMOwning Elite', 'Elite Member Betreuung', '', '0', '80', '80', '0', '35', '35', '1', '1', '1.14286', '0.75', '2', '1755', '1755', '0', '1504', '1000', '1500', '0', '1', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '7', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '1', '100', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_vip', '1');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('100012','0','0','0','0','0','28769','0','0','0','ViP торговец','','','0','80','80','0','35','35','129','1','1.14286','1','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','7','4718662','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','2','2','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_vip_vendor','1');
*/

#include "ScriptPCH.h"

class npc_vip_vendor : public CreatureScript
{
public:
    npc_vip_vendor() : CreatureScript("npc_vip_vendor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetSession()->IsPremium())
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        }
        else
            creature->MonsterWhisper("Ваш аккаунт не является VIP аккаунтом.", player->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());
        return true;
    }
};

void AddSC_npc_vip_vendor()
{
    new npc_vip_vendor;
}