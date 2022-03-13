/*
 * exception
 *
 *  Created on: 2014. 6. 5.
 *      Author: 1000059
 */

#ifndef EXCEPTION_
#define EXCEPTION_



#endif /* EXCEPTION_ */


extern void OSDataStorageException (void);
#if defined(OSCWPPC)
extern void Os_DataStorageException (void);
extern void Os_MachineCheckException(void);
#endif
