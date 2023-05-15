#define SIZE_TABLEAU 100

typedef struct {
    int tab_index[SIZE_TABLEAU];
    int nb_jump;
} table_jump;

void init_tjump();
void insert_tjump(int index);
int pop_tjump();