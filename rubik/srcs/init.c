#include "../rubik.h"

void init_actions() {
    strcpy(g_actions[0], "F");
    strcpy(g_actions[1], "R");
    strcpy(g_actions[2], "U");
    strcpy(g_actions[3], "B");
    strcpy(g_actions[4], "L");
    strcpy(g_actions[5], "D");
    strcpy(g_actions[6], "F2");
    strcpy(g_actions[7], "R2");
    strcpy(g_actions[8], "U2");
    strcpy(g_actions[9], "B2");
    strcpy(g_actions[10], "L2");
    strcpy(g_actions[11], "D2");
    strcpy(g_actions[12], "F'");
    strcpy(g_actions[13], "R'");
    strcpy(g_actions[14], "U'");
    strcpy(g_actions[15], "B'");
    strcpy(g_actions[16], "L'");
    strcpy(g_actions[17], "D'");
}

void init_edge_pos() {
    strcpy(g_edge_pos[0], "U_F");
    strcpy(g_edge_pos[1], "U_R");
    strcpy(g_edge_pos[2], "U_B");
    strcpy(g_edge_pos[3], "U_L");
    strcpy(g_edge_pos[4], "F_L");
    strcpy(g_edge_pos[5], "F_R");
    strcpy(g_edge_pos[6], "B_L");
    strcpy(g_edge_pos[7], "B_R");
    strcpy(g_edge_pos[8], "D_F");
    strcpy(g_edge_pos[9], "D_R");
    strcpy(g_edge_pos[10], "D_B");
    strcpy(g_edge_pos[11], "D_L");
}

void init_edge_color() {
    strcpy(g_edge_color[0], "YB");
    strcpy(g_edge_color[1], "YR");
    strcpy(g_edge_color[2], "YG");
    strcpy(g_edge_color[3], "YO");
    strcpy(g_edge_color[4], "BO");
    strcpy(g_edge_color[5], "BR");
    strcpy(g_edge_color[6], "GO");
    strcpy(g_edge_color[7], "GR");
    strcpy(g_edge_color[8], "WB");
    strcpy(g_edge_color[9], "WR");
    strcpy(g_edge_color[10], "WG");
    strcpy(g_edge_color[11], "WO");
}

void init_corner_pos() {
    strcpy(g_corner_pos[0], "URF");
    strcpy(g_corner_pos[1], "ULF");
    strcpy(g_corner_pos[2], "URB");
    strcpy(g_corner_pos[3], "ULB");
    strcpy(g_corner_pos[4], "DRF");
    strcpy(g_corner_pos[5], "DLF");
    strcpy(g_corner_pos[6], "DRB");
    strcpy(g_corner_pos[7], "DLB");
}

t_cube init_cube() {
    t_cube cube;

    for(size_t i = 0; i < 12; i++) {
        cube.edges.orientation[i] = 0;
        cube.edges.pos[i] = i;
        if (i < 8) {
            cube.corners.orientation[i] = 0;
            cube.corners.pos[i] = i;
        }
    }
    return cube;
}

t_cube init_rubiks() {

    init_actions();
    init_edge_color();
    init_edge_pos();
    init_corner_pos();

    return init_cube();
}