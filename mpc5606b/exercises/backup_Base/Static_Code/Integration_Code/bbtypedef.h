/*============================================================================*/
/*                        AUTRON SOFTWARE GROUP                               */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %bbtypedef.h%
* Instance:         %
* %version:         1 %
* %created_by:      ca364 %
* %date_created:    2013/12/18 11:06:56 %
*=============================================================================*/
/* DESCRIPTION : header file for FBL configuration                            */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/* COPYRIGHT (C) 2013 HYUNDAI AUTRON Co., Ltd.                                */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*    1.0    | 16/Oct/2013 |  Task xar~701                 |  SH Yoo          */
/* Initial creation for Infineon TC27x                                        */
/* This file is made from stdtypedef.h in xenon project                       */
/*============================================================================*/
#ifndef BBTYPEDEF_H                              /* To avoid double inclusion */
#define BBTYPEDEF_H

#ifndef NULL
#define NULL 0
#endif

typedef unsigned char       T_UBYTE;
typedef unsigned short      T_UWORD;  // jsjang
typedef unsigned long       T_ULONG;
typedef unsigned long long  T_ULLONG;
typedef signed char         T_SBYTE;
typedef signed short        T_SWORD;
typedef signed long         T_SLONG;
typedef signed long long    T_SLLONG;
typedef unsigned int        T_FLAG_ARRAY;

/* table of entry pochars */
typedef void(*T_PPROC_NEAR)(void);
typedef void(*T_PPROC_FAR)(void);

/* basic type pointers */
typedef T_UBYTE  * PTR_UBYTE ;
typedef T_UWORD  * PTR_UWORD;
typedef T_ULONG  * PTR_ULONG;
typedef T_ULLONG * PTR_ULLONG;
typedef T_SBYTE  * PTR_SBYTE ;
typedef T_SWORD  * PTR_SWORD;
typedef T_SLONG  * PTR_SLONG;
typedef T_SLLONG * PTR_SLLONG;


/* Carrier of 8 bits */
typedef struct {
    unsigned int    bit0:1;
    unsigned int    bit1:1;
    unsigned int    bit2:1;
    unsigned int    bit3:1;
    unsigned int    bit4:1;
    unsigned int    bit5:1;
    unsigned int    bit6:1;
    unsigned int    bit7:1;
}T_BITFLD8;


/* Carrier of 16 bits */
typedef struct {
    unsigned int    bit0:1;
    unsigned int    bit1:1;
    unsigned int    bit2:1;
    unsigned int    bit3:1;
    unsigned int    bit4:1;
    unsigned int    bit5:1;
    unsigned int    bit6:1;
    unsigned int    bit7:1;
    unsigned int    bit8:1;
    unsigned int    bit9:1;
    unsigned int    bit10:1;
    unsigned int    bit11:1;
    unsigned int    bit12:1;
    unsigned int    bit13:1;
    unsigned int    bit14:1;
    unsigned int    bit15:1;
}T_BITFLD16;


/* Carrier of 32 bits */
typedef struct {
    unsigned int    bit0:1;
    unsigned int    bit1:1;
    unsigned int    bit2:1;
    unsigned int    bit3:1;
    unsigned int    bit4:1;
    unsigned int    bit5:1;
    unsigned int    bit6:1;
    unsigned int    bit7:1;
    unsigned int    bit8:1;
    unsigned int    bit9:1;
    unsigned int    bit10:1;
    unsigned int    bit11:1;
    unsigned int    bit12:1;
    unsigned int    bit13:1;
    unsigned int    bit14:1;
    unsigned int    bit15:1;
    unsigned int    bit16:1;
    unsigned int    bit17:1;
    unsigned int    bit18:1;
    unsigned int    bit19:1;
    unsigned int    bit20:1;
    unsigned int    bit21:1;
    unsigned int    bit22:1;
    unsigned int    bit23:1;
    unsigned int    bit24:1;
    unsigned int    bit25:1;
    unsigned int    bit26:1;
    unsigned int    bit27:1;
    unsigned int    bit28:1;
    unsigned int    bit29:1;
    unsigned int    bit30:1;
    unsigned int    bit31:1;
}T_BITFLD32;


/* Word with msb and lsb handling */
typedef union{
  T_UWORD   wo;
  struct{
    T_UBYTE lsb;
    T_UBYTE msb;
  }by;
}T_BYTEFLD;


/* Long with word and byte handling */
typedef union{
  T_ULONG lo;
  struct {
    T_UBYTE lowword_lsb;  	
    T_UBYTE lowword_msb;
    T_UBYTE highword_lsb;
    T_UBYTE highword_msb;
  } by;
  struct {
    T_UWORD lowword;
    T_UWORD highword;    
  } wo;
}T_BYTEFLD32;


/* Carrier of 8 bits with byte handling */
typedef union {
    T_UBYTE by;
    T_BITFLD8   bi;
}T_FLAG8;


/* Carrier of 16 bits with word or byte (msb & lsb) carrier handling */
typedef union {
    T_BYTEFLD cr;
    T_BITFLD16 bi;
}T_FLAG16;


/* Carrier of 32 bits with word or byte (msb & lsb) carrier handling */
typedef union {
    T_BYTEFLD32 cr;
    T_BITFLD32  bi;
}T_FLAG32;





/* Error code type definition */
typedef enum errorcodes {
    E_SWP_OK,
    E_ADC_BUSY,
    E_INVALID_EVENT, 
    E_EVENT_ALREADY_QUEUED,
    E_INVALID_TIMER, 
    E_TIMER_ALREADY_RUNNING,
    E_TIMER_ALREADY_STOPPED,
    E_EEP_BUSY,
    E_EEP_INIT_FAIL,
    E_EEP_COMP,
    E_EEP_ERROR,
    E_SPI_BUSY,
    E_SPI_NOK,
    E_ASC_BUSY,
    E_FORCE_MINDELAY,
    E_FORCE_MAXDELAY,
    E_INVALID_PARAMETER,
    E_SWP_LPM_TASK_ALREADY_STARTED,
    E_SWP_NOT_IN_LPM,
    E_SWP_LPM_INVALID_DELAY
}T_ERROR_CODE;



typedef const struct  {
  /* address of the register to check*/
  T_UBYTE *Address;
  /* compare's mask: bit's position = 1 >> bit is checked */
  T_UBYTE Mask;
  /* value : the compare's value for the check */
  T_UBYTE Value;
}T_RegisterCheck;

/* structure to define the register and the kind of test */
typedef const struct  {
  T_RegisterCheck *TableAddress;
  T_UBYTE Errorcode;
}T_TableCheck;


/* Macros definition */
#ifdef TRUE
    #undef TRUE
#endif
#ifdef FALSE
    #undef FALSE
#endif

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

#ifndef NULL
	#define NULL 0
#endif

/* Compiler customization */
///* Memory macros definition */
#define IRAM                             /* RAM declaration into internal RAM */
//
// 이상일 conflict with MCAL.h in Infineon #define NEAR                            /* RAM declaration into near RAM */
//
// 이상일 conflict with MCAL.h in Infineon #define FAR                               /* RAM declaration into near RAM */
//
#define PRIVATE_DATA static              /* static data definition */
//
#define PRIVATE_FCT static               /* private function definition */
//
#define NEAR_FCT                        /* near function definition */
//
#define FAR_FCT                           /* far function definition */
//
#define INLINE_FCT                       /* inline function definition */
//


