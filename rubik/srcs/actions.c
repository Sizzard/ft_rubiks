#include "../rubik.h"

t_rotate select_colors(uint8_t action) {
    if (action == F || action == F2 || action == F_P) {
        // puts("F detected\n");
        return (t_rotate){ .face[0] = RED, .face[1] = WHITE, .face[2] = ORANGE, .face[3] = YELLOW, .row[0] = 0, .row[1] = 2, .row[2] = 1, .column[0] = 0, .column[1] = 0, .column[2] = 0};
    }
    else if (action == R || action == R2 || action == R_P) {
        // puts("R detected\n");
        return (t_rotate){ .face[0] = WHITE, .face[1] = BLUE, .face[2] = YELLOW, .face[3] = GREEN, .row[0] = 0, .row[1] = 1, .row[2] = 2, .column[0] = 2, .column[1] = 2, .column[2] = 2};
    }
    else if (action == U || action == U2 || action == U_P) {
        // puts("U detected\n");
        return (t_rotate){ .face[0] = RED, .face[1] = BLUE, .face[2] = ORANGE, .face[3] = GREEN, .row[0] = 2, .row[1] = 2, .row[2] = 2, .column[0] = 0, .column[1] = 1, .column[2] = 2};
    }
    else if (action == B || action == B2 || action == B_P) {
        // puts("B detected\n");
        return (t_rotate){ .face[0] = WHITE, .face[1] = RED, .face[2] = YELLOW, .face[3] = ORANGE, .row[0] = 0, .row[1] = 2, .row[2] = 1, .column[0] = 2, .column[1] = 2, .column[2] = 2};
    }
    else if (action == L || action == L2 || action == L_P) {
        // puts("L detected\n");
        return (t_rotate){ .face[0] = WHITE, .face[1] = GREEN, .face[2] = YELLOW, .face[3] = BLUE, .row[0] = 0, .row[1] = 1, .row[2] = 2, .column[0] = 0, .column[1] = 0, .column[2] = 0};
    }
    else {
        // puts("D detected\n");
        return (t_rotate){ .face[0] = RED, .face[1] = GREEN, .face[2] = ORANGE, .face[3] = BLUE, .row[0] = 0, .row[1] = 0, .row[2] = 0, .column[0] = 0, .column[1] = 1, .column[2] = 2};
    }
}

void handle_action(CUBE, uint8_t action) {
    t_rotate rot = select_colors(action);

    if (action <= D) {
        swap_layer(cube, rot);
    }
    else if (action <= D2) {
        swap_layer(cube, rot);
        swap_layer(cube, rot);
    }
    else if (action <= D_P) {
        swap_layer(cube, rot);
        swap_layer(cube, rot);
        swap_layer(cube, rot);
    }
    printf("%s ", g_actions[action]);
}

void swap_layer(CUBE, t_rotate rot) {
    uint8_t tmp[3];
    uint8_t tmp2[3];

    tmp[0] = cube[rot.face[0]][rot.row[0]][rot.column[0]];
    tmp[1] = cube[rot.face[0]][rot.row[1]][rot.column[1]];
    tmp[2] = cube[rot.face[0]][rot.row[2]][rot.column[2]];
    cube[rot.face[0]][rot.row[0]][rot.column[0]] = cube[rot.face[3]][rot.row[0]][rot.column[0]];
    cube[rot.face[0]][rot.row[1]][rot.column[1]] = cube[rot.face[3]][rot.row[1]][rot.column[1]];
    cube[rot.face[0]][rot.row[2]][rot.column[2]] = cube[rot.face[3]][rot.row[2]][rot.column[2]];
    tmp2[0] = cube[rot.face[1]][rot.row[0]][rot.column[0]];
    tmp2[1] = cube[rot.face[1]][rot.row[1]][rot.column[1]];
    tmp2[2] = cube[rot.face[1]][rot.row[2]][rot.column[2]];
    cube[rot.face[1]][rot.row[0]][rot.column[0]] = tmp[0];
    cube[rot.face[1]][rot.row[1]][rot.column[1]] = tmp[1];
    cube[rot.face[1]][rot.row[2]][rot.column[2]] = tmp[2];
    tmp[0] = cube[rot.face[2]][rot.row[0]][rot.column[0]];
    tmp[1] = cube[rot.face[2]][rot.row[1]][rot.column[1]];
    tmp[2] = cube[rot.face[2]][rot.row[2]][rot.column[2]];
    cube[rot.face[2]][rot.row[0]][rot.column[0]] = tmp2[0];
    cube[rot.face[2]][rot.row[1]][rot.column[1]] = tmp2[1];
    cube[rot.face[2]][rot.row[2]][rot.column[2]] = tmp2[2];
    cube[rot.face[3]][rot.row[0]][rot.column[0]] = tmp[0];
    cube[rot.face[3]][rot.row[1]][rot.column[1]] = tmp[1];
    cube[rot.face[3]][rot.row[2]][rot.column[2]] = tmp[2];
}
