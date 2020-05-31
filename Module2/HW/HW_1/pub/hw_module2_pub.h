//
#ifndef MODDULE2_HW_HW1_HW_PUB_MODULE2_H_
#define MODDULE2_HW_HW1_HW_PUB_MODULE2_H_

#define HW_MODULE2_TRUE  (0)
#define HW_MODULE2_FALSE (-1)

typedef int HwModule2S32;
typedef unsigned char HwModule2U8;

typedef struct HwModule2Handle{

  //Private data
  void *fd;

  //Public methods
  HwModule2S32 (*HwModule2Init)(void *handle);
  HwModule2S32 (*HwModule2Deinit)(void *handle);
  HwModule2S32 (*HwModule2Enable)(void *handle);
  HwModule2S32 (*HwModule2Disable)(void *handle);
  HwModule2S32 (*HwModule2Method1)(void *handle, HwModule2S32, HwModule2S32);
  HwModule2S32 (*HwModule2RegisterISRCbMethod)(void *handle, void *CalleeHandle, HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2));

  //Register for call back method

  //Self call back methods

}HwModule2Handle;

#endif // MODDULE2_HW_HW1_HW_PUB_MODULE2_H_
