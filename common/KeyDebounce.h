/**
 * \file
 * \brief Key debouncing interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements debouncing for multiple keys.
 */

#ifndef KEYDEBOUNCE_H_
#define KEYDEBOUNCE_H_

#define KEYDBNC_DBNCTIME 50 /* debounce time in ms */
#define KEYDBNC_LONGTIME 500 /* time for long pressed detection in ms */

/*!
 * \brief Kicks the debouncing state machine.
 */
void KEYDBNC_Process(void);

/*!
 * \brief Driver initialization.
 */
void KEYDBNC_Init(void);

/*!
 * \brief Driver de-initialization.
 */
void KEYDBNC_Deinit(void);

#endif /* KEYDEBOUNCE_H_ */
