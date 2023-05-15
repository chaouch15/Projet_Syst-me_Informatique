#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tab_manager.h"
#include "tab_instru.h"

table_instru TI;

void init_TI(){
    TI.nbr_instrus = -1;
}

table_instru get_Tab_instrus(){
    return TI;
}

int insert_TI(char inst[4], int addr_dest, int addr1, int addr2){
    TI.nbr_instrus++;
    strcpy(TI.tab_instrus[TI.nbr_instrus].inst,inst);
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
void actu_jump1(int from, int to){
    TI.tab_instrus[from].addr1 = to;
}

//patch du JUMP
void actu_jump(int from, int to){
    TI.tab_instrus[from].addr_dest = to;
}

//print the table of instru
void print_TI(){
    printf("LIGNE    OPERATION   ADDRESS DEST   ADDRESS 1   ADDRESS 2\n");
    int i;
    for(i=0; i<TI.nbr_instrus+1; i++){
        printf("%d\t  %s\t\t  %d\t\t%d\t  %d\n", i, TI.tab_instrus[i].inst, TI.tab_instrus[i].addr_dest, TI.tab_instrus[i].addr1, TI.tab_instrus[i].addr2);
    }
    printf("\n");
}

//create a file with all the instru into it
void create_file_TI(){
    FILE *file;
    file = fopen("instru.asm", "w");
    int i;
    for (i = 0; i < TI.nbr_instrus+1; i++){
        fprintf(file, "%s   ", TI.tab_instrus[i].inst);
        if(TI.tab_instrus[i].addr_dest != -1) fprintf(file, "%d\t",TI.tab_instrus[i].addr_dest); // on ne print que ce qui est définit
        if(TI.tab_instrus[i].addr1 != -1) fprintf(file, "%d\t",TI.tab_instrus[i].addr1);
        if(TI.tab_instrus[i].addr2 != -1) fprintf(file, "%d\t",TI.tab_instrus[i].addr2);
        fprintf(file,"\n");
    }
    fclose(file);
}

void printf_TI(char variable[4]){
    int addr = get_adresse_Tab(variable);
    insert_TI("PRI", addr, -1, -1);
}

// FONCTION ARITHMETIQUE

void add_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("ADD", stl_addr, stl_addr, addr);
}

void sub_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
   
    insert_TI("SUB", stl_addr, stl_addr, addr);
}

void mul_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("MUL", stl_addr, stl_addr, addr);
}

void div_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("DIV", stl_addr, stl_addr, addr);
}

void nb_TI(int value){
    int addr = insert_tmp_Tab();
    insert_TI("AFC", addr, value, -1);
}

void var_TI(char variable[4]){
    int var_addr = get_adresse_Tab(variable);
    int addr = insert_tmp_Tab();
    insert_TI("COP", addr, var_addr, -1);
}

// FONCTION CONDITIONNELLE

void condi_eq_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("EQU", stl_addr, stl_addr, addr);
}

void condi_ne_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("NE",stl_addr, stl_addr, addr);
}

void condi_gt_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("SUP",stl_addr, stl_addr, addr);
}

void condi_lt_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("INF",stl_addr, stl_addr, addr);
}

void condi_ge_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("SE",stl_addr, stl_addr, addr);
}

void condi_le_TI(){
    int addr = get_last_tmp_addr_Tab();
    int stl_addr = addr-1;
    free_last_tmp_Tab();
    insert_TI("LE",stl_addr, stl_addr, addr);
}

// DECLARATION

void decla_var_TI(char variable[4]){
    insert_Tab(variable);
}

// AFFECTATION

void affect_TI(char variable[4]){
    int addr = get_adresse_Tab(variable);
    int tmp_addr = get_last_tmp_addr_Tab();
    free_last_tmp_Tab();
    insert_TI("COP", addr, tmp_addr, -1);
}


