#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_T_Functions 1000

typedef struct Function {
    char id[20];
    int first;
    int last;
} Function;

typedef struct T_func {
    Function Tab_F[SIZE_T_Functions];
    int nb_func;
    int n_JMF, n_JMP, arg;

}T_func;

void init_TF();
int Add_Func(char id[20],  int first,    int last);
int get_first(char id[20]);
int get_last(char id[20]);
int get_addr_arg();
void RST_arg();
void start_func();