/************************************** UBYTE ***************************************/
/* NEAR ubyte */
typedef T_UBYTE T_NEAR_UBYTE;
/* constant NEAR ubyte */
typedef const T_UBYTE T_CONST_NEAR_UBYTE;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UBYTE T_FAR_UBYTE;
#else
typedef T_UBYTE T_FAR_UBYTE;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UBYTE T_CONST_FAR_UBYTE;
#else
typedef const T_UBYTE T_CONST_FAR_UBYTE;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_UBYTE * T_NEAR_PTR_NEAR_UBYTE;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_UBYTE *__far T_NEAR_PTR_FAR_UBYTE;
#else
typedef T_UBYTE * T_NEAR_PTR_FAR_UBYTE;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UBYTE * T_FAR_PTR_NEAR_UBYTE;
#else
typedef T_UBYTE * T_FAR_PTR_NEAR_UBYTE;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UBYTE *__far T_FAR_PTR_FAR_UBYTE;
#else
typedef T_UBYTE * T_FAR_PTR_FAR_UBYTE;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_UBYTE * T_NEAR_PTR_CONST_NEAR_UBYTE;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UBYTE *__far T_NEAR_PTR_CONST_FAR_UBYTE;
#else
typedef const T_UBYTE * T_NEAR_PTR_CONST_FAR_UBYTE;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_UBYTE * T_FAR_PTR_CONST_NEAR_UBYTE;
#else
typedef const T_UBYTE * T_FAR_PTR_CONST_NEAR_UBYTE;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UBYTE *__far T_FAR_PTR_CONST_FAR_UBYTE;
#else
typedef __far const T_UBYTE * T_FAR_PTR_CONST_FAR_UBYTE;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UBYTE *__far T_FAR_PTR_CONST_FAR_UBYTE;
#else
typedef const T_UBYTE * T_FAR_PTR_CONST_FAR_UBYTE;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_UBYTE * const T_CONST_NEAR_PTR_NEAR_UBYTE;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_UBYTE * __far const T_CONST_NEAR_PTR_FAR_UBYTE;
#else
typedef T_UBYTE * const T_CONST_NEAR_PTR_FAR_UBYTE;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UBYTE * const T_CONST_FAR_PTR_NEAR_UBYTE;
#else
typedef T_UBYTE * const T_CONST_FAR_PTR_NEAR_UBYTE;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UBYTE * __far const  T_CONST_FAR_PTR_FAR_UBYTE;
#else
typedef T_UBYTE * __far const  T_CONST_FAR_PTR_FAR_UBYTE;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UBYTE * const  T_CONST_FAR_PTR_FAR_UBYTE;
#else
typedef T_UBYTE * const  T_CONST_FAR_PTR_FAR_UBYTE;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_UBYTE * const T_CONST_NEAR_PTR_CONST_NEAR_UBYTE;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UBYTE *__far const T_CONST_NEAR_PTR_CONST_FAR_UBYTE;
#else
typedef const T_UBYTE * const T_CONST_NEAR_PTR_CONST_FAR_UBYTE;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UBYTE * const T_CONST_FAR_PTR_CONST_NEAR_UBYTE;
#else
typedef const T_UBYTE * const T_CONST_FAR_PTR_CONST_NEAR_UBYTE;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UBYTE *__far const T_CONST_FAR_PTR_CONST_FAR_UBYTE;
#else
typedef const T_UBYTE * const T_CONST_FAR_PTR_CONST_FAR_UBYTE;
#endif


/************************************** SBYTE ***************************************/
/* NEAR ubyte */
typedef T_SBYTE T_NEAR_SBYTE;
/* constant NEAR ubyte */
typedef const T_SBYTE T_CONST_NEAR_SBYTE;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SBYTE T_FAR_SBYTE;
#else
typedef T_SBYTE T_FAR_SBYTE;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SBYTE T_CONST_FAR_SBYTE;
#else
typedef const T_SBYTE T_CONST_FAR_SBYTE;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_SBYTE * T_NEAR_PTR_NEAR_SBYTE;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SBYTE *__far T_NEAR_PTR_FAR_SBYTE;
#else
typedef T_SBYTE * T_NEAR_PTR_FAR_SBYTE;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SBYTE * T_FAR_PTR_NEAR_SBYTE;
#else
typedef T_SBYTE * T_FAR_PTR_NEAR_SBYTE;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SBYTE *__far T_FAR_PTR_FAR_SBYTE;
#else
typedef T_SBYTE * T_FAR_PTR_FAR_SBYTE;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_SBYTE * T_NEAR_PTR_CONST_NEAR_SBYTE;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SBYTE *__far T_NEAR_PTR_CONST_FAR_SBYTE;
#else
typedef const T_SBYTE * T_NEAR_PTR_CONST_FAR_SBYTE;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_SBYTE * T_FAR_PTR_CONST_NEAR_SBYTE;
#else
typedef const T_SBYTE * T_FAR_PTR_CONST_NEAR_SBYTE;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SBYTE *__far T_FAR_PTR_CONST_FAR_SBYTE;
#else
typedef __far const T_SBYTE * T_FAR_PTR_CONST_FAR_SBYTE;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SBYTE *__far T_FAR_PTR_CONST_FAR_SBYTE;
#else
typedef const T_SBYTE * T_FAR_PTR_CONST_FAR_SBYTE;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_SBYTE * const T_CONST_NEAR_PTR_NEAR_SBYTE;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SBYTE * __far const T_CONST_NEAR_PTR_FAR_SBYTE;
#else
typedef T_SBYTE * const T_CONST_NEAR_PTR_FAR_SBYTE;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SBYTE * const T_CONST_FAR_PTR_NEAR_SBYTE;
#else
typedef T_SBYTE * const T_CONST_FAR_PTR_NEAR_SBYTE;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SBYTE * __far const  T_CONST_FAR_PTR_FAR_SBYTE;
#else
typedef T_SBYTE * __far const  T_CONST_FAR_PTR_FAR_SBYTE;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SBYTE * const  T_CONST_FAR_PTR_FAR_SBYTE;
#else
typedef T_SBYTE * const  T_CONST_FAR_PTR_FAR_SBYTE;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_SBYTE * const T_CONST_NEAR_PTR_CONST_NEAR_SBYTE;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SBYTE *__far const T_CONST_NEAR_PTR_CONST_FAR_SBYTE;
#else
typedef const T_SBYTE * const T_CONST_NEAR_PTR_CONST_FAR_SBYTE;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SBYTE * const T_CONST_FAR_PTR_CONST_NEAR_SBYTE;
#else
typedef const T_SBYTE * const T_CONST_FAR_PTR_CONST_NEAR_SBYTE;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SBYTE *__far const T_CONST_FAR_PTR_CONST_FAR_SBYTE;
#else
typedef const T_SBYTE * const T_CONST_FAR_PTR_CONST_FAR_SBYTE;
#endif


