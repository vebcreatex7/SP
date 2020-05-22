//scopes.cpp
#include "mlisp.h"
double a = 7.;
double f(double f);

double f(double f){
 f = f - 100./101.;
 {//let
  double 
        a(sin(f)),
        b(log(f)),
        f(0);
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
