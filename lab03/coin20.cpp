//coin20.cpp
#include "mlisp.h"

double VARIANT = 3;
double LAST__DIGIT__OF__GROUP__NUMBER = 6;
double KINDS__OF__COINS = 6;
bool implication_Q(bool x_Q, bool y_Q);
double cc(double amount, double kinds__of__coins);
double count__change(double amount, double kinds__of__coins);
double first__denomination(double kinds__of__coins);
double GR__AMOUNT();

bool implication_Q(bool x_Q, bool y_Q){
  return !(x_Q) || y_Q;
}

double cc(double amount, double kinds__of__coins){
  return
	( amount == 0 ? 1
	: implication_Q(amount >= 0, kinds__of__coins == 0) ? 0
	: cc(amount, kinds__of__coins - 1) +
	  cc(amount - first__denomination(kinds__of__coins),
	     kinds__of__coins)
	);
}

double count__change(double amount, double kinds__of__coins){
   display("count-change for ");
   display(amount);
   display(" ");
   display(kinds__of__coins);
   display(" \t= ");
   return
	( amount > 0 &&
	  kinds__of__coins > 0 &&
	  first__denomination(kinds__of__coins) > 0 ?
      		           cc(amount, kinds__of__coins)
	: (display("(improper parameter value) "), 0)
	);
}

double first__denomination(double kinds__of__coins) {
	return
	 ( kinds__of__coins == 1 ? 1
	 : kinds__of__coins == 2 ? 2
	 : kinds__of__coins == 3 ? 3
	 : kinds__of__coins == 4 ? 20
	 : kinds__of__coins == 5 ? 25
	 : kinds__of__coins == 6 ? 50
	 : 0
	 );
}

double GR__AMOUNT(){
   return
    remainder(100. * LAST__DIGIT__OF__GROUP__NUMBER + VARIANT,
              137.);
}


int main(){
 display ("VKO variant ");
 display (VARIANT);
 newline();
 display (" 1-2-3-20-25-50");
 newline();
 display (count__change(100, KINDS__OF__COINS) );
 newline();
 display (count__change(GR__AMOUNT(), KINDS__OF__COINS) );
 newline();
 display (count__change(100, 100) );
 newline();

display(GR__AMOUNT());
 std::cin.get();
 return 0;
}

