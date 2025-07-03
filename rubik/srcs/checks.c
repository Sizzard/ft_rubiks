#include "../rubik.h"

bool are_extern_layers_good(CUBE) {
    for(size_t i = 0; i < 12; i++) {
        if (cube.edges.orientation[i] != 0) {
            return false;
        }
    }
    for(size_t i = 0; i < 8; i++) {
        if (cube.corners.orientation[i] != 0) {
            return false;
        }
    }
    return true;
}

bool is_phase_1_good(CUBE) {
    if (are_extern_layers_good(cube))  {
        return true;
    }
    return false;
}

bool is_phase_2_good(CUBE) {
    for(size_t i = 0; i < 12; i++) {
        if (cube.edges.orientation[i] != 0 || cube.edges.pos[i] != i) {
            return false;
        }
        if (i < 8) {
            if (cube.corners.orientation[i] != 0 || cube.corners.pos[i] != i) {
                return false;
            }
        }
    }
    return true;
}

bool is_solved(CUBE) {
    if (is_phase_2_good(cube)) {
        return true;
    }
    return false;
}