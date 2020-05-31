CC = gcc
EXTRA_CFLAGS = -O3

ccflags-y += -I ${HALINC} \
             -I ${HALPUB} \
             -I ${HWINC} \
             -I ${HWPUB} \
             -I ${OSALINC} \
             -I ${OSALPUB}

LIB_OUT_PATH = ../../lib
HW_PATH = ../HW/HW_1
HAL_PATH = ../HAL
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out/

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

hal_module2-objs        := ${HAL_PATH}/src/hal_module2.o  \
                           ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_hal_module2.o
obj-m := hal_module2.o


all:
	make -f makefile_u.mk
linux_u:
	make linux_u -f makefile_u.mk
linux_k:
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../HAL/inc      \
                                        HALPUB=${PWD}/../HAL/pub      \
                                        HWINC=${PWD}/../HW/HW_1/inc   \
                                        HWPUB=${PWD}/../HW/HW_1/pub   \
                                        OSALINC=${PWD}/../../OSAL/inc \
                                        OSALPUB=${PWD}/../../OSAL/pub \
                                        modules
	mkdir -p ${LIB_OUT_PATH}
	mkdir -p ${OUTPUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp hal_module2.ko ${LIB_OUT_PATH}
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
	rm -rf ${LIB_OUT_PATH}/hal_module2.ko
