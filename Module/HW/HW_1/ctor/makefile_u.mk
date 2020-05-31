CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${HAL_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${OSAL_PATH}/ctor/pub \
      -I ${HW_PATH}/ctor/pub/

LIB_OUT_PATH = ../../../../lib
HW_PATH = ..
HAL_PATH = ../../../HAL
OSAL_PATH = ../../../../OSAL
OUTPUT_PATH=./out/
#LIB = -L

all:
	echo "usage:\nmake linux_u  :build the user space hal lib\nmake linux_k  :build the kernel space hal module"

linux_u:
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH}  -shared -fPIC  ${HW_PATH}/ctor/src/ctor_hw_module.c -o libctor_hw_module.so -lhw_module
	mkdir -p ${OUTPUT_PATH}
	cp *.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}


clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libctor_hw_module.so
