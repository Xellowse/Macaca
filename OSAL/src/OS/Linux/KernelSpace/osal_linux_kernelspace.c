/////////////////////////////////////////////////////////////////////////////////
//
// File name: OSAL/OS/Linux/KernelSpace/osal_linux_kernelspace.c
// Operating System Abstraction Layer of Linux Kernel Space is implement here.
// Such like printk, irq_request, etc.
//
/////////////////////////////////////////////////////////////////////////////////

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>       /* printk() */
#include <linux/slab.h>         /* kmalloc() */
#include <linux/interrupt.h>    /* request_irq()*/
#include <linux/string.h>       /* memset() */
#include <linux/delay.h>        /* msleep() */
#include <osal_pub.h>
#include <osal.h>

//osal_linux_kernelspace_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *osal_linux_kernelspace_version="sv#osal_linux_kernelspace_ver:1.0.0";

//----------------------------------------------------------------------------
//Function Name: OsalIsr
//Description  : Implement your OSAL ISR here. This function is the entry of every
//               IRQ. Each HW's ISR will be accessed by parameter "void *handle".
//
//Param        :
//      1. int irq : IRQ number.
//      2. void *handle : Each ISR's private data. Each HW's ISR entry should be
//                        assigned to this parameter.
//      3. none
//return value : IRQ_HANDLED
//----------------------------------------------------------------------------
irqreturn_t OsalIsr(int irq, void *handle){

  OsalPrivateData *osal_fd = (OsalPrivateData *)handle;

  osal_fd->IsrMethod();

  return IRQ_HANDLED;
}

//----------------------------------------------------------------------------
//Function Name: OsalOpen
//Description  : none.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : OSAL_LAYER_TRUE
//----------------------------------------------------------------------------
int OsalOpen(void){


  return OSAL_LAYER_TRUE;
}
EXPORT_SYMBOL(OsalOpen);

//----------------------------------------------------------------------------
//Function Name: OsalClose
//Description  : none.
//Param        :
//      1. none
//      2. none
//      3. none
//return value : OSAL_LAYER_TRUE
//----------------------------------------------------------------------------
int OsalClose(void){

  return OSAL_LAYER_TRUE;
}
EXPORT_SYMBOL(OsalClose);

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

  ret=(OsalS32)printk(format);

  return ret;
}
EXPORT_SYMBOL(OsalPrint);

//----------------------------------------------------------------------------
//Function Name: OsalMalloc
//Description  : Memory allocation. In this case is allocate virtually contiguous memory,
//               and then initialize it to 0.
//Param        :
//      1. OsalS32 size: Size of the memory(Byte).
//      2. none
//      3. none
//return value : Pointer of memory which allocated.
//----------------------------------------------------------------------------
void* OsalMalloc(OsalS32 size){

  void *addr;

  addr = vmalloc(size);
  memset(addr,0,size);

  return addr;
}
EXPORT_SYMBOL(OsalMalloc);

//----------------------------------------------------------------------------
//Function Name: OsalRegisterIRQCallBackFnc
//Description  : This function is used to ISR registration.
//Param        :
//      1. OsalS32 IrqNum      : IRQ number.
//      2. void* IrqHandler    : Entry of ISR.
//      3. OsalS32 IrqFlag     : IRQ flag, in this case is hard code to IRQF_SHARED.
//      4. const char* IrqName : String of ISR's name.
//      5. void* handle        : ISR's private data.
//return value : If success return 0. If not, return error code.
//----------------------------------------------------------------------------
OsalS32 OsalRegisterIRQCallBackFnc(OsalS32 IrqNum, void* IrqHandler, OsalS32 IrqFlag, const char* IrqName, void* handle){

  OsalPrivateData *osal_fd = (OsalPrivateData *)handle;
  OsalS32 ret=0;

  osal_fd->IsrMethod = IrqHandler;
  ret = (OsalS32) request_irq(IrqNum, (irq_handler_t) OsalIsr, IRQF_SHARED, IrqName, (void *)handle); //force to use IRQF_SHARED for default

  return ret;
}
EXPORT_SYMBOL(OsalRegisterIRQCallBackFnc);

//----------------------------------------------------------------------------
//Function Name: OsalUnRegisterIRQCallBackFnc
//Description  : This function is used to ISR unregistration.
//Param        :
//      1. OsalS32 IrqNum      : IRQ number.
//      2. void* handle        : ISR's private data.
//return value : none
//----------------------------------------------------------------------------
void OsalUnRegisterIRQCallBackFnc(OsalS32 IrqNum, void* handle){

  free_irq(IrqNum, (void *)(handle));
  return;
}
EXPORT_SYMBOL(OsalUnRegisterIRQCallBackFnc);

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

  vfree(addr);
  return;
}
EXPORT_SYMBOL(OsalFree);

//----------------------------------------------------------------------------
//Function Name: OsalMsleep
//Description  : Sleep for milliseconds
//Param        :
//      1. OsalS32 msec: milliseconds  to sleep
//      2. none
//      3. none
//return value : return 0 is success, -1 is fail.
//----------------------------------------------------------------------------
OsalS32 OsalMsleep(OsalS32 msec){

  msleep(msec);

  return OSAL_LAYER_TRUE;
}
EXPORT_SYMBOL(OsalMsleep);
