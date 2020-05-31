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
      -I ${IIF_PATH}/ctor/pub \
      -I ${UT_PATH}/pub/

LIB_OUT_PATH = ../../lib
UT_PATH = ../../UT
HW_MODULE_PATH = ../../Module/HW/HW_1
HAL_MODULE_PATH = ../../Module/HAL
CTOR_HAL_MODULE_PATH = ../../Module/HAL/ctor
CTOR_HW_MODULE_PATH = ../../Module/HW/HW_1/ctor
HW_MODULE2_PATH = ../../Module2/HW/HW_1
HAL_MODULE2_PATH = ../../Module2/HAL
CTOR_HAL_MODULE2_PATH = ../../Module2/HAL/ctor
CTOR_HW_MODULE2_PATH = ../../Module2/HW/HW_1/ctor
OSAL_PATH = ../../OSAL
OUTPUT_PATH=./out
IIF_PATH=..

linux_u:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L . -shared -fPIC ${IIF_PATH}/ut/src/ut_iif.c -o libut_iif.so -lctor_iif \
                                                                                         -lctor_hal_module \
                                                                                         -lctor_hw_module \
                                                                                         -lctor_hal_module2 \
                                                                                         -lctor_hw_module2
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ${IIF_PATH}/ut/src/ut_iif_main.c -o ut_iif  -lut_iif
	mkdir -p ${LIB_OUT_PATH}
	mv libut_iif.so ${LIB_OUT_PATH}
	mkdir -p ${OUTPUT_PATH}
	mv *.so ${OUTPUT_PATH}
	mv ut_iif ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf ${LIB_OUT_PATH}/libut_iif.so
	rm -rf .*.cmd
