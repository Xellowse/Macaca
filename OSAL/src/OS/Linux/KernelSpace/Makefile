CC = gcc
EXTRA_CFLAGS = -O3
ccflags-y += -I ${OSALINC} \
             -I ${OSALPUB}

OSAL_PATH = ../../..
OUTPUT_PATH=./out/
#LIB = -L

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

osal_linux_kernel_space-objs := ${OSAL_PATH}/OS/Linux/KernelSpace/osal_module_osal.o \
                                 ${OSAL_PATH}/OS/Linux/KernelSpace/osal_linux_kernelspace.o
obj-m :=osal_linux_kernel_space.o

all:
	make -C ${KERNEL_PATH} M=${PWD} OSALINC=${PWD}/../../../inc  OSALPUB=${PWD}/../../../pub
	mkdir -p ${OUTPUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}



clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf .*.cmd
	rm -rf *.o
	rm -rf .cache.mk
	rm -rf .tmp_versions
