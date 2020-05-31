CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/

LIB_OUT_PATH = ../../../../lib
OSAL_PATH = ../../..
OUTPUT_PATH=./out/
#LIB = -L
OBJS = osal_linux_userspace.o


all: ${OBJS}
	mkdir -p ${OUTPUT_PATH}
	mv *.so ${OUTPUT_PATH}

osal_linux_userspace.o: ${OSAL_PATH}/OS/Linux/UserSpace/osal_linux_userspace.c
	${CC} ${CFLAG} ${INC} -shared -fPIC $< -o libosal_linux_userspace.so
	cp libosal_linux_userspace.so ${LIB_OUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libosal_linux_userspace.so
