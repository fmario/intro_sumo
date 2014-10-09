/**
 * \file
 * \brief Main Application Module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module is the main application module. 
 * From here the application runs and performs all tasks.
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#include "CS1.h"
#if PL_HAS_LED
  #include "LED.h"
#endif
#if PL_HAS_EVENTS
	#include "Event.h"
#endif


static void APP_HandleEvent(EVNT_Handle event){
	switch(event){
	case EVNT_INIT:
		LED1_On();
		WAIT1_Waitms(50);
		LED1_Off();
		LED2_On();
		WAIT1_Waitms(50);
		LED2_Off();
		LED3_On();
		WAIT1_Waitms(50);
		LED3_Off();
		break;
	case EVNT_LED_HEARTBEAT:
		LED2_Neg();
		break;
	}
}

static void APP_Init(){
	PL_Init(); /* platform initialization */
	EVNT_Init(); /* event initialization*/
	TMR_Init(); /* timer initialization*/
}

static void APP_Deinit(){
	EVNT_Deinit(); /* event deinitialization */
	PL_Deinit(); /* platform deinitialization */
	TMR_Deinit(); /* timer deinitialization */
}

void APP_Start(void) {
  APP_Init();
  for(;;) {
#if PL_HAS_EVENTS
	  EVNT_HandleEvent(APP_HandleEvent);
#endif
	  WAIT1_Waitms(100);
  }
  APP_Deinit();
}
