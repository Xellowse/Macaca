CC = gcc
EXTRA_CFLAGS = -O3

ccflags-y += -I ${HALINC} \
             -I ${HALPUB} \
             -I ${CTORPUB} \
             -I ${HWPUB} \
             -I ${OSALINC} \
             -I ${OSALPUB}

LIB_OUT_PATH = ../../lib
HW_PATH = ../HW
HAL_PATH = ../HAL
CTOR_PATH = ../CTOR
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out/

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

hal_module-objs        := ${HAL_PATH}/src/hal_module.o  \
                          ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_hal_module.o
obj-m :=hal_module.o


all:
	make -f makefile_u.mk
linux_u:
	make linux_u -f makefile_u.mk
linux_k:
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../HAL/inc  HALPUB=${PWD}/../HAL/pub OSALINC=${PWD}/../../OSAL/inc  OSALPUB=${PWD}/../../OSAL/pub  CTORPUB=${PWD}/../CTOR/pub HWPUB=${PWD}/../HW/HW_1/pub modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp hal_module.ko ${LIB_OUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}

clean:
	rm -rf ./out
	rm -rf .*.cmd
	rm -rf ${HAL_PATH}/src/.*.cmd
	rm -rf ${HAL_PATH}/src/*.o
	rm -rf .cache.mk
	rm -rf .tmp_versions
	rm -rf ${LIB_OUT_PATH}/hal_module.ko
