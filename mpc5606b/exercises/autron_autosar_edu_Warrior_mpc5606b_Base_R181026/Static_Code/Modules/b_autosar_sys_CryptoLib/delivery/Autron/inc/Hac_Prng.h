/*-----------------------------------------------------------------------------
* Hyundai-AutoEver Cryptography Library
* Copyright (c) 2015-2016 Hyundai-AutoEver all rights reserved.
------------------------------------------------------------------------------*/
/**
* \file		Hac_Prng.h
* \date		Oct. 2016.
* \version	1.0.0
* \author	Hyundai Autoever Automotive Security Techology Team
* \brief	PRNG(Pseduo Random Number Generator) implementation
* \see		
*/

/* DEFINE TO PREVENT RECURSIVE INCLUSION -------------------------------------*/
#ifndef _HAC_PRNG_H_
#define _HAC_PRNG_H_

/* INCLUDES ------------------------------------------------------------------*/

/* EXPORTED DEFINE -----------------------------------------------------------*/

#if defined(__cplusplus)
extern "C"
{
#endif

/** \brief Endians */
#ifndef HAC_LITTLE_ENDIAN
#define HAC_LITTLE_ENDIAN	0x01u
#endif

#ifndef HAC_BIG_ENDIAN
#define HAC_BIG_ENDIAN		0x00u
#endif

#if defined (__BIG_ENDIAN__)
#define HAC_BYTE_ORDER	HAC_BIG_ENDIAN
#elif defined (__LITTLE_ENDIAN__)
#define HAC_BYTE_ORDER	HAC_LITTLE_ENDIAN
#endif

#ifndef HAC_BYTE_ORDER
#define HAC_BYTE_ORDER	HAC_BIG_ENDIAN
#endif

/** \brief retune & Error Type*/
#define HAC_VOID				/** no value */
#define HAC_SUCCESS			(0)	/** BOOL value true. */
#define HAC_FAILURE			(1)	/** BOOL value False. */
#define HAC_INVALID_VALUE	(3)	/** Error type invalid value  */
#define HAC_INVALID_LENGTH	(4)	/** Error type invalid length  */

/** \brief Entropy length for Hac_PrngReseed */
#define HAC_ENTROPY_LEN		16u

/** \brief Maximum length to generate random numbers at once */
#define HAC_RND_MAX_LEN		0x000FFFFFu /* 65536 * 16 = 1048576 */

/** \brief Rand key size in prng context */
#define HAC_RND_KEY_SIZE	32u

/** \brief State size in prng context */
#define HAC_RND_STATE_SIZE	16u

/** \brief Reseed period: user should reseed if reseedCnt reached to the period */
#define HAC_RESEED_PERIOD	100000u

/* EXPORTED MACRO  -----------------------------------------------------------*/

/* EXPORTED TYPES  -----------------------------------------------------------*/
/* Already defined in Platform_Types.h */
#if 0
#ifndef uint8
	/** 8 bit unsigned integer. */
	typedef unsigned char		uint8;
#endif
#ifndef uint16
	/** 16 bit unsigned integer. */
	typedef unsigned short		uint16;
#endif
#ifndef uint32
	/** 32 bit unsigned integer. */
	typedef unsigned long		uint32;
#endif
#ifndef uint64
	/** 64 bit unsigned integer. */
	typedef unsigned long long	uint64;
#endif
#ifndef sint8
	/** 8 bit signed integer. */
	typedef signed char			sint8;
#endif
#ifndef sint16
	/** 16 bit signed integer. */
	typedef signed short		sint16;
#endif
#ifndef sint32
	/** 32 bit signed integer. */
	typedef signed long			sint32;
#endif
#ifndef sint64
	/** 64 bit signed integer. */
	typedef signed long long	sint64;
#endif
#ifndef float32
	/** 32 bit floating point number. */
	typedef float				float32;
#endif
#ifndef float64
	/** 64 bit floating point number. */
	typedef double				float64;
#endif
#ifndef boolean
	/** simple return data. */
	typedef unsigned char		boolean;
#endif
#endif

/** \brief Context for Hac PRNG */
typedef struct {	
	uint8 state[HAC_RND_STATE_SIZE];
	uint8 rndkey[HAC_RND_KEY_SIZE];
	uint32 reseedCnt;
} HacPrngCtx;

/* EXPORTED VARIABLES  -------------------------------------------------------*/

/* EXPORTED FUNCTIONS  -------------------------------------------------------*/

/** \brief	PRNG initialization
*
* initializes prng context.
* \param[out]	hpc	context of PRNG
* \return		void
* \see			Hac_PrngReseed, Hac_PrngGetRand
*/
void Hac_PrngInit(
	HacPrngCtx		*hpc
	);

/** \brief	PRNG Reseed
*
* Reseed from user-input entropy(User must set entropy from entropy sources).
* \param[inout]	hpc		context of PRNG
* \param[in]	entropy	seed input for generating randoms
* \return		void
* \see			Hac_PrngInit, Hac_PrngGetRand
*/
void Hac_PrngReseed(
	HacPrngCtx		*hpc,
	const uint8		entropy[HAC_ENTROPY_LEN]
	);

/** \brief	Get pseudo random numbers
*
* Generate and return random numbers based on PRNG context values and entropy.
* \param[inout]	hpc		context of PRNG
* \param[in]	len		length of random numbers
* \param[out]	rndout	output of random numbers with len
* \return		HAC_SUCCESS/HAC_FAILURE/HAC_INVALID_VALUE/HAC_INVALID_LENGTH.
* \see			Hac_PrngInint, Hac_PrngReseed
*/
boolean Hac_PrngGetRand(
	HacPrngCtx		*hpc, 
	uint8			rndout[], 
	const uint32	len
	);


#if defined(__cplusplus)
}
#endif

#endif
/* END OF FILE ===============================================================*/