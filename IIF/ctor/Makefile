CC = gcc
ccflags-y += -I ${HALINC} \
             -I ${HALINC2} \
             -I ${HALPUB} \
             -I ${HALPUB2} \
             -I ${OSALINC} \
             -I ${OSALPUB} \
             -I ${CTOROSALPUB} \
             -I ${CTORHALPUB} \
             -I ${CTORHALMODULE2PUB} \
             -I ${IIFPUB} \
             -I ${IIFINC} \
             -I ${CTORIIFPUB}

LIB_OUT_PATH = ../../lib
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out
IIF_PATH=..

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

ctor_iif-objs           := ${IIF_PATH}/ctor/src/ctor_iif.o \
                           ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ctor_iif.o
ctor_iif_single-objs    := ${IIF_PATH}/ctor/src/ctor_iif_single.o \
                           ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ctor_iif.o
obj-m := ctor_iif.o ctor_iif_single.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../../Module/HAL/inc \
                                        HALINC2=${PWD}/../../Module2/HAL/inc \
                                        HALPUB=${PWD}/../../Module/HAL/pub \
                                        HALPUB2=${PWD}/../../Module2/HAL/pub \
                                        OSALINC=${PWD}/../../OSAL/inc  \
                                        OSALPUB=${PWD}/../../OSAL/pub \
                                        CTOROSALPUB=${PWD}/../../OSAL/ctor/pub \
                                        CTORHALPUB=${PWD}/../../Module/HAL/ctor/pub \
                                        CTORHALMODULE2PUB=${PWD}/../../Module2/HAL/ctor/pub \
                                        IIFPUB=${PWD}/../../IIF/pub \
                                        IIFINC=${PWD}/../../IIF/inc \
                                        CTORIIFPUB=${PWD}/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp *.ko ${LIB_OUT_PATH}
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
	rm -rf ${LIB_OUT_PATH}/ctor_iif*.ko
