The idea in this patch is to make a custom chat channel that can only be
owned/moderated by a selected account, but that other players can use even
if that account is not logged in (without becoming the owner).

It sets up two accounts as the possible owners.  The main one, OwnerGUID, will
be the owner/moderator anytime it is logged in.  When the main account logs
out the second account, IdleGUID, will become owner/moderator (even if not
logged in).  This prevents the second participant in the channel from 
getting privs when the owner logs out.

In my system, I have a special owner GM at GUID 1, which I've set to be the 
WorldChat owner.  I use another special GUID (2) as my AHBot, and have the
WorldChat configured to give ownershp to that GUID when GUID 1 is off-line.
I don't play the character at GUID 2, but I suspect that if I did, it would
not be able to participate in WorldChat (since the system will think that it
is already in-channel, it will not be able to join the channel).

Anyway - it's a work in progress.

-- Celtus

2010-10-23 : Refresh for r873
