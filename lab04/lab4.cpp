#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main() {
	tFSM fsm;
	addstr(fsm, 0, "-", 1);
	addstr(fsm, 0, "+", 1);
	addstr(fsm, 1, "-", 1);
	addstr(fsm, 1, "+", 1);
	addrange(fsm, 1, '0', '9', 2);
	addrange(fsm, 2, '0', '9', 2);
	addstr(fsm, 2, ".", 3);
	addrange(fsm, 3, '0', '9', 4);
	addrange(fsm, 4, '0', '9', 4);
	fsm.final(4);
	addstr(fsm, 4, "e", 5);
	addstr(fsm, 4, "E", 5);
	addstr(fsm, 5, "-", 6);
	addstr(fsm, 5, "+", 6);
	addrange(fsm, 6, '0', '9', 7);
	addrange(fsm, 7, '0', '9', 7);
	fsm.final(7);

	cout << "*** cppid  "
       << "size=" << fsm.size()
       << " ***\n";
  cout << endl;

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = fsm.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;

}