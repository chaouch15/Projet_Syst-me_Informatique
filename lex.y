%{
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "tab_instru.h"
#include "Jump_manager.h"
#include "interpreteur.h"
#include "Function_manager.h"

int yylex (void);
void yyerror (const char *);

extern int la_profondeur;
#define STACKSIZE 200
%}

%define parse.error verbose

%token tIF tELSE  tMain tWHILE tPRINT tRETURN tASSIGN tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA tCOMP tERROR tCONST TYPE PROFONDEUR ADDRESS tTID tADD tMUL tDIV tSUB tEQ tLT tGT tNE tGE tLE

%left tCOMMA
%left tOP
%left tCOMP

%union {
    int num;
    char* c;
}
%token <num> tNB tVOID tINT
%token <c> tID


%start Program
%%
/*
Program : 
      %empty
    | Program Statement 
;

Statement:  
    Declaration tLBRACE Body tRBRACE {insert_TI("NOP",0,0,0);}
    | tVOID Declaration tLBRACE Body tRBRACE {insert_TI("NOP",0,0,0);}
    |tINT Declaration tLBRACE Body Return tSEMI tRBRACE  {insert_TI("RET",0,0,0);}
    |tINT tMain tLBRACE Body Return tSEMI tRBRACE  {insert_TI("NOP",0,0,0);}

*/
Program : Statement;

Statement : Statement Main
		| Main
		| Statement Fonction 
		| Fonction;
/*
Fonction : tINT tID {  int line = insert_TI("JMP",-1,-1,-1); insert_tjump(line); $<num>1 = get_nbr_instrus_TI() ;} Declaration tLBRACE      {save_addr_func();} Body  {return_to_addr_func();} Return tSEMI tRBRACE { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  insert_TI("JMP",-1,-1,-1); Add_Func($2, $1, get_nbr_instrus_TI());}
         | tVOID tID { int line = insert_TI("JMP",-1,-1,-1); insert_tjump(line); $<num>1 = get_nbr_instrus_TI() + 1;} Declaration tLBRACE      {save_addr_func();} Body  {return_to_addr_func();} tRBRACE { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  insert_TI("JMP",-1,-1,-1); Add_Func($2, $1, get_nbr_instrus_TI());}
       
       
       ;
        */

            
Fonction : tINT tID  Declaration tLBRACE    Body  Return tSEMI tRBRACE {insert_TI("NOP",0,0,0);}
         | tVOID tID  Declaration tLBRACE   Body  tRBRACE  {insert_TI("NOP",0,0,0);}
        
Declaration:
     tLPAR Args tRPAR 
;
Main : 
        tINT tMain tLPAR tRPAR tLBRACE Body Return tSEMI tRBRACE
    | tVOID tMain tLPAR tRPAR tLBRACE Body tRBRACE
    | tMain tLPAR tRPAR tLBRACE Body tRBRACE
    ;



 //tVOID | Arg Args1 ;

// Args1 : %empty | tCOMMA Arg Args1 ;

Args :%empty
    |tINT tID {decla_var_TI($<c>2, la_profondeur); /*RST_arg();*/}  /*{push($<c>2,int_t,la_profondeur);}*/
    |tINT tID tCOMMA  {decla_var_TI($<c>2, la_profondeur);}Args
     ;

Body :
  %empty
    | BodyDec Body
    | BodyInstru  Body
;
/*
Instru : 
  %empty
    | Affect tSEMI Instru     
*/
BodyDec :
      tINT Initialisation  tSEMI  
    | tCONST Initialisationc tSEMI  
    ;

BodyInstru :
      Printf BodyInstru 
    | Affect tSEMI             
    | incr_prof While  decr_prof
    | incr_prof  If   decr_prof
    | Call tSEMI  
     ;


incr_prof : %empty {la_profondeur++;} 
decr_prof :  %empty {la_profondeur--;} 



Initialisationc :
    tID   
    | Affect
    ;

