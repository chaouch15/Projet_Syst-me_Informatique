#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pile.h"
la_profondeur = 0;
void pile_init(){
    printf("Stack INITIALISATION \n");
    
    addr=0;
    pile = NULL;
}

int get_addr(){
    return addr;
}

int get_profondeur(){
    return la_profondeur;         
}

int get_adress(Element *elmt ){ 
   
    return elmt-> addresse;
}

struct Element * get_haut_pile(){
    return pile;
}

/*void tmp (Element * elmt) {
   
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = nvid;
    nouvelle_pile -> tmp =nvtmp;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    printf("coucouuuuuuuuuu\n ");
    printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
        nouvelle_pile->precedent = NULL;
    }
    addr+=4;
   
    printf(" la profondeur %d\n", la_profondeur);
   }*/


int search (char * id){
    
    struct Element *aux = malloc(sizeof(*aux));
    aux=pile;
    while (aux->precedent != NULL){
        if (!strcmp(aux->id ,id)){
            return aux->addresse;
        }else{
            
            aux=aux->precedent;
        }
    }
    if (!strcmp(aux->id ,id)){
        return (aux->addresse + 1);
}
return -1;
}

int get_addr_pile (char id[20]){
    struct Element *aux = malloc(sizeof(*aux));
    aux=pile;
   
    while (aux->precedent != NULL){
        if (!strcmp(aux->id ,id)){
            return aux->addresse;
        }else{
            aux=aux->precedent;
        }
    }
    
    if (!strcmp(aux->id ,id)){
        return aux->addresse;
    }
    return -1;

}




int get_addr_tmp_pile (){
    
    struct Element *aux = malloc(sizeof(*aux));
    aux=pile;
    while (aux->precedent != NULL){
        if (aux->tmp == true){
            return aux->addresse;
        }else{
            aux=aux->precedent;
        }
    }
    if  (aux->tmp == true){
        return aux->addresse;
    }
return -1;
}

void printElement (Element *actuel){
        printf(" ID =  %s\n", actuel->id);
         printf("tmp = %d\n", actuel->tmp);
         printf("PRof = %d\n", actuel->profondeur);
         printf("addr = %d\n", actuel->addresse);
}

int push(char* nvid, int profondeur ){
   
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = nvid;
    nouvelle_pile -> tmp = false;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    
   //printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
       nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
   
   //printf(" la profondeur !!!%d\n", la_profondeur);
     print_stack();
    addr ++;
    return (addr);
   }

   int push_addr_return( int profondeur ){
   
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = "returnADDR";
    nouvelle_pile -> tmp = false;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    
   //printElement(nouvelle_pile);printf(" la bbbbbbb !!!%d\n", la_profondeur);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
       nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
   
   //printf(" la profondeur !!!%d\n", la_profondeur);
     
   print_stack();
    addr+=1;
    return (addr);
   }

int push_call_retVal_func( char * id, int profondeur ){
    
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = "retVal";
    nouvelle_pile -> tmp = false;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse = addr; 
    
   //printElement(nouvelle_pile);printf(" la bbbbbbb !!!%d\n", la_profondeur);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
       nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
   
   //printf(" la profondeur !!!%d\n", la_profondeur);
     
   print_stack();
   addr+=1;
    return (addr);
   }

   int push_call_addr_func( char * id, int profondeur ){
  
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = id;
    nouvelle_pile -> tmp = false;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse = addr; 
    
   //printElement(nouvelle_pile);printf(" la bbbbbbb !!!%d\n", la_profondeur);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
       nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
   
   //printf(" la profondeur !!!%d\n", la_profondeur);
     
   print_stack();
     addr+=1;
    return (addr);
   }


int push_tmp(int profondeur) {
    
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = "tmp-name";
    nouvelle_pile -> tmp = true;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
   // printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
         nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   // printf("begining push_tmp");
    //printf(" la profondeur %d\n", la_profondeur);
    
    addr+=1;
    
    print_stack();
    return (addr);
   }


