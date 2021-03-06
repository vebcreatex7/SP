#include "mlisp.h"

double a = 6.;
double b = 8.;
double mphi = (0.5 * (3. - sqrt(5.)));
double tolerance = 0.00001;
double xmin = 0.;

double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double __xxx__try(double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q(double a, double b);

double fun(double x) {
	x = x - (103. / 104.);
	return x - sin(x) - cos(x);
}

double golden__section__search(double a, double b) {
	{
		xmin = a < b ? golden__start(a, b) : golden__start(b, a);
		newline();
		return xmin;
	}
}

double golden__start(double a, double b) {
	{
		double xa(a + (mphi * (b - a)));
		double xb(b - (mphi * (b - a)));
		return __xxx__try(a, b, xa, fun(xa), xb, fun(xb));
	}
}

double __xxx__try(double a, double b, double xa, double ya, double xb, double yb) {
	return close__enough_Q(a, b) ? ((a + b) * 0.5) : (display("+"), ya < yb ? 
		(b = xb,
		xb = xa,
		yb = ya,
		xa = (a + (mphi * (b - a))),
		__xxx__try(a, b, xa, fun(xa), xb, yb)):
		(a = xa,
		xa = xb,
		ya = yb,
		xb = (b - (mphi * (b - a))),
		__xxx__try(a, b, xa, ya, xb, fun(xb)))
		);
}

bool close__enough_Q(double x, double y) {
	return abs(x - y) < tolerance;
}

int main() {
	xmin = golden__section__search(a, b);
	display("interval=\t[");
	display(a);
	display(" , ");
	display(b);
	display("]\n");
	display("xmin=\t\t");
	display(xmin);
	newline();
	display("f(xmin)=\t");
	display(fun(xmin));
	newline();
}

