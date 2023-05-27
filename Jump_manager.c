#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jump_manager.h"

table_jump Tab_JUMP;

void init_tjump(){
    printf("Jump Table INITIALISATION \n");
    Tab_JUMP.nb_jump = -1;
}

void insert_tjump(int index){
    Tab_JUMP.nb_jump++;
    Tab_JUMP.tab_index[Tab_JUMP.nb_jump] = index;
}

int pop_tjump(){
    int last = Tab_JUMP.tab_index[Tab_JUMP.nb_jump];
    Tab_JUMP.nb_jump--;
    return last;
}