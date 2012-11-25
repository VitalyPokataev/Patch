/* UPDATE creature_template SET ScriptName = 'npc_zafod_boombox' WHERE entry = 37184; */
class npc_zafod_boombox : public CreatureScript
{
    public:
        npc_zafod_boombox() : CreatureScript("npc_zafod_boombox") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            // Maybe this isn't blizzlike but I can't find any spell in the DBCs
            if (pPlayer->GetItemCount(49278, false) == 0)
                pPlayer->ADD_GOSSIP_ITEM(0, "Yeah, I'm sure safety is your top priority. Give me a rocket pack.", 631, 1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();
            if (action == 1)
            {
                // Seurity, this shouldn't happen. Maybe useless.
                uint32 curItemCount = player->GetItemCount(49278, false);
                if (curItemCount >= 1)
                {
                    pCreature->MonsterWhisper("You already have my rocket pack!", player->GetGUIDLow());
                    return false;
                }

                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 49278, 1);
                if (msg == EQUIP_ERR_OK)
                {
                    Item* item = player->StoreNewItem(dest, 49278, true);
                    player->SendNewItem(item, 1, true, false);
                }
                else
                {
                    pCreature->MonsterWhisper("You don't have any empty space for my rocket pack!", player->GetGUIDLow());
                    return false;
                }
            }

            return true;
        }
};

void AddSC_npc_zafod_boombox()
{
    new npc_zafod_boombox();
}