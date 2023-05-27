#include "Function_manager.h"

T_func TF;

void init_TF(){
    printf("Functions Table INITIALISATION \n");
    TF.nb_func = 0;
    TF.arg = 0;
}

int Add_Func(char id[20],  int first,    int last){
    Function f;
    strcpy(f.id,id);
    f.first = first;
    f.last = last;
    TF.Tab_F[TF.nb_func] = f;
    TF.nb_func++;
    return 1;
}

int get_first(char id[16]){
    for(int i = 0; i < TF.nb_func; i++){
        if (!strcmp(id, TF.Tab_F[i].id)) {
            return TF.Tab_F[i].first;
        }
    }
    printf("Cette fonction n'existe pas \n");
    return -1;
}

int get_last(char id[16]){
    for(int i = 0; i < TF.nb_func; i++){
        if (!strcmp(id, TF.Tab_F[i].id)) {
            return TF.Tab_F[i].last;
        }
    }
    printf("Cette fonction n'existe pas \n");
    return -1;
}

int get_addr_arg(){
    TF.arg++;
    return 999 - TF.arg + 1;
}

void RST_arg(){
    TF.arg = 0;
}

	

