//easylet2.cpp
#include "mlisp.h"
double a = 7.;
double b = 8.;

int main(){
//#2
 display(
  (a<b ? a
       :/*(*/display("b="),display(b),newline(),b/*)*/
  )
        );newline();

 std::cin.get();
 return 0;
}
