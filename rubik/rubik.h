#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define CUBE t_cube cube
#define INVALID 255

extern char g_actions[18][4];
extern char g_edge_pos[12][4];
extern char g_edge_color[12][4];
extern char g_corner_pos[8][4];

enum colors {
    YELLOW,
    BLUE,
    RED,
    GREEN,
    ORANGE,
    WHITE,
};

enum edge_colors {
    YB,
    YR,
    YG,
    YO,
    BO,
    BR,
    GO,
    GR,
    WB,
    WR,
    WG,
    WO,
};

enum edge_pos {
    U_F,
    U_R,
    U_B,
    U_L,
    F_L,
    F_R,
    B_L,
    B_R,
    D_F,
    D_R,
    D_B,
    D_L,
};

enum corner_pos {
    URF,
    ULF,
    URB,
    ULB,
    DRF,
    DLF,
    DRB,
    DLB,
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

typedef struct s_edge {
    uint8_t pos[12];
    uint8_t orientation[12];
}   t_edge;


typedef struct s_corner {
    uint8_t pos[8];
    uint8_t orientation[8];
}   t_corner;

typedef struct s_cube {
    t_edge      edges;
    t_corner    corners;
}   t_cube;

typedef struct s_rotate {
    uint8_t face[5];
}   t_rotate;

char	        **ft_split(char const *s, char c);
void            free_tab(char **tab);

t_cube          init_rubiks();
void            init_actions();
uint8_t         get_action(char *str);
t_cube          init_cube();
void            print_cube(CUBE);

t_cube          handle_action(CUBE, uint8_t action);

void            fill_corner_table(CUBE, uint8_t corner_table[2187]);

t_cube          solve_cube(CUBE);
uint8_t         IDA_algorithm(CUBE);

bool            is_solved(CUBE);
bool            is_phase_1_good(CUBE);
bool            is_white_cross_ok(CUBE);