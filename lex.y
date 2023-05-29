%{
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "tab_instru.h"
#include "interpreteur.h"
#include "Function_manager.h"
#include "cross_compiler.h"
#include "Jump_manager.h"

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
            tINT tID  incr_prof { start_func(); push_return_addr_func();push_return_val_func($<c>2); printf("Function done\n"); } Declaration tLBRACE   Body  Return {affect_TI ($<c>2);}tSEMI tRBRACE { Add_Func($2,  search($<c>2), get_nbr_instrus_TI());ret_inst();flush_stack();}
         | tVOID tID incr_prof {start_func();push_return_addr_func();push_return_val_func($<c>2);  $<num>1 = get_nbr_instrus_TI() + 1;} Declaration tLBRACE  Body  tRBRACE{Add_Func($2, $1, get_nbr_instrus_TI());ret_inst();flush_stack();}    
       ;
        
Declaration:
     tLPAR Args tRPAR 
;
Main : 
        tINT tMain incr_prof {push_return_addr_func();push_return_val_func($<c>2);  actu_jump(pop_tjump(), get_nbr_instrus_TI()+2); } tLPAR tRPAR tLBRACE Body Return tSEMI tRBRACE {ret_inst(); end_nop(); flush_stack(); }
    | tVOID  incr_prof {push_return_addr_func();push_return_val_func("void"); printf("START MAIN\n");}tMain {actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  }  tLPAR tRPAR tLBRACE Body tRBRACE {ret_inst();end_nop(); flush_stack(); }
    | tMain incr_prof { push_return_addr_func();push_return_val_func($<c>1); actu_jump(pop_tjump(), get_nbr_instrus_TI()+2);  } tLPAR tRPAR tLBRACE Body tRBRACE { ret_inst();end_nop();flush_stack(); }
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
    | incr_prof While  {flush_stack();}
    | incr_prof  If   {flush_stack();}
   
     ;


incr_prof : %empty {la_profondeur++;} 
decr_prof :  %empty {la_profondeur--;} 



Initialisationc :
    tID   
    | Affect
    ;

Call:

    tID tLPAR incr_prof {push_ret_addr_inst();} Parametre tRPAR {push_return_addr();call_inst(get_first($<c>1)); pop_return_addr(); recup_return_func();} 
   ;
Initialisation : 

     tID   tASSIGN {save_addr_return();  decla_var_TI($<c>1, la_profondeur); } Call  {affect_TI ($1); flush_stack();}
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
