/*
 * StateMachine.c
 *
 *  Created on: 01.12.2014
 *      Author: Imhof Dominik
 */


#include "Motor.h"
#include "Accel.h"
#include "Ultrasonic.h"
#include "Event.h"
#include "Events.h"
#include "Keys.h"
#include "FRTOS1.h"
#include "Ultrasonic.h"
#include "Reflectance.h"
#include "WAIT1.h"
#include "Buzzer.h"

#define SPEED_ATTACK 90
#define SPEED_TURN 45

typedef enum {
  START,
  DRIVE,
  REFLECTANCE,
  TURN,
  ULTRASONIC,
  ATTACK,
  STOP
} StateType;
static volatile StateType state = START; /* state machine state */


void Calibration_Run(void){
	// Wenn SW1 pressed, kommt er da rein. beim 2ten mal stopt er calibration.
	EVNT_SetEvent(EVNT_REF_START_STOP_CALIBRATION);
}

/*
void Motor_Run(void){
	MOT_SetDirection(MOT_GetMotorHandle(MOT_MOTOR_LEFT), MOT_DIR_FORWARD);
	MOT_SetDirection(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), MOT_DIR_FORWARD);
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 10);
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), 40);
}*/

static void StateMachine_Run(void){
  int i;
  int distance;

  switch (state) {
	case START:
		WAIT1_WaitOSms(800);
		BUZ_Beep(400,400);
		WAIT1_WaitOSms(800);
		BUZ_Beep(450,400);
		WAIT1_WaitOSms(800);
		BUZ_Beep(500,400);
		WAIT1_WaitOSms(800);
		BUZ_Beep(600,400);
		WAIT1_WaitOSms(800);
		BUZ_Beep(880,400);

		MOT_SetDirection(MOT_GetMotorHandle(MOT_MOTOR_LEFT), MOT_DIR_FORWARD);
		MOT_SetDirection(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), MOT_DIR_FORWARD);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), 40);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 40);

		/*int x0;
		int x5;
		int x0_cal;
		int x5_cal;
		x0 = Get_Reflectance_Values(0);
		x0_cal = x0 / 15;
		x5 = Get_Reflectance_Values(5);
		x5_cal = x5 / 15;
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), x0_cal);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), x5_cal);
		*/

		//uint16_t* calib_values_pointer;
		//calib_values_pointer = &SensorTimeType;
		//calib_values_pointer = S1_GetVal();

		state = DRIVE;

	  break;

	case DRIVE:
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), SPEED_TURN);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), -SPEED_TURN);

		if((Get_Reflectance_Values(3) <= 100) || (Get_Reflectance_Values(4) <= 100)){ // 0 = weiss / 1000 = schwarz
			state = STOP;
		}

		distance = US_usToCentimeters(US_Measure_us(),22);

		if((distance <= 30) && (distance != 0)){
			MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), SPEED_ATTACK);
			MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), SPEED_ATTACK);
			state = ATTACK;
		}

		/*if((MMA1_GetXmg() >= 500) || (MMA1_GetXmg() <= -500)){
			state = STOP;
		}
		*/
		/*if((MMA1_GetYmg() >= 500) || (MMA1_GetYmg() <= -500)){
			state = STOP;
		}*/

		break;

	case TURN:
		state = DRIVE;
		break;

	case STOP:
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), -50);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), -50);

		WAIT1_WaitOSms(150);

		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), -50);
		MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 50);

		WAIT1_WaitOSms(444);

		if(Get_Reflectance_Values(4) >= 400){
			state = DRIVE;
		}

		/*if((MMA1_GetXmg() >= -200) && (MMA1_GetXmg() <= 200)){
			state = DRIVE;
		}*/

		/*if((MMA1_GetYmg() >= -200) || (MMA1_GetYmg() <= 200)){
			state = DRIVE;
		}*/

		break;

	case ATTACK:
		if((distance <= 30) && (distance != 0)){
			state = ATTACK;
			MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), SPEED_ATTACK);
			MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), SPEED_ATTACK);
			WAIT1_WaitOSms(50);
		}else{
			state = DRIVE;
		}
		if((Get_Reflectance_Values(3) <= 100) || (Get_Reflectance_Values(4) <= 100)){ // 0 = weiss / 1000 = schwarz
			state = STOP;
		}

	break;
  } /* switch */
}



static portTASK_FUNCTION(StateMachineTask, pvParameters) {
  (void)pvParameters; /* not used */
  for(;;) {
    StateMachine_Run();
    FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
  }
}

void StateMachine_Deinit(void) {
}



void StateMachine_Init(void) {
  //refState = REF_STATE_INIT;
  //timerHandle = RefCnt_Init(NULL);
  /*! \todo You might need to adjust priority or other task settings */
  DRV_EnableDisable(0);
  if (FRTOS1_xTaskCreate(StateMachineTask, "StateMachine", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}
