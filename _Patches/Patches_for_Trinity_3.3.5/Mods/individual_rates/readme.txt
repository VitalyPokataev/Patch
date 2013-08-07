Regarding credits to this patch to 'silviu2008' ac-web profile: http://www.ac-web.org/forums/member.php?256608-silviu2008

How to install:
---------------
1. Import character_loot_rate.sql and character_xp_rate.sql in your TC characters database
2. Import commands.sql in your TC world database (not necessarily needed, used to add help to commands)
3. Apply individual_rates.patch to your TrinityCore clone, via git apply rates.patch (the file must be inside root TrinityCore folder), or GitExtensions. There are a lot of tutorials on how to apply patches via GIT.
4. Copy custom_rates.cpp to ../TrinityCoreClone/src/server/scripts/custom
5. Use cmake to configure & generate TC project files again, then re-compile
6. Make sure to copy worldserver.conf.dist in your server's binaries folder, on the bottom it contains different configs for this patch

Tested on:
----------
Using configuration file worldserver.conf.
Using SSL version: OpenSSL 1.0.1c 10 May 2012 (library: OpenSSL 1.0.1c 10 May 2012)
Using ACE version: 6.1.4
TrinityCore rev. 54749e6918df+ 2013-04-30 11:10:39 +0200 (master branch) (Win32, Release) (worldserver-daemon)
Using World DB: TDB 335.51