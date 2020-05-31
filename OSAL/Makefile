ccflags-y += -I ${OSALINC} \
             -I ${OSALPUB}


CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/

LIB_OUT_PATH = ../lib
OSAL_PATH = .
OSAL_U_PATH = ${OSAL_PATH}/OS/Linux/UserSpace
OUTPUT_PATH=./out/

KERNEL_PATH = /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

osal_linux_kernel_space-objs   := ${OSAL_PATH}/src/OS/Linux/KernelSpace/mod_osal.o \
                                  ${OSAL_PATH}/src/OS/Linux/KernelSpace/osal_linux_kernelspace.o
obj-m := osal_linux_kernel_space.o

all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	make -f makefile_u.mk
linux_k:
	mkdir -p ${OUTPUT_PATH}
	make -C ${KERNEL_PATH} M=${PWD} OSALINC=${PWD}/inc \
                                        OSALPUB=${PWD}/pub \
                                        modules
	mkdir -p ${LIB_OUT_PATH}
	mv *.order ${OUTPUT_PATH}
	mv *.symvers ${OUTPUT_PATH}
	cp osal_linux_kernel_space.ko ${LIB_OUT_PATH}
	mv *.ko ${OUTPUT_PATH}
	mv *.o ${OUTPUT_PATH}
	mv *.mod.* ${OUTPUT_PATH}


clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/osal_linux_kernel_space.ko
	rm -rf ${OSAL_PATH}/src/OS/Linux/KernelSpace/*.o
	rm -rf ${OSAL_PATH}/src/OS/Linux/KernelSpace/.*.cmd
	rm -rf ./.*.cmd
	rm -rf .cache.mk
	rm -rf .tmp_versions
