#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include"interpreteur.h"


#define MAX_LINE_LENGTH 1000

int TI_reg[1024];
int TI_code[1024][4];
int size=0;
index_code=0;

void read_file(){
    FILE *file;
    char line [100];
    int i = 0;
    file = fopen("instru.txt", "r");
    if (file == NULL){
        printf("ERROR : FILE EMPTY ");
        exit(1);
    } 
    while (fgets(line, sizeof(line), file)) {
         //printf("ok" );
        
        if (sscanf(line, "%d %d %d %d",&TI_code[i][0], &TI_code[i][1], &TI_code[i][2], &TI_code[i][3]) != 4) {
            printf("Error parsing line: %s", line);
            continue;
        }
    i++;
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
    

    printf("je commence à interpréter \n");
   // int tab_int[100];
  //  int index_code = 0;
   // char inst[4];
//for (int i = 0; i < 9; i++){
 //printf("'''''''''''%d %d ",i,TI_code[i][1] );}
    while(TI_code[index_code][0] != 0){

    int i ;
        
        switch (TI_code[index_code][0]) {
           case 1:
           printf("%d + %d = %d",TI_reg[TI_code[index_code][3]] ,TI_reg[TI_code[index_code][2]] ,TI_reg[TI_code[index_code][1]]  );
             TI_reg[TI_code[index_code][1]] = TI_reg[TI_code[index_code][2]] + TI_reg[TI_code[index_code][3] ]  ;
               break;
           case 2:
              TI_reg[TI_code[index_code][1]] =TI_reg[TI_code[index_code][2]] * TI_reg[TI_code[index_code][3] ]  ;

               break;
           case 3:
              TI_reg[TI_code[index_code][1]] = TI_reg[TI_code[index_code][2]] - TI_reg[TI_code[index_code][3] ]  ;
               break;
           case 4:
               TI_reg[TI_code[index_code][1]] = TI_reg[TI_code[index_code][2]] / TI_reg[TI_code[index_code][3] ]  ;
               break;
           case 5:
               TI_reg[TI_code[index_code][1]] = TI_reg[TI_code[index_code][2] ] ;
              // TI_reg[TI_code[index_code][2] ] = 0;
               break;
           case 6:
           
           TI_reg[TI_code[index_code][1]] = TI_code[index_code][2]  ;
               break;
           case 7:
          // printf (" JMP %d",TI_code[index_code][1]);
           index_code =  TI_code[index_code][1]-1 ;
          //  printf (" index code %d",index_code);
               break;
           case 8:
        
               if(TI_reg[TI_code[index_code][1]] == 0 ){
                index_code = TI_code[index_code][2]- 1 ; }
               break;
           case 9:
           if(TI_code[index_code][2] <TI_code[index_code][3]  ){
                TI_reg[TI_code[index_code][1]] = 1 ;} else{TI_reg[TI_code[index_code][1]] =0;} 
             break;
           case 10:
            if(TI_code[index_code][2] >TI_code[index_code][3]  ){
                TI_reg[TI_code[index_code][1]] = 1 ;} else{TI_reg[TI_code[index_code][1]] =0;} 
             break;
           case 11:
            if(TI_code[index_code][2] == TI_code[index_code][3]  ){
                TI_reg[TI_code[index_code][1]] = 1 ;} else{TI_reg[TI_code[index_code][1]] =0;} 
             break;
           case 12:
                printf("%d\n",TI_reg[TI_code[index_code][1]]) ;
                break;
            case 13:
                TI_reg[TI_code[index_code][1]] = index_code ;
            break;
            case 14:
               // index_code =  TI_reg[TI_code[index_code][1]] ;
            break;
             case 15:
               // index_code =  TI_code[index_code][1] ;
            break;
        }
        
      //  printf("-----%d-----%d \n",index_code,TI_code[index_code][0]);
        index_code= index_code+1;

       // printf("finished %d",index_code);}
       }
       int i;
         for(i=0; i<10; i++){
            printf("REG %d : %d  \n", i, TI_reg[i]);
          
         }
} 