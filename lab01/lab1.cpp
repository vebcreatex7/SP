#include "mlisp.h"

double dd = 31.;
double mm = 01.;
double yyyy = 2000.;

double odd__bits(double n);
double bit__count(double n);
double report__results(double n);

double even__bits(double n)
{
	return (n == 0 ? 1
		  : remainder(n, 2.) == 0 ?
		  	even__bits(quotient(n, 2.))
		  	 	:true ? odd__bits(quotient(n, 2.))
		  	 	: _infinity);
}

double odd__bits(double n)
{
	return (n == 0 ? 0
		  : remainder(n, 2.) == 0 ?
		  	odd__bits(quotient(n, 2.))
		  	: even__bits(quotient(n, 2.)));
}

double bit__count(double n)
{
	return (n == 0 ? 0
		  : remainder(n, 2.) + bit__count(quotient(n ,2)));
}


double report__results(double n)
{
	display("Happy birthday to you!\n");
	display(n);
	newline();
	display("even?\t");
	even__bits(n) == 1 ? display("yes") : display("no");
	newline();
	display("odd?\t");
	odd__bits(n) == 1 ? display("yes") : display("no");
	newline();
	display("bit__count = ");
	return bit__count(n);


}

int main() {
	display(report__results(dd * 1000000 + mm * 10000 + yyyy));
	 newline();	

 	std::cin.get();
	return 0;

}
