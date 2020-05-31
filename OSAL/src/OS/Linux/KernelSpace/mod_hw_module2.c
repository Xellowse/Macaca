#include <linux/init.h>
#include <linux/module.h>
#include <hw_module2_pub.h>

extern void HwModule2Init(void *handle);
extern void HwModule2Deinit(void *handle);
extern void HwModule2Enable(void *handle);
extern void HwModule2Disable(void *handle);
extern void HwModule2Method1(void *handle, HwModule2S32 param1, HwModule2S32 param2);
extern HwModule2S32 HwModule2RegisterISRCbMethod(void *handle, void *CalleeHandle, HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2));


MODULE_LICENSE("Dual BSD/GPL");

EXPORT_SYMBOL(HwModule2Init);
EXPORT_SYMBOL(HwModule2Deinit);
EXPORT_SYMBOL(HwModule2Enable);
EXPORT_SYMBOL(HwModule2Disable);
EXPORT_SYMBOL(HwModule2Method1);
EXPORT_SYMBOL(HwModule2RegisterISRCbMethod);

static int OsalHwModule2Init(void)
{
    printk(KERN_ALERT "Hello, HW Module2\n");
    return 0;
}

static void OsalHwModule2Exit(void)
{
    printk(KERN_ALERT "Goodbye, HW Module2\n");
}

module_init(OsalHwModule2Init);
module_exit(OsalHwModule2Exit);
