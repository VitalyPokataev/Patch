/*
MySQL Data Transfer
Source Host: localhost
Source Database: mangos
Target Host: localhost
Target Database: mangos
Date: 18.01.2009 21:44:20
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for playercreateinfo_item
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo_item`;
CREATE TABLE `playercreateinfo_item` (
  `race` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `class` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `itemid` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `amount` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`race`,`class`,`itemid`),
  KEY `playercreateinfo_race_class_index` (`race`,`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `playercreateinfo_item` VALUES ('2', '7', '5177', '1');
INSERT INTO `playercreateinfo_item` VALUES ('2', '7', '5175', '1');
INSERT INTO `playercreateinfo_item` VALUES ('2', '7', '5176', '1');
INSERT INTO `playercreateinfo_item` VALUES ('2', '7', '5178', '1');

INSERT INTO `playercreateinfo_item` VALUES ('6', '7', '5177', '1');
INSERT INTO `playercreateinfo_item` VALUES ('6', '7', '5175', '1');
INSERT INTO `playercreateinfo_item` VALUES ('6', '7', '5176', '1');
INSERT INTO `playercreateinfo_item` VALUES ('6', '7', '5178', '1');

INSERT INTO `playercreateinfo_item` VALUES ('8', '7', '5177', '1');
INSERT INTO `playercreateinfo_item` VALUES ('8', '7', '5175', '1');
INSERT INTO `playercreateinfo_item` VALUES ('8', '7', '5176', '1');
INSERT INTO `playercreateinfo_item` VALUES ('8', '7', '5178', '1');

INSERT INTO `playercreateinfo_item` VALUES ('11', '7', '5177', '1');
INSERT INTO `playercreateinfo_item` VALUES ('11', '7', '5175', '1');
INSERT INTO `playercreateinfo_item` VALUES ('11', '7', '5176', '1');
INSERT INTO `playercreateinfo_item` VALUES ('11', '7', '5178', '1');