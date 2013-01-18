
UPDATE `item_template` ,`Price_normal` SET  `item_template` . `BuyPrice`= `Price_normal` . `BuyPrice` , `item_template` . `SellPrice`= `Price_normal` . `SellPrice` WHERE `item_template`.`entry` = `Price_normal`.`entry`;
