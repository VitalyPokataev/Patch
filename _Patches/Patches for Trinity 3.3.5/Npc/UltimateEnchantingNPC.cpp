#include "ScriptPCH.h"
 
class npc_enchantment : public CreatureScript
{
    public:
        npc_enchantment() : CreatureScript("npc_enchantment") { }
 
    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(0, "[Enchant Weapon]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Off-Hand]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Cloak]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Chest]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Bracers]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Gloves]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
        player->ADD_GOSSIP_ITEM(0, "[Enchant Feet]", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
 
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }
 
    void Enchant(Player* player, uint8 equipSlot, uint32 enchantID)
    {
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipSlot);
        if (!item)
        {
            player->CLOSE_GOSSIP_MENU();
            return;
        }
 
            // Must re-check that the currently equipped item is valid
        uint32 i;
        for (i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(i);
            if (!spellInfo)
                continue;
            if (spellInfo->Effects[0].Effect != SPELL_EFFECT_ENCHANT_ITEM)
                continue;
            if (spellInfo->Effects[0].MiscValue != enchantID)
                continue;
 
            uint32 spellID = 0;
            SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellInfo->Id);
            for (SkillLineAbilityMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
                        {
                // Not from the enchanting skill
                if (itr->second->skillId != 333 || itr->second->spellId != spellInfo->Id)
                    continue;
                spellID = itr->second->id;
                break;
            }
            if (spellID == 0)
                continue;
 
            int32 invType = (int32)pow((float)2, (float)item->GetTemplate()->InventoryType);
            int32 subClass = (int32)pow((float)2, (float)item->GetTemplate()->SubClass);
            if (item->GetTemplate()->ItemLevel < spellInfo->BaseLevel)
                continue;
            else if (spellInfo->EquippedItemClass != item->GetTemplate()->Class)
                continue;
            else if (!(spellInfo->EquippedItemSubClassMask & subClass))
                continue;
            else if (item->GetTemplate()->Class == ITEM_CLASS_ARMOR && item->GetTemplate()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
            {
                if (!(spellInfo->EquippedItemInventoryTypeMask & invType))
                    continue;
                else // Passed all checks
                    break;
            }
            else
                break;
           
        }
        if (i == sSpellMgr->GetSpellInfoStoreSize())
        {
            ChatHandler(player->GetSession()).PSendSysMessage("Failed to enchant item.");
            return;
        }
 
            player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
        item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantID, 0, 0);
            player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true);
 
        std::string color = "|cff";
            switch (item->GetTemplate()->Quality)
            {
            case 0: color += "9d9d9d"; break;
                    case 1: color += "ffffff"; break;
                    case 2: color += "1eff00"; break;
                    case 3: color += "0070dd"; break;
                    case 4: color += "a335ee"; break;
                    case 5: color += "ff8000"; break;
            }
        ChatHandler(player->GetSession()).PSendSysMessage("|cffFFFFFF[%s%s|cffFFFFFF] |cffFF0000succesfully enchanted!", color.c_str(), item->GetTemplate()->Name1.c_str());
    }
 
    void ShowPage(Player* player, uint32 page, uint8 equipSlot)
    {
        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipSlot);
        if (!item)
        {
            player->CLOSE_GOSSIP_MENU();
            return;
        }
 
        ItemTemplate const* itemTemplate = item->GetTemplate();
        if (!itemTemplate)
        {
            player->CLOSE_GOSSIP_MENU();
            return;
        }
 
        player->PlayerTalkClass->ClearMenus();
        uint32 startPos = (page - 1) * 10;
        uint32 currentPos = 0;
 
        uint32 i;
        for (i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(i);
            if (!spellInfo)
                continue;
            if (spellInfo->Effects[0].Effect != SPELL_EFFECT_ENCHANT_ITEM)
                continue;
            if (spellInfo->Id == 62257) // Ignore Titanguard
                continue;
            if (itemTemplate->ItemLevel < spellInfo->BaseLevel)
                continue;
            if (spellInfo->EquippedItemClass != itemTemplate->Class)
                continue;
            int32 subClass = (int32)pow((float)2, (float)itemTemplate->SubClass);
            if (!(spellInfo->EquippedItemSubClassMask & subClass))
                continue;
            int32 invType = (int32)pow((float)2, (float)itemTemplate->InventoryType);
            if (itemTemplate->Class == ITEM_CLASS_ARMOR && itemTemplate->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
                if (!(spellInfo->EquippedItemInventoryTypeMask & invType))
                    continue;
 
            uint32 spellID = 0;
            SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellInfo->Id);
            for (SkillLineAbilityMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
                        {
                // Not from the enchanting skill
                if (itr->second->skillId != 333 || itr->second->spellId != spellInfo->Id)
                    continue;
                spellID = itr->second->id;
                break;
            }
            if (spellID == 0)
                continue;
            if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(spellInfo->Effects[0].MiscValue))
            {
                if (enchant->requiredLevel > player->getLevel())
                    continue;
                if (currentPos >= startPos)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, enchant->description[0], equipSlot, enchant->ID);
 
                currentPos++;
                // Stop looping once we are 10 positions ahead
                if (currentPos == startPos + 10)
                    break;
            }
        }
 
        // Make sure there is actually another page
        if (currentPos == startPos + 10 && i != sSpellMgr->GetSpellInfoStoreSize())
            player->ADD_GOSSIP_ITEM(0, "Next Page", 100 + page + 1, equipSlot);  // Have to offset by 100 to ensure it gets pushed to the default case
        player->ADD_GOSSIP_ITEM(0, "Back", 100 + page - 1, equipSlot);
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(sender)
        {
            case GOSSIP_SENDER_MAIN:
                ShowPage(player, 1, action);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;
            default:
                if (sender < 100)
                {
                    Enchant(player, sender, action);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                }
                if (sender == 100)
                    OnGossipHello(player, creature);
                else
                {
                    ShowPage(player, sender - 100, action);
                    player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                }
                break;
        }
        return true;
    }
};
 
void AddSC_npc_enchantment()
{
        new npc_enchantment();
}