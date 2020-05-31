#include <linux/init.h>
#include <linux/module.h>
#include <hw_module_pub.h>

extern void HwModuleInit(void *handle);
extern void HwModuleDeinit(void *handle);
extern void HwModuleEnable(void *handle);
extern void HwModuleDisable(void *handle);
extern void HwModuleMethod1(void *handle, HwModuleS32 param1, HwModuleS32 param2);
extern HwModuleS32 HwModuleRegisterISRCbMethod(void *handle, void *CalleeHandle, HwModuleS32 (*CbMethod)(void *handle, HwModuleS32 param1, HwModuleS32 param2));


MODULE_LICENSE("Dual BSD/GPL");

EXPORT_SYMBOL(HwModuleInit);
EXPORT_SYMBOL(HwModuleDeinit);
EXPORT_SYMBOL(HwModuleEnable);
EXPORT_SYMBOL(HwModuleDisable);
EXPORT_SYMBOL(HwModuleMethod1);
EXPORT_SYMBOL(HwModuleRegisterISRCbMethod);

static int OsalHwInit(void)
{
    printk(KERN_ALERT "Hello, HAL\n");
    return 0;
}

static void OsalHwExit(void)
{
    printk(KERN_ALERT "Goodbye, HAL\n");
}

module_init(OsalHwInit);
module_exit(OsalHwExit);
