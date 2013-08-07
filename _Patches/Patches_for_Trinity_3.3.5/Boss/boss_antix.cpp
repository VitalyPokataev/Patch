/*
           Boss Antrix
		   By Killam aka Monkeylover
		   05-31-2012
*/


#include "ScriptPCH.h"

enum Spells
{
	SPELL_SHADOW_LANCE       = 72806,
	SPELL_SHADOWSTEP         = 72326,
	SPELL_SHADOW_NOVA        = 71106,
	SPELL_SHADOW_BLAST       = 70866,
	SPELL_GRAVITY_BOMB       = 63024,
	SPELL_DEATH_COIL         = 67931,
	SPELL_FEAR               = 29321,
};

class boss_antix : public CreatureScript
{
    public:

        boss_antix()
			: CreatureScript("boss_antrix"){}

		struct boss_antrixAI : public ScriptedAI
		{
					boss_antrixAI(Creature * c) : ScriptedAI(c){}
					uint32 ShadowLanceTimer;
					uint32 ShadowStepTimer;
					uint32 ShadowNovaTimer;
					uint32 ShadowBlastTimer;
					uint32 GravityBombTimer;
					uint32 DeathCoilTimer;
					uint32 FearTimer;

					void Reset()
					{
						ShadowLanceTimer = 4500;
						ShadowStepTimer = 3000;
						ShadowNovaTimer = 6000;
						ShadowBlastTimer = 5500;
						GravityBombTimer = 3500;
						DeathCoilTimer = 11000;
						FearTimer = 7000;
					}

			void KilledUnit(Unit * /* killed */)
			{
				me->MonsterYell("As I leach your soul, I'll leach them all!", LANG_UNIVERSAL, me->GetGUID());
			}

			void JustDied(Unit * /* killer */)
			{
				me->MonsterYell("You've beaten me! You won't pass us all!", LANG_UNIVERSAL, me->GetGUID());
			}

			void EnterCombat(Unit* /* who */)
			{
				me->MonsterYell("You've entered the Realm of Shadow's! You won't return!", LANG_UNIVERSAL, me->GetGUID());
			}

			void UpdateAI(const uint32 diff)
			{
				 if (!UpdateVictim())
					  return;

				 if (ShadowLanceTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_SHADOW_LANCE);
					 ShadowLanceTimer = 4500;
				 }
				 else
					 ShadowLanceTimer -= diff;

				 if (ShadowStepTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_SHADOWSTEP);
					 ShadowStepTimer = 3000;
				 }
				 else
					 ShadowStepTimer -= diff;

				 if (ShadowNovaTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_SHADOW_NOVA);
					 ShadowNovaTimer = 6000;
				 }
				 else
					 ShadowNovaTimer -= diff;

				 if (ShadowBlastTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_SHADOW_BLAST);
					 ShadowBlastTimer = 5500;
				 }
				 else
					 ShadowBlastTimer -= diff;

				 if (GravityBombTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_GRAVITY_BOMB);
					 GravityBombTimer = 3500;
				 }
				 else
					 GravityBombTimer -= diff;

				 if (DeathCoilTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_DEATH_COIL);
					 DeathCoilTimer = 11000;
				 }
				 else
					 DeathCoilTimer -= diff;

				 if (FearTimer < diff)
				 {
					 DoCast(me->getVictim(), SPELL_FEAR);
					 FearTimer = 7000;
				 }
				 else
					 FearTimer -= diff;
			}

		};

		CreatureAI* GetAI(Creature* creature) const
		{
			return new boss_antrixAI(creature);
		}

};

void AddSC_boss_antrix()
{
	new boss_antix();
}