Initialisation :
       tID  {decla_var_TI($<c>1, la_profondeur);}
    |   tID tASSIGN { decla_var_TI($<c>1, la_profondeur);}Val  {affect_TI ($1); }
    | Initialisation tCOMMA Initialisation  
    ;

Printf : tPRINT tLPAR Val tRPAR tSEMI {printf_TI($<c>3);}  


Affect :
    tID tASSIGN Val   {affect_TI ($1);}
    ;

Val :  
%empty
    |  tID {var_TI($<c>1, la_profondeur);}/* { push($<c>1, int_t,la_profondeur);}*/
    | tNB {nb_TI($<num>1, la_profondeur);}/*{ push("tmp", int_t,la_profondeur);}*/
    | Val Operation Val
    | Call 
    ;

Operation : 

     tADD  {add_TI();} {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("ADD  %%%d %%%d \n ",addr1, add*/} 
    |  tMUL  {mul_TI();} {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("MUL  %%%d %%%d \n ",addr1, add*/}   
    |  tDIV  {div_TI();} {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("DIV  %%%d %%%d \n ",addr1, add*/}   
    |  tSUB  {sub_TI();} {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUB  %%%d %%%d \n ",addr1, add*/}   
    ;

LVal :
    Val  
    | tLPAR Val tRPAR
    ;

Logic : LVal
    |  LVal tEQ  LVal {  condi_eq_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("EQU  %%%d %%%d \n ",addr1, add*/} 
    |  LVal tLT  LVal {  condi_lt_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("INF  %%%d %%%d \n ",addr1, add*/} 
    |  LVal tGT  LVal  {  condi_gt_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUP  %%%d %%%d \n ",addr1, add*/} 
    |  LVal tNE  LVal {  condi_ne_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("NEQ  %%%d %%%d \n ",addr1, add*/} 
    |  LVal tGE  LVal {  condi_ge_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("GE  %%%d %%%d \n ",addr1, add*/} 
    |  LVal tLE  LVal   {  condi_le_TI() ; } {/*struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("LE  %%%d %%%d \n ",addr1, add*/} 



If : tIF  tLPAR Logic tRPAR 
        {  
                int condition = get_addr_tmp_pile(); //get_last_tmp_addr_Tab();
                pop(); //free_last_tmp_Tab();
                int line = insert_TI("JMF",condition,-1,-1);
                insert_tjump(line);
        }
        BodyCond
        Else
        ;

Else :   %empty 
        {
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+1);
        }
       
        |tELSE
        {              
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+2);
                int line = insert_TI("JMP",-1,-1,-1);
                insert_tjump(line);
        }
        BodyCond
        {
                int current = get_nbr_instrus_TI();
                actu_jump(pop_tjump(), current+1);
        }
        
        ;

While :tWHILE tLPAR LVal tRPAR
        {
                $<num>1 = get_nbr_instrus_TI()-2;
                int condi = get_addr_tmp_pile(); //get_last_tmp_addr_Tab();
                pop(); //free_last_tmp_Tab();
                int line =insert_TI("JMF",condi,-1,-1);
                insert_tjump(line);
        }
        BodyCond
        {
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+2);
                insert_TI("JMP",$<num>1,-1,-1);
        }
        
        ;

BodyCond :    
        tLBRACE Body tRBRACE    

        ;

Parametre :
    Val   {RST_arg();}
    | Val tCOMMA Parametre 
    ;

Return :
    tRETURN tLPAR Val tRPAR  
    | tRETURN Val 
    ;



Call:
    tID tLPAR Parametre tRPAR {int line = insert_TI("JMP",get_first($<c>1),-1,-1);actu_jump(get_last($<c>1),line +1);  }
    ;

 

%%

void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
     printf("-------");
    pile_init();
    //yydebug = 1;
    init_TI();
    init_tjump();
    init_TF();
    yyparse();
   print_TI();
   // afficherPile();
   
   create_file_TI();

   // printf("-------");
   // interpreteuree();

    return 0;
}
