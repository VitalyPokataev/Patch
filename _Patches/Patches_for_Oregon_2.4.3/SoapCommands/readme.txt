This patch adds six server commands to the core.  They are probably most
useful when called by SOAP from a website.  The commands are:

server version     - Shows the core version string (1st line of server info).
server rev         - Shows only the core rev.
server dbversion   - Shows the database version string.
server players     - Shows the online/queued player string (as server info).
server playercount - Shows the player data as 4 comma-separated values.
server uptime      - Shows the human-readable uptime.

These may be useful to avoid having to slice and dice server info to get the
data into PHP variables for display (or something similar).

Not earth shattering, but practical - I think.

-- Celtus
