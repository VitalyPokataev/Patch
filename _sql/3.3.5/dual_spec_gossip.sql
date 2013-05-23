SET @GOSSIP_TEXT = 'Purchase a Dual Talent Specialization.';
SET @PRICE = 100000;

UPDATE `gossip_menu_option` SET `option_text` = @GOSSIP_TEXT, `box_money` = @PRICE, `option_icon` = 2
WHERE (`menu_id` = 0 AND `id` = 16)
OR (`menu_id` = 6647 AND `id` = 2)
OR (`menu_id` = 10371 AND `id` = 0);

DELETE FROM `locales_gossip_menu_option`
WHERE (`menu_id` = 0 AND `id` = 16)
OR (`menu_id` = 6647 AND `id` = 2)
OR (`menu_id` = 10371 AND `id` = 0);

INSERT INTO `locales_gossip_menu_option` (`menu_id`, `id`, `option_text_loc8`, `box_text_loc8`)
SELECT `menu_id`, `id`, 'Купить двойную специализацию талантов.', 'Вы уверены что хотите купить двойную специализацию талантов?'
FROM `gossip_menu_option` WHERE `option_text` = @GOSSIP_TEXT;