#ifndef __ADV_SEED_KEY_H__
#define __ADV_SEED_KEY_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char BYTE;
/* already declared in Platform_Types.h */
#if 0
typedef unsigned short uint16;
typedef unsigned char uint8;
#endif
typedef enum{
    SEEDKEY_SUCCESS = 0,
    SEEDKEY_FAIL = 1,
} SEEDKEY_RT;

#ifndef VERSION_INFO_AVAILABLE
#define VERSION_INFO_AVAILABLE
#endif

typedef struct {
    uint16 vendorID;
    uint16 moduleID;
    uint8 majorVersion;
    uint8 minorVersion;
    uint8 patchVersion;
} VERSION_INFO;

SEEDKEY_RT ASK_KeyGenerate(const BYTE *seed_buffer_8byte, BYTE *key_buffer_8byte);
SEEDKEY_RT ASK_Rand8ByteGenerate(BYTE *seed_buffer_8byte);
void ASK_RandInit(unsigned long rand_seed);
void vGetVersionInfo(VERSION_INFO *pVersionInfo);

#ifdef __cplusplus
};
#endif
#endif
