
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tab_manager.h"

typedef struct {
    char name[10]; // nom de la variable 
    int addr;
    bool tmp; // true si c'est une variable temporaire
} symboles;

typedef struct {
    symboles tab_symboles[SIZE_TAB];
    int nbr_symboles;
} tab_symboles;

tab_symboles Tab_Symb;

void init_Tab(){
    Tab_Symb.nbr_symboles = -1;
}

int insert_Tab(char name[10]){
    Tab_Symb.nbr_symboles++; 
    strcpy(Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].name,name);
    Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].addr = Tab_Symb.nbr_symboles;
    Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].tmp = false;
    return Tab_Symb.nbr_symboles;
}
int insert_tmp_Tab(){
    Tab_Symb.nbr_symboles++; 
    strcpy(Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].name,"tmp_name");
    Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].tmp = true;
    Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].addr = Tab_Symb.nbr_symboles;
 
    return Tab_Symb.nbr_symboles;
}

int get_adresse_Tab(char name[20]){
    for (int i = 0; i < Tab_Symb.nbr_symboles+1; i++){
        if (strcmp(Tab_Symb.tab_symboles[i].name, name) == 0){
            return Tab_Symb.tab_symboles[i].addr;
        }
    }
    return -1;
}

int get_last_tmp_addr_Tab(){
    if (Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].tmp == true){
        return Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].addr;
    }
    printf("probleme get last tmp addr\n");
    return -1;
}

void free_last_tmp_Tab(){
    if (Tab_Symb.tab_symboles[Tab_Symb.nbr_symboles].tmp == true){
        Tab_Symb.nbr_symboles--;
    }
    else {
        printf("probleme free last tmp\n");
    }
}

void print_Tab(){
    printf("NAME | ADDRESS\n");
    for (int i = 0; i < Tab_Symb.nbr_symboles+1; i++){
        printf("%s : \t%d\n", Tab_Symb.tab_symboles[i].name, Tab_Symb.tab_symboles[i].addr);
    }
    printf("\n");
}