#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tab_instru.h"
#include "pile.h"

table_instru TI;

void init_TI(){
    printf("Instruction Table INITIALISATION \n");
    int line = insert_TI("JMP  ",-1,-1,-1); 
    insert_tjump(line); 
    TI.nbr_instrus = 0;
   

}

table_instru get_Tab_instrus(){
    return TI;
}

int insert_TI(char id[4], int addr_dest, int addr1, int addr2){
    TI.nbr_instrus++;
    strcpy(TI.tab_instrus[TI.nbr_instrus].id,id);
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
    TI.tab_instrus[from].addr1 = to;
}

//patch du JUMP
void actu_jump(int from, int to){
    TI.tab_instrus[from].addr_dest = to;
}

int convert_instru (char instru[4] ){
     if  (strcmp(instru,"NOP" )== 0){
        return 0;}
     else if (strcmp(instru, "ADD")==0){
        return 1;
        }else if (strcmp(instru, "MUL" ) == 0){
        return 2;
         }else if (strcmp(instru, "SUB" )== 0){
        return 3; 
        }else if (strcmp(instru, "DIV" )== 0){
        return 4;}
         else if  (strcmp(instru, "COP" )== 0){
        return 5;}
         else if  (strcmp(instru, "AFC" )== 0){
        return 6;}
         else if  (strcmp(instru, "JMP" )== 0){
        return 7;}
          else if  (strcmp(instru,"JMF" )== 0){
        return 8;}
        else if  (strcmp(instru, "LT")== 0){
        return 9;}
        else if  (strcmp(instru, "GT" )== 0){
        return 10;}
        else if  (strcmp(instru, "EQU")== 0){
        return 11;}
        else if  (strcmp(instru, "PRI" )== 0){
        return 12;} 
         else if  (strcmp(instru, "PUSH" )== 0){
        return 13;} 
         else if  (strcmp(instru, "POP" )== 0){
        return 14;} 
         else if  (strcmp(instru, "CALL" )== 0){
        return 15;} 
        else return -1;
    
     
    
}

//print the table of instru
void print_TI(){
    printf("------------------------ASM INSTRUCTIONS ------------------------------\n");
    printf("LIGNE    OPERATION     CODE   ADDRESS DEST   ADDRESS 1   ADDRESS 2\n");
    int i;
    int code ;
    for(i=0; i<TI.nbr_instrus+1; i++){
         code = convert_instru(TI.tab_instrus[i].id);

        printf("%d\t  %s\t\t %d\t\t %d\t\t%d\t  %d\n", i, TI.tab_instrus[i].id, code , TI.tab_instrus[i].addr_dest, TI.tab_instrus[i].addr1, TI.tab_instrus[i].addr2);
    }
    
    printf("----\n");
}

//create a file with all the instru into it
void create_file_TI(){    
    int code;
    FILE *file;
    file = fopen("instru.txt", "wr");
    int i;
    for (i = 0; i < TI.nbr_instrus+1; i++){
     //   fprintf(file, "%s ", TI.tab_instrus[i].inst);
         code = convert_instru(TI.tab_instrus[i].id);
          fprintf(file, "%d ", code);
        /*if(TI.tab_instrus[i].addr_dest != -1) */fprintf(file, "%d ",TI.tab_instrus[i].addr_dest); 
      /*  if(TI.tab_instrus[i].addr1 != -1)*/ fprintf(file, "%d ",TI.tab_instrus[i].addr1);
       /* if(TI.tab_instrus[i].addr2 != -1) */fprintf(file, "%d ",TI.tab_instrus[i].addr2);
        fprintf(file,"\n");
    }
   
    fclose(file);
    printf("finished creating file instructions \n");
   }
  

void printf_TI(char variable[4]){
    int addr = get_addr_pile(variable) ; 
    insert_TI("PRI", addr, -1, -1);

   
}



// FONCTION ARITHMETIQUE

void add_TI(){
    int addr = get_addr_tmp_pile()+1 ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr -1;
    pop(); //free_last_tmp_Tab();
    insert_TI("ADD", stl_addr, stl_addr, addr);
}

void sub_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
   
    insert_TI("SUB", stl_addr, stl_addr, addr);
}

void mul_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1 ;
    pop(); //free_last_tmp_Tab();
    insert_TI("MUL", stl_addr, stl_addr, addr);
}

void div_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr - 1;
    pop(); //free_last_tmp_Tab();
    insert_TI("DIV", stl_addr, stl_addr, addr);
}

void nb_TI(int nvid,int profondeur){
    int addr = push_tmp(profondeur) ;
     printf("gggggggggggg");
     // insert_tmp_Tab();
    insert_TI("AFC", addr, nvid, -1);
   
}
void affect_TI(char variable[4]){
    int var_addr =  get_addr_pile(variable) +1 ; // get_adresse_Tab(variable);
    int tmp_addr = get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    pop(); //free_last_tmp_Tab();
    insert_TI("COP", var_addr, tmp_addr, -1);
}



void var_TI(char variable[4], int profondeur){
    int var_addr = get_addr_pile(variable);
    int addr = push_tmp(profondeur) ;// insert_tmp_Tab();
    insert_TI("COP", addr, var_addr, -1);
   
}

// FONCTION CONDITIONNELLE

void condi_eq_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("EQU", stl_addr, stl_addr, addr);
}

void condi_ne_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("NE",stl_addr, stl_addr, addr);
}

void condi_gt_TI(){
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("GT",stl_addr, stl_addr, addr);
}

void condi_lt_TI(){
   
    int addr = get_addr_tmp_pile() ; // get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("LT",stl_addr, stl_addr, addr);
}

void condi_ge_TI(){
    int addr = get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("GE",stl_addr, stl_addr, addr);
}

void condi_le_TI(){
    int addr = get_addr_tmp_pile() ; // get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    pop(); //free_last_tmp_Tab();
    insert_TI("LE",stl_addr, stl_addr, addr);
}

// DECLARATION

void decla_var_TI(char variable[4] , int profondeur){
   // insert_Tab(variable);
   push(variable , profondeur);
    
}

void start_main( int la_profondeur){
    int addr = push_addr_return(la_profondeur);
    insert_TI("PUSH",addr, -1, -1);
} 




