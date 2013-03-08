REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200133, 0, 0, 0, 0, 0, 29780, 0, 0, 0, 'Reagent', 'Reagent', '', 0, 80, 80, 0, 35, 35, 4224, 1, 1, 50, 150, 0, 1000, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200133);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200133, 5565, 0, 0, 0),
(200133, 6265, 0, 0, 0),
(200133, 16583, 0, 0, 0),
(200133, 17020, 0, 0, 0),
(200133, 17030, 0, 0, 0),
(200133, 17031, 0, 0, 0),
(200133, 17032, 0, 0, 0),
(200133, 17033, 0, 0, 0),
(200133, 21177, 0, 0, 0),
(200133, 37201, 0, 0, 0),
(200133, 44605, 0, 0, 0),
(200133, 44614, 0, 0, 0),
(200133, 44615, 0, 0, 0),
(200133, 49633, 0, 0, 0),
(200133, 49634, 0, 0, 0);


DELETE FROM `creature` WHERE `id`=200133;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201156, 200133, 0, 1, 1, 0, 0, -8918.81, 537.589, 94.8596, 3.92805, 300, 0, 0, 5342, 0, 0),
(201408, 200133, 1, 1, 1, 0, 0, 1424.57, -4382.98, 25.4627, 0.13534, 300, 0, 0, 5342, 0, 0);


REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200142, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Enchanting/Materials', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1000, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200142);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200142, 10940, 0, 0, 0),
(200142, 34052, 0, 0, 0),
(200142, 34053, 0, 0, 0),
(200142, 34054, 0, 0, 0),
(200142, 34056, 0, 0, 0),
(200142, 34057, 0, 0, 0),
(200142, 41745, 0, 0, 0),
(200142, 44452, 0, 0, 0),
(200142, 46849, 0, 0, 0),
(200142, 49640, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200141, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Elemental/Other', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1000, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200141);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200141, 34055, 0, 0, 0),
(200141, 35622, 0, 0, 0),
(200141, 35623, 0, 0, 0),
(200141, 35624, 0, 0, 0),
(200141, 35625, 0, 0, 0),
(200141, 35627, 0, 0, 0),
(200141, 36781, 0, 0, 0),
(200141, 36860, 0, 0, 0),
(200141, 37145, 0, 0, 0),
(200141, 37147, 0, 0, 0),
(200141, 37159, 0, 0, 0),
(200141, 37160, 0, 0, 0),
(200141, 37164, 0, 0, 0),
(200141, 37168, 0, 0, 0),
(200141, 37700, 0, 0, 0),
(200141, 37701, 0, 0, 0),
(200141, 37702, 0, 0, 0),
(200141, 37703, 0, 0, 0),
(200141, 37704, 0, 0, 0),
(200141, 37705, 0, 0, 0),
(200141, 39151, 0, 0, 0),
(200141, 39334, 0, 0, 0),
(200141, 39338, 0, 0, 0),
(200141, 39339, 0, 0, 0),
(200141, 39340, 0, 0, 0),
(200141, 39341, 0, 0, 0),
(200141, 39342, 0, 0, 0),
(200141, 39343, 0, 0, 0),
(200141, 39354, 0, 0, 0),
(200141, 39501, 0, 0, 0),
(200141, 39502, 0, 0, 0),
(200141, 39505, 0, 0, 0),
(200141, 40195, 0, 0, 0),
(200141, 40199, 0, 0, 0),
(200141, 40248, 0, 0, 0),
(200141, 40411, 0, 0, 0),
(200141, 42440, 0, 0, 0),
(200141, 43007, 0, 0, 0),
(200141, 43102, 0, 0, 0),
(200141, 43103, 0, 0, 0),
(200141, 43104, 0, 0, 0),
(200141, 43105, 0, 0, 0),
(200141, 43106, 0, 0, 0),
(200141, 43107, 0, 0, 0),
(200141, 43108, 0, 0, 0),
(200141, 43109, 0, 0, 0),
(200141, 44142, 0, 0, 0),
(200141, 44161, 0, 0, 0),
(200141, 44163, 0, 0, 0),
(200141, 44316, 0, 0, 0),
(200141, 44317, 0, 0, 0),
(200141, 44318, 0, 0, 0),
(200141, 44322, 0, 0, 0),
(200141, 44323, 0, 0, 0),
(200141, 44324, 0, 0, 0),
(200141, 44475, 0, 0, 0),
(200141, 44700, 0, 0, 0),
(200141, 44835, 0, 0, 0),
(200141, 44852, 0, 0, 0),
(200141, 44853, 0, 0, 0),
(200141, 44958, 0, 0, 0),
(200141, 45087, 0, 0, 0),
(200141, 45909, 0, 0, 0),
(200141, 47556, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200140, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Meat/Herb', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1000, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200140);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200140, 34736, 0, 0, 0),
(200140, 35794, 0, 0, 0),
(200140, 36782, 0, 0, 0),
(200140, 36901, 0, 0, 0),
(200140, 36902, 0, 0, 0),
(200140, 36903, 0, 0, 0),
(200140, 36904, 0, 0, 0),
(200140, 36905, 0, 0, 0),
(200140, 36906, 0, 0, 0),
(200140, 36907, 0, 0, 0),
(200140, 36908, 0, 0, 0),
(200140, 37921, 0, 0, 0),
(200140, 41800, 0, 0, 0),
(200140, 41801, 0, 0, 0),
(200140, 41802, 0, 0, 0),
(200140, 41803, 0, 0, 0),
(200140, 41805, 0, 0, 0),
(200140, 41806, 0, 0, 0),
(200140, 41807, 0, 0, 0),
(200140, 41808, 0, 0, 0),
(200140, 41809, 0, 0, 0),
(200140, 41810, 0, 0, 0),
(200140, 41812, 0, 0, 0),
(200140, 41813, 0, 0, 0),
(200140, 41814, 0, 0, 0),
(200140, 43009, 0, 0, 0),
(200140, 43010, 0, 0, 0),
(200140, 43011, 0, 0, 0),
(200140, 43012, 0, 0, 0),
(200140, 43013, 0, 0, 0),
(200140, 43501, 0, 0, 0),
(200140, 43571, 0, 0, 0),
(200140, 43572, 0, 0, 0),
(200140, 43646, 0, 0, 0),
(200140, 43647, 0, 0, 0),
(200140, 43652, 0, 0, 0),
(200140, 44834, 0, 0, 0),
(200140, 45907, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200138, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Jewelcrafting Cloth', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1000, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200138);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES
(200138, 2589, 0, 0, 0), 
(200138, 33470, 0, 0, 0),
(200138, 38426, 0, 0, 0),
(200138, 41510, 0, 0, 0),
(200138, 41511, 0, 0, 0),
(200138, 41593, 0, 0, 0),
(200138, 41594, 0, 0, 0),
(200138, 41595, 0, 0, 0),
(200138, 42253, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200137, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Explosives/Devices', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1000, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200137);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200137, 2901, 0, 0, 0),
(200137, 5956, 0, 0, 0),
(200137, 6219, 0, 0, 0),
(200137, 7005, 0, 0, 0),
(200137, 10580, 0, 0, 0),
(200137, 10719, 0, 0, 0),
(200137, 20815, 0, 0, 0),
(200137, 20824, 0, 0, 0),
(200137, 23820, 0, 0, 0),
(200137, 37567, 0, 0, 0),
(200137, 40536, 0, 0, 0),
(200137, 40768, 0, 0, 0),
(200137, 40769, 0, 0, 0),
(200137, 40771, 0, 0, 0),
(200137, 40772, 0, 0, 0),
(200137, 40892, 0, 0, 0),
(200137, 40893, 0, 0, 0),
(200137, 41119, 0, 0, 0),
(200137, 41146, 0, 0, 0),
(200137, 41167, 0, 0, 0),
(200137, 42546, 0, 0, 0),
(200137, 42641, 0, 0, 0),
(200137, 44739, 0, 0, 0),
(200137, 44951, 0, 0, 0),
(200137, 47828, 0, 0, 0),
(200137, 49040, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200136, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Trade Goods Parts', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200136);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200136, 37101, 0, 0, 0),
(200136, 39354, 0, 0, 0),
(200136, 39469, 0, 0, 0),
(200136, 39505, 0, 0, 0),
(200136, 39681, 0, 0, 0),
(200136, 39682, 0, 0, 0),
(200136, 39683, 0, 0, 0),
(200136, 39684, 0, 0, 0),
(200136, 39685, 0, 0, 0),
(200136, 39686, 0, 0, 0),
(200136, 39690, 0, 0, 0),
(200136, 39774, 0, 0, 0),
(200136, 40533, 0, 0, 0),
(200136, 43115, 0, 0, 0),
(200136, 43116, 0, 0, 0),
(200136, 43117, 0, 0, 0),
(200136, 43118, 0, 0, 0),
(200136, 43119, 0, 0, 0),
(200136, 43120, 0, 0, 0),
(200136, 43121, 0, 0, 0),
(200136, 43122, 0, 0, 0),
(200136, 43123, 0, 0, 0),
(200136, 43124, 0, 0, 0),
(200136, 43125, 0, 0, 0),
(200136, 43126, 0, 0, 0),
(200136, 43127, 0, 0, 0),
(200136, 44499, 0, 0, 0),
(200136, 44500, 0, 0, 0),
(200136, 44501, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200143, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Armor Enchantment/Weapon Enchantment', 'Trade Goods', '', 0, 80, 80, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200143);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200143, 37602, 0, 0, 0),
(200143, 38682, 0, 0, 0),
(200143, 39349, 0, 0, 0),
(200143, 39350, 0, 0, 0),
(200143, 43145, 0, 0, 0),
(200143, 43146, 0, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200139, 0, 0, 0, 0, 0, 23156, 0, 0, 0, 'Leather Metal Stone', 'Trade Goods', '', 0, 83, 83, 0, 35, 35, 4224, 1, 2, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4430, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200139);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES
(200139, 2318, 0, 0, 0),
(200139, 2770, 0, 0, 0),
(200139, 2835, 0, 0, 0),
(200139, 2840, 0, 0, 0),
(200139, 33567, 0, 0, 0),
(200139, 33568, 0, 0, 0),
(200139, 36909, 0, 0, 0),
(200139, 36910, 0, 0, 0),
(200139, 36912, 0, 0, 0),
(200139, 36913, 0, 0, 0),
(200139, 36916, 0, 0, 0),
(200139, 37663, 0, 0, 0),
(200139, 38425, 0, 0, 0),
(200139, 38557, 0, 0, 0),
(200139, 38558, 0, 0, 0),
(200139, 38561, 0, 0, 0),
(200139, 41163, 0, 0, 0),
(200139, 44128, 0, 0, 0);

DELETE FROM `creature` WHERE `id`=200143;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201438, 200143, 1, 1, 1, 0, 0, 1393.49, -4360.57, 25.5748, 4.86053, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200136;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201190, 200136, 0, 1, 1, 0, 0, -8930.34, 551.631, 94.3792, 3.75092, 300, 0, 0, 5342, 0, 0),
(201431, 200136, 1, 1, 1, 0, 0, 1395.26, -4360.38, 25.4627, 4.79289, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200137;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201191, 200137, 0, 1, 1, 0, 0, -8931.47, 553.234, 94.4857, 3.90014, 300, 0, 0, 5342, 0, 0),
(201432, 200137, 1, 1, 1, 0, 0, 1397.05, -4360.07, 25.4627, 4.80075, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200138;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201193, 200138, 0, 1, 1, 0, 0, -8932.74, 554.869, 94.5957, 3.87658, 300, 0, 0, 5342, 0, 0),
(201433, 200138, 1, 1, 1, 0, 0, 1398.97, -4359.87, 25.4627, 4.91463, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200139;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(204321, 200139, 0, 1, 1, 0, 0, -8937.38, 560.682, 94.3646, 3.80288, 300, 0, 0, 5342, 0, 0),
(201434, 200139, 1, 1, 1, 0, 0, 1401.09, -4359.66, 25.4627, 4.93034, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200140;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201435, 200140, 1, 1, 1, 0, 0, 1403.05, -4359.34, 25.4627, 4.9539, 300, 0, 0, 5342, 0, 0),
(204326, 200140, 0, 1, 1, 0, 0, -8933.87, 556.448, 94.6886, 3.79922, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200141;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201436, 200141, 1, 1, 1, 0, 0, 1405, -4359.1, 25.4627, 4.7929, 300, 0, 0, 5342, 0, 0),
(204322, 200141, 0, 1, 1, 0, 0, -8935.08, 557.857, 94.5727, 3.84608, 300, 0, 0, 5342, 0, 0);

DELETE FROM `creature` WHERE `id`=200142;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201437, 200142, 1, 1, 1, 0, 0, 1406.64, -4358.98, 25.4627, 4.89194, 300, 0, 0, 5342, 0, 0),
(204323, 200142, 0, 1, 1, 0, 0, -8936.2, 559.172, 94.464, 3.77068, 300, 0, 0, 5342, 0, 0);

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200091, 0, 0, 0, 0, 0, 18593, 0, 18593, 0, 'Reagent Level 70', 'Burning Crusade Reagents', '', 0, 83, 83, 2, 35, 35, 4225, 1, 2, 340, 510, 0, 127, 1, 2000, 2000, 1, 2, 0, 0, 2, 0, 0, 0, 272, 408, 102, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 1000, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4321, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200091);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200091, 2840, 0, 0, 0),
(200091, 2841, 0, 0, 0),
(200091, 3576, 0, 0, 0),
(200091, 3577, 0, 0, 0),
(200091, 3859, 0, 0, 0),
(200091, 3860, 0, 0, 0),
(200091, 6037, 0, 0, 0),
(200091, 11371, 0, 0, 0),
(200091, 12359, 0, 0, 0),
(200091, 12360, 0, 0, 0),
(200091, 12655, 0, 0, 0),
(200091, 14256, 0, 0, 0),
(200091, 17203, 0, 0, 0),
(200091, 17771, 0, 0, 0),
(200091, 20725, 0, 0, 0),
(200091, 21840, 0, 0, 0),
(200091, 21842, 0, 0, 0),
(200091, 21845, 0, 0, 0),
(200091, 21881, 0, 0, 0),
(200091, 21884, 0, 0, 0),
(200091, 21885, 0, 0, 0),
(200091, 21886, 0, 0, 0),
(200091, 22445, 0, 0, 0),
(200091, 22446, 0, 0, 0),
(200091, 22450, 0, 0, 0),
(200091, 22451, 0, 0, 0),
(200091, 22452, 0, 0, 0),
(200091, 22456, 0, 0, 0),
(200091, 22457, 0, 0, 0),
(200091, 23445, 0, 0, 0),
(200091, 23446, 0, 0, 0),
(200091, 23447, 0, 0, 0),
(200091, 23448, 0, 0, 0),
(200091, 23449, 0, 0, 0),
(200091, 23571, 0, 0, 0),
(200091, 23572, 0, 0, 0),
(200091, 23573, 0, 0, 0),
(200091, 23793, 0, 0, 0),
(200091, 24271, 0, 0, 0),
(200091, 24272, 0, 0, 0),
(200091, 25707, 0, 0, 0),
(200091, 25708, 0, 0, 0),
(200091, 29547, 0, 0, 0),
(200091, 30183, 0, 0, 0),
(200091, 31079, 0, 0, 0),
(200091, 34664, 0, 0, 0),
(200091, 35128, 0, 0, 0),
(200091, 36914, 0, 0, 0),
(200091, 40248, 0, 0, 0),
(200091, 41510, 0, 0, 0),
(200091, 41511, 0, 0, 0),
(200091, 17968, 0, 0, 0),
(200091, 12811, 0, 0, 0);

DELETE FROM `creature` WHERE `id`=200091;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(9338213, 200091, 0, 1, 1, 0, 4321, -8938.79, 562.206, 93.8212, 3.78282, 300, 0, 0, 1394500, 0, 0),
(9338209, 200091, 1, 1, 1, 18595, 4321, 1423.89, -4375.8, 25.4627, 0.157448, 300, 0, 0, 1394500, 0, 0);


