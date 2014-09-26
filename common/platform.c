/**
 * \file
 * \brief Platform Interface.
 * \author Mario Felder, mario.felder@stud.hslu.ch
 *
 * This implements the platform interface.
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */

#include "Platform.h"
#if PL_HAS_LED
  #include "LED.h"
#endif

void PL_Init(void) {
#if PL_HAS_LED
  LED_Init();
#endif
}

void PL_Deinit(void) {
#if PL_HAS_LED
  LED_Deinit();
#endif
}
