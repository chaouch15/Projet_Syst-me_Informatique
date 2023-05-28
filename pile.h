//#ifndef ELEMENTS_H
//#define ELEMENTS_H
#include <stdbool.h>

typedef struct Element Element;
enum Type { /*déclarer les nouveaux types d'énumération*/
    int_t,
    const_t,
};
struct Element
{
    char* id; 
    bool tmp;
    int profondeur;
    int addresse;
    Element *precedent;
};
#ifndef GLOBAL_H 
#define GLOBAL_H 
 
int addr; 
 
#endif 
int la_profondeur;

int return_addr;
struct Element *pile;
void pile_init();
int get_profondeur();
int get_adress(Element *elmt );
struct Element * get_haut_pile();
int search (char * id);
int get_addr_pile (char id[20]);
int get_addr_tmp_pile ();
void printElement (Element *actuel);
int push(char* nvid, int profondeur );
//void afficherPile()
Element* pop();
int push_tmp(int profondeur) ;
void save_addr_return ();
int push_addr_return(int la_profondeur);
int get_addr_return();



//#endif