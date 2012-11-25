This is mostly a port of the TeleNPC2 scripts, currently maintained in the
spgm repo.  There have been some minor edits, and the database content has
been expanded from the original.

2010-10-10: I've added a display_order field to the associations to give some
control of how the list sorts.  I've also added fields to the destination 
table for say_on_departure, and cast_on_arrival.  These will do a MonsterSay
of the phrase in the DB when you leave, and cast the spell indicated in 
cast_on_arrival when you get to the destination - from an idea by Zuen.  Thx!

-- Celtus

