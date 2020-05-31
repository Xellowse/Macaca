#include <linux/init.h>
#include <linux/module.h>
#include <hal_module2_pub.h>
#include <hal_module2.h>

extern int HalModule2Init(void *handle);
extern int HalModule2Deinit(void *handle);
extern int HalModule2Enable(void *handle);
extern int HalModule2Disable(void *handle);
extern int HalModule2CbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2);
extern HalModule2S32 HalModule2ISRCbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2);

EXPORT_SYMBOL(HalModule2Init);
EXPORT_SYMBOL(HalModule2Deinit);
EXPORT_SYMBOL(HalModule2Enable);
EXPORT_SYMBOL(HalModule2Disable);
EXPORT_SYMBOL(HalModule2CbMethod);
EXPORT_SYMBOL(HalModule2ISRCbMethod);

MODULE_LICENSE("Dual BSD/GPL");


static int OsalHalModule2Init(void)
{
    printk(KERN_ALERT "Hello, Module2 HAL\n");
    return 0;
}

static void OsalHalModule2Exit(void)
{
    printk(KERN_ALERT "Goodbye, Module2 HAL\n");
}

module_init(OsalHalModule2Init);
module_exit(OsalHalModule2Exit);
