CC = gcc
ccflags-y += -I ${HALINC} \
             -I ${HALINC2} \
             -I ${HALPUB} \
             -I ${HALPUB2} \
             -I ${OSALINC} \
             -I ${OSALPUB} \
             -I ${CTORPUB} \
             -I ${CTORPUB2} \
             -I ${IIFPUB} \
             -I ${IIFINC}

LIB_OUT_PATH = ../lib
HW_MODULE_PATH = ../Module/HW/HW_1
HAL_MODULE_PATH = ../Module/HAL
HW_MODULE2_PATH = ../Module2/HW
HAL_MODULE2_PATH = ../Module2/HAL
CTOR_MODULE_PATH = ../Module/CTOR
CTOR_MODULE2_PATH = ../Module2/CTOR

OSAL_PATH = ../OSAL
OUTPUT_PATH=./out
IIF_PATH=.

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


iif-objs           := ${IIF_PATH}/src/iif.o \
                      ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_iif.o
obj-m := iif.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	mkdir -p ${OUTPUT_PATH}
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../Module/HAL/inc \
                                        HALINC2=${PWD}/../Module2/HAL/inc \
                                        HALPUB=${PWD}/../Module/HAL/pub \
                                        HALPUB2=${PWD}/../Module2/HAL/pub \
                                        OSALINC=${PWD}/../OSAL/inc  \
                                        OSALPUB=${PWD}/../OSAL/pub \
                                        CTORPUB=${PWD}/../Module/CTOR/pub \
                                        CTORPUB2=${PWD}/../Module2/CTOR/pub \
                                        IIFPUB=${PWD}/../IIF/pub \
                                        IIFINC=${PWD}/../IIF/inc \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp iif.ko ${LIB_OUT_PATH}
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
	rm -rf ${LIB_OUT_PATH}/iif.ko
