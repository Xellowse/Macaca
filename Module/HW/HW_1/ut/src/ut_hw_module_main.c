#include <ut_pub.h>

extern UtResult UtHwModuleWholeTest(void);

int main(){

  UtResult result={0,0};

  result=UtHwModuleWholeTest();

  return result.ng_num;
}
