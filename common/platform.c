/**
 * \file
 * \brief Platform implementation module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This implements the platform module. 
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */

#include "Platform.h"
#if PL_HAS_LED
  #include "LED.h"
#endif
#if PL_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_HAS_TIMER
  #include "Timer.h"
#endif
#if PL_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_HAS_MEALY
  #include "Mealy.h"
#endif
#if PL_HAS_TRIGGER
  #include "Trigger.h"
#endif
#if PL_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_HAS_DEBOUNCE
  #include "Debounce.h"
  #include "KeyDebounce.h"
#endif
#if PL_HAS_RTOS
  #include "RTOS.h"
#endif
#if PL_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_HAS_SHELL_QUEUE
  #include "ShellQueue.h"
#endif
#if PL_HAS_SEMAPHORE
  #include "Sem.h"
#endif
#if PL_HAS_REFLECTANCE
  #include "Reflectance.h"
#endif
#if PL_HAS_MOTOR
  #include "Motor.h"
#endif
#if PL_HAS_CONFIG_NVM
  #include "NVM_Config.h"
#endif
#if PL_HAS_MOTOR_TACHO
  #include "Tacho.h"
#endif
#if PL_HAS_PID
  #include "Pid.h"
#endif
#if PL_HAS_DRIVE
  #include "Drive.h"
#endif
#if PL_HAS_ACCEL
  #include "Accel.h"
#endif
#if PL_HAS_ULTRASONIC
  #include "Ultrasonic.h"
#endif
#if PL_HAS_ACCEL
  #include "Accel.h"
#endif
#if PL_HAS_RADIO
  #include "RNet_App.h"
#endif
//#if PL_HAS_REMOTE
  //#include "Remote.h"
//#endif

void PL_Init(void) {
#if PL_HAS_LED
  LED_Init();
#endif  
#if PL_HAS_TIMER
  TMR_Init();
#endif
#if PL_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_HAS_KEYS
  KEY_Init();
#endif
#if PL_HAS_MEALY
  MEALY_Init();
#endif
#if PL_HAS_TRIGGER
  TRG_Init();
#endif
#if PL_HAS_BUZZER
  BUZ_Init();
#endif
#if PL_HAS_DEBOUNCE
  DBNC_Init();
  KEYDBNC_Init();
#endif
#if PL_HAS_RTOS
  RTOS_Init();
#endif
#if PL_HAS_SHELL
  SHELL_Init();
#endif
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Init();
#endif
#if PL_HAS_SEMAPHORE
  SEM_Init();
#endif
#if PL_HAS_REFLECTANCE
  REF_Init();
#endif
#if PL_HAS_MOTOR
  MOT_Init();
#endif
#if PL_HAS_CONFIG_NVM
  NVMC_Init();
#endif
#if PL_HAS_MOTOR_TACHO
  TACHO_Init();
#endif
#if PL_HAS_PID
  PID_Init();
#endif
#if PL_HAS_DRIVE
  DRV_Init();
#endif
#if PL_HAS_ACCEL
  ACCEL_Init();
#endif
#if PL_HAS_ULTRASONIC
  US_Init();
#endif
#if PL_HAS_RADIO
  RNETA_Init();
#endif
#if PL_HAS_ACCEL
  ACCEL_Init();
#endif
#if PL_HAS_REMOTE
  REMOTE_Init();
#endif
}

void PL_Deinit(void) {
#if PL_HAS_REMOTE
  REMOTE_Deinit();
#endif
#if PL_HAS_ACCEL
  ACCEL_Deinit();
#endif
#if PL_HAS_RADIO
  RNETA_Deinit();
#endif
#if PL_HAS_ULTRASONIC
  US_Deinit();
#endif
#if PL_HAS_ACCEL
  ACCEL_Deinit();
#endif
#if PL_HAS_DRIVE
  DRV_Deinit();
#endif
#if PL_HAS_PID
  PID_Deinit();
#endif
#if PL_HAS_MOTOR_TACHO
  TACHO_Deinit();
#endif
#if PL_HAS_CONFIG_NVM
  NVMC_Deinit();
#endif
#if PL_HAS_MOTOR
  MOT_Deinit();
#endif
#if PL_HAS_REFLECTANCE
  REF_Deinit();
#endif
#if PL_HAS_SEMAPHORE
  SEM_Deinit();
#endif
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Deinit();
#endif
#if PL_HAS_SHELL
  SHELL_Deinit();
#endif
#if PL_HAS_RTOS
  RTOS_Deinit();
#endif
#if PL_HAS_BUZZER
  BUZ_Deinit();
#endif
#if PL_HAS_DEBOUNCE
  KEYDBNC_Deinit();
  DBNC_Deinit();
#endif
#if PL_HAS_TRIGGER
  TRG_Deinit();
#endif
#if PL_HAS_MEALY
  MEALY_Deinit();
#endif
#if PL_HAS_KEYS
  KEY_Deinit();
#endif
#if PL_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_HAS_TIMER
  TMR_Deinit();
#endif
#if PL_HAS_LED
  LED_Deinit();
#endif
}
