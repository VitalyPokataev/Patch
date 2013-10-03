REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200123, 0, 0, 0, 0, 0, 22209, 0, 22209, 0, 'Bag', 'Container', '', 0, 80, 80, 0, 35, 35, 4224, 1, 1, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 547, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200123);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200123, 38082, 0, 0, 0),
(200123, 51809, 0, 0, 0);

/*
UPDATE `npc_vendor` SET `ExtendedCost` = '2426' WHERE `entry` = 200123;
*/
DELETE FROM `creature` WHERE `id`=200123;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201236, 200123, 0, 1, 1, 0, 0, -8954.96, 555.501, 93.8492, 1.46932, 300, 0, 0, 5342, 0, 0),
(201399, 200123, 1, 1, 1, 0, 0, 1425.89, -4391.58, 25.4627, 0.110411, 300, 0, 0, 5342, 0, 0);
