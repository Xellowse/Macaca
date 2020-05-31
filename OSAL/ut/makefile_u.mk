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
OBJS = ctor_osal.o
OBJS_USERSPACE = osal_linux_userspace.o ctor_osal.o


linux_u:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH} -shared -fPIC ./src/ut_osal.c -o libut_osal.so  -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ./src/ut_osal_main.c -o ut_osal  -lut_osal
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	cp libut_osal.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}
	mv ut_osal ${OUTPUT_PATH}
clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf src/*.o
	rm -rf src/.*.cmd
	rm -rf ${LIB_OUT_PATH}/libut_osal.so
