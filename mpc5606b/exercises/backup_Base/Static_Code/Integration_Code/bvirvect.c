#define OS_ASM_ALIGN_INTCVEC      .align 4

void VirtualVectorTable(void);
#if defined(OSCWPPC)
extern void _start(void);
#endif

#if defined(OSGHSPPC)
#pragma ghs section text=".VT_VECT_TBL"
#elif defined(OSCWPPC)
#pragma push
#pragma section code_type ".VT_VECT_TBL"
#endif

/* This table is located at a fixed address to handle it from Boot SW */

void VirtualVectorTable(void)
{
#if defined(OSGHSPPC)
#pragma asm
#elif defined(OSCWPPC)
  asm
  {
#endif
      OS_ASM_ALIGN_INTCVEC
      e_b _start
#if defined(OSGHSPPC)
#pragma endasm
#elif defined(OSCWPPC)
  }
#endif
}

#if defined(OSCWPPC)
#pragma pop
#endif
