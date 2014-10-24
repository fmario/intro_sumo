/**
 * \file
 * \brief Main Application Interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Interface to the main application module. 
 * From here the application runs and performs all tasks.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

/*!
 * \brief Application main start and main routine 
 */
void APP_Start(void);

#if PL_HAS_RTOS
static void APP_Loop(void* pvParameters);
#endif

#endif /* APPLICATION_H_ */
