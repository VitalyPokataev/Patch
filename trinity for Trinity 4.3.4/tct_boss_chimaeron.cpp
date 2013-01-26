#include "ScriptPCH.h"


enum Spells
{
    //chimaeron
    SPELL_BERSERK                   = 26662,
    SPELL_FAST_ASLEEP               = 82706,
    SPELL_DOUBLE_ATTACK_DUMMY       = 88826,
    SPELL_DOUBLE_ATTACK             = 82882,
    SPELL_FEUD                      = 88872,
    SPELL_BREAK                     = 82881,
    SPELL_MASSACRE                  = 82848,
    SPELL_CAUSTIC_SLIME_MISSILE     = 82913,
    SPELL_CAUSTIC_SLIME_TARGET      = 82871,
    SPELL_CAUSTIC_SLIME             = 82935,
    SPELL_MORTALITY                 = 82890,
    SPELL_MORTALITY_SELF            = 82934,

    //bile o tron 800
    SPELL_FINKLES_MIXTURE           = 82705,
    SPELL_REROUTE_POWER             = 88861,
    SPELL_SYSTEMS_FAILURE           = 88853,
    SPELL_FINKLES_MIXTURE_VISUAL    = 91106,

    SPELL_LOW_HEALTH                = 89084,

    SPELL_SHADOW_WHIP               = 91304,
    SPELL_MOCKING_SHADOWS           = 91307,
};

enum Events
{
    //chimaeron
    EVENT_BERSERK                   = 1,
    EVENT_FAST_ASLEEP               = 2,
    EVENT_DOUBLE_ATTACK_DUMMY       = 3,
    EVENT_DOUBLE_ATTACK             = 4,
    EVENT_FEUD                      = 5,
    EVENT_BREAK                     = 6,
    EVENT_MASSACRE                  = 7,
    EVENT_CAUSTIC_SLIME_MISSILE     = 8,
    EVENT_CAUSTIC_SLIME_TARGET      = 9,
    EVENT_CAUSTIC_SLIME             = 10,
    EVENT_MORTALITY                 = 11,
    EVENT_MORTALITY_SELF            = 12,
    EVENT_ENRAGE                    = 20,
    EVENT_MASSACRE_SLIME            = 21,

    //bile o tron 800
    EVENT_FINKLES_MIXTURE           = 13,
    EVENT_REROUTE_POWER             = 14,
    EVENT_SYSTEMS_FAILURE           = 15,
    EVENT_FINKLES_MIXTURE_VISUAL    = 16,


    EVENT_LOW_HEALTH                = 17,
    
    EVENT_SHADOW_WHIP               = 18,
    EVENT_MOCKING_SHADOWS           = 19,
};



class boss_chimaeron : public CreatureScript
	{
    
	public:
    boss_chimaeron() : CreatureScript("boss_chimaeron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chimaeronAI (creature);
    }
	 
	
	struct boss_chimaeronAI : public ScriptedAI
	{
	    boss_chimaeronAI(Creature* creature) : ScriptedAI(creature) 
		{	
          DoCast(me, SPELL_FAST_ASLEEP);
		}
		
		EventMap events;

		void Reset()
            {
                me->SetReactState(REACT_DEFENSIVE);
                events.Reset();
            }

		 void JustReachedHome()
            {
                DoCast(SPELL_FAST_ASLEEP);
            }


		 void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();
				events.ScheduleEvent(EVENT_ENRAGE, 420000);              //Сперва энрейд - 7 мин.
				events.ScheduleEvent(EVENT_BREAK, urand(14000, 15000));  //Разлом
                events.ScheduleEvent(EVENT_MASSACRE_SLIME, 26000);       //Массакр + 3 слайма.
                events.ScheduleEvent(EVENT_MASSACRE_SLIME, 56000);       //Массакр + 3 слайма.
                events.ScheduleEvent(EVENT_MASSACRE_SLIME, 86000);       //Массакр + 3 слайма.
                events.ScheduleEvent(EVENT_FEUD, 90000);                 //Распри и далле массакры со слаймами.					 
            }

		  void UpdateAI(const uint32 diff)
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
                           //Разлом каждые 14-15 сек.
                      case EVENT_BREAK :                         
                           DoCastVictim(SPELL_BREAK);
						   DoCast(SPELL_DOUBLE_ATTACK);
						   events.ScheduleEvent(EVENT_BREAK, urand(14000, 15000));
						   break;
				           
					  case EVENT_CAUSTIC_SLIME_MISSILE : 
						   if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                               DoCast(pTarget, SPELL_CAUSTIC_SLIME_MISSILE);             
                           break;

                           
                           //Массакр + 3 слайма.
                      case EVENT_MASSACRE_SLIME :
					       me->InterruptNonMeleeSpells(false);
                           DoCastAOE(SPELL_MASSACRE);	
                           events.ScheduleEvent(EVENT_CAUSTIC_SLIME_MISSILE, 19000);
                           events.ScheduleEvent(EVENT_CAUSTIC_SLIME_MISSILE, 24000);
                           events.ScheduleEvent(EVENT_CAUSTIC_SLIME_MISSILE, 29000);
					       break;	

					  case EVENT_ENRAGE :
						   DoCast (SPELL_MORTALITY);
						   DoCastAOE (SPELL_MORTALITY_SELF, true);
						   break;

                           //Распри, через 26 сек Массакр со слаймами и т.д каждые 30 сек.
                      case EVENT_FEUD :
                           DoCast (SPELL_FEUD);
                           events.ScheduleEvent(EVENT_MASSACRE_SLIME, 26000);
                           events.ScheduleEvent(EVENT_MASSACRE_SLIME, 56000);
                           events.ScheduleEvent(EVENT_MASSACRE_SLIME, 86000);
                           events.ScheduleEvent(EVENT_FEUD, 90100);                          
                           break;
					  					  
                      }
                 }
			
				DoMeleeAttackIfReady();
		  }
	};
};

void AddSC_boss_chimaeron()
{
    new boss_chimaeron();
}