/////////////////////////////////////////////////////////////////////////////////
//
// File name: Macaca/demo/demo.c
// This demo is the demonstration of how module's HAL work. It include 2 modules'
// communication mechanism.
//////////////////////////////////////////////////////////////////////////////////

#include <hal_module_pub.h>
#include <ctor_hal_module_pub.h>
#include <hal_module2_pub.h>
#include <ctor_hal_module2_pub.h>

int main(){

  HalModuleHandle  *hal_module1_handle;
  HalModule2Handle *hal_module2_handle;

  CtorHalModuleCreateHandle(&hal_module1_handle);
  CtorHalModule2CreateHandle(&hal_module2_handle);

  hal_module1_handle->HalModuleInit(hal_module1_handle->fd);
  hal_module2_handle->HalModule2Init(hal_module2_handle->fd);

  hal_module1_handle->HalModuleRegisterHalCbMethod1(hal_module1_handle->fd, hal_module2_handle->fd, hal_module2_handle->HalModule2CbMethod); //Register Module2's call back into Module1
  hal_module1_handle->HalModuleMethod1(hal_module1_handle->fd); //Module 1 will call Module2's call back function for validate 2 modules's communication feature

  hal_module1_handle->HalModuleDeinit(hal_module1_handle->fd);
  hal_module2_handle->HalModule2Deinit(hal_module2_handle->fd);

  CtorHalModuleDestroyHandle(hal_module1_handle);
  CtorHalModule2DestroyHandle(hal_module2_handle);

  return 0;
}
