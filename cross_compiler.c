#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include"interpreteur.h"



#define MAX_LINE_LENGTH 1000

int TI_reg[1024];
int TI_code[1024][4];

void read_file_cross(){
    FILE *file;
    char line [100];
    int i = 0;
    file = fopen("instru.txt", "r");
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
 FILE * create_file_Cross(){    
    FILE *file;
    file = fopen("cross.txt", "w");
    return file;
    
   }

   void write_in( FILE *file,int code, int addr_dest, int addr1, int addr2){
     //printf("%d %d %d %d \n", code,  addr_dest,  addr1,  addr2);
        fprintf(file, "%d ", code);
        fprintf(file, "%d ",addr_dest); 
        fprintf(file, "%d ",addr1);
        fprintf(file, "%d ",addr2);
        fprintf(file,"\n");

   }


void cross(){
     read_file_cross();
     printf("CROSS-COMPILER START");
     FILE *file_cross = create_file_Cross();
     int index_code = 0;
  while(TI_code[index_code][0] != 0){ 
        switch (TI_code[index_code][0]) {
            case 0 : 
               write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );

           case 1:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
               write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
               write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
               break;
           case 2:
               write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
               break;
           case 3:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
                break;
           case 4:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
                break;
           case 5:
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
                break;
           case 6:
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
           case 7:
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                break;
           case 8:
                write_in(file_cross, 16,TI_code[index_code][1],TI_code[index_code][1],-1   );
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][2],-1   );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
               
               break;
           case 9:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
             break;
           case 10:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
                 break;
           case 11:
                write_in(file_cross, 16,TI_code[index_code][3],TI_code[index_code][3],-1  );
                write_in(file_cross, 16,TI_code[index_code][2],TI_code[index_code][2],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],TI_code[index_code][1],-1  );
                 break;
           case 12:
                write_in(file_cross, 16,TI_code[index_code][1],TI_code[index_code][1],-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                break;
            case 13:
                write_in(file_cross, 16,TI_code[index_code][1],-1,-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],-1,-1  );
                 break;
     
            case 14:
                write_in(file_cross, 16,TI_code[index_code][1],-1,-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],-1,-1  );
                 break;
            case 15:
                write_in(file_cross, 16,TI_code[index_code][1],-1,-1  );
                write_in(file_cross, TI_code[index_code][0],TI_code[index_code][1],TI_code[index_code][2],TI_code[index_code][3]   );
                write_in(file_cross, 17,TI_code[index_code][1],-1,-1  );
                break;
     

        }
        index_code++;}
        printf("finished");}
  