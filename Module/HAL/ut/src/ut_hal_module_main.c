#include <ut_pub.h>

extern UtResult UtHalModuleWholeTest(void);

int main(){

  UtResult result={0,0};

  result=UtHalModuleWholeTest();

  return result.ng_num;
}
