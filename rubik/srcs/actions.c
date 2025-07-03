#include "../rubik.h"

t_rotate select_colors(uint8_t action) {
    if (action == F || action == F2 || action == F_P) {
        // puts("F detected\n");
        return (t_rotate){ .face[0] = YELLOW, .face[1] = RED, .face[2] = WHITE, .face[3] = ORANGE, .face[4] = BLUE};
    }
    else if (action == R || action == R2 || action == R_P) {
        // puts("R detected\n");
        return (t_rotate){ .face[0] = BLUE, .face[1] = YELLOW, .face[2] = GREEN, .face[3] = WHITE, .face[4] = RED};
    }
    else if (action == U || action == U2 || action == U_P) {
        // puts("U detected\n");
        return (t_rotate){ .face[0] = BLUE, .face[1] = ORANGE, .face[2] = GREEN, .face[3] = RED, .face[4] = YELLOW};
    }
    else if (action == B || action == B2 || action == B_P) {
        // puts("B detected\n");
        return (t_rotate){ .face[0] = YELLOW, .face[1] = ORANGE, .face[2] = WHITE, .face[3] = RED, .face[4] = GREEN};
    }
    else if (action == L || action == L2 || action == L_P) {
        // puts("L detected\n");
        return (t_rotate){ .face[0] = BLUE, .face[1] = WHITE, .face[2] = GREEN, .face[3] = YELLOW, .face[4] = ORANGE};
    }
    else{
        // puts("D detected\n");
        return (t_rotate){ .face[0] = BLUE, .face[1] = RED, .face[2] = GREEN, .face[3] = ORANGE, .face[4] = WHITE};
    }
}

void rotate_90_degree(CUBE, uint8_t face) {
    uint8_t original[3][3];

    memcpy(original, cube[face], sizeof(uint8_t [3][3]));
    cube[face][0][0] = original[2][0];
    cube[face][0][1] = original[1][0];
    cube[face][0][2] = original[0][0];
    cube[face][1][0] = original[2][1];
    cube[face][1][1] = original[1][1];
    cube[face][1][2] = original[0][1];
    cube[face][2][0] = original[2][2];
    cube[face][2][1] = original[1][2];
    cube[face][2][2] = original[0][2];
}

void rotate_f(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][2][0];
    tmp[0][1] = cube[rot.face[0]][2][1];
    tmp[0][2] = cube[rot.face[0]][2][2];

    tmp[1][0] = cube[rot.face[1]][2][0];
    tmp[1][1] = cube[rot.face[1]][1][0];
    tmp[1][2] = cube[rot.face[1]][0][0];

    tmp[2][0] = cube[rot.face[2]][0][0];
    tmp[2][1] = cube[rot.face[2]][0][1];
    tmp[2][2] = cube[rot.face[2]][0][2];

    tmp[3][0] = cube[rot.face[3]][2][2];
    tmp[3][1] = cube[rot.face[3]][1][2];
    tmp[3][2] = cube[rot.face[3]][0][2];

    cube[rot.face[0]][2][0] = tmp[3][0];
    cube[rot.face[0]][2][1] = tmp[3][1];
    cube[rot.face[0]][2][2] = tmp[3][2];

    cube[rot.face[1]][0][0] = tmp[0][0];
    cube[rot.face[1]][1][0] = tmp[0][1];
    cube[rot.face[1]][2][0] = tmp[0][2];

    cube[rot.face[2]][0][0] = tmp[1][0];
    cube[rot.face[2]][0][1] = tmp[1][1];
    cube[rot.face[2]][0][2] = tmp[1][2];

    cube[rot.face[3]][0][2] = tmp[2][0];
    cube[rot.face[3]][1][2] = tmp[2][1];
    cube[rot.face[3]][2][2] = tmp[2][2];

    rotate_90_degree(cube,  rot.face[4]);
}

