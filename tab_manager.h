#include <stdbool.h>
#define SIZE_TAB 1024

typedef struct {
    char name[10]; // nom de la variable 
    int addr;
    bool tmp; // true si c'est une variable temporaire
} symbole;

typedef struct {
    symbole tab_symboles[SIZE_TAB];
    int nbr_symboles;
} tab_symboles;


void print_Tab();
void init_Tab();
int insert_Tab(char name[10]);
int insert_tmp_Tab();
int get_adresse_Tab(char name[20]);
int get_last_tmp_addr_Tab();
void free_last_tmp_Tab();