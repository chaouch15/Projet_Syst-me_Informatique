#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pile.h"



int la_profondeur;
int addr;
int return_addr;

void pile_init(void){
    printf("Stack INITIALISATION \n");
    la_profondeur = 0;
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
        return aux->addresse;
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
    printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
       nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
   
   // printf(" la profondeur %d\n", la_profondeur);
     
    addr+=1;
    return (addr-1);
   }


int push_tmp(int profondeur) {
    
    
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = "tmp-name";
    nouvelle_pile -> tmp = true;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->precedent = pile;
        pile = nouvelle_pile;
    }else{
         nouvelle_pile->precedent = NULL;
        pile = nouvelle_pile;
    }
   
    printf(" la profondeur %d\n", la_profondeur);
    
    addr+=1;
    
    return (addr-1);
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
    return result;
  
}

void afficherPile(){
    if (pile == NULL)   {     exit(EXIT_FAILURE);   }

     Element *actuel = pile;

    while (actuel  != NULL){
        printf("ID = %s\n", actuel->id);
        printf("tmp = %d\n", actuel->tmp);
        printf("Pronfonduer = %d\n", actuel->profondeur);
        printf("ADDR = %d\n", actuel->addresse);
         
         actuel = actuel->precedent;
        
         
   

    }

    printf("\n");
}

void save_addr_func () {
     printf("I am saving return addr");
    return_addr = addr; 

}

void return_to_addr_func (){
  Element*  elmt = malloc(sizeof(*elmt));
  elmt = pop();
  printElement(elmt);
  
    while (elmt->addresse != return_addr){
        elmt = pop();
         printElement(elmt);
         printf("addddddddr: %d \n",return_addr);
    }
   
    if (elmt != NULL){
        elmt->precedent = pile;
        pile = elmt;
    }else{
       elmt->precedent = NULL;
        pile = elmt;
    }
   
     
    addr= return_addr;
   
}




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