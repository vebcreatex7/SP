//               testadec.cpp
#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Adec;
///////////////////////
//  Постоить автомат
  addrange(Adec,0,'1','9',1);
  addrange(Adec,1,'0','9',1);
  addstr(Adec,1,".",2);
  addrange(Adec,2,'0','9',2);
//......................
 Adec.final(2);
//......................
///////////////////////
  cout << "*** xxx Adec "
       << "size=" << Adec.size()
       << " ***\n";
  cout << endl;

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = Adec.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;
}

