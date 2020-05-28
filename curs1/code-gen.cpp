/* $k03 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //   PROG -> CALCS
	S1->obj = "int main(){\n\t" + S1->obj
    + "std::cin.get();\n\treturn 0;\n}\n";
	return 0;}
int tCG::p03(){ //   PROG -> DEFS
	S1->obj += "int main(){\n\t"
    "display(\"No calculations!\");newline();\n\t"
    "std::cin.get();\n\treturn 0;\n}\n";
	return 0;}
int tCG::p04(){ //   PROG -> DEFS CALCS
	S1->obj += "int main(){\n\t" + S2->obj
    + "std::cin.get();\n\treturn 0;\n}\n";
	return 0;}
int tCG::p05(){ //      E -> $id
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p06(){ //      E -> $int
	S1->obj = S1->name + '.';
	return 0;}
int tCG::p07(){ //      E -> $dec
	S1->obj = S1->name;
	return 0;}
int tCG::p08(){ //      E -> ADD
	return 0;}
int tCG::p09(){ //      E -> SUB
	return 0;}
int tCG::p10(){ //      E -> DIV
	return 0;}
int tCG::p11(){ //      E -> MUL
	return 0;}
int tCG::p12(){ //      E -> COND
	return 0;}
int tCG::p13(){ //      E -> EASYLET
	return 0;}
int tCG::p14(){ //      E -> CPROC
	return 0;}
int tCG::p15(){ //    ADD -> HADD E )
	if(S1->count==0)
    	S1->obj = S2->obj;
 	else            
    	S1->obj += S2->obj + ")";
 	S1->count =0;
	return 0;}
int tCG::p16(){ //   HADD -> ( +
	S1->obj = "(";
	return 0;}
int tCG::p17(){ //   HADD -> HADD E
	S1->obj += S2->obj + " + ";
 	++S1->count;
	return 0;}
int tCG::p18(){ //    SUB -> HSUB E )
	if(S1->count==0)
    	S1->obj = S2->obj;
 	else            
    	S1->obj += S2->obj + ")";
 	S1->count =0;
	return 0;}
int tCG::p19(){ //   HSUB -> ( -
	S1->obj = "(";
	return 0;}
int tCG::p20(){ //   HSUB -> HSUB E
	S1->obj += S2->obj + " - ";
 	++S1->count;
	return 0;}
int tCG::p21(){ //    DIV -> ( / E E )
	S1->obj = "(" + S3->obj + " / " + S4->obj + ")";
	return 0;}
int tCG::p22(){ //    MUL -> HMUL E )
	if(S1->count==0)
    	S1->obj = S2->obj;
	 else            
    	S1->obj += S2->obj;
 	S1->count =0;
	return 0;}
int tCG::p23(){ //   HMUL -> ( *
	return 0;}
int tCG::p24(){ //   HMUL -> HMUL E
	S1->obj += S2->obj + " * ";
 	++S1->count;
	return 0;}
int tCG::p25(){ //   COND -> HCOND ELSE )
	S1->obj += S2->obj;
	return 0;}
int tCG::p26(){ //  HCOND -> ( cond CLAUS ??
	S1->obj += S3->obj;
	return 0;}
int tCG::p27(){ //  CLAUS -> ( BOOL E ) ??
	S1->obj += S2->obj + " ? " + S3->obj + " : ";
	return 0;}
int tCG::p28(){ //   ELSE -> ( else E ) ??
	S1->obj += S3->obj;
	return 0;}
int tCG::p29(){ //EASYLET -> HEASYL E ) 
	if(S1->count) 
		S1->obj += ", ";
	S1->obj += S2->obj + ')';
 	S1->count = 0;
	return 0;}
int tCG::p30(){ // HEASYL -> ( let ( )
	S1->obj += "(";
	return 0;}
int tCG::p31(){ // HEASYL -> HEASYL INTER
	if(S1->count) 
		S1->obj += ", ";
	S1->obj += S2->obj;
	++S1->count;
	return 0;}
int tCG::p32(){ //    STR -> $str
	S1->obj = S1->name;
	return 0;}
int tCG::p33(){ //    STR -> SIF
	return 0;}
int tCG::p34(){ //    SIF -> ( if BOOL STR STR )
	S1->obj = S3->obj + " ? " + S4->obj + " : " + S5->obj;
	return 0;}
int tCG::p35(){ //  CPROC -> HCPROC )
	S1->obj += ")";
	return 0;}
int tCG::p36(){ // HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p37(){ // HCPROC -> HCPROC E
	 if(S1->count)
        S1->obj += ", ";
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}
int tCG::p38(){ //   BOOL -> $bool
	S1->obj = S1->name == "#t" ? "true" : "false";
	return 0;}
int tCG::p39(){ //   BOOL -> $idq
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p40(){ //   BOOL -> REL
	return 0;}
int tCG::p41(){ //   BOOL -> AND
	return 0;}
int tCG::p42(){ //   BOOL -> CPRED
	return 0;}
int tCG::p43(){ //  CPRED -> HCPRED )
	S1->obj += ")";
	return 0;}
int tCG::p44(){ // HCPRED -> ( $idq
	S1->obj = decor(S2->name) + "(";
	return 0;}
int tCG::p45(){ // HCPRED -> HCPRED ARG
	if(S1->count) 
        S1->obj += ", ";
    S1->obj += S2->obj;
    ++S1->count;
	return 0;}
int tCG::p46(){ //    ARG -> E
	return 0;}
int tCG::p47(){ //    ARG -> BOOL
	return 0;}
int tCG::p48(){ //    REL -> ( = E E )
	S1->obj = S3->obj + " == " + S4->obj;
	return 0;}
int tCG::p49(){ //    REL -> ( <= E E )
	S1->obj = S3->obj + " <= " + S4->obj;
	return 0;}
int tCG::p50(){ //    AND -> HAND BOOL )
	if(S1->count == 0) 
		S1->obj = S2->obj ;
	else 
		S1->obj += S2->obj + ")";
	S1->count = 0;
	return 0;}
int tCG::p51(){ //   HAND -> ( and
	S1->obj = "(";
	return 0;}
int tCG::p52(){ //   HAND -> HAND BOOL
	S1->obj += S2->obj + " && ";
	++S1->count;
	return 0;}
int tCG::p53(){ //    SET -> HSET E )
	S1->obj += S2->obj; 
	return 0;}
int tCG::p54(){ //   HSET -> ( set! $id
	S1->obj = decor(S3->name) + " = ";
	return 0;}
int tCG::p55(){ //DISPSET -> ( display E )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p56(){ //DISPSET -> ( display BOOL )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p57(){ //DISPSET -> ( display STR )
	S1->obj = "display(" + S3->obj + ")";
	return 0;}
int tCG::p58(){ //DISPSET -> ( newline )
	S1->obj = "newline()";
	return 0;}
int tCG::p59(){ //DISPSET -> SET
	return 0;}
int tCG::p60(){ //  INTER -> DISPSET
	return 0;}
int tCG::p61(){ //  INTER -> E
	return 0;}
int tCG::p62(){ //  CALCS -> CALC
	return 0;}
int tCG::p63(){ //  CALCS -> CALCS CALC
	S1->obj += S2->obj;
	return 0;}
int tCG::p64(){ //   CALC -> E
	S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}
int tCG::p65(){ //   CALC -> BOOL
	S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}
int tCG::p66(){ //   CALC -> STR
	S1->obj = "display(" + S1->obj + "); newline();\n\t";
	return 0;}
int tCG::p67(){ //   CALC -> DISPSET
	S1->obj += ";\n\t";
	return 0;}
int tCG::p68(){ //   DEFS -> DEF
	return 0;}
int tCG::p69(){ //   DEFS -> DEFS DEF
	S1->obj += S2->obj;
	return 0;}
int tCG::p70(){ //    DEF -> PRED
	return 0;}
int tCG::p71(){ //    DEF -> VAR
	return 0;}
int tCG::p72(){ //    DEF -> PROC
	return 0;}
int tCG::p73(){ //   PRED -> HPRED BOOL )
	S1->obj += "return " + S2->obj + ";\n}\n";
	return 0;}
int tCG::p74(){ //  HPRED -> PDPAR )
	S1->obj += ")";
    declarations += S1->obj + ";\n";
    S1->obj += "{\n\t";
	return 0;}
int tCG::p75(){ //  PDPAR -> ( define ( $idq
	S1->obj += "bool " + decor(S4->name) + "(";
    S1->count = 0;
    S1->name = S4->name;
	return 0;}
int tCG::p76(){ //  PDPAR -> PDPAR $idq
	if(S1->count) 
        S1->obj += ", ";
    S1->obj += "bool " + decor(S2->name);
    ++S1->count;
	return 0;}
int tCG::p77(){ //  PDPAR -> PDPAR $id
	if(S1->count)
        S1->obj += ", ";
    S1->obj += "double " + decor(S2->name);
    ++S1->count;
	return 0;}
int tCG::p78(){ //    VAR -> VARDCL E )
	S1->obj += S2->obj + ";\n";
    declarations += S1->obj;
    S1->obj = "";
	return 0;}
int tCG::p79(){ // VARDCL -> ( define $id
	S1->obj += "double " + decor(S3->name) + " = ";
	return 0;}
int tCG::p80(){ //   PROC -> HPROC BLOCK )
	S1->obj += S2->obj + ";\n}\n";
	return 0;}
int tCG::p81(){ //   PROC -> HPROC E )
	S1->obj += "return " + S2->obj+";\n}\n";
	return 0;}
int tCG::p82(){ //  HPROC -> PCPAR )
	S1->obj += ")";
 	declarations += S1->obj + ";\n"; 
 	S1->obj += " {\n\t";
	return 0;}
int tCG::p83(){ //  HPROC -> HPROC INTER
	S1->obj += S2->obj + ";\n\t";
	return 0;}
int tCG::p84(){ //  PCPAR -> ( define ( $id
	S1->obj = "double " + decor(S4->name) + "(";
 	S1->count = 0;
 	S1->name = S4->name;
	return 0;}
int tCG::p85(){ //  PCPAR -> PCPAR $id
	if(S1->count)
		S1->obj += ", ";// не первый параметр
 	S1->obj += "double " + decor(S2->name);
 	++(S1->count);
	return 0;}
int tCG::p86(){ //  BLOCK -> HBLOCK E )
	S1->obj += "return " + S2->obj;
	return 0;}
int tCG::p87(){ // HBLOCK -> BLVAR )
	S1->obj += ";\n\t";
	return 0;}
int tCG::p88(){ // HBLOCK -> HBLOCK INTER
	S1->obj += S2->obj + ";\n\t";
	return 0;}
int tCG::p89(){ //  BLVAR -> ( let ( LOCDEF
	S1->obj += S4->obj;
	return 0;}
int tCG::p90(){ //  BLVAR -> BLVAR LOCDEF
	S1->obj += ";\n\t" + S2->obj;
	return 0;}
int tCG::p91(){ // LOCDEF -> ( $id E )
	S1->obj = "double " + decor(S2->name) + " = " + S3->obj;
	return 0;}
//_____________________
int tCG::p92(){return 0;} int tCG::p93(){return 0;} 
int tCG::p94(){return 0;} int tCG::p95(){return 0;} 
int tCG::p96(){return 0;} int tCG::p97(){return 0;} 
int tCG::p98(){return 0;} int tCG::p99(){return 0;} 
int tCG::p100(){return 0;} int tCG::p101(){return 0;} 
int tCG::p102(){return 0;} int tCG::p103(){return 0;} 
int tCG::p104(){return 0;} int tCG::p105(){return 0;} 
int tCG::p106(){return 0;} int tCG::p107(){return 0;} 
int tCG::p108(){return 0;} int tCG::p109(){return 0;} 
int tCG::p110(){return 0;} 