/************************************** UWORD ***************************************/
/* NEAR ubyte */
typedef T_UWORD T_NEAR_UWORD;
/* constant NEAR ubyte */
typedef const T_UWORD T_CONST_NEAR_UWORD;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UWORD T_FAR_UWORD;
#else
typedef T_UWORD T_FAR_UWORD;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UWORD T_CONST_FAR_UWORD;
#else
typedef const T_UWORD T_CONST_FAR_UWORD;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_UWORD * T_NEAR_PTR_NEAR_UWORD;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_UWORD *__far T_NEAR_PTR_FAR_UWORD;
#else
typedef T_UWORD * T_NEAR_PTR_FAR_UWORD;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UWORD * T_FAR_PTR_NEAR_UWORD;
#else
typedef T_UWORD * T_FAR_PTR_NEAR_UWORD;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_UWORD *__far T_FAR_PTR_FAR_UWORD;
#else
typedef T_UWORD * T_FAR_PTR_FAR_UWORD;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_UWORD * T_NEAR_PTR_CONST_NEAR_UWORD;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UWORD *__far T_NEAR_PTR_CONST_FAR_UWORD;
#else
typedef const T_UWORD * T_NEAR_PTR_CONST_FAR_UWORD;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_UWORD * T_FAR_PTR_CONST_NEAR_UWORD;
#else
typedef const T_UWORD * T_FAR_PTR_CONST_NEAR_UWORD;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UWORD *__far T_FAR_PTR_CONST_FAR_UWORD;
#else
typedef __far const T_UWORD * T_FAR_PTR_CONST_FAR_UWORD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UWORD *__far T_FAR_PTR_CONST_FAR_UWORD;
#else
typedef const T_UWORD * T_FAR_PTR_CONST_FAR_UWORD;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_UWORD * const T_CONST_NEAR_PTR_NEAR_UWORD;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_UWORD * __far const T_CONST_NEAR_PTR_FAR_UWORD;
#else
typedef T_UWORD * const T_CONST_NEAR_PTR_FAR_UWORD;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UWORD * const T_CONST_FAR_PTR_NEAR_UWORD;
#else
typedef T_UWORD * const T_CONST_FAR_PTR_NEAR_UWORD;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UWORD * __far const  T_CONST_FAR_PTR_FAR_UWORD;
#else
typedef T_UWORD * __far const  T_CONST_FAR_PTR_FAR_UWORD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_UWORD * const  T_CONST_FAR_PTR_FAR_UWORD;
#else
typedef T_UWORD * const  T_CONST_FAR_PTR_FAR_UWORD;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_UWORD * const T_CONST_NEAR_PTR_CONST_NEAR_UWORD;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UWORD *__far const T_CONST_NEAR_PTR_CONST_FAR_UWORD;
#else
typedef const T_UWORD * const T_CONST_NEAR_PTR_CONST_FAR_UWORD;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_UWORD * const T_CONST_FAR_PTR_CONST_NEAR_UWORD;
#else
typedef const T_UWORD * const T_CONST_FAR_PTR_CONST_NEAR_UWORD;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_UWORD *__far const T_CONST_FAR_PTR_CONST_FAR_UWORD;
#else
typedef const T_UWORD * const T_CONST_FAR_PTR_CONST_FAR_UWORD;
#endif


/************************************** SWORD ***************************************/
/* NEAR ubyte */
typedef T_SWORD T_NEAR_SWORD;
/* constant NEAR ubyte */
typedef const T_SWORD T_CONST_NEAR_SWORD;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SWORD T_FAR_SWORD;
#else
typedef T_SWORD T_FAR_SWORD;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SWORD T_CONST_FAR_SWORD;
#else
typedef const T_SWORD T_CONST_FAR_SWORD;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_SWORD * T_NEAR_PTR_NEAR_SWORD;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SWORD *__far T_NEAR_PTR_FAR_SWORD;
#else
typedef T_SWORD * T_NEAR_PTR_FAR_SWORD;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SWORD * T_FAR_PTR_NEAR_SWORD;
#else
typedef T_SWORD * T_FAR_PTR_NEAR_SWORD;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SWORD *__far T_FAR_PTR_FAR_SWORD;
#else
typedef T_SWORD * T_FAR_PTR_FAR_SWORD;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_SWORD * T_NEAR_PTR_CONST_NEAR_SWORD;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SWORD *__far T_NEAR_PTR_CONST_FAR_SWORD;
#else
typedef const T_SWORD * T_NEAR_PTR_CONST_FAR_SWORD;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_SWORD * T_FAR_PTR_CONST_NEAR_SWORD;
#else
typedef const T_SWORD * T_FAR_PTR_CONST_NEAR_SWORD;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SWORD *__far T_FAR_PTR_CONST_FAR_SWORD;
#else
typedef __far const T_SWORD * T_FAR_PTR_CONST_FAR_SWORD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SWORD *__far T_FAR_PTR_CONST_FAR_SWORD;
#else
typedef const T_SWORD * T_FAR_PTR_CONST_FAR_SWORD;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_SWORD * const T_CONST_NEAR_PTR_NEAR_SWORD;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SWORD * __far const T_CONST_NEAR_PTR_FAR_SWORD;
#else
typedef T_SWORD * const T_CONST_NEAR_PTR_FAR_SWORD;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SWORD * const T_CONST_FAR_PTR_NEAR_SWORD;
#else
typedef T_SWORD * const T_CONST_FAR_PTR_NEAR_SWORD;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SWORD * __far const  T_CONST_FAR_PTR_FAR_SWORD;
#else
typedef T_SWORD * __far const  T_CONST_FAR_PTR_FAR_SWORD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SWORD * const  T_CONST_FAR_PTR_FAR_SWORD;
#else
typedef T_SWORD * const  T_CONST_FAR_PTR_FAR_SWORD;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_SWORD * const T_CONST_NEAR_PTR_CONST_NEAR_SWORD;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SWORD *__far const T_CONST_NEAR_PTR_CONST_FAR_SWORD;
#else
typedef const T_SWORD * const T_CONST_NEAR_PTR_CONST_FAR_SWORD;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SWORD * const T_CONST_FAR_PTR_CONST_NEAR_SWORD;
#else
typedef const T_SWORD * const T_CONST_FAR_PTR_CONST_NEAR_SWORD;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SWORD *__far const T_CONST_FAR_PTR_CONST_FAR_SWORD;
#else
typedef const T_SWORD * const T_CONST_FAR_PTR_CONST_FAR_SWORD;
#endif


