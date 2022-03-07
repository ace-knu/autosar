/**************************************************************************************
* 
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc. 
*   All other product or service names are the property of their respective owners. 
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
* 
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation 
*      thereof.
*
*  Description:  Green Hills linker command file for AUTOSAR OS sample application
*
**************************************************************************************/
DEFAULTS
{
    BOOT_STACK_SIZE = 0x150   /* 336 bytes for common stack */   
    STARTUP_COMMAND = 0x10
    BOOT_STACK_BASE = 0x40013FFF - BOOT_STACK_SIZE - STARTUP_COMMAND        /* 80k RAM - 5606B */
    /* BOOT_STACK_BASE = 0x4000FFFF - BOOT_STACK_SIZE - STARTUP_COMMAND */  /* 64k RAM - 5605B */ /* 5607B RM 61page Table 3-1 */
}
MEMORY
{
    /* 5602B - Flash 256 KB - 0x00 - 0x3FFFF */
    /* 5603B - Flash 384 KB - 0x00 - 0x5FFFF */
    /* 5604B - Flash 512 KB - 0x00 - 0x7FFFF */
    /* 5605B - Flash 768 KB - 0x00 - 0xBFFFF */
    /* 5606B - Flash 1024 KB - 0x00 - 0xFFFFF */
    /* 5607B - Flash 1536 KB - 0x00 - 0x17FFFF */

    rchwarea            : org = 0x00000000, len = 0x00000008

    /* 5602B BxLL, BxLQ - SRAM 24 KB : 0x40000000 - 0x40005FFF */
    /* 5602B CxLL       - SRAM 32 KB : 0x40000000 - 0x40007FFF */
    /* 5603B BxLL, BxLQ - SRAM 28 KB : 0x40000000 - 0x40006FFF */
    /* 5603B CxLL       - SRAM 40 KB : 0x40000000 - 0x40009FFF */
    /* 5604B BxLL, BxLQ - SRAM 32 KB : 0x40000000 - 0x40007FFF */
    /* 5604B BxMG, CxLL - SRAM 48 KB : 0x40000000 - 0x4000BFFF */
    /* 5605B BxLL, BxLQ - SRAM 64 KB : 0x40000000 - 0x4000FFFF */
    /* 5606B BxLL, BxLQ - SRAM 80 KB : 0x40000000 - 0x40013FFF */
    /* 5607B BxLL, BxLQ - SRAM 96 KB : 0x40000000 - 0x40017FFF */
    
    /* The memory areas for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */ 
    /* The end of the memory areas for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
}

SECTIONS
{
    .rchwdata                       : > rchwarea

    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    .osbegincode  ALIGN(0x20)       : > OsInternalROM
    .VT_VECT_TBL         0x00001000 : > .
    
    .vects        ALIGN(4K)         : > .  

    .vletext                        : > .
    .ostext                         : > .
    .oshook                         : > .
    .osrodata                       : > .
    .syscall                        : > .
    .secinfo                        : > .
    .rodata       ALIGN(32)         :{*(".rodata.*")} > .
    .sdata2                         : > .
    .ossrodata                      : > .
    .sapp_c32                       : > .
    .sapp_c16                       : > .
    .sapp_cU                        : > .
    .sapp_c8                        : > .
    .text         ALIGN(32)         :{*(".text.*")} > .
    .appcode                        : > .
    .mcal_text                      : > . /* MCAL */
    .fixaddr                        : > . /* MCAL */
    .fixtype                        : > . /* MCAL */
    /* Make section .data be burned into flash. It will be copied into RAM during startup */
    .ROM.ramcode          ROM(.ramcode) ALIGN(0x20) : > . /* MCAL */
    .ROM.PPC.EMB.sdata0   ROM(.PPC.EMB.sdata0) ALIGN(0x20): > . /* MCAL */
    .ROM.sdata            ROM(.sdata) : > . /* MCAL */
    .ROM.data             ROM(.data) ALIGN(0x8)  : > .
    .ROM.mcal_data        ROM(.mcal_data) : > . /* MCAL */
    .mcal_const_cfg                 : > . /* MCAL */
    .mcal_const                     : > . /* MCAL */
    .osendcode                      : > .

    .ramcode                    ABS ALIGN(0x20) : > OsInternalRAM  /* MCAL : nedded to placing func in RAM */
    .PPC.EMB.sdata0             ABS ALIGN(0x20) : > .          /* MCAL */
    .PPC.EMB.sbss0        CLEAR ABS : > .          /* MCAL */

    /* OS stack area. This section shall be placed before application data area */
    .osstack      ALIGN(0x20)       : > .

    /* Begin of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
    /* End of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

    /* Begin of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */ 
    /* End of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

    /* Begin of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */ 
    /* End of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

    /* Default data/bss */
    .data         ALIGN(32)         :{*(".data.*")} > .
    .osdata                         : > .
    .mcal_data                      : > . /* MCAL */

    /* Default sdata threshold is 0, so sdata/sbss section are empty always. */
    .sdabase      ALIGN(0x8)        : > .  
    .sdata                          : > .
    .sapp_v32_data                  : > .
    .sapp_v16_data                  : > .
    .sapp_vU_data                   : > .
    .sapp_v8_data                   : > .
    .niapp_v16_bss NOCLEAR             : > .  /* EOL */    
    /* BSS sections */
    .sbss                           : > .
    .ossbss       CLEAR             : > .
    .sapp_v32_bss CLEAR             : > .
    .sapp_v16_bss CLEAR             : > .
    .sapp_vU_bss  CLEAR             : > .
    .sapp_v8_bss  CLEAR             : > .

    .osbss        CLEAR             : > . 
    .bss_noclear  NOCLEAR           :{*(".bss.*NO_INIT*")
                                      *(".bss.*SAVED_ZONE*")} > .
    .bss                            :{*(".bss.*")} > .
    .mcal_bss                       : > . /* MCAL */

    .stack        ALIGN(16) PAD(4K) : > .
    .heap         ALIGN(16)         : > .   
    
    .ASW_IDENT           0x00001010 : > .
    .ASW_SECURITY_KEY    0x000010C0 : > .

    _stack_addr  = addr(.stack)+sizeof(.stack);
    _stack_end   = addr(.stack);

    OS_MAIN_TOS   = _stack_addr;
    OS_MAIN_BOS   = _stack_end;

    _heap_addr   = addr(.heap);
    _heap_end    = addr(.heap)+sizeof(.heap);
    
    /* Total RAM size = Os_RamEnd - Os_RamStart + 1
    /* RAM size should be multiples of 64byte */
    Os_RamStart  = addr(OsInternalRAM);
    Os_RamEnd    = endaddr(OsInternalRAM);
    
}
