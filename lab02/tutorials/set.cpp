//set.cpp
#include "mlisp.h"
double a = 7.;
double g(double x, double a);

double g(double x, double a){
  a = 5.;
  return x + a;
}
int main(){
  display("(g 1 0)=");display(g(1, 0));newline();
  a = 8.;
  display(a);newline();
std::cin.get();
 return 0;
}
