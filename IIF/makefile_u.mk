CC = gcc

INC = -I ${HW_MODULE_PATH}/HW_1/inc/ \
      -I ${HW_MODULE_PATH}/HW_1/pub/ \
      -I ${HAL_MODULE_PATH}/inc/ \
      -I ${HAL_MODULE_PATH}/pub/ \
      -I ${CTOR_HAL_MODULE_PATH}/pub/ \
      -I ${HW_MODULE2_PATH}/HW_1/inc/ \
      -I ${HW_MODULE2_PATH}/HW_1/pub/ \
      -I ${HAL_MODULE2_PATH}/inc/ \
      -I ${HAL_MODULE2_PATH}/pub/ \
      -I ${CTOR_HAL_MODULE2_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/pub/ \
      -I ${IIF_PATH}/inc/ \
      -I ${IIF_PATH}/pub/ \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../lib
UT_PATH = ../UT
HW_MODULE_PATH = ../Module/HW/HW_1
HAL_MODULE_PATH = ../Module/HAL
CTOR_HAL_MODULE_PATH = ../Module/HAL/ctor
CTOR_HW_MODULE_PATH = ../Module/HW/HW_1/ctor
HW_MODULE2_PATH = ../Module2/HW/HW_1
HAL_MODULE2_PATH = ../Module2/HAL
CTOR_HAL_MODULE2_PATH = ../Module2/HAL/ctor
CTOR_HW_MODULE2_PATH = ../Module2/HW/HW_1/ctor
OSAL_PATH = ../OSAL
OUTPUT_PATH=./out
IIF_PATH=.

linux_u:
	${CC} ${CFLAG} ${INC} -L ${LIB_OUT_PATH} -shared -fPIC ${IIF_PATH}/src/iif.c -o libiif.so
	mkdir -p ${LIB_OUT_PATH}
	mkdir -p ${OUTPUT_PATH}
	cp *.so ${LIB_OUT_PATH}
	mv *.so ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf .*.cmd
	rm -rf ${LIB_OUT_PATH}/libiif*.so
