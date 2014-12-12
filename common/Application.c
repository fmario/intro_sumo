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
#if PL_HAS_MEALY
  #include "Mealy.h"
#endif
#if PL_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_HAS_RTOS
  #include "RTOS.h"
  #include "FRTOS1.h"
#endif
#if PL_HAS_RTOS_TRACE
  #include "RTOSTRC1.h"
#endif
#if PL_HAS_ACCEL
  #include "Accel.h"
#endif
#include "Test.h"
#include "Motor.h"
#include "StateMachine.h"
#include "Reflectance.h"


void APP_DebugPrint(unsigned char *str) {
#if PL_HAS_SHELL
  CLS1_SendStr(str, CLS1_GetStdio()->stdOut);
#endif
}

static void APP_EventHandler(EVNT_Handle event) {
	switch(event){
	case EVNT_INIT:
		#if PL_HAS_BUZZER
			  BUZ_Beep(400, 700);
		#endif
	    break;
	#if PL_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
		  Calibration_Run();
		  //StateMachine_Init();
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
		  //StateMachine_Init(); // StateMachine Startet
	  #endif
	  break;
	case EVNT_SW1_LPRESSED:
		  //Calibration_Run();
		  REF_SetMeasur();
		  StateMachine_Init();
	case EVNT_SW1_RELEASED:
		break;
		#endif
	#if PL_NOF_KEYS >= 2
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW2_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW2 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW2_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW2 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW2_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW2 released!\r\n");
	  #endif
	#endif
	#if PL_NOF_KEYS >= 3
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW3_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW3 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW3_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW3 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW3_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW3 released!\r\n");
	  #endif
	#endif
	#if PL_NOF_KEYS >= 4
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW4_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW4 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW4_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW4 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW4_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW4 released!\r\n");
	  #endif
	#endif
	#if PL_NOF_KEYS >= 5
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW5_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW5 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW5_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW5 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW5_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW5 released!\r\n");
	  #endif
	#endif
	#if PL_NOF_KEYS >= 6
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW6_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW6 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW6_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW6 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW6_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW6 released!\r\n");
	  #endif
	#endif
	#if PL_NOF_KEYS >= 7
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW7_PRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW7 pressed!\r\n");
	  #endif
	  #if PL_HAS_BUZZER
		  BUZ_Beep(300, 500);
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW7_LPRESSED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW7 long pressed!\r\n");
	  #endif
	  } else if (EVNT_EventIsSetAutoClear(EVNT_SW7_RELEASED)) {
	  #if PL_HAS_SHELL
		  SHELL_SendString("SW7 released!\r\n");
	  #endif
	#endif
  }
}

#if PL_HAS_RTOS
static void AppTask(void *pvParameters) {
  (void)pvParameters; /* not used */

  #if PL_HAS_ACCEL /* need to initialize accelerometer from a task (interrupts enabled). */
    ACCEL_LowLevelInit();
  #endif

  for(;;) {
	#if PL_HAS_EVENTS
	  EVNT_HandleEvent(APP_EventHandler); /* handle pending events */
	#endif
	#if PL_HAS_KEYS && PL_NOF_KEYS>0
		KEY_Scan(); /* scan keys */
	#endif
    FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
  }
}
#else
static void APP_Loop(void) {
  int i;

#if PL_HAS_SHELL
  CLS1_SendStr("Hello World!\r\n", CLS1_GetStdio()->stdOut);
#endif
  for(;;) {
#if PL_HAS_EVENTS
    EVNT_HandleEvent(APP_EventHandler); /* handle pending events */
#endif
#if PL_HAS_KEYS && PL_NOF_KEYS>0
    KEY_Scan(); /* scan keys */
#endif
#if PL_HAS_MEALY
    MEALY_Step();
#endif
    WAIT1_Waitms(100);
  }
}
#endif

void APP_Start(void) {
#if PL_HAS_RTOS_TRACE
  if (RTOSTRC1_uiTraceStart()==0) {
    for(;;){} /* error starting trace recorder. Not setup for enough queues/tasks/etc? */
  }
#endif
  PL_Init(); /* platform initialization */

  EVNT_SetEvent(EVNT_INIT); /* set initial event */
#if PL_HAS_RTOS
  if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS)
  {
    for(;;){} /* error */
  }
  RTOS_Run();
#else
  APP_Loop();
#endif
  /* just in case we leave the main application loop */
  PL_Deinit();
}
