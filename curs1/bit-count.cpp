/*  VKO2020   */
#include "mlisp.h"
double even__bits(double n);
double odd__bits(double n);
double bit__count(double n);
double report__results(double n);
double dd = 31.;
double mm = 01.;
double yyyy = 2000.;
//________________ 
double even__bits(double n) {
	return n == 0. ? 1. : remainder(n, 2.) == 0. ? even__bits(quotient(n, 2.)) : odd__bits(quotient(n, 2.));
}
double odd__bits(double n) {
	return n == 0. ? 0. : remainder(n, 2.) == 0. ? odd__bits(quotient(n, 2.)) : even__bits(quotient(n, 2.));
}
double bit__count(double n) {
	return n == 0. ? 0. : (remainder(n, 2.) + bit__count(quotient(n, 2.)));
}
double report__results(double n) {
	display("Happy birthday to you!\n\t");
	display(n);
	newline();
	display("\teven?\t");
	display(even__bits(n) == 1. ? "yes" : "no");
	newline();
	display("\todd?\t");
	display(odd__bits(n) == 1. ? "yes" : "no");
	newline();
	display("bit-count = ");
	return bit__count(n);
}
int main(){
	display(report__results((dd * 1000000. + mm * 10000. + yyyy))); newline();
	std::cin.get();
	return 0;
}

