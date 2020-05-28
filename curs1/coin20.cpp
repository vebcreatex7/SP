/*  VKO2020   */
#include "mlisp.h"
bool NOT_Q(bool x_Q);
bool implication_Q(bool x_Q, bool y_Q);
double variant = 3.;
double last__digit__of__group__number = 6.;
double kinds__of__coins = 6.;
double cc(double amount, double kinds__of__coins);
double count__change(double amount, double kinds__of__coins);
double first__denomination(double kinds__of__coins);
double gr__amount();
//________________ 
bool NOT_Q(bool x_Q){
	return 0. == x_Q ? 1. : 0.;
}
bool implication_Q(bool x_Q, bool y_Q){
	return NOT_Q((x_Q && NOT_Q(y_Q)));
}
double cc(double amount, double kinds__of__coins) {
	return amount == 0. ? 1. : implication_Q(0. <= amount, kinds__of__coins == 0.) ? 0. : (cc(amount, (kinds__of__coins - 1.)) + cc((amount - first__denomination(kinds__of__coins)), kinds__of__coins));
}
double count__change(double amount, double kinds__of__coins) {
	display("count-change for ");
	display(amount);
	display(" ");
	display(kinds__of__coins);
	display("\t= ");
	return (NOT_Q(amount <= 0.) && NOT_Q(kinds__of__coins <= 0.) && NOT_Q(first__denomination(kinds__of__coins) <= 0.)) ? cc(amount, kinds__of__coins) : (display("(improper parametr value)"), 0.);
}
double first__denomination(double kinds__of__coins) {
	return kinds__of__coins == 1. ? 1. : kinds__of__coins == 2. ? 2. : kinds__of__coins == 3. ? 3. : kinds__of__coins == 4. ? 20. : kinds__of__coins == 5. ? 25. : kinds__of__coins == 6. ? 50. : 0.;
}
double gr__amount() {
	return remainder((100. * last__digit__of__group__number + variant), 137.);
}
int main(){
	display("VKO variant ");
	display(variant);
	newline();
	display(" 1-2-3-20-25-50");
	newline();
	display(count__change(100., kinds__of__coins));
	newline();
	display(count__change(gr__amount(), kinds__of__coins));
	newline();
	display(count__change(100., 100.));
	newline();
	display(gr__amount());
	std::cin.get();
	return 0;
}

