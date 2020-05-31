CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HAL_PATH}/inc/ \
      -I ${HAL_PATH}/pub/ \
      -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../../lib
HAL_PATH  = .
HW_PATH   = ../HW/HW_1
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out/
UT_PATH = ../../UT
OBJS = hal_module.o
OBJS_USERSPACE = osal_linux_userspace.o ctor_osal.o
SRCS = ${HAL_PATH}/src/hal_module.c


all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u: ${HAL_PATH}/src/hal_module2.c
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH} -shared -fPIC  $< -o libhal_module2.so
	mkdir -p ${OUTPUT_PATH}
	cp *.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}


clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libhal_module2.so
