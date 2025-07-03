#include "../rubik.h"

t_cube rotate_edges(CUBE, uint8_t edges[4]) {

    uint8_t tmp = edges[0];

    cube.edges.pos[edges[0]] = cube.edges.pos[edges[1]];
    cube.edges.orientation[edges[0]] ^= 1;

    cube.edges.pos[edges[1]] = cube.edges.pos[edges[2]];
    cube.edges.orientation[edges[1]] ^= 1;

    cube.edges.pos[edges[2]] = cube.edges.pos[edges[3]];
    cube.edges.orientation[edges[2]] ^= 1;

    cube.edges.pos[edges[3]] = tmp;
    cube.edges.orientation[edges[3]] ^= 1;

    return cube;
}

t_cube rotate_corners(CUBE, uint8_t corners[4]) {

    uint8_t tmp_pos = cube.corners.pos[corners[0]];
    uint8_t tmp_orient = cube.corners.orientation[corners[0]];

    cube.corners.pos[corners[0]] = cube.corners.pos[corners[1]];
    cube.corners.orientation[corners[0]] = (cube.corners.orientation[corners[1]] + 1) % 3;

    cube.corners.pos[corners[1]] = cube.corners.pos[corners[2]];
    cube.corners.orientation[corners[1]] = (cube.corners.orientation[corners[2]] + 1) % 3;

    cube.corners.pos[corners[2]] = cube.corners.pos[corners[3]];
    cube.corners.orientation[corners[2]] = (cube.corners.orientation[corners[3]] + 1) % 3;

    cube.corners.pos[corners[3]] = tmp_pos;
    cube.corners.orientation[corners[3]] = (tmp_orient + 1) % 3;

    return cube;
    // uint8_t tmp_pos = cube.corners.pos[corners[0]];
    // uint8_t tmp_orientation = cube.corners.orientation[corners[0]];

    // cube.corners.pos[corners[0]] = cube.corners.pos[corners[1]];
    // cube.corners.orientation[corners[0]] = (cube.corners.orientation[corners[1]] + 1) % 3;

    // cube.corners.pos[corners[1]] = cube.corners.pos[corners[2]];
    // cube.corners.orientation[corners[1]] = (cube.corners.orientation[corners[2]] + 1) % 3;


    // cube.corners.pos[corners[2]] = cube.corners.pos[corners[3]];
    // cube.corners.orientation[corners[2]] = (cube.corners.orientation[corners[3]] + 1) % 3;


    // cube.corners.pos[corners[3]] = tmp_pos;
    // cube.corners.orientation[corners[3]] = (tmp_orientation + 1) % 3;

    // return cube;
} 

t_cube rotate_F(CUBE) {
    uint8_t edges[4] = {U_F, F_L, D_F, F_R};
    uint8_t corners[4] = {URF, DRF, DLF,ULF};
    

    cube = rotate_edges(cube, edges);

    cube = rotate_corners(cube, corners);

    return cube;
}

t_cube handle_action(CUBE, uint8_t action) {
    // t_rotate rot = select_colors(action);
    uint8_t limit = 0;
    (void)cube;

    t_cube (*func_ptr)(CUBE) = 0;

    if (action == F || action == F2 || action == F_P) {
        func_ptr = &rotate_F;
    }
    else if (action == R || action == R2 || action == R_P) {
        // func_ptr = &rotate_r;
    }
    else if (action == U || action == U2 || action == U_P) {
        // func_ptr = &rotate_u;
    }
    else if (action == B || action == B2 || action == B_P) {
        // func_ptr = &rotate_b;
    }
    else if (action == L || action == L2 || action == L_P) {
        // func_ptr = &rotate_l;
    }
    else if (action == D || action == D2 || action == D_P) {
        // func_ptr = &rotate_d;
    }
    if (action <= D) {
        limit = 1;
    }
    else if (action <= D2) {
        // limit = 2;
    }
    else {
        // limit = 3;
    }

    for(uint8_t i = 0; i < limit; i++) {
        cube = (*func_ptr)(cube);
    }

    printf("%s ", g_actions[action]);

    return cube;
}