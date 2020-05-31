#include <linux/init.h>
#include <linux/module.h>
#include <hal_module_pub.h>
#include <ctor_hal_module_pub.h>
MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorHalModuleCreateHandle);
EXPORT_SYMBOL(CtorHalModuleDestroyHandle);

static int OsalCtorHalInit(void)
{
        printk(KERN_ALERT "Hello, OSAL CTOR HAL\n");
        return 0;
}

static void OsalCtorHalExit(void)
{
        printk(KERN_ALERT "Goodbye, CTOR HAL\n");
}

module_init(OsalCtorHalInit);
module_exit(OsalCtorHalExit);
