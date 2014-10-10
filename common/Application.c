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
		LED2_On();
		WAIT1_Waitms(100);
		LED1_Off();
		break;
	case EVNT_LED_HEARTBEAT:
		LED3_Neg();
		break;
	case EVNT_SW1_PRESSED:
		LED_AllOff();
		LED1_On();
		break;
	case EVNT_SW2_PRESSED:
		LED_AllOff();
		LED3_On();
		break;
	case EVNT_SW3_PRESSED:
		LED_AllOff();
		LED1_On();
		LED2_On();
		break;
	case EVNT_SW4_PRESSED:
		LED_AllOff();
		LED2_On();
		break;
	case EVNT_SW5_PRESSED:
		LED_AllOff();
		LED2_On();
		LED3_On();
		break;
	case EVNT_SW6_PRESSED:
		LED_AllOff();
		LED1_On();
		LED3_On();
		break;
	case EVNT_SW7_PRESSED:
		LED_AllOff();
		LED1_On();
		LED2_On();
		LED3_On();
		break;
	}
}

void APP_Start(void) {
  PL_Init(); /* platform initialization */
  for(;;) {
	  KEY_Scan();
#if PL_HAS_EVENTS
	  EVNT_HandleEvent(APP_HandleEvent);
#endif
	  WAIT1_Waitms(100);
  }
  PL_Deinit(); /* platform deinitialization */
}
