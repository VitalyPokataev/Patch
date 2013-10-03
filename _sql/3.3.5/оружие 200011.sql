REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (200011, 0, 0, 0, 0, 0, 29774, 0, 29774, 0, 'Weapon', 'weapon', '', 0, 80, 80, 0, 35, 35, 4224, 1, 1, 50, 150, 0, 1000, 1, 2000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2029, 0, 0, '');

DELETE FROM `npc_vendor` WHERE (`entry`=200011);
INSERT INTO `npc_vendor` (entry, item, maxcount, incrtime, ExtendedCost) VALUES 
(200011, 50048, 0, 0, 0),
(200011, 50052, 0, 0, 0),
(200011, 50047, 0, 0, 0),
(200011, 50046, 0, 0, 0),
(200011, 50049, 0, 0, 0),
(200011, 50051, 0, 0, 0),
(200011, 50050, 0, 0, 0),
(200011, 50319, 0, 0, 0),
(200011, 49852, 0, 0, 0),
(200011, 49801, 0, 0, 0),
(200011, 49802, 0, 0, 0),
(200011, 50227, 0, 0, 0),
(200011, 50771, 0, 0, 0),
(200011, 50760, 0, 0, 0),
(200011, 44313, 0, 0, 0),
(200011, 50759, 0, 0, 0),
(200011, 49493, 0, 0, 0),
(200011, 42508, 0, 0, 0);


DELETE FROM `creature` WHERE `id`=200011;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(201103, 200011, 0, 1, 1, 0, 0, -8923.59, 553.601, 94.2601, 5.41457, 300, 0, 0, 5342, 0, 0),
(201374, 200011, 1, 1, 1, 0, 0, 1439.14, -4431.26, 25.4627, 1.6919, 300, 0, 0, 5342, 0, 0);
