#define SIZE_TAB 100

typedef struct {
    char id[4];
    int addr_dest; 
    int addr1;
    int addr2;
} instru;


typedef struct {
    instru tab_instrus[SIZE_TAB];
    int nbr_instrus;
} table_instru;



int code_instru(char instru[4]);
void init_TI();
table_instru get_Tab_instrus();
int insert_TI(char inst[4], int addr_dest, int addr1, int addr2);
void delete_TI();
int get_nbr_instrus_TI();
void actu_jumf(int from, int to);
void actu_jump(int from, int to);
void print_TI();
void create_file_TI();
void printf_TI(char variable[4]);
void add_TI();
void sub_TI();
void mul_TI();
void div_TI();
void nb_TI(int nvid,int profondeur);
void var_TI(char variable[4], int profondeur);
void condi_eq_TI();
void condi_ne_TI();
void condi_gt_TI();
void condi_lt_TI();
void condi_ge_TI();
void condi_le_TI();
void decla_var_TI(char variable[4] , int profondeur);
void affect_TI(char variable[4]);