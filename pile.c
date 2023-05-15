#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "pile.h"


int la_profondeur = 0;
int addr=0;
struct Element * pile = NULL;


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
    nouvelle_pile -> type =nvtype;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    printf("coucouuuuuuuuuu\n ");
    printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->suivant = pile;
        pile = nouvelle_pile;
    }else{
        nouvelle_pile->suivant = NULL;
    }
    addr+=4;
   
    printf(" la profondeur %d\n", la_profondeur);
   }*/


int search (char * id){
    struct Element *aux = malloc(sizeof(*aux));
    aux=pile;
    while (aux->suivant != NULL){
        if (!strcmp(aux->id ,id)){
            return aux->addresse;
        }else{
            
            aux=aux->suivant;
        }
    }
    if (!strcmp(aux->id ,id)){
        return aux->addresse;
}
}
void printElement (Element *actuel){
        printf(" ID =  %s\n", actuel->id);
         printf("TYpe = %d\n", actuel->type);
         printf("PRof = %d\n", actuel->profondeur);
         printf("addr = %d\n", actuel->addresse);
}

void push(char* nvid, enum Type nvtype, int profondeur ){
  
    struct Element *nouvelle_pile = malloc(sizeof(*nouvelle_pile));
    nouvelle_pile->id = nvid;
    nouvelle_pile -> type =nvtype;
    nouvelle_pile -> profondeur = profondeur;
    nouvelle_pile->addresse= addr; 
    printElement(nouvelle_pile);
    if (nouvelle_pile != NULL){
        nouvelle_pile->suivant = pile;
        pile = nouvelle_pile;
    }else{
        nouvelle_pile->suivant = NULL;
    }
    addr+=4;
   
    printf(" la profondeur %d\n", la_profondeur);
   }



Element* pop(){

    if (pile == NULL)  { exit(EXIT_FAILURE);  }

    char* idDepile ;
    int typeDepile ;
    int profondeurDepile ;
    int addresseDepile ;
    Element *elementDepile = pile;
    Element *result=malloc(sizeof(*result));

    if (pile != NULL ){
        
        idDepile = elementDepile->id;
        typeDepile = elementDepile->type;
        profondeurDepile = elementDepile->profondeur;
        addresseDepile = elementDepile->addresse;
       
        
        result->id=idDepile;
        result->type=typeDepile;
        result->profondeur=profondeurDepile;
        result->addresse=addresseDepile;
        pile = elementDepile->suivant;
        free(elementDepile);
        addr-=4;
    }
    return result;
  
}
void afficherPile(){
    if (pile == NULL)   {     exit(EXIT_FAILURE);   }

     Element *actuel = pile;

    while (actuel  != NULL){
        printf("ID = %s\n", actuel->id);
         printf("TYPE = %d\n", actuel->type);
         printf("Pronfonduer = %d\n", actuel->profondeur);
         printf("ADDR = %d\n", actuel->addresse);
         
         actuel = actuel->suivant;
        
         
   

    }

    printf("\n");
}



int main(){
    printf("\nEtat de la pile :\n");
   
    push( "1", 1,1);
    push( "2", 3,2);
    push( "3", 3,2);

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
}
