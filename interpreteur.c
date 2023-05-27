#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include"interpreteur.h"

#define MAX_LINE_LENGTH 1000

int TI_reg[1024];
int TI_code[1024][4];


void read_file(){
    FILE *file;
    char line [100];
    int i = 0;
    file = fopen("instru.txt", "r");
   // printf("file opened");
    if (file == NULL){
        printf("ERROR : FILE EMPTY ");
        exit(1);
    } 
    while (fgets(line, sizeof(line), file)) {
         printf("ok" );
        
        if (sscanf(line, "%d %d %d %d",&TI_code[i][0], &TI_code[i][1], &TI_code[i][2], &TI_code[i][3]) != 4) {
            printf("Error parsing line: %s", line);
            continue;
        }

     
       
        // Increment the row index
        
       
    i++;
   
    // Check if the array is full
    if (i >= 1024) {
        printf("Error: array is full.\n");
        break;
    }


}

/*while(TI_code[index_code][0] != 0){
    printf(" %d  %d  %d  %d\n ",TI_code[index_code][0],TI_code[index_code][1] ,TI_code[index_code][2],TI_code[index_code][3] );
    index_code++ ;}*/
fclose(file);
//printf("file closed");

}

void interpreteuree(){
    read_file();
    int index_code = 0;

    printf("je commence à interpréter");
   // int tab_int[100];
  //  int index_code = 0;
   // char inst[4];

    while(TI_code[index_code][0] != 0){
        switch (TI_code[index_code][0]) {
           case 1:
                TI_reg[1] = TI_code[index_code][2] + TI_code[index_code][3]   ;
               break;
           case 2:
              TI_reg[1] = TI_code[index_code][2] * TI_code[index_code][3] ;
               break;
           case 3:
              TI_reg[1] = TI_code[index_code][2] - TI_code[index_code][3] ;
               break;
           case 4:
               TI_reg[1] = TI_code[index_code][2] / TI_code[index_code][3] ;
               break;
           case 5:
               TI_reg[1] = TI_code[index_code][2]  ;
               break;
           case 6:
                TI_reg[1] = TI_code[index_code][2]  ;
               break;
           case 7:
           index_code =  TI_reg[1]  ;
               break;
           case 8:
               if(TI_code[index_code][0]){
                index_code = TI_code[index_code][1]; }
               break;
           case 9:
           if(TI_code[index_code][2] <TI_code[index_code][3]  ){
                TI_reg[1] = 1 ;} else{TI_reg[1] =0;} 
             break;
           case 10:
            if(TI_code[index_code][2] >TI_code[index_code][3]  ){
                TI_reg[1] = 1 ;} else{TI_reg[1] =0;} 
             break;
           case 11:
            if(TI_code[index_code][2] == TI_code[index_code][3]  ){
                TI_reg[1] = 1 ;} else{TI_reg[1] =0;} 
             break;
           case 12:
                printf("%d\n",TI_reg[TI_code[index_code][1]]) ;
                break;

        }
        index_code++;}
        printf("finished");}
  