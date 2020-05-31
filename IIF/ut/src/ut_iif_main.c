#include <ut_pub.h>

extern UtResult UtIifWholeTest(void);

int main(){

  UtResult result;

  result=UtIifWholeTest();

  return result.ng_num;
}
