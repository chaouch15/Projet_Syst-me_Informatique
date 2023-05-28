%{
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "tab_instru.h"
#include "Jump_manager.h"
#include "interpreteur.h"
#include "Function_manager.h"
#include "cross_compiler.h"

int yylex (void);
void yyerror (const char *);

extern int la_profondeur;
#define STACKSIZE 200
%}

%define parse.error verbose

%token tIF tELSE tWHILE tPRINT tRETURN tASSIGN tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA tCOMP tERROR tCONST TYPE PROFONDEUR ADDRESS tTID tADD tMUL tDIV tSUB tEQ tLT tGT tNE tGE tLE

%left tCOMMA
%left tMUL
%left tDIV
%left tADD
%left tSUB
%left tCOMP

%union {
    int num;
    char* c;
}
%token <num> tNB tVOID tINT
%token <c> tID tMain


%start Program
%%

Program :  Statement ;

Statement : Statement Main
        | Fonction ;
		| Main
		| Statement Fonction 
		;

Fonction : 
            tINT tID  incr_prof { start_func();decla_var_TI($<c>2, la_profondeur); printf("Function done\n"); } Declaration tLBRACE   Body  Return {affect_TI ($<c>2);insert_TI("RET",0,0,0);}tSEMI tRBRACE { Add_Func($2,  search($<c>2), get_nbr_instrus_TI());}
         | tVOID tID{start_func(); $<num>1 = get_nbr_instrus_TI() + 1;} Declaration tLBRACE  Body  tRBRACE{Add_Func($2, $1, get_nbr_instrus_TI());}    
       ;
        
Declaration:
     tLPAR Args tRPAR 
;
Main : 
        tINT tMain { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2); } tLPAR tRPAR tLBRACE Body Return tSEMI tRBRACE {insert_TI("RET",0,0,0);}
    | tVOID  {printf("START MAIN\n");}tMain {actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  } incr_prof tLPAR tRPAR tLBRACE Body tRBRACE {insert_TI("NOP",0,0,0);}
    | tMain { actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  } tLPAR tRPAR tLBRACE Body tRBRACE {insert_TI("NOP",0,0,0);}
    ;



Args :%empty
    |tINT tID {decla_var_TI($<c>2, la_profondeur);} 
    |tINT tID tCOMMA  {decla_var_TI($<c>2, la_profondeur);}Args
     ;

Body :
  %empty 
       |  BodyInstru  Body
        |   BodyDec Body

;

BodyDec :
      tINT Initialisation tSEMI  
    | tCONST Initialisationc tSEMI  

    ;

BodyInstru :
      Printf BodyInstru 
    | Affect tSEMI             
    | incr_prof While  decr_prof
    | incr_prof  If   decr_prof
  
   
     ;


incr_prof : %empty {la_profondeur++;} 
decr_prof :  %empty {la_profondeur--;} 



Initialisationc :
    tID   
    | Affect
    ;

Call:

    tID tLPAR  {push_addr_return(la_profondeur);}Parametre tRPAR {insert_TI("PUSH",search("returnADDR")-1,-1,-1);insert_TI("CALL",search($<c>1),-1,-1); insert_TI("POP",search("returnADDR")-1,-1,-1);} 
   ;
Initialisation : 

     tID   tASSIGN {save_addr_return();  decla_var_TI($<c>1, la_profondeur); } Call  {affect_TI ($1); }
     | tID tASSIGN { decla_var_TI($<c>1, la_profondeur);} Val  {affect_TI ($1); }
    | Initialisation tCOMMA Initialisation  
    |  tID  {decla_var_TI($<c>1, la_profondeur);} 
    ;

Printf : tPRINT tLPAR Val tRPAR tSEMI {printf_TI($<c>3);}  


Affect :
    tID tASSIGN Val   {affect_TI ($1);}
    ;

Val :  
        %empty
    | tID {var_TI($<c>1, la_profondeur);}
    | tNB {nb_TI($<num>1, la_profondeur);}
    | Val Operation 
   
    ;

Operation : 
     tADD  Val {add_TI();} 
    |   tMUL Val {mul_TI();}    
    |   tDIV Val {div_TI();}  
    |   tSUB Val {sub_TI();}
    ;

LVal :
    Val  
    | tLPAR Val tRPAR
    ;

Logic : LVal
    |  LVal tEQ  LVal {  condi_eq_TI() ; } 
    |  LVal tLT  LVal {  condi_lt_TI() ; } 
    |  LVal tGT  LVal {  condi_gt_TI() ; } 
    |  LVal tNE  LVal {  condi_ne_TI() ; } 
    |  LVal tGE  LVal {  condi_ge_TI() ; } 
    |  LVal tLE  LVal {  condi_le_TI() ; } 



If : tIF  tLPAR Logic tRPAR 
        {  
               jmf_body();
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
                jmp_body();
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
               jmf_body();
        }
        BodyCond
        {   jmp_body();
        /*
                int current = get_nbr_instrus_TI();
                actu_jumf(pop_tjump(), current+2);
                insert_TI("JMP",$<num>1,-1,-1);*/
        }
        
        ;

BodyCond :    
        tLBRACE Body tRBRACE    

        ;

Parametre  : 
Val|Val tCOMMA Parametre ;
 /*    %empty
    | tID {var_TI($<c>1, la_profondeur);} { push($<c>1, int_t,la_profondeur);}
    | tNB {nb_TI($<num>1, la_profondeur);}/*{ push("tmp", int_t,la_profondeur);}
    |  Operation 
    |Parametre tCOMMA Parametre
    ;*/

Return :
    tRETURN tLPAR Val tRPAR  
    | tRETURN Val 
    ;



 

%%

void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  
    pile_init();
   // yydebug = 1;
    init_TI();
    init_tjump();
    init_TF();
    yyparse();
   print_TI();
   // afficherPile();
   
    create_file_TI();

   // 
    interpreteuree();
   cross();
    return 0;
}
