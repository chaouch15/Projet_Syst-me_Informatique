void appel_function(){
    int offset =  TI_code[index_code][1] ;
     
    while(TI_code[index_code][0] != 19){

     printf (" INSTRU :  %d LIGNE : %d\n",TI_code[index_code][0], index_code);
        
        switch (TI_code[index_code][0]) {
           case 1:
           printf("%d + %d = %d",TI_reg[TI_code[index_code][3] + offset] ,TI_reg[TI_code[index_code][2] + offset] ,TI_reg[TI_code[index_code][1] + offset]  );
             TI_reg[TI_code[index_code][1] + offset] = TI_reg[TI_code[index_code][2] + offset] + TI_reg[TI_code[index_code][3] + offset ]  ;
               break;
           case 2:
              TI_reg[TI_code[index_code][1] + offset] =TI_reg[TI_code[index_code][2] + offset] * TI_reg[TI_code[index_code][3] + offset ]  ;

               break;
           case 3:
              TI_reg[TI_code[index_code][1] + offset] = TI_reg[TI_code[index_code][2] + offset] - TI_reg[TI_code[index_code][3] + offset ]  ;
               break;
           case 4:
               TI_reg[TI_code[index_code][1] + offset] = TI_reg[TI_code[index_code][2] + offset] / TI_reg[TI_code[index_code][3] + offset ]  ;
               break;
           case 5:
               TI_reg[TI_code[index_code][1] + offset] = TI_reg[TI_code[index_code][2] + offset ] ;
              // TI_reg[TI_code[index_code][2] + offset ] = 0;
               break;
           case 6:
           
           TI_reg[TI_code[index_code][1] + offset] = TI_code[index_code][2] + offset  ;
               break;
           case 7:
           printf (" JMP %d",TI_code[index_code][1] + offset);
           index_code =  TI_code[index_code][1] + offset -1;
          //  printf (" index code %d",index_code);
               break;
           case 8:
        
               if(TI_reg[TI_code[index_code][1] + offset] == 0 ){
                index_code = TI_code[index_code][2] + offset- 1 ; }
               break;
           case 9:
           if(TI_code[index_code][2] + offset <TI_code[index_code][3] + offset  ){
                TI_reg[TI_code[index_code][1] + offset] = 1 ;} else{TI_reg[TI_code[index_code][1] + offset] =0;} 
             break;
           case 10:
            if(TI_code[index_code][2] + offset >TI_code[index_code][3] + offset  ){
                TI_reg[TI_code[index_code][1] + offset] = 1 ;} else{TI_reg[TI_code[index_code][1] + offset] =0;} 
             break;
           case 11:
            if(TI_code[index_code][2] + offset == TI_code[index_code][3] + offset  ){
                TI_reg[TI_code[index_code][1] + offset] = 1 ;} else{TI_reg[TI_code[index_code][1] + offset] =0;} 
             break;
           case 12:
                printf("%d\n",TI_reg[TI_code[index_code][1] + offset]) ;
                break;
            case 13:
            
                TI_reg[TI_code[index_code][1] + offset] = index_code+2 ;
            break;
            case 14:
            //    index_code =  TI_reg[TI_code[index_code][1] + offset] ;
            break;
             case 15:
               index_code =  TI_code[index_code][1] + offset - 1 ;
               appel_function();
            break;
            
        }
           

      //  printf("-----%d-----%d \n",index_code,TI_code[index_code][0]);
        index_code= index_code+1;

       // printf("finished %d",index_code);}
   
         for(int i=0; i<10; i++){
            printf("REG %d : %d  \n", i, TI_reg[i]);
          
         } }

          index_code = offset ;
} 