/************************************** ULONG ***************************************/
/* NEAR ubyte */
typedef T_ULONG T_NEAR_ULONG;
/* constant NEAR ubyte */
typedef const T_ULONG T_CONST_NEAR_ULONG;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_ULONG T_FAR_ULONG;
#else
typedef T_ULONG T_FAR_ULONG;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_ULONG T_CONST_FAR_ULONG;
#else
typedef const T_ULONG T_CONST_FAR_ULONG;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_ULONG * T_NEAR_PTR_NEAR_ULONG;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_ULONG *__far T_NEAR_PTR_FAR_ULONG;
#else
typedef T_ULONG * T_NEAR_PTR_FAR_ULONG;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_ULONG * T_FAR_PTR_NEAR_ULONG;
#else
typedef T_ULONG * T_FAR_PTR_NEAR_ULONG;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_ULONG *__far T_FAR_PTR_FAR_ULONG;
#else
typedef T_ULONG * T_FAR_PTR_FAR_ULONG;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_ULONG * T_NEAR_PTR_CONST_NEAR_ULONG;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_ULONG *__far T_NEAR_PTR_CONST_FAR_ULONG;
#else
typedef const T_ULONG * T_NEAR_PTR_CONST_FAR_ULONG;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_ULONG * T_FAR_PTR_CONST_NEAR_ULONG;
#else
typedef const T_ULONG * T_FAR_PTR_CONST_NEAR_ULONG;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_ULONG *__far T_FAR_PTR_CONST_FAR_ULONG;
#else
typedef __far const T_ULONG * T_FAR_PTR_CONST_FAR_ULONG;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_ULONG *__far T_FAR_PTR_CONST_FAR_ULONG;
#else
typedef const T_ULONG * T_FAR_PTR_CONST_FAR_ULONG;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_ULONG * const T_CONST_NEAR_PTR_NEAR_ULONG;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_ULONG * __far const T_CONST_NEAR_PTR_FAR_ULONG;
#else
typedef T_ULONG * const T_CONST_NEAR_PTR_FAR_ULONG;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_ULONG * const T_CONST_FAR_PTR_NEAR_ULONG;
#else
typedef T_ULONG * const T_CONST_FAR_PTR_NEAR_ULONG;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_ULONG * __far const  T_CONST_FAR_PTR_FAR_ULONG;
#else
typedef T_ULONG * __far const  T_CONST_FAR_PTR_FAR_ULONG;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_ULONG * const  T_CONST_FAR_PTR_FAR_ULONG;
#else
typedef T_ULONG * const  T_CONST_FAR_PTR_FAR_ULONG;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_ULONG * const T_CONST_NEAR_PTR_CONST_NEAR_ULONG;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_ULONG *__far const T_CONST_NEAR_PTR_CONST_FAR_ULONG;
#else
typedef const T_ULONG * const T_CONST_NEAR_PTR_CONST_FAR_ULONG;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_ULONG * const T_CONST_FAR_PTR_CONST_NEAR_ULONG;
#else
typedef const T_ULONG * const T_CONST_FAR_PTR_CONST_NEAR_ULONG;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_ULONG *__far const T_CONST_FAR_PTR_CONST_FAR_ULONG;
#else
typedef const T_ULONG * const T_CONST_FAR_PTR_CONST_FAR_ULONG;
#endif


/************************************** SLONG ***************************************/
/* NEAR ubyte */
typedef T_SLONG T_NEAR_SLONG;
/* constant NEAR ubyte */
typedef const T_SLONG T_CONST_NEAR_SLONG;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SLONG T_FAR_SLONG;
#else
typedef T_SLONG T_FAR_SLONG;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SLONG T_CONST_FAR_SLONG;
#else
typedef const T_SLONG T_CONST_FAR_SLONG;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_SLONG * T_NEAR_PTR_NEAR_SLONG;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SLONG *__far T_NEAR_PTR_FAR_SLONG;
#else
typedef T_SLONG * T_NEAR_PTR_FAR_SLONG;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SLONG * T_FAR_PTR_NEAR_SLONG;
#else
typedef T_SLONG * T_FAR_PTR_NEAR_SLONG;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_SLONG *__far T_FAR_PTR_FAR_SLONG;
#else
typedef T_SLONG * T_FAR_PTR_FAR_SLONG;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_SLONG * T_NEAR_PTR_CONST_NEAR_SLONG;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SLONG *__far T_NEAR_PTR_CONST_FAR_SLONG;
#else
typedef const T_SLONG * T_NEAR_PTR_CONST_FAR_SLONG;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_SLONG * T_FAR_PTR_CONST_NEAR_SLONG;
#else
typedef const T_SLONG * T_FAR_PTR_CONST_NEAR_SLONG;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SLONG *__far T_FAR_PTR_CONST_FAR_SLONG;
#else
typedef __far const T_SLONG * T_FAR_PTR_CONST_FAR_SLONG;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SLONG *__far T_FAR_PTR_CONST_FAR_SLONG;
#else
typedef const T_SLONG * T_FAR_PTR_CONST_FAR_SLONG;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_SLONG * const T_CONST_NEAR_PTR_NEAR_SLONG;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_SLONG * __far const T_CONST_NEAR_PTR_FAR_SLONG;
#else
typedef T_SLONG * const T_CONST_NEAR_PTR_FAR_SLONG;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SLONG * const T_CONST_FAR_PTR_NEAR_SLONG;
#else
typedef T_SLONG * const T_CONST_FAR_PTR_NEAR_SLONG;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SLONG * __far const  T_CONST_FAR_PTR_FAR_SLONG;
#else
typedef T_SLONG * __far const  T_CONST_FAR_PTR_FAR_SLONG;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_SLONG * const  T_CONST_FAR_PTR_FAR_SLONG;
#else
typedef T_SLONG * const  T_CONST_FAR_PTR_FAR_SLONG;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_SLONG * const T_CONST_NEAR_PTR_CONST_NEAR_SLONG;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SLONG *__far const T_CONST_NEAR_PTR_CONST_FAR_SLONG;
#else
typedef const T_SLONG * const T_CONST_NEAR_PTR_CONST_FAR_SLONG;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_SLONG * const T_CONST_FAR_PTR_CONST_NEAR_SLONG;
#else
typedef const T_SLONG * const T_CONST_FAR_PTR_CONST_NEAR_SLONG;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_SLONG *__far const T_CONST_FAR_PTR_CONST_FAR_SLONG;
#else
typedef const T_SLONG * const T_CONST_FAR_PTR_CONST_FAR_SLONG;
#endif


/************************************** FLAG_ARRAY ***************************************/
/* NEAR ubyte */
typedef T_FLAG_ARRAY T_NEAR_FLAG_ARRAY;
/* constant NEAR ubyte */
typedef const T_FLAG_ARRAY T_CONST_NEAR_FLAG_ARRAY;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG_ARRAY T_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY T_FAR_FLAG_ARRAY;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG_ARRAY T_CONST_FAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY T_CONST_FAR_FLAG_ARRAY;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_FLAG_ARRAY * T_NEAR_PTR_NEAR_FLAG_ARRAY;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG_ARRAY *__far T_NEAR_PTR_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * T_NEAR_PTR_FAR_FLAG_ARRAY;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG_ARRAY * T_FAR_PTR_NEAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * T_FAR_PTR_NEAR_FLAG_ARRAY;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG_ARRAY *__far T_FAR_PTR_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * T_FAR_PTR_FAR_FLAG_ARRAY;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG_ARRAY * T_NEAR_PTR_CONST_NEAR_FLAG_ARRAY;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG_ARRAY *__far T_NEAR_PTR_CONST_FAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * T_NEAR_PTR_CONST_FAR_FLAG_ARRAY;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_FLAG_ARRAY * T_FAR_PTR_CONST_NEAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * T_FAR_PTR_CONST_NEAR_FLAG_ARRAY;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG_ARRAY *__far T_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#else
typedef __far const T_FLAG_ARRAY * T_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG_ARRAY *__far T_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * T_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_FLAG_ARRAY * const T_CONST_NEAR_PTR_NEAR_FLAG_ARRAY;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG_ARRAY * __far const T_CONST_NEAR_PTR_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * const T_CONST_NEAR_PTR_FAR_FLAG_ARRAY;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG_ARRAY * const T_CONST_FAR_PTR_NEAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * const T_CONST_FAR_PTR_NEAR_FLAG_ARRAY;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG_ARRAY * __far const  T_CONST_FAR_PTR_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * __far const  T_CONST_FAR_PTR_FAR_FLAG_ARRAY;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG_ARRAY * const  T_CONST_FAR_PTR_FAR_FLAG_ARRAY;
#else
typedef T_FLAG_ARRAY * const  T_CONST_FAR_PTR_FAR_FLAG_ARRAY;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG_ARRAY * const T_CONST_NEAR_PTR_CONST_NEAR_FLAG_ARRAY;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG_ARRAY *__far const T_CONST_NEAR_PTR_CONST_FAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * const T_CONST_NEAR_PTR_CONST_FAR_FLAG_ARRAY;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG_ARRAY * const T_CONST_FAR_PTR_CONST_NEAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * const T_CONST_FAR_PTR_CONST_NEAR_FLAG_ARRAY;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG_ARRAY *__far const T_CONST_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#else
typedef const T_FLAG_ARRAY * const T_CONST_FAR_PTR_CONST_FAR_FLAG_ARRAY;
#endif


