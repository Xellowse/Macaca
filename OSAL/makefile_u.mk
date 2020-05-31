CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../lib
OSAL_PATH = .
OSAL_U_PATH = ${OSAL_PATH}/OS/Linux/UserSpace
OUTPUT_PATH=./out/
UT_PATH = ../UT
OBJS = ctor_osal.o
OBJS_USERSPACE = osal_linux_userspace.o ctor_osal.o


linux_u:
	${CC} ${CFLAG} ${INC} -shared -fPIC ${OSAL_PATH}/src/OS/Linux/UserSpace/osal_linux_userspace.c -o libosal_linux_userspace.so
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	cp libosal_linux_userspace.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}
clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf src/*.o
	rm -rf src/.*.cmd
	rm -rf ${LIB_OUT_PATH}/libosal_linux_userspace.so