void rotate_r(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][0][2];
    tmp[0][1] = cube[rot.face[0]][1][2];
    tmp[0][2] = cube[rot.face[0]][2][2];

    tmp[1][0] = cube[rot.face[1]][0][2];
    tmp[1][1] = cube[rot.face[1]][1][2];
    tmp[1][2] = cube[rot.face[1]][2][2];

    tmp[2][0] = cube[rot.face[2]][2][0];
    tmp[2][1] = cube[rot.face[2]][1][0];
    tmp[2][2] = cube[rot.face[2]][0][0];

    tmp[3][0] = cube[rot.face[3]][0][2];
    tmp[3][1] = cube[rot.face[3]][1][2];
    tmp[3][2] = cube[rot.face[3]][2][2];

    cube[rot.face[0]][0][2] = tmp[3][0];
    cube[rot.face[0]][1][2] = tmp[3][1];
    cube[rot.face[0]][2][2] = tmp[3][2];

    cube[rot.face[1]][0][2] = tmp[0][0];
    cube[rot.face[1]][1][2] = tmp[0][1];
    cube[rot.face[1]][2][2] = tmp[0][2];

    cube[rot.face[2]][0][0] = tmp[1][2];
    cube[rot.face[2]][1][0] = tmp[1][1];
    cube[rot.face[2]][2][0] = tmp[1][0];

    cube[rot.face[3]][0][2] = tmp[2][0];
    cube[rot.face[3]][1][2] = tmp[2][1];
    cube[rot.face[3]][2][2] = tmp[2][2];

    rotate_90_degree(cube,  rot.face[4]);
}

void rotate_b(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][0][0];
    tmp[0][1] = cube[rot.face[0]][0][1];
    tmp[0][2] = cube[rot.face[0]][0][2];

    tmp[1][0] = cube[rot.face[1]][0][0];
    tmp[1][1] = cube[rot.face[1]][1][0];
    tmp[1][2] = cube[rot.face[1]][2][0];

    tmp[2][0] = cube[rot.face[2]][2][2];
    tmp[2][1] = cube[rot.face[2]][2][1];
    tmp[2][2] = cube[rot.face[2]][2][0];

    tmp[3][0] = cube[rot.face[3]][0][2];
    tmp[3][1] = cube[rot.face[3]][1][2];
    tmp[3][2] = cube[rot.face[3]][2][2];
    
    cube[rot.face[0]][0][0] = tmp[3][0];
    cube[rot.face[0]][0][1] = tmp[3][1];
    cube[rot.face[0]][0][2] = tmp[3][2];

    cube[rot.face[1]][0][0] = tmp[0][2];
    cube[rot.face[1]][1][0] = tmp[0][1];
    cube[rot.face[1]][2][0] = tmp[0][0];

    cube[rot.face[2]][2][0] = tmp[1][0];
    cube[rot.face[2]][2][1] = tmp[1][1];
    cube[rot.face[2]][2][2] = tmp[1][2];

    cube[rot.face[3]][0][2] = tmp[2][0];
    cube[rot.face[3]][1][2] = tmp[2][1];
    cube[rot.face[3]][2][2] = tmp[2][2];


    rotate_90_degree(cube,  rot.face[4]);
}

void rotate_u(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][0][0];
    tmp[0][1] = cube[rot.face[0]][0][1];
    tmp[0][2] = cube[rot.face[0]][0][2];

    tmp[1][0] = cube[rot.face[1]][0][0];
    tmp[1][1] = cube[rot.face[1]][0][1];
    tmp[1][2] = cube[rot.face[1]][0][2];

    tmp[2][0] = cube[rot.face[2]][0][0];
    tmp[2][1] = cube[rot.face[2]][0][1];
    tmp[2][2] = cube[rot.face[2]][0][2];

    tmp[3][0] = cube[rot.face[3]][0][0];
    tmp[3][1] = cube[rot.face[3]][0][1];
    tmp[3][2] = cube[rot.face[3]][0][2];

    cube[rot.face[0]][0][0] = tmp[3][0];
    cube[rot.face[0]][0][1] = tmp[3][1];
    cube[rot.face[0]][0][2] = tmp[3][2];

    cube[rot.face[1]][0][0] = tmp[0][0];
    cube[rot.face[1]][0][1] = tmp[0][1];
    cube[rot.face[1]][0][2] = tmp[0][2];

    cube[rot.face[2]][0][0] = tmp[1][0];
    cube[rot.face[2]][0][1] = tmp[1][1];
    cube[rot.face[2]][0][2] = tmp[1][2];

    cube[rot.face[3]][0][0] = tmp[2][0];
    cube[rot.face[3]][0][1] = tmp[2][1];
    cube[rot.face[3]][0][2] = tmp[2][2];

    rotate_90_degree(cube,  rot.face[4]);
}

