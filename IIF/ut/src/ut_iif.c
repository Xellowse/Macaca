#include <iif_pub.h>
#include <ctor_iif_pub.h>
#include <ut_pub.h>

//ut_iif_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_iif_version="sv#ut_iif_ver:1.0.0";

#define CASE_NUM (3)

UtResult UtIifWholeTest(void){

  IifS32 ret=0;
  UtResult result={CASE_NUM,0};

  IifS32 i=0;
  IifHandle        *iif_handle;

  ret=CtorIifCreateHandle(&iif_handle);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(iif_handle->IifInit(iif_handle->fd) < 0)
            result.ng_num++;
          break;
      case 1:
          if(iif_handle->IifMethod1(iif_handle->fd) < 0)
            result.ng_num++;
          break;
      case 2:
          if(iif_handle->IifDeinit(iif_handle->fd) < 0)
            result.ng_num++;
          break;
      default:
          break;
      }
  }

  CtorIifDestroyHandle(iif_handle);

  return result;
}
