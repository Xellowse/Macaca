CC = gcc
ccflags-y += -I ${UTPUB} \
             -I ${HALINC} \
             -I ${HALPUB} \
             -I ${HWPUB} \
             -I ${OSALPUB} \
             -I ${CTORHALPUB}

LIB_OUT_PATH = ../../../lib
OSAL_PATH = ../../../OSAL
OUTPUT_PATH=./out
HAL_PATH=../

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


ut_hal_module2-objs  := ${HAL_PATH}/ut/src/ut_hal_module2.o \
                        ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ut_hal_module2.o
obj-m := ut_hal_module2.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	make -C ${KERNEL_PATH} M=${PWD} UTPUB=${PWD}/../../../UT/pub \
                                        HALPUB=${PWD}/../pub \
                                        HALINC=${PWD}/../inc \
                                        HWPUB=${PWD}/../../HW/HW_1/pub \
                                        OSALPUB=${PWD}/../../../OSAL/pub \
                                        CTORHALPUB=${PWD}/../ctor/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp ut_hal_module2.ko ${LIB_OUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}


clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf .*.cmd
	rm -rf ./src/*.o
	rm -rf ./src/.*.cmd
	rm -rf .cache.mk
	rm -rf .tmp_versions
	rm -rf ${LIB_OUT_PATH}/ut_hal_module2.ko
	rm -rf ${LIB_OUT_PATH}/ut_hal_module2.so
