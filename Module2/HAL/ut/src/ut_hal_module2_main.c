#include <ut_pub.h>

extern UtResult UtHalModule2WholeTest(void);

int main(){

  UtResult result={0,0};

  result=UtHalModule2WholeTest();

  return result.ng_num;
}
