/***************************************************************************
 * Copyright                                                               *
 *                                                                         *
 *     ESCRYPT GmbH - Embedded Security       ESCRYPT Inc.                 *
 *     Zentrum fuer IT-Sicherheit             315 E Eisenhower Parkway     *
 *     Lise-Meitner-Allee 4                   Suite 214                    *
 *     44801 Bochum                           Ann Arbor, MI 48108          *
 *     Germany                                USA                          *
 *                                                                         *
 *     http://www.escrypt.com                                              *
 *     info"at"escrypt.com                                                 *
 *                                                                         *
 * All Rights reserved                                                     *
 ***************************************************************************/

/***************************************************************************/
/*!
   \file        callback.h

   \brief       Definitions for the callback mechanism for RSA

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_CALLBACK_H_
#define _ESC_CALLBACK_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "cycurlib_config.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Type for callback function */
typedef void (*EscCallbackFunc)(void);

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
 * Set the callback function.
 * 
 * \param[in] function      The callback function to be used. If this parameter
 *                          is 0 then no function is called.
 */
void
EscCallback_setFunction(
    EscCallbackFunc callbackFunc);

/**
 * Run the previously set callback function.
 */
void
EscCallback_execCallback(void);

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

#endif

/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
