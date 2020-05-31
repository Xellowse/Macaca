CC = gcc
EXTRA_CFLAGS = -O3

ccflags-y += -I ${HALINC} \
             -I ${HALPUB} \
             -I ${CTORHALPUB} \
             -I ${HWINC} \
             -I ${HWPUB} \
             -I ${CTORHWPUB} \
             -I ${OSALPUB} \
             -I ${OSALINC} \
             -I ${CTOROSALPUB}

LIB_OUT_PATH = ../../../lib
HAL_PATH = ..
OSAL_PATH = ../../../OSAL
OUTPUT_PATH=./out/

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

ctor_hal_module-objs        := ${HAL_PATH}/ctor/src/ctor_hal_module.o  \
                               ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ctor_hal_module.o
obj-m :=ctor_hal_module.o


all:
	make -f makefile_u.mk
linux_u:
	make linux_u -f makefile_u.mk
linux_k:
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../inc \
                                        HALPUB=${PWD}/../pub \
                                        CTORHALPUB=${PWD}/pub \
                                        HWINC=${PWD}/../../HW/HW_1/inc \
                                        HWPUB=${PWD}/../../HW/HW_1/pub \
                                        CTORHWPUB=${PWD}/../../HW/HW_1/ctor/pub \
                                        OSALINC=${PWD}/../../../OSAL/inc \
                                        OSALPUB=${PWD}/../../../OSAL/pub \
                                        CTOROSALPUB=${PWD}/../../../OSAL/ctor/pub \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp ctor_hal_module.ko ${LIB_OUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}

clean:
	rm -rf ./out
	rm -rf .*.cmd
	rm -rf ${HAL_PATH}/ctor/src/.*.cmd
	rm -rf ${HAL_PATH}/ctor/src/*.o
	rm -rf .cache.mk
	rm -rf .tmp_versions
	rm -rf ${LIB_OUT_PATH}/ctor_hal_module.ko
