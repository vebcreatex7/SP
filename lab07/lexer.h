//                 lexer.h 2020
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  xxx		     *
//*             (c)  2020                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "VKO"
                +std::string("2020");}
//конструктор
 tLexer():tBaseLexer(){
//создать автоматы:

//  целое Aint
    addstr  (Aint,0,"+-", 2);
    addrange(Aint,2,'0','9',1);
    addrange(Aint,0,'0','9',1);
    addrange(Aint,1,'0','9',1);
  Aint.final(1);

//________________________________________

// вещественное
   /* addrange(Adec,0,'0','9',1);
    addstr  (Adec,1,".",   2);
    addrange(Adec,2,'0','9',2);
  Adec.final(2); */
  addstr(Adec, 0, "-", 1);
  addstr(Adec, 0, "+", 1);
  addrange(Adec, 1, '0', '9', 2);
  addrange(Adec, 2, '0', '9', 2);
  addstr(Adec, 2, ".", 3);
  addrange(Adec, 3, '0', '9', 4);
  addrange(Adec, 4, '0', '9', 4);
  Adec.final(4);
  addstr(Adec, 4, "e", 5);
  addstr(Adec, 4, "E", 5);
  addstr(Adec, 5, "-", 6);
  addstr(Adec, 5, "+", 6);
  addrange(Adec, 6, '0', '9', 7);
  addrange(Adec, 7, '0', '9', 7);
  Adec.final(7);
//________________________________________

// идентификатор
   /* addrange(Aid,0,'a','z',1);
    addrange(Aid,1,'a','z',1);
    addstr  (Aid,1,"!",   1);
  Aid.final(1);
 */
  /*
  addrange(Aid, 0, 'a', 'z', 1);
  addrange(Aid, 0, 'A', 'Z', 1);
  addstr(Aid, 0, "!", 1);
  addstr(Aid, 0, "?", 2);
  addrange(Aid, 1, 'a', 'z', 1);
  addrange(Aid, 1, 'A', 'Z', 1);
  addrange(Aid, 1, '0', '9', 1);
  addstr(Aid, 1, "!", 1);
  addstr(Aid, 1, "-", 1);
  addstr(Aid, 1, "?", 2);
  addstr(Aid, 2, "?", 2);
  addrange(Aid, 2, 'a', 'z', 1);
  addrange(Aid, 2, 'A', 'Z', 1);
  addrange(Aid, 2, '0', '9', 1);
  addstr(Aid, 2, "!", 1);
  addstr(Aid, 2, "-", 1);
  Aid.final(1);
*/

  addrange(Aid, 0, 'a', 'z', 1);
  addrange(Aid, 0, 'A', 'Z', 1);
  addstr(Aid, 0, "?", 3);
  addstr(Aid, 0, "!", 2);
  addrange(Aid, 1, 'a', 'z', 1);
  addrange(Aid, 1, 'A', 'Z', 1);
  addrange(Aid, 1, '0', '9', 1);
  addstr(Aid, 1, "-", 1);
  addstr(Aid, 1, "!", 2);
  addstr(Aid, 1, "?", 3);
  addrange(Aid, 2, 'a', 'z', 1);
  addrange(Aid, 2, 'A', 'Z', 1);
  addrange(Aid, 2, '0', '9', 1);
  addstr(Aid, 2, "-", 3);
  addstr(Aid, 2, "!", 2);
  addstr(Aid, 3, "!", 2);
  addstr(Aid, 3, "?", 3);
  addrange(Aid, 3, 'a', 'z', 2);
  addrange(Aid, 3, 'A', 'Z', 2);
  addrange(Aid, 3, '0', '9', 2);
  addstr(Aid, 3, "-", 2);
  Aid.final(1);
  Aid.final(2);
//________________________________________

// идентификатор предиката
  /*
    addstr  (Aidq,0,"?",   1);
  Aidq.final(1);
  */

  addstr(Aidq, 0, "?", 1);
  addstr(Aidq, 0, "-", 3);
  addrange(Aidq, 0, 'a', 'z', 2);
  addrange(Aidq, 0, 'A', 'Z', 2);
  addstr(Aidq, 0, "!", 2);

  addstr(Aidq, 1, "?", 1);
  addstr(Aidq, 1, "-", 4);
  addrange(Aidq, 1, 'a', 'z', 2);
  addrange(Aidq, 1, 'A', 'Z', 2);
  addrange(Aidq, 1, '0', '9', 2);
  addstr(Aidq, 1, "!", 2);
  
  addstr(Aidq, 2, "?", 1);
  addstr(Aidq, 2, "-", 4);
  addrange(Aidq, 2, 'a', 'z', 2);
  addrange(Aidq, 2, 'A', 'Z', 2);
  addrange(Aidq, 2, '0', '9', 2);
  addstr(Aidq, 2, "!", 2);
  
  addstr(Aidq, 3, "?", 1);
  addstr(Aidq, 3, "-", 5);
  addrange(Aidq, 3, 'a', 'z', 2);
  addrange(Aidq, 3, 'A', 'Z', 2); 
  addrange(Aidq, 3, '0', '9', 2);
  addstr(Aidq, 3, "!", 2);

  addstr(Aidq, 4, "?", 1);
  addstr(Aidq, 4, "-", 5);
  addrange(Aidq, 4, 'a', 'z', 2);
  addrange(Aidq, 4, 'A', 'Z', 2);
  addrange(Aidq, 4, '0', '9', 2);
  addstr(Aidq, 4, "!", 2);

  addstr(Aidq, 5, "-", 5);
  addrange(Aidq, 5, 'a', 'z', 2);
  addrange(Aidq, 5, 'A', 'Z', 2);
  addrange(Aidq, 5, '0', '9', 2);
  addstr(Aidq, 5, "!", 2);

  Aidq.final(1);

}
};
#endif

