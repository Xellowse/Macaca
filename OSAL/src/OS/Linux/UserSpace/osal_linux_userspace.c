/////////////////////////////////////////////////////////////////////////////////
//
// File name: OSAL/OS/Linux/UserSpace/osal_linux_userspace.c
// Operating System Abstraction Layer of Linux User Space is implement here.
// Such like printf, malloc, etc.
//
/////////////////////////////////////////////////////////////////////////////////

#include <osal_pub.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

//osal_linux_userspace_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *osal_linux_userspace_version="sv#osal_linux_userspace_ver:1.0.0";

//----------------------------------------------------------------------------
//Function Name: OsalOpen
//Description  : none.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : OSAL_LAYER_TRUE
//----------------------------------------------------------------------------
int OsalOpen(){


  return OSAL_LAYER_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: OsalClose
//Description  : none.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : OSAL_LAYER_TRUE
//----------------------------------------------------------------------------
int OsalClose(){

  return OSAL_LAYER_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: OsalPrint
//Description  : Print method just like GNU LibC's prinf
//Param        :
//      1. const char * format : string usage is like printf.
//      2. none
//      3. none
//return value : If success, the total number of characters written is returned.
//               If error, negative number returned.
//----------------------------------------------------------------------------
OsalS32 OsalPrint( const char * format, ... ){

  OsalS32 ret;

  ret=(OsalS32)printf(format);

  return ret;
}

//----------------------------------------------------------------------------
//Function Name: OsalMalloc
//Description  : Memory allocation just like GNC LibC's calloc.
//Param        :
//      1. OsalS32 size: Size of the memory(Byte).
//      2. none
//      3. none
//return value : Pointer of memory which allocated.
//----------------------------------------------------------------------------
void* OsalMalloc(OsalS32 size){

  return calloc(size,1);
}

//----------------------------------------------------------------------------
//Function Name: OsalRegisterIRQCallBackFnc
//Description  : This is a null function because of linux userspace is no ISR feature.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : OSAL_LAYER_FALSE
//----------------------------------------------------------------------------
OsalS32 OsalRegisterIRQCallBackFnc(OsalS32 IrqNum, void* IrqHandler, OsalS32 IrqFlag, const char* IrqName, void* arg){

  /* Null, linux user space can not using irq*/

  return OSAL_LAYER_FALSE;
}

//----------------------------------------------------------------------------
//Function Name: OsalUnRegisterIRQCallBackFnc
//Description  : This is a null function because of linux userspace is no ISR feature.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : none
//----------------------------------------------------------------------------
void OsalUnRegisterIRQCallBackFnc(OsalS32 IrqNum, void* arg){
  /* Null, linux user space can not using irq*/

  return;
}

//----------------------------------------------------------------------------
//Function Name: OsalFree
//Description  : Free the memory which allocated.
//Param        :
//      1. void *addr: Pointer of memory which allocated.
//      2. none
//      3. none
//return value : none
//----------------------------------------------------------------------------
void OsalFree(void *addr){

  free(addr);
  return;
}

//----------------------------------------------------------------------------
//Function Name: OsalMsleep
//Description  : Sleep for milliseconds
//Param        :
//      1. OsalS32 msec: milliseconds to sleep
//      2. none
//      3. none
//return value : return 0 is success, -1 is fail.
//----------------------------------------------------------------------------
OsalS32 OsalMsleep(OsalS32 msec){

  return usleep(1000*msec);
}
