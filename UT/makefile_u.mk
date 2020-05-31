CC = gcc

INC = -I ${UT_PATH}/pub/ \
      -I ${OSAL_PATH}/inc/ \
      -I ${OSAL_PATH}/ctor/pub \
      -I ${OSAL_PATH}/pub/


LIB_OUT_PATH = ../lib

UT_PATH = .
UT_HAL_MODULE_PATH = ../Module/HAL/ut
UT_HW_MODULE_PATH = ../Module/HW/HW_1/ut
UT_HAL_MODULE2_PATH = ../Module2/HAL/ut
UT_HW_MODULE2_PATH = ../Module2/HW/HW_1/ut
UT_IIF_PATH = ../IIF/ut

HW_MODULE_PATH = ../Module/HW/HW_1
HW_MODULE2_PATH = ../Module2/HW/HW_1

HAL_MODULE_PATH = ../Module/HAL
HAL_MODULE2_PATH = ../Module2/HAL

CTOR_HAL_MODULE_PATH = ../Module/HAL/ctor
CTOR_HW_MODULE_PATH = ../Module/HW/HW_1/ctor
CTOR_HAL_MODULE2_PATH = ../Module2/HAL/ctor
CTOR_HW_MODULE2_PATH = ../Module2/HW/HW_1/ctor
CTOR_IIF_PATH = ../IIF/ctor

IIF_PATH = ../IIF
OSAL_PATH = ../OSAL
OUTPUT_PATH=./out

linux_u:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. -shared -fPIC ${UT_PATH}/src/ut_all.c -o libut_all.so  -lut_iif \
                                                                                      -lut_hal_module \
                                                                                      -lut_hal_module2 \
                                                                                      -lut_hw_module \
                                                                                      -lut_hw_module2 \
                                                                                      -lut_osal \
                                                                                      -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ${UT_PATH}/src/ut_all_main.c -o ut_all -lut_all
	mkdir -p ${OUTPUT_PATH}
	mv *.so ${OUTPUT_PATH}
	mv ut_all ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf .*.cmd
