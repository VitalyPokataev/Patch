/*
Navicat MySQL Data Transfer
Source Host     : localhost:3306
Source Database : world1
Target Host     : localhost:3306
Target Database : world1
Date: 2012-08-12 22:02:12
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for playercreateinfo
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo`;
CREATE TABLE `playercreateinfo` (
  `race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `class` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `map` smallint(5) unsigned NOT NULL DEFAULT '0',
  `zone` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`race`,`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of playercreateinfo
-- ----------------------------
INSERT INTO `playercreateinfo` VALUES ('1', '1', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '2', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '4', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '5', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '8', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '9', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '1', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '3', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '4', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '7', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '9', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '1', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '2', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '3', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '4', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '5', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '1', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '3', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '4', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '5', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '11', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '1', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '4', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '5', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '8', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '9', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '1', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '3', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '7', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '11', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '1', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '9', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '8', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '4', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '1', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '3', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '4', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '5', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '7', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '8', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '2', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '3', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '4', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '5', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '8', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '9', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '1', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '2', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '3', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '5', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '7', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '8', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '6', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '6',  '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '6', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '6', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '6', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '6', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '6', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '6', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '6', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '6', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '3', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '7', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('1', '11', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '7', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '8', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '9', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('3', '11', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '7', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '2', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '9', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('4', '8', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '2', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '3', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '5', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '7', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('7', '11', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '4', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '9', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('11', '11', '0', '1519', '-8952.6', '566.102', '93.7933', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '2', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '5', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '8', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('2', '11', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '2', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '3', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '7', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('5', '11', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '2', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '4', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '5', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '8', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('6', '9', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '2', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '9', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('8', '11', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '1', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '7', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
INSERT INTO `playercreateinfo` VALUES ('10', '11', '1', '1637', '1434.25', '-4398.33', '25.4628', '0');
