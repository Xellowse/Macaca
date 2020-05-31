
HW_MODULE_PATH = ./Module/HW/HW_1
HAL_MODULE_PATH = ./Module/HAL
CTOR_HAL_MODULE_PATH = ./Module/HAL/ctor
CTOR_HW_MODULE_PATH = ./Module/HW/HW_1/ctor

OSAL_PATH = ./OSAL
OSAL_U_PATH=./OSAL/OS/Linux/UserSpace
OSAL_K_PATH=./OSAL/OS/Linux/KernelSpace
CTOR_OSAL_PATH = ./OSAL/ctor

HW_MODULE2_PATH = ./Module2/HW/HW_1
HAL_MODULE2_PATH = ./Module2/HAL
CTOR_HAL_MODULE2_PATH = ./Module2/HAL/ctor
CTOR_HW_MODULE2_PATH = ./Module2/HW/HW_1/ctor

CTOR_IIF_PATH = ./IIF/ctor
IIF_PATH = ./IIF
UT_IIF_PATH = ./IIF/ut

UT_HAL_MODULE_PATH = ./Module/HAL/ut
UT_HW_MODULE_PATH = ./Module/HW/HW_1/ut
UT_HAL_MODULE2_PATH = ./Module2/HAL/ut
UT_HW_MODULE2_PATH = ./Module2/HW/HW_1/ut
UT_OSAL_PATH = ./OSAL/ut
UT_PATH = ./UT

LIB_OUT_PATH = ./lib

all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"
linux_u:
	make linux_u -C ${OSAL_PATH}
	make linux_u -C ${CTOR_OSAL_PATH}
	make linux_u -C ${HAL_MODULE_PATH}
	make linux_u -C ${HAL_MODULE2_PATH}
	make linux_u -C ${HW_MODULE_PATH}
	make linux_u -C ${HW_MODULE2_PATH}
	make linux_u -C ${CTOR_HW_MODULE_PATH}
	make linux_u -C ${CTOR_HAL_MODULE_PATH}
	make linux_u -C ${CTOR_HW_MODULE2_PATH}
	make linux_u -C ${CTOR_HAL_MODULE2_PATH}
	make linux_u -C ${IIF_PATH}
	make linux_u -C ${CTOR_IIF_PATH}
	make linux_u -C ${UT_IIF_PATH}
	make linux_u -C ${UT_HAL_MODULE_PATH}
	make linux_u -C ${UT_HW_MODULE_PATH}
	make linux_u -C ${UT_HAL_MODULE2_PATH}
	make linux_u -C ${UT_HW_MODULE2_PATH}
	make linux_u -C ${UT_OSAL_PATH}
	make linux_u -C ${UT_PATH}
linux_k:
	make linux_k -C ${OSAL_PATH}
	make linux_k -C ${CTOR_OSAL_PATH}
	make linux_k -C ${HAL_MODULE_PATH}
	make linux_k -C ${HAL_MODULE2_PATH}
	make linux_k -C ${HW_MODULE_PATH}
	make linux_k -C ${HW_MODULE2_PATH}
	make linux_k -C ${CTOR_HAL_MODULE_PATH}
	make linux_k -C ${CTOR_HAL_MODULE2_PATH}
	make linux_k -C ${CTOR_HW_MODULE_PATH}
	make linux_k -C ${CTOR_HW_MODULE2_PATH}
	make linux_k -C ${IIF_PATH}
	make linux_k -C ${CTOR_IIF_PATH}
	make linux_k -C ${UT_IIF_PATH}
	make linux_k -C ${UT_HAL_MODULE_PATH}
	make linux_k -C ${UT_HW_MODULE_PATH}
	make linux_k -C ${UT_HAL_MODULE2_PATH}
	make linux_k -C ${UT_HW_MODULE2_PATH}
	make linux_k -C ${UT_OSAL_PATH}
	make linux_k -C ${UT_PATH}
clean:
	make clean -C ${OSAL_PATH}
	make clean -C ${CTOR_OSAL_PATH}
	make clean -C ${CTOR_OSAL_PATH}
	make clean -C ${HAL_MODULE_PATH}
	make clean -C ${HAL_MODULE2_PATH}
	make clean -C ${CTOR_HAL_MODULE_PATH}
	make clean -C ${CTOR_HW_MODULE_PATH}
	make clean -C ${CTOR_HAL_MODULE2_PATH}
	make clean -C ${CTOR_HW_MODULE2_PATH}
	make clean -C ${CTOR_IIF_PATH}
	make clean -C ${HW_MODULE_PATH}
	make clean -C ${HW_MODULE2_PATH}
	make clean -C ${IIF_PATH}
	make clean -C ${UT_IIF_PATH}
	make clean -C ${UT_HAL_MODULE_PATH}
	make clean -C ${UT_HW_MODULE_PATH}
	make clean -C ${UT_HAL_MODULE2_PATH}
	make clean -C ${UT_HW_MODULE2_PATH}
	make clean -C ${UT_PATH}
	make clean -C ${UT_OSAL_PATH}
	rm -rf ${LIB_OUT_PATH}
