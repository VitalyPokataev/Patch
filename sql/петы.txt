REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200135, 0, 0, 0, 0, 0, 29516, 0, 29516, 0, 'Pets', 'Vanity pets', '', 0, 80, 80, 0, 35, 35, 4224, 1, 1, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1949, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200135);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200135, 44984, 0, 0, 0),
(200135, 45022, 0, 0, 0),
(200135, 47541, 0, 0, 0),
(200135, 44998, 0, 0, 0),
(200135, 44819, 0, 0, 0),
(200135, 32588, 0, 0, 0),
(200135, 46767, 0, 0, 0),
(200135, 20371, 0, 0, 0),
(200135, 23083, 0, 0, 0),
(200135, 35350, 0, 0, 0),
(200135, 34425, 0, 0, 0),
(200135, 49646, 0, 0, 0),
(200135, 46545, 0, 0, 0),
(200135, 46544, 0, 0, 0),
(200135, 13584, 0, 0, 0),
(200135, 34493, 0, 0, 0),
(200135, 44970, 0, 0, 0),
(200135, 44973, 0, 0, 0),
(200135, 32616, 0, 0, 0),
(200135, 32622, 0, 0, 0),
(200135, 44974, 0, 0, 0),
(200135, 44982, 0, 0, 0),
(200135, 39286, 0, 0, 0),
(200135, 39973, 0, 0, 0),
(200135, 43698, 0, 0, 0),
(200135, 37297, 0, 0, 0),
(200135, 21301, 0, 0, 0),
(200135, 46802, 0, 0, 0),
(200135, 23713, 0, 0, 0),
(200135, 21308, 0, 0, 0),
(200135, 44738, 0, 0, 0),
(200135, 49693, 0, 0, 0),
(200135, 44841, 0, 0, 0),
(200135, 30360, 0, 0, 0),
(200135, 45002, 0, 0, 0),
(200135, 33818, 0, 0, 0),
(200135, 44980, 0, 0, 0),
(200135, 45180, 0, 0, 0),
(200135, 25535, 0, 0, 0),
(200135, 44723, 0, 0, 0),
(200135, 49362, 0, 0, 0),
(200135, 13583, 0, 0, 0),
(200135, 49665, 0, 0, 0),
(200135, 49912, 0, 0, 0),
(200135, 23007, 0, 0, 0),
(200135, 22114, 0, 0, 0),
(200135, 46707, 0, 0, 0),
(200135, 23015, 0, 0, 0),
(200135, 21305, 0, 0, 0),
(200135, 40653, 0, 0, 0),
(200135, 34492, 0, 0, 0),
(200135, 34955, 0, 0, 0),
(200135, 45606, 0, 0, 0),
(200135, 46820, 0, 0, 0),
(200135, 46821, 0, 0, 0),
(200135, 33154, 0, 0, 0),
(200135, 32617, 0, 0, 0),
(200135, 35349, 0, 0, 0),
(200135, 21309, 0, 0, 0),
(200135, 38050, 0, 0, 0),
(200135, 49343, 0, 0, 0),
(200135, 44794, 0, 0, 0),
(200135, 44983, 0, 0, 0),
(200135, 44965, 0, 0, 0),
(200135, 44971, 0, 0, 0),
(200135, 50446, 0, 0, 0),
(200135, 22235, 0, 0, 0),
(200135, 44810, 0, 0, 0),
(200135, 23002, 0, 0, 0),
(200135, 39656, 0, 0, 0),
(200135, 41133, 0, 0, 0),
(200135, 38658, 0, 0, 0),
(200135, 32233, 0, 0, 0),
(200135, 12264, 0, 0, 0),
(200135, 56806, 0, 0, 0),
(200135, 13582, 0, 0, 0);


DELETE FROM `creature` WHERE `id`=200135;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(9338226, 200135, 0, 1, 1, 0, 1949, -8940.63, 564.309, 93.7997, 3.71793, 300, 0, 0, 53420, 0, 0),
(201410, 200135, 1, 1, 1, 0, 1949, 1424.27, -4378.62, 25.4627, 0.114134, 300, 0, 0, 5342, 0, 0);

/*
UPDATE `npc_vendor` SET `ExtendedCost` = '634' WHERE `entry` = 200135;
2805 хонора
UPDATE `npc_vendor` SET `ExtendedCost` = '2557' WHERE `entry` = 200135;
2500 хонора
UPDATE `npc_vendor` SET `ExtendedCost` = '460' WHERE `entry` = 200135;
1 хонор
*/
