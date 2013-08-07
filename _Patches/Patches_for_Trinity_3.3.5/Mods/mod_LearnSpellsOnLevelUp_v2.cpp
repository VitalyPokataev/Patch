#include "ScriptPCH.h"
#include "ScriptMgr.h"
 
class player_learnspell : public PlayerScript
{
public:
        player_learnspell() : PlayerScript ("player_learnspell") {}
 
        void OnLevelChanged(Player* player, uint8 oldLevel)
        {
		uint8 newLevel = player->getLevel();
       		if (newLevel < oldLevel) return;
        	uint32 entry;
        	switch (player->getClass()) 
		{
        		case CLASS_ROGUE: entry = 917; break;
        		case CLASS_PRIEST: entry = 377; break;
        		case CLASS_MAGE: entry = 328; break;
        		case CLASS_PALADIN: entry = 927; break;
        		case CLASS_WARRIOR: entry = 913; break;
        		case CLASS_SHAMAN: entry = 20407; break;
        		case CLASS_DRUID: entry = 5505; break;
        		case CLASS_HUNTER: entry = 5515; break;
        		case CLASS_WARLOCK: entry = 5496; break;
        		case CLASS_DEATH_KNIGHT: entry = 29196; break;
        	}
 
 		bool EnableAutoLearnSpellv2 = ConfigMgr::GetBoolDefault("Enable.Learn.Spell.On.Level.Up_v2", true);
		if (EnableAutoLearnSpellv2)
		{
     			TrainerSpellData const* t_spells = (sObjectMgr->GetNpcTrainerSpells(entry));
         		for (TrainerSpellMap::const_iterator itr = t_spells->spellList.begin(); itr != t_spells->spellList.end(); ++itr) {
                 	uint32 f_spell = itr->first;
                 	TrainerSpell const* spell = t_spells->Find(f_spell);
                 	if (!spell) continue;
                 	if ((spell->reqLevel > newLevel) || (player->HasSpell(f_spell))) continue;
                 	const SpellInfo* prevSpellInfo = sSpellMgr->GetSpellInfo(f_spell)->GetPrevRankSpell();
                 	if ((prevSpellInfo && player->HasSpell(prevSpellInfo->Id)) || !prevSpellInfo) player->learnSpell(f_spell, false);
		}
        }
};  
 
void AddSC_player_learnspell()
{
new player_learnspell();
}