#ifndef ELEMENTS_H
#define ELEMENTS_H

typedef struct Element Element;
enum Type { /*déclarer les nouveaux types d'énumération*/
    int_t,
    const_t,
};
struct Element
{
    char* id; 
    int type;
    int profondeur;
    int addresse;
    Element *suivant; 
};
extern int addr;
extern int la_profondeur;
extern struct Element *pile;

void push(char* nvid, enum Type nvtype, int profondeur);

Element* pop();

#endif