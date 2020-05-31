CC = gcc
ccflags-y += -I ${UTPUB} \
             -I ${HWPUB} \
             -I ${HWINC} \
             -I ${OSALPUB} \
             -I ${CTORHWPUB}

LIB_OUT_PATH = ../../../../lib
OSAL_PATH = ../../../../OSAL
OUTPUT_PATH=./out
HW_PATH=../

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


ut_hw_module2-objs  := ${HW_PATH}/ut/src/ut_hw_module2.o \
                       ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ut_hw_module2.o
obj-m := ut_hw_module2.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	make -C ${KERNEL_PATH} M=${PWD} UTPUB=${PWD}/../../../../UT/pub \
                                        HWPUB=${PWD}/../pub \
                                        HWINC=${PWD}/../inc \
                                        OSALPUB=${PWD}/../../../../OSAL/pub \
                                        CTORHWPUB=${PWD}/../ctor/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp ut_hw_module2.ko ${LIB_OUT_PATH}
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
	rm -rf ${LIB_OUT_PATH}/ut_hw_module2.ko
	rm -rf ${LIB_OUT_PATH}/ut_hw_module2.so
