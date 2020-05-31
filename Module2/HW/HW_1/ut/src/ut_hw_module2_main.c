#include <ut_pub.h>

extern UtResult UtHwModule2WholeTest(void);

int main(){

  UtResult result={0,0};

  result=UtHwModule2WholeTest();

  return result.ng_num;
}
