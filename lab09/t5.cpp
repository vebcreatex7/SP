/*  xxx2020   */
#include "mlisp.h"
double __xxx2020__try(double x);
//________________ 
double __xxx2020__try(double x){
	x = x * x;

return x;
}
int main(){
 display(__xxx2020__try(2)); newline();
 std::cin.get();
 return 0;
}