Element* pop(){

    if (pile == NULL)  { exit(EXIT_FAILURE);  }

    char* idDepile ;
    int tmpDepile ;
    int profondeurDepile ;
    int addresseDepile ;
    Element *elementDepile = pile;
    Element *result=malloc(sizeof(*result));

    if (pile != NULL ){

        if (elementDepile->tmp  == true){
        
            idDepile = elementDepile->id;
            tmpDepile = elementDepile->tmp;
            profondeurDepile = elementDepile->profondeur;
            addresseDepile = elementDepile->addresse;
        
            
            result->id=idDepile;
            result->tmp=tmpDepile;
            result->profondeur=profondeurDepile;
            result->addresse=addresseDepile;
            pile = elementDepile->precedent;
            free(elementDepile);
            addr-=1;
        }
    }
    print_stack();
    return result;
  
}

Element* pop_end_call(){

    if (pile == NULL)  { exit(EXIT_FAILURE);  }

    char* idDepile ;
    int tmpDepile ;
    int profondeurDepile ;
    int addresseDepile ;
    Element *elementDepile = pile;
    Element *result=malloc(sizeof(*result));

    if (pile != NULL ){

      
        
            idDepile = elementDepile->id;
            tmpDepile = elementDepile->tmp;
            profondeurDepile = elementDepile->profondeur;
            addresseDepile = elementDepile->addresse;
        
            
            result->id=idDepile;
            result->tmp=tmpDepile;
            result->profondeur=profondeurDepile;
            result->addresse=addresseDepile;
            pile = elementDepile->precedent;
            free(elementDepile);
            addr-=1;
        
    }
    print_stack();
    return result;
  
}

void print_stack(){
    if (pile == NULL)   {     exit(EXIT_FAILURE);   }

     Element *actuel = pile;
     printf("-------------------------STACK------------------------------------\n");
         
         
     printf("ID                      tmp         Pronfondeur         ADDRr\n");
    while (actuel  != NULL){
       
       printf("%s\t\t\t   %d\t\t %d\t\t %d\t\t\n", actuel->id, actuel->tmp, actuel->profondeur, actuel->addresse);
         
         actuel = actuel->precedent;
        
         
   

    }

    printf("\n");
}

void save_addr_return () {
    // printf("I am saving return addr");
    return_addr = addr; 

}

int get_addr_return() {
    return return_addr;
} 



void flush_stack(){
     struct Element *aux = malloc(sizeof(*aux));
    aux=pile;
        while (aux->profondeur ==la_profondeur && aux->precedent != NULL){
            aux=aux->precedent;
        }

        if (aux->precedent == NULL){
            pile_init();

        }else{pile = aux;
        }
            
        
    
    la_profondeur--;
   
}

/*
void return_to_addr_main (){
   printf("addr %d ::::::::::", return_addr); Element*  elmt = malloc(sizeof(*elmt));
  elmt = pop();
  printElement(elmt);

  
    while (elmt->addresse != return_addr){
        elmt = pop();
         printElement(elmt);
         printf("addddddddr: %d \n",return_addr);
    
   
    if (elmt != NULL){
        elmt->precedent = pile;
        pile = elmt;
    }else{
       elmt->precedent = NULL;
        pile = elmt;
    }
    }
     
    addr= return_addr;
   push(elmt->id, la_profondeur);
}

*/

/*



int main(){
    pile_init();
    printf("\nEtat de la pile :\n");
   
    push( "1", 1);
    push( "2", 3);
    push( "3", 3);

    afficherPile(pile);
    printf(" Search  Result %d\n",search("3"));
    printf("Je depile \n" );
    printf("here ---- \n");
    printElement(pop(pile));
    printf("Je depile 2 \n" );
    printElement(pop(pile));
 
  printf("Je depile 3 \n" );
    printElement(pop(pile));
   
 
    //printf("Je depile \n");
    //printf(" id depile %d\n",pop(maPile));
    //printf(" id depile %d\n",pop(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(pile);
    return 0;
}*/