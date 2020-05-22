//block.cpp
#include "mlisp.h"
double f(double x);

double f(double x){
 x = x - 100./101.;
 {//let
  double 
        a(sin(x)),
        b(log(x)),
        f(0);
        display(f);
        newline();
  f = 5. * a * b;
  display("f=");display(f);newline();
  return f;
 }//let
}
int main(){
 display(f(1));newline();
std::cin.get();
 return 0;
}
