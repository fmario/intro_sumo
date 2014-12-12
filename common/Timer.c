/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_HAS_TIMER
#include "Timer.h"
#if PL_HAS_LED
  #include "LED.h"
#endif
#if PL_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_HAS_TRIGGER
  #include "Trigger.h"
#endif
#if PL_HAS_MOTOR_TACHO
  #include "Tacho.h"
#endif
#include "TMOUT1.h"

void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  static int cntr=0;
  cntr++;

  #if PL_HAS_TRIGGER
    TRG_IncTick();
  #endif
    TMOUT1_AddTick();

  if (cntr==(5/portTICK_RATE_MS)) {
	#if PL_HAS_MOTOR_TACHO
	  TACHO_Sample();
	#endif
  cntr = 0;
  }

}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
