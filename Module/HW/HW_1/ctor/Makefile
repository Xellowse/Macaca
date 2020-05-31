CC = gcc
EXTRA_CFLAGS = -O3

ccflags-y += -I ${HALINC} \
             -I ${HALPUB} \
             -I ${CTORHWPUB} \
             -I ${HWPUB} \
             -I ${HWINC} \
             -I ${OSALINC} \
             -I ${OSALPUB} \
             -I ${CTOROSALPUB}

LIB_OUT_PATH = ../../../../lib
HW_PATH = ..
OSAL_PATH = ../../../../OSAL
OUTPUT_PATH=./out/

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

ctor_hw_module-objs      := ${HW_PATH}/ctor/src/ctor_hw_module.o  \
                            ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_ctor_hw_module.o
obj-m :=ctor_hw_module.o


all:
	make -f makefile_u.mk
linux_u:
	make linux_u -f makefile_u.mk
linux_k:
	make -C ${KERNEL_PATH} M=${PWD} HALINC=${PWD}/../../../HAL/inc \
                                        HALPUB=${PWD}/../../../HAL/pub \
                                        OSALINC=${PWD}/../../../../OSAL/inc \
                                        OSALPUB=${PWD}/../../../../OSAL/pub \
                                        CTOROSALPUB=${PWD}/../../../../OSAL/ctor/pub \
                                        CTORHWPUB=${PWD}/pub \
                                        HWPUB=${PWD}/../../../HW/HW_1/pub \
                                        HWINC=${PWD}/../../../HW/HW_1/inc \
                                        modules
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp ctor_hw_module.ko ${LIB_OUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}

clean:
	rm -rf ./out
	rm -rf .*.cmd
	rm -rf ${HW_PATH}/ctor/src/.*.cmd
	rm -rf ${HW_PATH}/ctor/src/*.o
	rm -rf .cache.mk
	rm -rf .tmp_versions
	rm -rf ${LIB_OUT_PATH}/ctor_hw_module.ko
