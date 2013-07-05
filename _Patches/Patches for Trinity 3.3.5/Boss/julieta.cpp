/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "ScriptPCH.h"

/*
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) values('500032','38186','100','1','1','3','3'); 

DELETE FROM `creature_template` WHERE `entry`=500032;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values
('500032','0','0','0','0','0','7553','0','0','0','Julieta la Esperanza','','','0','83','83','2','16','16','0','1','0.992063','2','2','589','698','0','869','35','2000','2000','1','33280','2048','8','0','0','0','0','0','445','654','169','1','72','500030','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1250000','1250000','','1','7','1','450','1','1','0','38186','0','0','0','0','0','0','1','0','617299839','0','w_boss_julieta_la_esperanza','12340');


DELETE FROM `creature` WHERE `id`=500032;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values
('500032','571','1','128','0','0','4463.77','3790.81','348.12','6.12777','28800','0','0','4800000','0','0','0','0','0');

DELETE FROM `creature_text` WHERE `entry`=500032;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(500032, 0, 0, 'Vamos a degustar carne fresca', 14, 0, 100, 0, 0, 0, Julieta -  SAY_COMBAT'),
(500032, 1, 0, '¡Quemare vuestr cuerpo por insolentes!', 14, 0, 100, 0, 0, 0, 'Julieta - SAY_FLAME_BREATH'),
(500032, 2, 0, 'Me encanta verte en el suelo...', 14, 0, 100, 0, 0, 0, 'Julieta - SAY_SLAY'),
(500032, 3, 0, '¡Esto termina aqui!', 14, 0, 100, 0, 0, 0, 'Julieta - SAY_BERSERK'),
(500032, 4, 0, 'Ha llegado mi hora Romeo.', 14, 0, 100, 0, 0, 0, 'Julieta -  SAY_DEATH'),
(500032, 5, 0, '¡Sentid lo que es vivir sin Julieta!', 41, 0, 100, 0, 0, 0, 'Julieta - EMOTE_BELLOWING_ROAR');
*/

enum Talks
{
    SAY_COMBAT                   = 0, // Vamos a degustar carne fresca
    SAY_FLAME_BREATH             = 1, // ¡Quemare vuestr cuerpo por insolentes!
    SAY_SLAY                     = 2, // Me encanta verte en el suelo.
    SAY_BERSERK                  = 3, // ¡Esto termina aqui!
    SAY_DEATH                    = 4, // Ha llegado mi hora Romeo...
    EMOTE_BELLOWING_ROAR         = 5  // ¡Sentid lo que es vivir sin Romeo!
};

enum Spells
{
    SPELL_FLAME_BREATH           = 18435,
    SPELL_BELLOWING_ROAR         = 18431,
    SPELL_TAIL_SWEEP             = 68867,
    SPELL_FLAME_BUFFET           = 46279,
    SPELL_CLEAVE                 = 68868,
    SPELL_BERSERK                = 47008
};

enum Events
{
    EVENT_FLAME_BREATH           = 1,
    EVENT_BELLOWING_ROAR         = 2,
    EVENT_TAIL_SWEEP             = 3,
    EVENT_FLAME_BUFFET           = 4,
    EVENT_CLEAVE                 = 5,
    EVENT_BERSERK                = 6 
};

class w_boss_julieta_la_esperanza : public CreatureScript
{
    public:
        w_boss_julieta_la_esperanza() : CreatureScript("w_boss_julieta_la_esperanza") { }

        struct w_boss_julieta_la_esperanzaAI : public ScriptedAI
        {
            w_boss_julieta_la_esperanzaAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
			
            void Reset()
            {
                events.Reset();

                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
            }
            
            void EnterCombat(Unit* who)
            {
                DoZoneInCombat();

                events.Reset();
                Talk(SAY_COMBAT);
                events.ScheduleEvent(EVENT_FLAME_BREATH, urand(9*IN_MILLISECONDS, 14*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_BELLOWING_ROAR, 27*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(5*IN_MILLISECONDS, 8*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CLEAVE, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FLAME_BUFFET, 5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 4*MINUTE*IN_MILLISECONDS);
            }
            
            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
            }
            
            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }
      
            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);
				
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BELLOWING_ROAR:
                            Talk(EMOTE_BELLOWING_ROAR);
                            DoCast(me, SPELL_BELLOWING_ROAR);
                            events.ScheduleEvent(EVENT_BELLOWING_ROAR, urand(28*IN_MILLISECONDS, 32*IN_MILLISECONDS));
                            return;
                        case EVENT_FLAME_BREATH:
                            Talk(SAY_FLAME_BREATH);
                            if (Unit* target = me->getVictim())
                            DoCast(SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, urand(9*IN_MILLISECONDS, 14*IN_MILLISECONDS));
                            return;
                        case EVENT_TAIL_SWEEP:
                            DoCastAOE(SPELL_TAIL_SWEEP);
                            events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(5*IN_MILLISECONDS, 8*IN_MILLISECONDS));
                            return;
                        case EVENT_FLAME_BUFFET:
                            if (Unit* target = me->getVictim())
                            DoCast(SPELL_FLAME_BUFFET);
                            events.ScheduleEvent(EVENT_FLAME_BUFFET, 4*IN_MILLISECONDS);
                            return;
                        case EVENT_CLEAVE:
                            if (Unit* target = me->getVictim())
                            DoCast(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS));
                            return;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();

                EnterEvadeIfOutOfCombatArea(diff);
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new w_boss_julieta_la_esperanzaAI(creature);
        }
};

void AddSC_julieta_la_esperanza()
{
    new w_boss_julieta_la_esperanza();
}