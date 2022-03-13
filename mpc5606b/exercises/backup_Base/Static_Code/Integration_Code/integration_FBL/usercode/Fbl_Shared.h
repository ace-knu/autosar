/*
 *  Fbl_Shared.h
 *
 *  Created on: 2016. 5. 3.
 *      Author: 1000064
 */
#ifndef FBL_SHARED_H
#define FBL_SHARED_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"
#include "zbbswmap.h" /* For START_BOOT */

#define FAR_DATA_REF 

 /* ========================================================= */
 /* typedefs required by the BBAIFT and the                   */
 /* referenced functions                                      */
 /* This structure is used to provide cryptographic library interfaces */
#define PUB_EXP_LEN               4U
#define PUB_MODULUS_LEN         256U

/** Type for callback function */
typedef void (*EscCallbackFunc)(void);

typedef struct {
    uint8  aubExp[PUB_EXP_LEN];
    uint8  aubModulus[PUB_MODULUS_LEN];
} T_SERVER_PUBKEY;

 typedef struct {
    uint32  ubPubkeylen;
    uint8* aubPubkey;
 } T_SECURITY_PUBKEY;
 
 /* T_BAIFT_TESTADDR: describe an area for the CRC check */
 typedef struct 
  {
  uint32 cul_StartAddr;
  uint32 cul_EndAddr;
  } T_BAIFT_TESTADDR;

 /* T_BAIFT_CRC: Contains the CRC and all the data needed to */
 /* check it                                                 */
 typedef struct 
  {
  uint16 cuw_CrcValue;
  uint16 cuw_NumberOfCrcAreas;
  T_BAIFT_TESTADDR cs_Area[2];  /* The size of this structure is not relevant.   */
                                /* The real size is given by cuw_NumberOfCrcAreas */
  } T_BAIFT_CRC;
 /* This structure is used to provide usefull informations */
 /* related to every SW module in the ECU                  */

 typedef struct 
 {
   const uint32                    ul_StartAddress;       /* Address of the first byte of the Area            */
   const uint32                    ul_EndAddress;         /* Address of the last byte of the Area             */
   const void                      *pv_SKAddress;          /* Address of the Security Key of the Area (if any) */
   const void                      *pv_IdentificationArea; /* Address of the Identification (if any)           */
   const T_BAIFT_CRC               *ps_CRCArea;	           /* Address of the CRC structure (if any)            */
   const uint8                    ub_LogicalIdentifier;  /* Logical identifier                               */
   const uint8                    ub_AccessType;		   /* Access restrictions                              */
 } T_BAIFT_SOFTWARE_MODULE;

 /* T_BAIFT: The table from which the exported functions & structures */
 /* are available.                                                    */
 /* All pointers to data or functions of the FBL are NEAR pointers    */
 /* because the FBL is stored in a non-paged area                     */
 typedef struct 
  {
  const uint16                   *pcauw_CRCA001_8;       /* Pointer to the Siemens CRC16 algorithm table */
  const T_BAIFT_SOFTWARE_MODULE   *pcs_SwMap;	          /* Pointer to the SW mapping Table */
  const uint8                   cub_NumberOfSwModules;  /* Number of entries in pcs_SwMap */
  const uint8                   *pcs_Pubkey;
  } T_BAIFT;


/* Define a reference to the BAIFT structure in the Boot area  */

 /* Macro to access the structure */
 /*lint --e{923} suppress "cast from to unsigned long to pointer"*/
 /* The BAIFT can be found in the FBL area at address 0xFEA0     */
 /* This must be consistent with the declaration of the section  */
 /* SEC_BOOT_BAIFT in the locate file of the FBL                      */
#if (START_BOOT == 0x00000000UL)                 /* FBL in 1st sector */
 #define cas_FBL_BAIFT  *((T_BAIFT *)0x00000028UL)
#elif (START_BOOT == 0x00008000UL)               /* FBL in 2nd sector */
 #define cas_FBL_BAIFT  *((T_BAIFT *)0x00008028UL)
#else
 #error "Undefined BOOT Start Address, One of 0x00000000 or 0x00008000"
#endif

#endif /* FBL_SHARED_H */
