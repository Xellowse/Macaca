#include <linux/init.h>
#include <linux/module.h>
#include <hal_module2_pub.h>
#include <ctor_hal_module2_pub.h>
MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorHalModule2CreateHandle);
EXPORT_SYMBOL(CtorHalModule2DestroyHandle);

static int OsalCtorHalModule2Init(void)
{
        printk(KERN_ALERT "Hello, CTOR HAL Module2\n");
        return 0;
}

static void OsalCtorHalModule2Exit(void)
{
        printk(KERN_ALERT "Goodbye, CTOR HAL Module2\n");
}

module_init(OsalCtorHalModule2Init);
module_exit(OsalCtorHalModule2Exit);
