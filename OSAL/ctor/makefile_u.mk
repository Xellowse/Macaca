CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${OSAL_PATH}/ctor/pub \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../../lib
OSAL_PATH = ..
OSAL_U_PATH = ${OSAL_PATH}/OS/Linux/UserSpace
OUTPUT_PATH=./out/
UT_PATH = ../../UT


linux_u:
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH} -fPIC ./src/ctor_osal.c -o libctor_osal.so -losal_linux_userspace -shared
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	cp libctor_osal.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}
clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf src/*.o
	rm -rf src/.*.cmd
	rm -rf ${LIB_OUT_PATH}/libctor_osal.so
