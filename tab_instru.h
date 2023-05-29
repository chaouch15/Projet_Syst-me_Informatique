#define SIZE_TAB 100

typedef struct {
    int id;
    int addr_dest; 
    int addr1;
    int addr2;
} instru;


typedef struct {
    instru tab_instrus[SIZE_TAB];
    int nbr_instrus;
} table_instru;

void ret_inst();
void call_inst(char id);
char* strip_string(char instru[100]);
const char* convert_instru (int code );
void init_TI();
table_instru get_Tab_instrus();
int insert_TI(int inst, int addr_dest, int addr1, int addr2);
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
void start_main( int la_profondeur);
void decla_var_TI(char variable[4] , int profondeur);
void affect_TI(char variable[4]);
void jmf_body();
void jmp_body();
void pop_return_addr();
void end_nop();
char *strstrip(char *s);
void push_return_addr_func();
void push_return_val_func(char * func);
void push_return_addr();
void push_ret_addr_inst();
void recup_return_func();