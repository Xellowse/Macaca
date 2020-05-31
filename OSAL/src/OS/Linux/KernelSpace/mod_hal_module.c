#include <linux/init.h>
#include <linux/module.h>
#include <hal_module_pub.h>
#include <hal_module.h>

extern int HalModuleInit(void *handle);
extern int HalModuleDeinit(void *handle);
extern int HalModuleEnable(void *handle);
extern int HalModuleDisable(void *handle);
extern int HalModuleRegisterHalCbMethod1(void *handle, void *CbMethodHandle,int (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));
extern int HalModuleMethod1(void *handle);
extern HalModuleS32 HalModuleRegisterISRCbMethod(void *handle, void *CalleeCB, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));

MODULE_LICENSE("Dual BSD/GPL");

EXPORT_SYMBOL(HalModuleInit);
EXPORT_SYMBOL(HalModuleDeinit);
EXPORT_SYMBOL(HalModuleEnable);
EXPORT_SYMBOL(HalModuleDisable);
EXPORT_SYMBOL(HalModuleMethod1);
EXPORT_SYMBOL(HalModuleRegisterHalCbMethod1);
EXPORT_SYMBOL(HalModuleRegisterISRCbMethod);

static int OsalHalInit(void)
{
        printk(KERN_ALERT "Hello, HAL\n");
        return 0;
}

static void OsalHalExit(void)
{
        printk(KERN_ALERT "Goodbye, HAL\n");
}

module_init(OsalHalInit);
module_exit(OsalHalExit);