void rotate_d(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][2][0];
    tmp[0][1] = cube[rot.face[0]][2][1];
    tmp[0][2] = cube[rot.face[0]][2][2];

    tmp[1][0] = cube[rot.face[1]][2][0];
    tmp[1][1] = cube[rot.face[1]][2][1];
    tmp[1][2] = cube[rot.face[1]][2][2];

    tmp[2][0] = cube[rot.face[2]][2][0];
    tmp[2][1] = cube[rot.face[2]][2][1];
    tmp[2][2] = cube[rot.face[2]][2][2];

    tmp[3][0] = cube[rot.face[3]][2][0];
    tmp[3][1] = cube[rot.face[3]][2][1];
    tmp[3][2] = cube[rot.face[3]][2][2];

    cube[rot.face[0]][2][0] = tmp[3][0];
    cube[rot.face[0]][2][1] = tmp[3][1];
    cube[rot.face[0]][2][2] = tmp[3][2];

    cube[rot.face[1]][2][0] = tmp[0][0];
    cube[rot.face[1]][2][1] = tmp[0][1];
    cube[rot.face[1]][2][2] = tmp[0][2];

    cube[rot.face[2]][2][0] = tmp[1][0];
    cube[rot.face[2]][2][1] = tmp[1][1];
    cube[rot.face[2]][2][2] = tmp[1][2];

    cube[rot.face[3]][2][0] = tmp[2][0];
    cube[rot.face[3]][2][1] = tmp[2][1];
    cube[rot.face[3]][2][2] = tmp[2][2];

    rotate_90_degree(cube,  rot.face[4]);
}

void rotate_l(CUBE, t_rotate rot) {
    uint8_t tmp[4][3];

    tmp[0][0] = cube[rot.face[0]][0][0];
    tmp[0][1] = cube[rot.face[0]][1][0];
    tmp[0][2] = cube[rot.face[0]][2][0];

    tmp[1][0] = cube[rot.face[1]][0][0];
    tmp[1][1] = cube[rot.face[1]][1][0];
    tmp[1][2] = cube[rot.face[1]][2][0];

    tmp[2][0] = cube[rot.face[2]][2][2];
    tmp[2][1] = cube[rot.face[2]][1][2];
    tmp[2][2] = cube[rot.face[2]][0][2];

    tmp[3][0] = cube[rot.face[3]][0][0];
    tmp[3][1] = cube[rot.face[3]][1][0];
    tmp[3][2] = cube[rot.face[3]][2][0];

    cube[rot.face[0]][0][0] = tmp[3][0];
    cube[rot.face[0]][1][0] = tmp[3][1];
    cube[rot.face[0]][2][0] = tmp[3][2];

    cube[rot.face[1]][0][0] = tmp[0][0];
    cube[rot.face[1]][1][0] = tmp[0][1];
    cube[rot.face[1]][2][0] = tmp[0][2];

    cube[rot.face[2]][0][2] = tmp[1][2];
    cube[rot.face[2]][1][2] = tmp[1][1];
    cube[rot.face[2]][2][2] = tmp[1][0];

    cube[rot.face[3]][0][0] = tmp[2][0];
    cube[rot.face[3]][1][0] = tmp[2][1];
    cube[rot.face[3]][2][0] = tmp[2][2];

    rotate_90_degree(cube,  rot.face[4]);
}

void handle_action(CUBE, uint8_t action) {
    t_rotate rot = select_colors(action);
    uint8_t limit;

    void (*func_ptr)(CUBE, t_rotate rot);

    if (action == F || action == F2 || action == F_P) {
        func_ptr = &rotate_f;
    }
    else if (action == R || action == R2 || action == R_P) {
        func_ptr = &rotate_r;
    }
    else if (action == U || action == U2 || action == U_P) {
        func_ptr = &rotate_u;
    }
    else if (action == B || action == B2 || action == B_P) {
        func_ptr = &rotate_b;
    }
    else if (action == L || action == L2 || action == L_P) {
        func_ptr = &rotate_l;
    }
    else if (action == D || action == D2 || action == D_P) {
        func_ptr = &rotate_d;
    }
    if (action <= D) {
        limit = 1;
    }
    else if (action <= D2) {
        limit = 2;
    }
    else {
        limit = 3;
    }

    for(uint8_t i = 0; i < limit; i++) {
        (*func_ptr)(cube, rot);
    }

    // printf("%s ", g_actions[action]);
}