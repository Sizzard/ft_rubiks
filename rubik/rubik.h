#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define CUBE uint8_t cube[6][3][3]
#define INVALID 255

extern char g_colors[6][16];
extern char g_actions[18][4];

enum colors {
    WHITE,
    GREEN,
    RED,
    BLUE,
    ORANGE,
    YELLOW,
};

enum actions {
    F,
    R,
    U,
    B,
    L,
    D,
    F2,
    R2,
    U2,
    B2,
    L2,
    D2,
    F_P,
    R_P,
    U_P,
    B_P,
    L_P,
    D_P,
};

typedef struct s_rotate {
    uint8_t face[4];
    uint8_t row[3];
    uint8_t column[3];
}   t_rotate;

char	        **ft_split(char const *s, char c);
void            free_tab(char **tab);

void            init_colors();
void            init_actions();
uint8_t         get_action(char *str);
void            init_cube(CUBE);
void            print_cube(CUBE);

void            handle_action(CUBE, uint8_t action);
void            swap_layer(CUBE, t_rotate rot);
