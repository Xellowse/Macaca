//
#ifndef MODDULE_HAL_PUB_MODULE2_H_
#define MODDULE_HAL_PUB_MODULE2_H_


#define HAL_MODULE2_TRUE  (0)
#define HAL_MODULE2_FALSE (-1)

typedef int HalModule2S32;

typedef struct HalModule2Handle{

  //Private data
  void *fd;

  //Public method
  HalModule2S32  (*HalModule2Init)(void *fd);
  HalModule2S32  (*HalModule2Deinit)(void *fd);
  HalModule2S32  (*HalModule2Enable)(void *fd);
  HalModule2S32  (*HalModule2Disable)(void *fd);
  void (*HalModule2LayerMethod1)(HalModule2S32, HalModule2S32);
  void (*HalModule2LayerMethod2)(HalModule2S32);

  //Register for call back method
  HalModule2S32  (*HalModule2RegisterHalCbMethod1)(void *handle, HalModule2S32 (*CbMethod)(HalModule2S32 param1, HalModule2S32 param2));

  //Self call back methods
  HalModule2S32 (*HalModule2CbMethod)(void *handle, HalModule2S32 param1, HalModule2S32 param2);
  HalModule2S32 (*HalModule2ISRCbMethod)(void *handle, HalModule2S32 param1, HalModule2S32 param2);

}HalModule2Handle;

#endif // MODDULE_HAL_PUB_MODULE2_H_
