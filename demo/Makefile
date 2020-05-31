CC = gcc
ccflags-y += -I ${HALINC} \
             -I ${HALINC2} \
             -I ${HALPUB} \
             -I ${HALPUB2} \
             -I ${OSALINC} \
             -I ${OSALPUB} \
             -I ${CTORHALPUB} \
             -I ${CTORHALMODULE2PUB} \
             -I ${IIFPUB} \
             -I ${CTORIIFPUB} \
             -I ${CTOROSALPUB}

LIB_OUT_PATH = ../lib
HW_MODULE_PATH = ../Module/HW/HW_1
HAL_MODULE_PATH = ../Module/HAL
HW_MODULE2_PATH = ../Module2/HW/HW_1
HAL_MODULE2_PATH = ../Module2/HAL
CTOR_MODULE_PATH = ../Module/CTOR
CTOR_MODULE2_PATH = ../Module2/CTOR
IIF_PATH = ../IIF

OSAL_PATH = ../OSAL
OUTPUT_PATH=./out
TEST_DEMO_PATH=.

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)


demo_kernel-objs            := ${TEST_DEMO_PATH}/src/demo_kernel.o
demo_iif_kernel-objs        := ${TEST_DEMO_PATH}/src/demo_iif_kernel.o

obj-m := demo_kernel.o demo_iif_kernel.o


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk

linux_k:
	cp ${LIB_OUT_PATH}/*.ko ./
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../Module/HAL/inc \
                                        HALINC2=${PWD}/../Module2/HAL/inc \
                                        HALPUB=${PWD}/../Module/HAL/pub \
                                        HALPUB2=${PWD}/../Module2/HAL/pub \
                                        OSALINC=${PWD}/../OSAL/inc  \
                                        OSALPUB=${PWD}/../OSAL/pub \
                                        CTORHALPUB=${PWD}/../Module/HAL/ctor/pub \
                                        CTORHALMODULE2PUB=${PWD}/../Module2/HAL/ctor/pub \
                                        IIFPUB=${PWD}/../IIF/pub \
                                        CTORIIFPUB=${PWD}/../IIF/ctor/pub \
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
