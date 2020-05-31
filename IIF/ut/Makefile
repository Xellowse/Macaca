CC = gcc
ccflags-y += -I ${UTPUB} \
             -I ${IIFPUB} \
             -I ${CTORIIFPUB}

LIB_OUT_PATH = ../../lib
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out
IIF_PATH=..

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


ut_iif-objs      := ${IIF_PATH}/ut/src/ut_iif.o \
                    ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ut_iif.o
obj-m := ut_iif.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	make -C ${KERNEL_PATH} M=${PWD} UTPUB=${PWD}/../../UT/pub \
                                        IIFPUB=${PWD}/../pub \
                                        CTORIIFPUB=${PWD}/../ctor/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp ut_iif.ko ${LIB_OUT_PATH}
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
	rm -rf ${LIB_OUT_PATH}/ut_iif.ko
	rm -rf ${LIB_OUT_PATH}/ut_iif.so
