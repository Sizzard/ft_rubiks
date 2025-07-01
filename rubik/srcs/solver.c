#include "../rubik.h"

bool is_extern_layer_good(CUBE, uint8_t face) {
    for(size_t row = 0; row < 3; row++) {
        for(size_t column = 0; column < 3; column++) {
            if (cube[face][row][column] != WHITE && cube[face][row][column] != YELLOW ) {
                return false;
            }
        }
    }
    return true;
}

bool is_phase_1_good(CUBE) {
    if (is_extern_layer_good(cube, WHITE) && is_extern_layer_good(cube, YELLOW))  {
        return true;
    }
    return false;
}

bool is_solved(CUBE) {
    for (size_t face = 0; face < 6; face++) {
        for(size_t row = 0; row < 3; row++) {
            for(size_t column = 0; column < 3; column++) {
                if (cube[face][row][column] != face) {
                    return false;
                }
            }
        }
    }
    return true;
}