/************************************** BITFLD8 ***************************************/
/* NEAR ubyte */
typedef T_BITFLD8 T_NEAR_BITFLD8;
/* constant NEAR ubyte */
typedef const T_BITFLD8 T_CONST_NEAR_BITFLD8;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD8 T_FAR_BITFLD8;
#else
typedef T_BITFLD8 T_FAR_BITFLD8;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD8 T_CONST_FAR_BITFLD8;
#else
typedef const T_BITFLD8 T_CONST_FAR_BITFLD8;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_BITFLD8 * T_NEAR_PTR_NEAR_BITFLD8;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD8 *__far T_NEAR_PTR_FAR_BITFLD8;
#else
typedef T_BITFLD8 * T_NEAR_PTR_FAR_BITFLD8;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD8 * T_FAR_PTR_NEAR_BITFLD8;
#else
typedef T_BITFLD8 * T_FAR_PTR_NEAR_BITFLD8;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD8 *__far T_FAR_PTR_FAR_BITFLD8;
#else
typedef T_BITFLD8 * T_FAR_PTR_FAR_BITFLD8;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD8 * T_NEAR_PTR_CONST_NEAR_BITFLD8;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD8 *__far T_NEAR_PTR_CONST_FAR_BITFLD8;
#else
typedef const T_BITFLD8 * T_NEAR_PTR_CONST_FAR_BITFLD8;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_BITFLD8 * T_FAR_PTR_CONST_NEAR_BITFLD8;
#else
typedef const T_BITFLD8 * T_FAR_PTR_CONST_NEAR_BITFLD8;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD8 *__far T_FAR_PTR_CONST_FAR_BITFLD8;
#else
typedef __far const T_BITFLD8 * T_FAR_PTR_CONST_FAR_BITFLD8;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD8 *__far T_FAR_PTR_CONST_FAR_BITFLD8;
#else
typedef const T_BITFLD8 * T_FAR_PTR_CONST_FAR_BITFLD8;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_BITFLD8 * const T_CONST_NEAR_PTR_NEAR_BITFLD8;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD8 * __far const T_CONST_NEAR_PTR_FAR_BITFLD8;
#else
typedef T_BITFLD8 * const T_CONST_NEAR_PTR_FAR_BITFLD8;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD8 * const T_CONST_FAR_PTR_NEAR_BITFLD8;
#else
typedef T_BITFLD8 * const T_CONST_FAR_PTR_NEAR_BITFLD8;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD8 * __far const  T_CONST_FAR_PTR_FAR_BITFLD8;
#else
typedef T_BITFLD8 * __far const  T_CONST_FAR_PTR_FAR_BITFLD8;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD8 * const  T_CONST_FAR_PTR_FAR_BITFLD8;
#else
typedef T_BITFLD8 * const  T_CONST_FAR_PTR_FAR_BITFLD8;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD8 * const T_CONST_NEAR_PTR_CONST_NEAR_BITFLD8;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD8 *__far const T_CONST_NEAR_PTR_CONST_FAR_BITFLD8;
#else
typedef const T_BITFLD8 * const T_CONST_NEAR_PTR_CONST_FAR_BITFLD8;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD8 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD8;
#else
typedef const T_BITFLD8 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD8;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD8 *__far const T_CONST_FAR_PTR_CONST_FAR_BITFLD8;
#else
typedef const T_BITFLD8 * const T_CONST_FAR_PTR_CONST_FAR_BITFLD8;
#endif


/************************************** BITFLD16 ***************************************/
/* NEAR ubyte */
typedef T_BITFLD16 T_NEAR_BITFLD16;
/* constant NEAR ubyte */
typedef const T_BITFLD16 T_CONST_NEAR_BITFLD16;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD16 T_FAR_BITFLD16;
#else
typedef T_BITFLD16 T_FAR_BITFLD16;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD16 T_CONST_FAR_BITFLD16;
#else
typedef const T_BITFLD16 T_CONST_FAR_BITFLD16;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_BITFLD16 * T_NEAR_PTR_NEAR_BITFLD16;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD16 *__far T_NEAR_PTR_FAR_BITFLD16;
#else
typedef T_BITFLD16 * T_NEAR_PTR_FAR_BITFLD16;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD16 * T_FAR_PTR_NEAR_BITFLD16;
#else
typedef T_BITFLD16 * T_FAR_PTR_NEAR_BITFLD16;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD16 *__far T_FAR_PTR_FAR_BITFLD16;
#else
typedef T_BITFLD16 * T_FAR_PTR_FAR_BITFLD16;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD16 * T_NEAR_PTR_CONST_NEAR_BITFLD16;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD16 *__far T_NEAR_PTR_CONST_FAR_BITFLD16;
#else
typedef const T_BITFLD16 * T_NEAR_PTR_CONST_FAR_BITFLD16;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_BITFLD16 * T_FAR_PTR_CONST_NEAR_BITFLD16;
#else
typedef const T_BITFLD16 * T_FAR_PTR_CONST_NEAR_BITFLD16;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD16 *__far T_FAR_PTR_CONST_FAR_BITFLD16;
#else
typedef __far const T_BITFLD16 * T_FAR_PTR_CONST_FAR_BITFLD16;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD16 *__far T_FAR_PTR_CONST_FAR_BITFLD16;
#else
typedef const T_BITFLD16 * T_FAR_PTR_CONST_FAR_BITFLD16;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_BITFLD16 * const T_CONST_NEAR_PTR_NEAR_BITFLD16;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD16 * __far const T_CONST_NEAR_PTR_FAR_BITFLD16;
#else
typedef T_BITFLD16 * const T_CONST_NEAR_PTR_FAR_BITFLD16;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD16 * const T_CONST_FAR_PTR_NEAR_BITFLD16;
#else
typedef T_BITFLD16 * const T_CONST_FAR_PTR_NEAR_BITFLD16;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD16 * __far const  T_CONST_FAR_PTR_FAR_BITFLD16;
#else
typedef T_BITFLD16 * __far const  T_CONST_FAR_PTR_FAR_BITFLD16;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD16 * const  T_CONST_FAR_PTR_FAR_BITFLD16;
#else
typedef T_BITFLD16 * const  T_CONST_FAR_PTR_FAR_BITFLD16;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD16 * const T_CONST_NEAR_PTR_CONST_NEAR_BITFLD16;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD16 *__far const T_CONST_NEAR_PTR_CONST_FAR_BITFLD16;
#else
typedef const T_BITFLD16 * const T_CONST_NEAR_PTR_CONST_FAR_BITFLD16;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD16 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD16;
#else
typedef const T_BITFLD16 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD16;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD16 *__far const T_CONST_FAR_PTR_CONST_FAR_BITFLD16;
#else
typedef const T_BITFLD16 * const T_CONST_FAR_PTR_CONST_FAR_BITFLD16;
#endif


