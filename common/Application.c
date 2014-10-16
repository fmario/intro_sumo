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
#if PL_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_HAS_SHELL
  #include "CLS1.h"
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
#if PL_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
		LED_AllOff();
		LED3_On();
    #if PL_HAS_SHELL
		  CLS1_SendStr("SW1 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 2
	case EVNT_SW2_PRESSED:
		LED_AllOff();
		LED1_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW2 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 3
	case EVNT_SW3_PRESSED:
		LED_AllOff();
		LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW3 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 4
	case EVNT_SW4_PRESSED:
		LED_AllOff();
		LED1_On();
		LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW4 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 5
	case EVNT_SW5_PRESSED:
		LED_AllOff();
		LED2_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW5 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 6
	case EVNT_SW6_PRESSED:
		LED_AllOff();
		LED1_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW6 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
#if PL_NOF_KEYS >= 7
	case EVNT_SW7_PRESSED:
		LED_AllOff();
		LED1_On();
		LED2_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW7 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
#endif
	default: break;
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
