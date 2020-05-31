CC = gcc
EXTRA_CFLAGS = -O3

INC = -I ${HAL_PATH}/inc/ \
      -I ${HAL_PATH}/pub/ \
      -I ${HW_PATH}/inc/ \
      -I ${HW_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${CTOR_HAL_MODULE_PATH}/pub/ \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../../../lib
HAL_PATH = ../../HAL
HW_PATH = ../../HW/HW_1
OSAL_PATH = ../../../OSAL
CTOR_HAL_MODULE_PATH = ../ctor
CTOR_HW_MODULE_PATH = ../../HW/HW_1/ctor
OUTPUT_PATH=./out/
UT_PATH = ../../../UT


all:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L . -shared -fPIC ./src/ut_hal_module.c -o libut_hal_module.so  -lctor_hal_module -lctor_hw_module -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ./src/ut_hal_module_main.c -o ut_hal_module  -lut_hal_module
	mkdir -p ${OUTPUT_PATH}
	cp libut_hal_module.so ${LIB_OUT_PATH}
	mv *.so  ${OUTPUT_PATH}
	mv ut_hal_module ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libut_hal_module.so