/************************************** BITFLD32 ***************************************/
/* NEAR ubyte */
typedef T_BITFLD32 T_NEAR_BITFLD32;
/* constant NEAR ubyte */
typedef const T_BITFLD32 T_CONST_NEAR_BITFLD32;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD32 T_FAR_BITFLD32;
#else
typedef T_BITFLD32 T_FAR_BITFLD32;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD32 T_CONST_FAR_BITFLD32;
#else
typedef const T_BITFLD32 T_CONST_FAR_BITFLD32;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_BITFLD32 * T_NEAR_PTR_NEAR_BITFLD32;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD32 *__far T_NEAR_PTR_FAR_BITFLD32;
#else
typedef T_BITFLD32 * T_NEAR_PTR_FAR_BITFLD32;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD32 * T_FAR_PTR_NEAR_BITFLD32;
#else
typedef T_BITFLD32 * T_FAR_PTR_NEAR_BITFLD32;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BITFLD32 *__far T_FAR_PTR_FAR_BITFLD32;
#else
typedef T_BITFLD32 * T_FAR_PTR_FAR_BITFLD32;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD32 * T_NEAR_PTR_CONST_NEAR_BITFLD32;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD32 *__far T_NEAR_PTR_CONST_FAR_BITFLD32;
#else
typedef const T_BITFLD32 * T_NEAR_PTR_CONST_FAR_BITFLD32;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_BITFLD32 * T_FAR_PTR_CONST_NEAR_BITFLD32;
#else
typedef const T_BITFLD32 * T_FAR_PTR_CONST_NEAR_BITFLD32;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD32 *__far T_FAR_PTR_CONST_FAR_BITFLD32;
#else
typedef __far const T_BITFLD32 * T_FAR_PTR_CONST_FAR_BITFLD32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD32 *__far T_FAR_PTR_CONST_FAR_BITFLD32;
#else
typedef const T_BITFLD32 * T_FAR_PTR_CONST_FAR_BITFLD32;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_BITFLD32 * const T_CONST_NEAR_PTR_NEAR_BITFLD32;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BITFLD32 * __far const T_CONST_NEAR_PTR_FAR_BITFLD32;
#else
typedef T_BITFLD32 * const T_CONST_NEAR_PTR_FAR_BITFLD32;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD32 * const T_CONST_FAR_PTR_NEAR_BITFLD32;
#else
typedef T_BITFLD32 * const T_CONST_FAR_PTR_NEAR_BITFLD32;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD32 * __far const  T_CONST_FAR_PTR_FAR_BITFLD32;
#else
typedef T_BITFLD32 * __far const  T_CONST_FAR_PTR_FAR_BITFLD32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BITFLD32 * const  T_CONST_FAR_PTR_FAR_BITFLD32;
#else
typedef T_BITFLD32 * const  T_CONST_FAR_PTR_FAR_BITFLD32;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_BITFLD32 * const T_CONST_NEAR_PTR_CONST_NEAR_BITFLD32;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD32 *__far const T_CONST_NEAR_PTR_CONST_FAR_BITFLD32;
#else
typedef const T_BITFLD32 * const T_CONST_NEAR_PTR_CONST_FAR_BITFLD32;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BITFLD32 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD32;
#else
typedef const T_BITFLD32 * const T_CONST_FAR_PTR_CONST_NEAR_BITFLD32;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BITFLD32 *__far const T_CONST_FAR_PTR_CONST_FAR_BITFLD32;
#else
typedef const T_BITFLD32 * const T_CONST_FAR_PTR_CONST_FAR_BITFLD32;
#endif


/************************************** BYTEFLD ***************************************/
/* NEAR ubyte */
typedef T_BYTEFLD T_NEAR_BYTEFLD;
/* constant NEAR ubyte */
typedef const T_BYTEFLD T_CONST_NEAR_BYTEFLD;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD T_FAR_BYTEFLD;
#else
typedef T_BYTEFLD T_FAR_BYTEFLD;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD T_CONST_FAR_BYTEFLD;
#else
typedef const T_BYTEFLD T_CONST_FAR_BYTEFLD;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_BYTEFLD * T_NEAR_PTR_NEAR_BYTEFLD;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BYTEFLD *__far T_NEAR_PTR_FAR_BYTEFLD;
#else
typedef T_BYTEFLD * T_NEAR_PTR_FAR_BYTEFLD;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD * T_FAR_PTR_NEAR_BYTEFLD;
#else
typedef T_BYTEFLD * T_FAR_PTR_NEAR_BYTEFLD;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD *__far T_FAR_PTR_FAR_BYTEFLD;
#else
typedef T_BYTEFLD * T_FAR_PTR_FAR_BYTEFLD;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_BYTEFLD * T_NEAR_PTR_CONST_NEAR_BYTEFLD;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD *__far T_NEAR_PTR_CONST_FAR_BYTEFLD;
#else
typedef const T_BYTEFLD * T_NEAR_PTR_CONST_FAR_BYTEFLD;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_BYTEFLD * T_FAR_PTR_CONST_NEAR_BYTEFLD;
#else
typedef const T_BYTEFLD * T_FAR_PTR_CONST_NEAR_BYTEFLD;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD *__far T_FAR_PTR_CONST_FAR_BYTEFLD;
#else
typedef __far const T_BYTEFLD * T_FAR_PTR_CONST_FAR_BYTEFLD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD *__far T_FAR_PTR_CONST_FAR_BYTEFLD;
#else
typedef const T_BYTEFLD * T_FAR_PTR_CONST_FAR_BYTEFLD;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_BYTEFLD * const T_CONST_NEAR_PTR_NEAR_BYTEFLD;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BYTEFLD * __far const T_CONST_NEAR_PTR_FAR_BYTEFLD;
#else
typedef T_BYTEFLD * const T_CONST_NEAR_PTR_FAR_BYTEFLD;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD * const T_CONST_FAR_PTR_NEAR_BYTEFLD;
#else
typedef T_BYTEFLD * const T_CONST_FAR_PTR_NEAR_BYTEFLD;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD * __far const  T_CONST_FAR_PTR_FAR_BYTEFLD;
#else
typedef T_BYTEFLD * __far const  T_CONST_FAR_PTR_FAR_BYTEFLD;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD * const  T_CONST_FAR_PTR_FAR_BYTEFLD;
#else
typedef T_BYTEFLD * const  T_CONST_FAR_PTR_FAR_BYTEFLD;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_BYTEFLD * const T_CONST_NEAR_PTR_CONST_NEAR_BYTEFLD;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD *__far const T_CONST_NEAR_PTR_CONST_FAR_BYTEFLD;
#else
typedef const T_BYTEFLD * const T_CONST_NEAR_PTR_CONST_FAR_BYTEFLD;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD * const T_CONST_FAR_PTR_CONST_NEAR_BYTEFLD;
#else
typedef const T_BYTEFLD * const T_CONST_FAR_PTR_CONST_NEAR_BYTEFLD;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD *__far const T_CONST_FAR_PTR_CONST_FAR_BYTEFLD;
#else
typedef const T_BYTEFLD * const T_CONST_FAR_PTR_CONST_FAR_BYTEFLD;
#endif


