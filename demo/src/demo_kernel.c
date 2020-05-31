/////////////////////////////////////////////////////////////////////////////////
//
// File name: Macaca/demo/demo_kernel.c
// This demo is the Linux kernel space version's demonstration of how module's HAL work.
// It include 2 modules' communication mechanism.
//////////////////////////////////////////////////////////////////////////////////

#include <linux/init.h>
#include <linux/module.h>
#include <hal_module_pub.h>
#include <hal_module2_pub.h>
#include <ctor_hal_module_pub.h>
#include <ctor_hal_module2_pub.h>

MODULE_LICENSE("Dual BSD/GPL");

extern CtorHalModuleS32 CtorHalModuleCreateHandle(HalModuleHandle **handle);
extern CtorHalModule2S32 CtorHalModule2CreateHandle(HalModule2Handle **handle);
extern CtorHalModuleS32 CtorHalModuleDestroyHandle(HalModuleHandle *handle);
extern CtorHalModule2S32 CtorHalModule2DestroyHandle(HalModule2Handle *handle);

HalModuleHandle  *hal_module1_handle;
HalModule2Handle *hal_module2_handle;

static int DemoInit(void)
{

        printk(KERN_ALERT "Hello, Demo\n");

        CtorHalModuleCreateHandle(&hal_module1_handle);
        CtorHalModule2CreateHandle(&hal_module2_handle);

        hal_module1_handle->HalModuleInit(hal_module1_handle->fd);
        hal_module2_handle->HalModule2Init(hal_module2_handle->fd);

        hal_module1_handle->HalModuleRegisterHalCbMethod1(hal_module1_handle->fd, hal_module2_handle->fd, hal_module2_handle->HalModule2CbMethod);
        hal_module1_handle->HalModuleMethod1(hal_module1_handle->fd);

        hal_module1_handle->HalModuleRegisterISRCbMethod(hal_module1_handle->fd, hal_module2_handle->fd, hal_module2_handle->HalModule2ISRCbMethod);

        return 0;
}

static void DemoExit(void)
{
        hal_module1_handle->HalModuleDeinit(hal_module1_handle->fd);
        hal_module2_handle->HalModule2Deinit(hal_module2_handle->fd);
        CtorHalModuleDestroyHandle(hal_module1_handle);
        CtorHalModule2DestroyHandle(hal_module2_handle);

        printk(KERN_ALERT "Goodbye, Demo\n");
}

module_init(DemoInit);
module_exit(DemoExit);
