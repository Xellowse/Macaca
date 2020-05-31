#include <ut_pub.h>
#include <osal_pub.h>
#include <ctor_osal_pub.h>

//ut_all_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_all_version="sv#ut_all_ver:1.0.0";

extern UtResult UtIifWholeTest(void);
extern UtResult UtHalModuleWholeTest(void);
extern UtResult UtHalModule2WholeTest(void);
extern UtResult UtHwModuleWholeTest(void);
extern UtResult UtHwModule2WholeTest(void);
extern UtResult UtOsalWholeTest(void);


UtU32 UtUTAll(void){

  UtResult iif_result;
  UtResult hal_module_result;
  UtResult hal_module2_result;
  UtResult hw_module_result;
  UtResult hw_module2_result;
  UtResult osal_result;

  OsalHandle        *osal_handle;

  CtorOsalCreateHandle(&osal_handle);

  osal_handle->OsalPrint("------------- IIF UT begin ----------\n");
  iif_result         = UtIifWholeTest();
  osal_handle->OsalPrint("------------- HAL Module UT begin ----------\n");
  hal_module_result  = UtHalModuleWholeTest();
  osal_handle->OsalPrint("------------- HW Module UT begin ----------\n");
  hw_module_result  = UtHwModuleWholeTest();
  osal_handle->OsalPrint("------------- HAL Module2 UT begin ----------\n");
  hal_module2_result = UtHalModule2WholeTest();
  osal_handle->OsalPrint("------------- HW Module2 UT begin ----------\n");
  hw_module2_result = UtHwModule2WholeTest();
  osal_handle->OsalPrint("------------- OSAL UT begin ----------\n");
  osal_result        = UtOsalWholeTest();

  osal_handle->OsalPrint("\n=============== UT Result =============\n");
  osal_handle->OsalPrint("IIF         ng/total : %d/%d\n",iif_result.ng_num,iif_result.total_num);
  osal_handle->OsalPrint("HAL Module  ng/total : %d/%d\n",hal_module_result.ng_num,hal_module_result.total_num);
  osal_handle->OsalPrint("HW Module   ng/total : %d/%d\n",hw_module_result.ng_num,hw_module_result.total_num);
  osal_handle->OsalPrint("HAL Module2 ng/total : %d/%d\n",hal_module2_result.ng_num,hal_module2_result.total_num);
  osal_handle->OsalPrint("HW Module2  ng/total : %d/%d\n",hw_module2_result.ng_num,hw_module2_result.total_num);
  osal_handle->OsalPrint("OSAL        ng/total : %d/%d\n",osal_result.ng_num,osal_result.total_num);

  if(iif_result.ng_num)
    return -1;
  else if(hal_module_result.ng_num)
    return -1;
  else if(hal_module2_result.ng_num)
    return -1;
  else if(osal_result.ng_num > 2) //Tolerance for 1. ISR and 2. IRQ handler registration on Linux userspace
    return -1;
  else
    return 0;

}
