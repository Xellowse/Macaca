CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${HAL_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/

LIB_OUT_PATH = ../../../lib
HAL_PATH = ../../HAL
HW_PATH = .
OSAL_PATH = ../../../OSAL
OUTPUT_PATH=./out/
#LIB = -L

all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u: ${HW_PATH}/src/hw_module.c
	${CC} ${CFLAG} ${INC}   -shared -fPIC  $< -o libhw_module.so
	mkdir -p ${OUTPUT_PATH}
	cp *.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}


clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libhw_module.so
