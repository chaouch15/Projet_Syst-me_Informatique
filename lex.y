%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.c"
int yylex (void);
void yyerror (const char *);
#define STACKSIZE 200
%}

%define parse.error verbose

%token tIF tELSE tWHILE tPRINT tRETURN tINT tVOID tASSIGN tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA tCOMP tERROR tCONST TYPE PROFONDEUR ADDRESS tTID tADD tMUL tDIV tSUB tEQ tLT tGT tNE tGE tLE
%left tCOMMA
%left tOP
%left tCOMP

%union {
    int num;
    char* c;
}
%token <num> tNB
%token <c> tID


%start Program
%%
Program : 
      %empty
    | Program Statement 
;

Statement:  
     tVOID Declaration tLBRACE Body tRBRACE 
    |tINT Declaration tLBRACE Body Return tSEMI tRBRACE  

Declaration:
    tID tLPAR Args tRPAR 
;

Args :
%empty| tVOID | Arg Args1 ;

Args1 : %empty | tCOMMA Arg Args1 ;

Arg :
     tINT tID  /*{push($<c>2,int_t,la_profondeur);}*/
    ;

Body :
    /*eps*/
    BodyDec BodyInstru    
;

BodyDec :
%empty
    | tINT Initialisation tSEMI BodyDec 
    | tCONST Initialisationc tSEMI BodyDec 
    ;

incr_prof : %empty {la_profondeur++;} 
decr_prof :  %empty {la_profondeur--;} 






Initialisationc :
    tID   
    | tID tASSIGN Val  
    ;

Initialisation :
    tID  {decla_var_TI($1);} {push($<c>1,int_t,la_profondeur);} {printf("je suis là 1");}
    | tID tASSIGN Val  {decla_var_TI($1); affect_TI ($3)}  { push($<c>1, int_t,la_profondeur); }
    | Initialisation tCOMMA Initialisation  {printf("je suis là");}
    ;


Affect :
    tID tASSIGN Val   {affect_TI ($1)}
    ;

Val : 
    tID {var_TI($1);} { push($<c>1, int_t,la_profondeur);}
    | tNB  {nb_TI($1);}{ push("tmp", int_t,la_profondeur);}
    | Val tADD Val {add_TI()} {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("ADD  %%%d %%%d \n ",addr1, addr2);} 
    | Val tMUL Val {mul_TI()}{struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("MUL  %%%d %%%d \n ",addr1, addr2);}   
    | Val tDIV Val {div_TI()} {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3);  printf("DIV  %%%d %%%d \n ",addr1, addr2);}   
    | Val tSUB Val {sub_TI()} {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2);printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUB  %%%d %%%d \n ",addr1, addr2);}   
    | tID tLPAR Parametre tRPAR  
    | tID tLPAR tRPAR   
    ;

LVal :
    Val  
    | LVal tEQ LVal  {  condi_eq_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("EQU  %%%d %%%d \n ",addr1, addr2);} 
    | LVal tLT LVal  {  condi_lt_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("INF  %%%d %%%d \n ",addr1, addr2);} 
    | LVal tGT LVal  {  condi_gt_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("SUP  %%%d %%%d \n ",addr1, addr2);} 
    | LVal tNE LVal  {  condi_ne_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("NEQ  %%%d %%%d \n ",addr1, addr2);} 
    | LVal tGE LVal  {  condi_ge_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("GE  %%%d %%%d \n ",addr1, addr2);} 
    | LVal tLE LVal  {  condi_le_TI() ; } {struct Element* tmp1=pop();struct Element* tmp2=pop();int  addr1=get_adress(tmp1); int addr2= get_adress(tmp2); printf("AFC %%%d %d \n", addr1, $<num>1);printf("AFC %%%d %d \n", addr2, $<num>3); printf("LE  %%%d %%%d \n ",addr1, addr2);} 

    ;

BodyInstru :
      %empty /* c'est ici ou je dois pop? */
    | Affect tSEMI BodyInstru            
    | Printf  BodyInstru 
    | incr_prof While BodyInstru decr_prof
    | incr_prof If BodyInstru decr_prof
    ;


If :   tIF tLPAR LVal tRPAR 
        {
                int condition = get_last_tmp_addr_Tab();
                free_last_tmp_Tab();
                int line = insert_TI("JMPF",condi,-1,-1);
                insert_tjump(line);
        }
        BodyCond
        Else
        ;

Else :  {
                int current = get_nbr_instrus_TI();
                actu_jump1(pop_tjump(), current+1);
        }
       
        |tELSE
       incr_prof {              
                int current = get_nbr_instrus_TI();
                actu_jump1(pop_tjump(), current+2);
                int line = insert_TI("JMP",-1,-1,-1);
                tjmp_insert(line);
        }
        BodyCond
        {
                int current = get_nbr_instrus_TI();
                actu_jump(pop_tjump(), current+1);
        }
        
        ;

While :tWHILE tLPAR LVal tRPAR
        {
                $1 = get_nbr_instrus_TI()-2;
                int condi = get_last_tmp_addr_Tab();
                free_last_tmp_Tab();
                int line = insert_TI("JMPF",condi,-1,-1);
                insert_tjump(line);
        }
        BodyCond
        {
                int current = get_nbr_instrus_TI();
                actu_jump1(pop_tjump(), current+2);
                insert_TI("JMP",$1,-1,-1);
        }
        
        ;

Printf :  tPRINT tLPAR Val tRPAR tSEMI {print_TI($3);}  
BodyCond :    
        tLBRACE Body tRBRACE     
        |tLBRACE Body tRBRACE 
        |tLBRACE Body tRBRACE

        ;

Parametre :
    Val   
    | Val tCOMMA Parametre 
    ;

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
    init_Tab();
    init_TI();
    init_tjump();
    yyparse();
    print_TI();
    print_Tab();
    create_file_TI();


    return 0;
}