/************************************** BYTEFLD32 ***************************************/
/* NEAR ubyte */
typedef T_BYTEFLD32 T_NEAR_BYTEFLD32;
/* constant NEAR ubyte */
typedef const T_BYTEFLD32 T_CONST_NEAR_BYTEFLD32;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD32 T_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 T_FAR_BYTEFLD32;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD32 T_CONST_FAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 T_CONST_FAR_BYTEFLD32;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_BYTEFLD32 * T_NEAR_PTR_NEAR_BYTEFLD32;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BYTEFLD32 *__far T_NEAR_PTR_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * T_NEAR_PTR_FAR_BYTEFLD32;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD32 * T_FAR_PTR_NEAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * T_FAR_PTR_NEAR_BYTEFLD32;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_BYTEFLD32 *__far T_FAR_PTR_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * T_FAR_PTR_FAR_BYTEFLD32;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_BYTEFLD32 * T_NEAR_PTR_CONST_NEAR_BYTEFLD32;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD32 *__far T_NEAR_PTR_CONST_FAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * T_NEAR_PTR_CONST_FAR_BYTEFLD32;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_BYTEFLD32 * T_FAR_PTR_CONST_NEAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * T_FAR_PTR_CONST_NEAR_BYTEFLD32;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD32 *__far T_FAR_PTR_CONST_FAR_BYTEFLD32;
#else
typedef __far const T_BYTEFLD32 * T_FAR_PTR_CONST_FAR_BYTEFLD32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD32 *__far T_FAR_PTR_CONST_FAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * T_FAR_PTR_CONST_FAR_BYTEFLD32;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_BYTEFLD32 * const T_CONST_NEAR_PTR_NEAR_BYTEFLD32;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_BYTEFLD32 * __far const T_CONST_NEAR_PTR_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * const T_CONST_NEAR_PTR_FAR_BYTEFLD32;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD32 * const T_CONST_FAR_PTR_NEAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * const T_CONST_FAR_PTR_NEAR_BYTEFLD32;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD32 * __far const  T_CONST_FAR_PTR_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * __far const  T_CONST_FAR_PTR_FAR_BYTEFLD32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_BYTEFLD32 * const  T_CONST_FAR_PTR_FAR_BYTEFLD32;
#else
typedef T_BYTEFLD32 * const  T_CONST_FAR_PTR_FAR_BYTEFLD32;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_BYTEFLD32 * const T_CONST_NEAR_PTR_CONST_NEAR_BYTEFLD32;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD32 *__far const T_CONST_NEAR_PTR_CONST_FAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * const T_CONST_NEAR_PTR_CONST_FAR_BYTEFLD32;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_BYTEFLD32 * const T_CONST_FAR_PTR_CONST_NEAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * const T_CONST_FAR_PTR_CONST_NEAR_BYTEFLD32;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_BYTEFLD32 *__far const T_CONST_FAR_PTR_CONST_FAR_BYTEFLD32;
#else
typedef const T_BYTEFLD32 * const T_CONST_FAR_PTR_CONST_FAR_BYTEFLD32;
#endif


