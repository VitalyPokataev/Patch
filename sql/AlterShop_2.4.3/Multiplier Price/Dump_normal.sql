
DROP TABLE `price_normal`;
CREATE TABLE `Price_normal` (
  `entry` int(11) unsigned NOT NULL,
  `BuyPrice` int(11) unsigned NOT NULL,
  `SellPrice` int(11) unsigned NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


TRUNCATE TABLE `price_normal`;
INSERT INTO `Price_normal` (`entry`, `BuyPrice`, `SellPrice`) SELECT `entry`, `BuyPrice`, `SellPrice` FROM `item_template`;

