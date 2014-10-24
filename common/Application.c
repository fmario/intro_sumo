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
#if PL_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_HAS_RTOS
  #include "RTOS.h"
  #include "FRTOS1.h"
#endif

#if PL_HAS_EVENTS
static void APP_HandleEvent(EVNT_Handle event){
	switch(event){
	case EVNT_INIT:
		LED2_On();
    #if PL_HAS_RTOS
		  FRTOS1_vTaskDelay(350/portTICK_RATE_MS);
		#else
		  WAIT1_Waitms(350);
    #endif
		LED2_Off();
		break;
	case EVNT_LED_HEARTBEAT:
		LED3_Neg();
		break;
#if PL_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
		LED3_On();
    #if PL_HAS_SHELL
		  CLS1_SendStr("SW1 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW1_LPRESSED:
    LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW1 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
	case EVNT_SW1_RELEASED:
    LED_AllOff();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW1 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
#if PL_NOF_KEYS >= 2
	case EVNT_SW2_PRESSED:
		LED1_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW2 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW2_LPRESSED:
    LED1_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW2 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
	case EVNT_SW2_RELEASED:
	  LED_AllOff();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW2 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
#if PL_NOF_KEYS >= 3
	case EVNT_SW3_PRESSED:
		LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW3 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW3_LPRESSED:
    LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW3 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
  case EVNT_SW3_RELEASED:
    LED_AllOff();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW3 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
#if PL_NOF_KEYS >= 4
	case EVNT_SW4_PRESSED:
		LED1_On();
		LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW4 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
  case EVNT_SW4_LPRESSED:
    LED1_On();
    LED2_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW4 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
  case EVNT_SW4_RELEASED:
    LED_AllOff();
     #if PL_HAS_SHELL
      CLS1_SendStr("SW4 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
#if PL_NOF_KEYS >= 5
	case EVNT_SW5_PRESSED:
		LED2_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW5 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW5_LPRESSED:
	    LED2_On();
	    LED3_On();
	    #if PL_HAS_SHELL
	      CLS1_SendStr("SW5 long pressed\n",CLS1_GetStdio()->stdOut);
	    #endif
	    break;
	case EVNT_SW5_RELEASED:
	    LED_AllOff();
	    #if PL_HAS_SHELL
	      CLS1_SendStr("SW5 released\n",CLS1_GetStdio()->stdOut);
	    #endif
	    break;
#endif
#if PL_NOF_KEYS >= 6
	case EVNT_SW6_PRESSED:
		LED1_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW6 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW6_LPRESSED:
    LED1_On();
    LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW6 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
	case EVNT_SW6_RELEASED:
    LED_AllOff();
     #if PL_HAS_SHELL
      CLS1_SendStr("SW6 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
#if PL_NOF_KEYS >= 7
	case EVNT_SW7_PRESSED:
		LED1_On();
		LED2_On();
		LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW7 pressed\n",CLS1_GetStdio()->stdOut);
    #endif
		break;
	case EVNT_SW7_LPRESSED:
    LED1_On();
    LED2_On();
    LED3_On();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW7 long pressed\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
	case EVNT_SW7_RELEASED:
    LED_AllOff();
    #if PL_HAS_SHELL
      CLS1_SendStr("SW7 released\n",CLS1_GetStdio()->stdOut);
    #endif
    break;
#endif
	default: break;
	}
}
#endif

void APP_Start(void) {
  PL_Init(); /* platform initialization */
  #if PL_HAS_RTOS
    if(FRTOS1_xTaskCreate( APP_Loop,
          "MainLoop",
          configMINIMAL_STACK_SIZE,
          (void*)NULL,
          tskIDLE_PRIORITY,
          (xTaskHandle*)NULL) != pdPASS){
      for(;;); /* error */
    }
    RTOS_Run();
    #else
      APP_Loop();
    #endif
  PL_Deinit(); /* platform deinitialization */
}

#if PL_HAS_RTOS
static void APP_Loop(void* pvParameters){
  (void) pvParameters;
  #if PL_HAS_BUZZER
    BUZ_Beep(440, 1000);
  #endif

    for(;;) {
    KEY_Scan();
    #if PL_HAS_EVENTS
      EVNT_HandleEvent(APP_HandleEvent);
    #endif
    #if PL_HAS_KEYS && PL_NOF_KEYS>0
      KEY_Scan();
    #endif
    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
  }
}
#else
static void APP_Loop(void){
  #if PL_HAS_BUZZER
    BUZ_Beep(440, 1000);
  #endif

  for(;;) {
    KEY_Scan();
    #if PL_HAS_EVENTS
      EVNT_HandleEvent(APP_HandleEvent);
    #endif
    WAIT1_Waitms(100);
  }
}
#endif