/************************************** FLAG8 ***************************************/
/* NEAR ubyte */
typedef T_FLAG8 T_NEAR_FLAG8;
/* constant NEAR ubyte */
typedef const T_FLAG8 T_CONST_NEAR_FLAG8;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG8 T_FAR_FLAG8;
#else
typedef T_FLAG8 T_FAR_FLAG8;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG8 T_CONST_FAR_FLAG8;
#else
typedef const T_FLAG8 T_CONST_FAR_FLAG8;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_FLAG8 * T_NEAR_PTR_NEAR_FLAG8;
/* NEAR pointer to FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
typedef T_FLAG8 *__far T_NEAR_PTR_FAR_FLAG8;
#else
typedef T_FLAG8 * T_NEAR_PTR_FAR_FLAG8;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG8 * T_FAR_PTR_NEAR_FLAG8;
#else
typedef T_FLAG8 * T_FAR_PTR_NEAR_FLAG8;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG8 *__far T_FAR_PTR_FAR_FLAG8;
#else
typedef T_FLAG8 * T_FAR_PTR_FAR_FLAG8;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG8 * T_NEAR_PTR_CONST_NEAR_FLAG8;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG8 *__far T_NEAR_PTR_CONST_FAR_FLAG8;
#else
typedef const T_FLAG8 * T_NEAR_PTR_CONST_FAR_FLAG8;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_FLAG8 * T_FAR_PTR_CONST_NEAR_FLAG8;
#else
typedef const T_FLAG8 * T_FAR_PTR_CONST_NEAR_FLAG8;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG8 *__far T_FAR_PTR_CONST_FAR_FLAG8;
#else
typedef __far const T_FLAG8 * T_FAR_PTR_CONST_FAR_FLAG8;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG8 *__far T_FAR_PTR_CONST_FAR_FLAG8;
#else
typedef const T_FLAG8 * T_FAR_PTR_CONST_FAR_FLAG8;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_FLAG8 * const T_CONST_NEAR_PTR_NEAR_FLAG8;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG8 * __far const T_CONST_NEAR_PTR_FAR_FLAG8;
#else
typedef T_FLAG8 * const T_CONST_NEAR_PTR_FAR_FLAG8;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG8 * const T_CONST_FAR_PTR_NEAR_FLAG8;
#else
typedef T_FLAG8 * const T_CONST_FAR_PTR_NEAR_FLAG8;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG8 * __far const  T_CONST_FAR_PTR_FAR_FLAG8;
#else
typedef T_FLAG8 * __far const  T_CONST_FAR_PTR_FAR_FLAG8;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG8 * const  T_CONST_FAR_PTR_FAR_FLAG8;
#else
typedef T_FLAG8 * const  T_CONST_FAR_PTR_FAR_FLAG8;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG8 * const T_CONST_NEAR_PTR_CONST_NEAR_FLAG8;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG8 *__far const T_CONST_NEAR_PTR_CONST_FAR_FLAG8;
#else
typedef const T_FLAG8 * const T_CONST_NEAR_PTR_CONST_FAR_FLAG8;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG8 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG8;
#else
typedef const T_FLAG8 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG8;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG8 *__far const T_CONST_FAR_PTR_CONST_FAR_FLAG8;
#else
typedef const T_FLAG8 * const T_CONST_FAR_PTR_CONST_FAR_FLAG8;
#endif


/************************************** FLAG16 ***************************************/
/* NEAR ubyte */
typedef T_FLAG16 T_NEAR_FLAG16;
/* constant NEAR ubyte */
typedef const T_FLAG16 T_CONST_NEAR_FLAG16;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG16 T_FAR_FLAG16;
#else
typedef T_FLAG16 T_FAR_FLAG16;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG16 T_CONST_FAR_FLAG16;
#else
typedef const T_FLAG16 T_CONST_FAR_FLAG16;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_FLAG16 * T_NEAR_PTR_NEAR_FLAG16;
/* NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG16 *__far T_NEAR_PTR_FAR_FLAG16;
#else
typedef T_FLAG16 * T_NEAR_PTR_FAR_FLAG16;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG16 * T_FAR_PTR_NEAR_FLAG16;
#else
typedef T_FLAG16 * T_FAR_PTR_NEAR_FLAG16;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG16 *__far T_FAR_PTR_FAR_FLAG16;
#else
typedef T_FLAG16 * T_FAR_PTR_FAR_FLAG16;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG16 * T_NEAR_PTR_CONST_NEAR_FLAG16;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG16 *__far T_NEAR_PTR_CONST_FAR_FLAG16;
#else
typedef const T_FLAG16 * T_NEAR_PTR_CONST_FAR_FLAG16;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_FLAG16 * T_FAR_PTR_CONST_NEAR_FLAG16;
#else
typedef const T_FLAG16 * T_FAR_PTR_CONST_NEAR_FLAG16;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG16 *__far T_FAR_PTR_CONST_FAR_FLAG16;
#else
typedef __far const T_FLAG16 * T_FAR_PTR_CONST_FAR_FLAG16;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG16 *__far T_FAR_PTR_CONST_FAR_FLAG16;
#else
typedef const T_FLAG16 * T_FAR_PTR_CONST_FAR_FLAG16;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_FLAG16 * const T_CONST_NEAR_PTR_NEAR_FLAG16;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG16 * __far const T_CONST_NEAR_PTR_FAR_FLAG16;
#else
typedef T_FLAG16 * const T_CONST_NEAR_PTR_FAR_FLAG16;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG16 * const T_CONST_FAR_PTR_NEAR_FLAG16;
#else
typedef T_FLAG16 * const T_CONST_FAR_PTR_NEAR_FLAG16;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG16 * __far const  T_CONST_FAR_PTR_FAR_FLAG16;
#else
typedef T_FLAG16 * __far const  T_CONST_FAR_PTR_FAR_FLAG16;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG16 * const  T_CONST_FAR_PTR_FAR_FLAG16;
#else
typedef T_FLAG16 * const  T_CONST_FAR_PTR_FAR_FLAG16;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG16 * const T_CONST_NEAR_PTR_CONST_NEAR_FLAG16;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG16 *__far const T_CONST_NEAR_PTR_CONST_FAR_FLAG16;
#else
typedef const T_FLAG16 * const T_CONST_NEAR_PTR_CONST_FAR_FLAG16;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG16 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG16;
#else
typedef const T_FLAG16 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG16;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG16 *__far const T_CONST_FAR_PTR_CONST_FAR_FLAG16;
#else
typedef const T_FLAG16 * const T_CONST_FAR_PTR_CONST_FAR_FLAG16;
#endif


/************************************** FLAG32 ***************************************/
/* NEAR ubyte */
typedef T_FLAG32 T_NEAR_FLAG32;
/* constant NEAR ubyte */
typedef const T_FLAG32 T_CONST_NEAR_FLAG32;
/* FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG32 T_FAR_FLAG32;
#else
typedef T_FLAG32 T_FAR_FLAG32;
#endif
/* constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG32 T_CONST_FAR_FLAG32;
#else
typedef const T_FLAG32 T_CONST_FAR_FLAG32;
#endif

/* NEAR pointer to NEAR ubyte */
typedef T_FLAG32 * T_NEAR_PTR_NEAR_FLAG32;
/* NEAR pointer to FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
typedef T_FLAG32 *__far T_NEAR_PTR_FAR_FLAG32;
#else
typedef T_FLAG32 * T_NEAR_PTR_FAR_FLAG32;
#endif
/* FAR pointer to NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG32 * T_FAR_PTR_NEAR_FLAG32;
#else
typedef T_FLAG32 * T_FAR_PTR_NEAR_FLAG32;
#endif
/* FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far T_FLAG32 *__far T_FAR_PTR_FAR_FLAG32;
#else
typedef T_FLAG32 * T_FAR_PTR_FAR_FLAG32;
#endif


/* NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG32 * T_NEAR_PTR_CONST_NEAR_FLAG32;
/* NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG32 *__far T_NEAR_PTR_CONST_FAR_FLAG32;
#else
typedef const T_FLAG32 * T_NEAR_PTR_CONST_FAR_FLAG32;
#endif
/* FAR pointer to constant NEAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef __far const T_FLAG32 * T_FAR_PTR_CONST_NEAR_FLAG32;
#else
typedef const T_FLAG32 * T_FAR_PTR_CONST_NEAR_FLAG32;
#endif
/* FAR pointer to constant FAR ubyte */
#if (defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR))
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG32 *__far T_FAR_PTR_CONST_FAR_FLAG32;
#else
typedef __far const T_FLAG32 * T_FAR_PTR_CONST_FAR_FLAG32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG32 *__far T_FAR_PTR_CONST_FAR_FLAG32;
#else
typedef const T_FLAG32 * T_FAR_PTR_CONST_FAR_FLAG32;
#endif
#endif

/* constant NEAR pointer to NEAR ubyte */
typedef T_FLAG32 * const T_CONST_NEAR_PTR_NEAR_FLAG32;
/* constant NEAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
typedef T_FLAG32 * __far const T_CONST_NEAR_PTR_FAR_FLAG32;
#else
typedef T_FLAG32 * const T_CONST_NEAR_PTR_FAR_FLAG32;
#endif
/* constant FAR pointer to NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG32 * const T_CONST_FAR_PTR_NEAR_FLAG32;
#else
typedef T_FLAG32 * const T_CONST_FAR_PTR_NEAR_FLAG32;
#endif
/* constant FAR pointer to FAR ubyte */
#if defined(USED_RAM_SIZE_12K_NEAR) || defined(USED_RAM_SIZE_8K_NEAR)|| defined(USED_RAM_SIZE_FAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG32 * __far const  T_CONST_FAR_PTR_FAR_FLAG32;
#else
typedef T_FLAG32 * __far const  T_CONST_FAR_PTR_FAR_FLAG32;
#endif
#elif defined(USED_RAM_SIZE_ALL_NEAR)
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far T_FLAG32 * const  T_CONST_FAR_PTR_FAR_FLAG32;
#else
typedef T_FLAG32 * const  T_CONST_FAR_PTR_FAR_FLAG32;
#endif
#endif

/* constant NEAR pointer to constant NEAR ubyte */
typedef const T_FLAG32 * const T_CONST_NEAR_PTR_CONST_NEAR_FLAG32;
/* constant NEAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG32 *__far const T_CONST_NEAR_PTR_CONST_FAR_FLAG32;
#else
typedef const T_FLAG32 * const T_CONST_NEAR_PTR_CONST_FAR_FLAG32;
#endif
/* constant FAR pointer to constant NEAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef const T_FLAG32 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG32;
#else
typedef const T_FLAG32 * const T_CONST_FAR_PTR_CONST_NEAR_FLAG32;
#endif
/* constant FAR pointer to constant FAR ubyte */
#if defined(BNK_ROM_USED_FOR_DATA)
typedef __far const T_FLAG32 *__far const T_CONST_FAR_PTR_CONST_FAR_FLAG32;
#else
typedef const T_FLAG32 * const T_CONST_FAR_PTR_CONST_FAR_FLAG32;
#endif


#endif
