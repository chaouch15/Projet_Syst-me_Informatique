#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "Jump_manager.h"
#include "tab_instru.h"
#include "pile.h"

table_instru TI;

void init_TI(){
    printf("Instruction Table INITIALISATION \n");
   
    TI.nbr_instrus = -1;
   

}

table_instru get_Tab_instrus(){
    return TI;
}

int insert_TI(int id, int addr_dest, int addr1, int addr2){
    TI.nbr_instrus++;
    TI.tab_instrus[TI.nbr_instrus].id = id;
   // printf("zzzzzzzzzzzz%d" , TI.tab_instrus[TI.nbr_instrus].id);
    TI.tab_instrus[TI.nbr_instrus].addr_dest = addr_dest;
    TI.tab_instrus[TI.nbr_instrus].addr1 = addr1;
    TI.tab_instrus[TI.nbr_instrus].addr2 = addr2;
    return TI.nbr_instrus;
}

//delete last instruction
void delete_TI(){
    TI.nbr_instrus--;
}

int get_nbr_instrus_TI(){
    return TI.nbr_instrus;
}

// patch du JUMPF
void actu_jumf(int from, int to){
    TI.tab_instrus[from].addr1 = to ;
}

//patch du JUMP
void actu_jump(int from, int to){
    TI.tab_instrus[from].addr_dest = to - 1;
}

const char* convert_instru (int code ){
   // printf("CODE ------%d \n",code);

           
        switch (code) {
            case 0 : 
            return "NOP";
            break;
           case 1:
            return "ADD";
               break;
           case 2:
            return "MUL";
               break;
           case 3:
              return "SUB";
              break;
           case 4:
              return "DIV";
              break;
           case 5:
             return  "COP";
             break;
           case 6:
            return  "AFC";
            break;
           case 7:
            return "JMP";
               break;
           case 8:
        return "JMF";
               break;
           case 9:
           return "LT";
             break;
           case 10:
           return "GT";
             break;
           case 11:
           return   "EQ";
             break;
           case 12:
            return "PRI";
                break;
            case 13:
                return  "PUSH";
            break;
            case 14:
             return "POP";
            break;
             case 15:
              return "CALL";
            break;
            case 16:
            return "NE";
            break;
            case 17:
            return "GE";
            break;
            case 18:
            return "LE";
            break;
             case 19:
            return "RET";
            break;
        }
        return "ERROR";
     
    
}
/*
char *strstrip(char *s)
{
        size_t size;
        char *end;

        size = strlen(s);

        if (!size)
                return s;

        end = s + size - 1;
        while (end >= s && isspace(*end))
                end--;
        *(end + 1) = '\0';

        while (*s && isspace(*s))
                s++;
  printf("-------mmmmmmmmmm -------------%s-----------------\n", s );
     
        return s;
}


char * strip_string(char str[100]){
     
    int i,j = 0;
       char  *result[4];
   //  for(i = 0; str[i] != " " ; ++i)
     str = strstrip(str);
     printf("------------------------ASM INSTRUCTIONS -------------%s-----------------\n", str );
     
        while (!( (str[i] >= 'A' && str[i] <= 'Z') || !isspace(str[i] ) ))
        {result[j] = str[i];  printf("------------------------ASM INSTRUCTIONS -------------%s-----------------\n", result );
    
    i ++;
    j++;
        }
   // }
    return result;
} 
*/
//print the table of instru
void print_TI(){
    printf("------------------------ASM INSTRUCTIONS ------------------------------\n");
   printf("LIGNE    OPERATION     CODE       ADDRESS DEST     ADDRESS 1     ADDRESS 2\n");
   
   // char code ;
    
    for(int i=0; i<TI.nbr_instrus+1; i++){
           
           const char* op = convert_instru(TI.tab_instrus[i].id);
 // printf("------------op = %s -------------",op);
        printf("%d\t  %s\t\t  %d\t\t %d\t\t%d\t  %d\n", i, op,TI.tab_instrus[i].id, TI.tab_instrus[i].addr_dest, TI.tab_instrus[i].addr1, TI.tab_instrus[i].addr2);
    }
    
   // printf("----\n");
}

