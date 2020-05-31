#include <ut_pub.h>

extern UtResult UtOsalWholeTest(void);

int main(){

  UtResult result={0,0};

  result=UtOsalWholeTest();

  return result.ng_num;
}
