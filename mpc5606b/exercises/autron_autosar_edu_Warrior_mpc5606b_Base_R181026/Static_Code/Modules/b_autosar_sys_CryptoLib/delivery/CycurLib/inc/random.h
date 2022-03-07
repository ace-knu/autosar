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
   \file        random.h

   \brief       Random number generator
   \attention   The implementation has to be adapted to your needs!

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_RANDOM_H_
#define _ESC_RANDOM_H_

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

/** Length of the seed. */
#ifndef EscRandom_RND_LENGTH
#   define EscRandom_RND_LENGTH 20U
#endif

/** Random context */
typedef struct {
    /** random data */
    UINT8 rnd[ EscRandom_RND_LENGTH ];
} EscRandom_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the random context.
\param[out] ctx Random context
\param[out] rnd Pointer to init data of size Esc_Random_RND_LENGTH
\return TRUE on error

\attention The implementation has to be adapted to your needs!
*/
extern BOOL
EscRandom_Init(
    EscRandom_ContextT* ctx,
    const UINT8 rnd[] );

/**
Returns an array of random data
\param[in] ctx Random context
\param[out] ctx Updated random context
\param[out] rnd Pointer to the array where the random data will be stored
\param[in] len Expected length of random data
\return TRUE on error

\attention The implementation has to be adapted to your needs!
*/
extern BOOL
EscRandom_GetRandom(
    EscRandom_ContextT* ctx,
    UINT8 rnd[],
    UINT32 len );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/
#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif /*
*/

#endif /*
*/
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