//create a file with all the instru into it
void create_file_TI(){    
   // int code;
    FILE *file;
    file = fopen("instru.txt", "w");
    int i;
    for (i = 0; i < TI.nbr_instrus+1; i++){
       //char * re = TI.tab_instrus[i].id;
     //  fprintf(file, "%s ", re);
     //re = strip_string(TI.tab_instrus[i].id);
        printf("-------CODE----------%d",TI.tab_instrus[i].id);
        fprintf(file, "%d ",TI.tab_instrus[i].id);
        fprintf(file, "%d ",TI.tab_instrus[i].addr_dest); 
        fprintf(file, "%d ",TI.tab_instrus[i].addr1);
        fprintf(file, "%d ",TI.tab_instrus[i].addr2);
        fprintf(file,"\n");
    }
   
    fclose(file);
    printf("finished creating file instructions \n");
   }
  

void printf_TI(char variable[4]){
    int addr = get_addr_pile(variable) ; 
    insert_TI(12, addr, -1, -1);

   
}


void add_TI(){
    int addr = get_addr_tmp_pile(); 
    int stl_addr = addr -1;
    pop(); 
    insert_TI(1, stl_addr, stl_addr, addr);
}

void sub_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
   
    insert_TI(3, stl_addr, stl_addr, addr);
}

void mul_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1 ;
    pop(); 
    insert_TI(2, stl_addr, stl_addr, addr);
}

void div_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr - 1;
    pop(); 
    insert_TI(4, stl_addr, stl_addr, addr);
}

void nb_TI(int nvid,int profondeur){
    int addr = push_tmp(profondeur) -1 ;
    insert_TI(6, addr, nvid, -1);
   
}
void affect_TI(char variable[4]){
    int var_addr =  get_addr_pile(variable) ; 
    int tmp_addr = get_addr_tmp_pile() ; 
    pop(); 
    insert_TI(5, var_addr, tmp_addr, -1);
}



void var_TI(char variable[4], int profondeur){
    int var_addr = get_addr_pile(variable) ;
    int addr = push_tmp(profondeur)-1;
    //pop();
    insert_TI(5, addr, var_addr, -1);
   
}


void condi_eq_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(11, stl_addr, stl_addr, addr);
}

void condi_ne_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(16,stl_addr, stl_addr, addr);
}

void condi_gt_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(10,stl_addr, stl_addr, addr);
}

void condi_lt_TI(){
   
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(9,stl_addr, stl_addr, addr);
}

void condi_ge_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(17,stl_addr, stl_addr, addr);
}

void condi_le_TI(){
    int addr = get_addr_tmp_pile() ; 
    int stl_addr = addr-1;
    pop(); 
    insert_TI(18,stl_addr, stl_addr, addr);
}

void decla_var_TI(char variable[4] , int profondeur){
   // insert_Tab(variable);
 int addr = push(variable , profondeur);
 //printf("ADDR : %d PUSH DECLA VAR : %s ",addr, variable );
    
}

void start_main( int la_profondeur){
    int addr = push_addr_return(la_profondeur)-1;
    push("retVal", la_profondeur);
    insert_TI(13,addr, -1, -1);
} 


void jmf_body(){
     int condition = get_addr_tmp_pile() ; 
    pop(); 
    int line = insert_TI(8,condition,-1,-1);
    insert_tjump(line);
 
} 

void jmp_body(){
    int current = get_nbr_instrus_TI();
    actu_jumf(pop_tjump(), current+2);
    int line = insert_TI(7,-1,-1,-1);
    insert_tjump(line);
} 

void pop_return_addr(){
    insert_TI(14,search("retinst"),-1,-1);}

void push_return_addr(){
    insert_TI(13,search("retinst"),-1,-1);}

void pop_return_val(){
    insert_TI(14,search("retVal")-1,-1,-1);}

void push_return_val(){
    insert_TI(13,search("retVal")-1,-1,-1);}

void end_nop(){
    insert_TI(0,0,0,0);
}
void ret_inst(){
    insert_TI(19,0,0,0);
}
void call_inst(char id){
    insert_TI(15,id,-1,-1);
}
void push_return_addr_func(){
    push("FuncAddr", la_profondeur);}

void push_return_val_func(char * func){
       push(func, la_profondeur);}

void push_ret_addr_inst(){
    int retaddr = push_call_addr_func("retinst" ,la_profondeur);
    push_call_retVal_func("retvalinst",la_profondeur);
   // push_return_addr(retaddr);
}

void recup_return_func(){
   
   insert_TI(5,search("retinst"),search("retVal"),-1);  
  pop();  pop_end_call();    
    pop_end_call();
    
    push_tmp(la_profondeur);

}

// push a laddr ou je suis le nb instruction ou je suis et pop le meme 