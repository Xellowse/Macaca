CC = gcc
ccflags-y += -I ${UTPUB} \
             -I ${OSALPUB} \
             -I ${CTOROSALPUB}

LIB_OUT_PATH = ../lib
OSAL_PATH = ../OSAL
OUTPUT_PATH=./out
UT_PATH=.

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


ut_all-objs      := ${UT_PATH}/src/ut_all.o \
                    ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ut_all.o
obj-m := ut_all.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	cp ${LIB_OUT_PATH}/*.ko ./
	make -C ${KERNEL_PATH} M=${PWD} UTPUB=${PWD}/pub \
                                        OSALPUB=${PWD}/../OSAL/pub \
                                        CTOROSALPUB=${PWD}/../OSAL/ctor/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
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
