CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HAL_PATH}/inc/ \
      -I ${HAL_PATH}/pub/ \
      -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${OSAL_PATH}/ctor/pub \
      -I ${HAL_PATH}/ctor/pub \
      -I ${HW_PATH}/ctor/pub

LIB_OUT_PATH = ../../../lib
HAL_PATH = ..
HW_PATH = ../../HW/HW_1
OSAL_PATH = ../../../OSAL
OUTPUT_PATH=./out/
UT_PATH = ../../UT
OBJS = hal_module.o
OBJS_USERSPACE = osal_linux_userspace.o ctor_osal.o
SRCS = ${HAL_PATH}/src/hal_module.c


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH} -shared -fPIC  ${HAL_PATH}/ctor/src/ctor_hal_module.c -o libctor_hal_module.so  -lhal_module -lctor_hw_module
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	cp *.so ${OUTPUT_PATH}
	mv *.so ${LIB_OUT_PATH}


clean:
	rm -rf ${LIB_OUT_PATH}/libctor_hal_module.so
	rm -rf ${OUTPUT_PATH}
