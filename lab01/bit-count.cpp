#include "mlisp.h"
//...
double even__bits(double n);
double odd__bits(double n);
double bit__count(double n);
double odd__bits(double n)
 {
  return (n == 0 ? 0
       : remainder(n,2) == 0 ?
                odd__bits (quotient(n,2))
       : true ? even__bits(quotient(n,2))
       : _infinity);
 }

 double even__bits(double n)
 {
 	return ()
 }


//...
int main(){
 display(report__results (dd*1000000+
                         mm*10000+
                         yyyy));
 newline();

 std::cin.get();
 return 0;
}
