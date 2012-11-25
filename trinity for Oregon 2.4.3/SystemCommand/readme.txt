This is pretty neat.  I use it to check the machine status from in-game, 
fire off backup jobs, etc.  This patch will let you add external shell 
commands to a table, with a descriptive command name, and execute the
associated command/program in the shell environment as the user that is
running the core.

By tabling the commands, we avoid anyone executing arbitrary programs from
within the game.

This could be a very powerful command, but it might also be extremely 
dangerous.  You should thoroughly test the commands before you exec them
in-game.  You have been cautioned.

Good Luck!

-- Celtus

