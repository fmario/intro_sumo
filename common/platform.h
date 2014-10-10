/**
 * \file
 * \brief Platform Interface.
 * \author Mario Felder, mario.felder@stud.hslu.ch
 *
 * This implements the platform interface.
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */
#include <stddef.h>   /* for NULL */

/* List of supported platforms. The PL_BOARD_IS_xxx is defined in the compiler command line settings.  */
#define PL_IS_FRDM   (defined(PL_BOARD_IS_FRDM))
  /*!< Macro is defined through compiler option for the FRDM board */
#define PL_IS_ROBO  (defined(PL_BOARD_IS_ROBO))
  /*!< Macro is defined through compiler option for the Robot board */

#define PL_HAS_LED  (1)
  /*!< Set to 1 to enable LED support, 0 otherwise */

#if PL_IS_FRDM
  #define PL_NOF_LEDS       3
     /*!< FRDM board has 3 LEDs (RGB) */

  #define PL_HAS_EVENTS (1)
	/*!< Set to 1 to enable event support, 0 otherwise */

  #define PL_HAS_TIMER (1)
	/*!< Set to 1 to enable timer support, 0 otherwise */

  #define PL_HAS_KEYS (1)
	/*!< Set to 1 to enable key support, 0 otherwise */

  #define PL_NOF_KEYS 		7
	/*!< FRDM board has 7 Keys (A-F and Joystick pressed) */

  #define PL_HAS_KBI (1)
	/*!< Set to 1 to enable key interrupt support, 0 otherwise */
	#define PL_KEY1_POLLED (0)
	#define PL_KEY2_POLLED (0)
	#define PL_KEY3_POLLED (0)
	#define PL_KEY4_POLLED (0)
	#define PL_KEY5_POLLED (1)
	#define PL_KEY6_POLLED (1)
	#define PL_KEY7_POLLED (0)

  #define PL_HAS_JOYSTICK (1)
	/*!< Set to 1 to enable joystick support, 0 otherwise */

#elif PL_IS_ROBO
  #define PL_NOF_LEDS       2
     /*!< We have up to 2 LED's on the robo board */

#else
  #error "unknown configuration?"

#endif

/*!
 * \brief Platform initialization
 */
void PL_Init(void);

/*!
 * \brief Platform de-initialization
 */
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
