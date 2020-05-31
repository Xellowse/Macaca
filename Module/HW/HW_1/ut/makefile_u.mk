CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HAL_PATH}/inc/ \
      -I ${HAL_PATH}/pub/ \
      -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${CTOR_HW_MODULE_PATH}/pub/ \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../../../../lib
HAL_PATH = ../../../HAL
HW_PATH = ../../../HW/HW_1
OSAL_PATH = ../../../../OSAL
CTOR_HW_MODULE_PATH = ../ctor
OUTPUT_PATH=./out/
UT_PATH = ../../../../UT


all:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L . -shared -fPIC ./src/ut_hw_module.c -o libut_hw_module.so  -lctor_hw_module -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ./src/ut_hw_module_main.c -o ut_hw_module  -lut_hw_module
	mkdir -p ${OUTPUT_PATH}
	mkdir -p ${LIB_OUT_PATH}
	cp libut_hw_module.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}
	mv ut_hw_module ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libut_hw_module.so
