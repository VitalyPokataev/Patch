DELETE FROM oregon_string WHERE entry BETWEEN 11600 AND 11608;

INSERT INTO `oregon_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11600, 'ChatSpy appended to player |cffff0000%s|r(%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11601, 'ChatSpy for player |cffff0000%s|r(%u) cancelled by massive ChatSpy cancel.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11602, 'All ChatSpys reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11603, 'Player %s(%u) has no ChatSpy.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11604, 'You were ChatSpying player, cancelled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11605, '%s(%u) was ChatSpying player, cancelled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11606, 'List of ChatSpys appended', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11607, 'Total: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11608, '%s(%u) spys |cffff0000%s|r(%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name` LIKE 'chatspy%';

INSERT INTO `command` (`name`, `security`, `help`) VALUES
('chatspy', 3, 'Syntax: .chatpsy $PlayerName\r\n\r\nChatspy a player.  All chat will be echoed to the GM''s chatlog.  Can also be activated by .chatspy with the player selected.'),
('chatspy cancel', 3, 'Syntax: .chatspy cancel $PlayerName\r\n\r\nRemoves the player from the GM''s ChatSpy.'),
('chatspy reset', 3, 'Syntax: .chatspy reset\r\n\r\nClears the GM''s ChatSpy for all players.'),
('chatspy status', 3, 'Syntax: .chatspy status\r\n\r\nShows a list of characters that are ChatSpied.');

