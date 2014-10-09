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
#if PL_HAS_EVENTS
	#include "Event.h"
#endif

void TMR_OnInterrupt(void) {
  static unsigned char cntr_tick = 0;

  if((++cntr_tick) >= 1000/TMR_TICK_MS){
	  EVNT_SetEvent(EVNT_LED_HEARTBEAT);
	  cntr_tick = 0;
  }
}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
