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
      -I ${OSAL_PATH}/ctor/pub \
      -I ${IIF_PATH}/inc/ \
      -I ${IIF_PATH}/pub/ \
      -I ${IIF_PATH}/ctor/pub/

LIB_OUT_PATH= ../lib
HW_MODULE_PATH = ../Module/HW/HW_1
HAL_MODULE_PATH = ../Module/HAL
CTOR_HAL_MODULE_PATH = ../Module/HAL/ctor
CTOR_HW_MODULE_PATH = ../Module/HW/HW_1/ctor
HW_MODULE2_PATH = ../Module2/HW/HW_1
HAL_MODULE2_PATH = ../Module2/HAL
CTOR_HAL_MODULE2_PATH = ../Module2/HAL/ctor
CTOR_HW_MODULE2_PATH = ../Module2/HW/HW_1/ctor
IIF_PATH = ../IIF
CTOR_IIF_PATH =../IIF/ctor
OSAL_PATH = ../OSAL
OUTPUT_PATH=./out
TEST_DEMO_PATH=.

linux_u:
	cp ${LIB_OUT_PATH}/*.so ./
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ${TEST_DEMO_PATH}/src/demo.c -o demo -lctor_hal_module -lctor_hal_module2 -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ${TEST_DEMO_PATH}/src/demo_iif.c -o demo_iif -lctor_iif -lctor_hal_module -lctor_hal_module2 -lctor_osal
	${CC} ${CFLAG} ${INC} -L . -Wl,-rpath,. ${TEST_DEMO_PATH}/src/demo_iif.c -o demo_iif_single -lctor_iif_single -lctor_hal_module -lctor_hal_module2 -lctor_osal
	mkdir -p ${OUTPUT_PATH}
	mv *.so ${OUTPUT_PATH}
	mv demo ${OUTPUT_PATH}
	mv demo_iif ${OUTPUT_PATH}
	mv demo_iif_single ${OUTPUT_PATH}

clean:
	rm -rf ${OUTPUT_PATH}
	rm -rf .*.cmd
