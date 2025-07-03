#include "../rubik.h"

uint8_t do_all_turns(CUBE, uint8_t inner_depth, uint8_t max_depth) {
    uint8_t original_state[6][3][3];
    
    if (is_phase_1_good(cube)) {
        // puts("PHASE 1 GOOD");
        return 0;
    }
    else if (inner_depth >= max_depth) {
        return INVALID;
    }

    memcpy(original_state, cube, sizeof(uint8_t [6][3][3]));


    for (uint8_t i = 0; i < 18; i++) {
        if (do_all_turns(cube, inner_depth + 1, max_depth) == 0) {
            return 0;
        }
        memcpy(cube, original_state, sizeof(uint8_t [6][3][3]));
        printf("%s ", g_actions[i]);
        handle_action(cube, i);
    }
    // puts("INVALID BRANCH");
    return INVALID;
}

uint8_t IDA_algorithm(CUBE) {
    uint8_t original_state[6][3][3];
    uint8_t moves[32];

    memset(moves, INVALID, sizeof(uint8_t) * 32);
    memcpy(original_state, cube, sizeof(uint8_t [6][3][3]));

    for (uint8_t depth = 0; depth != INVALID; depth++) {
        uint8_t move = do_all_turns(cube, 0, depth);
        printf("RETURNED : %hhu\n", move);
        if (move != INVALID) {
            puts("\n PHASE 1 GOOD");
            print_cube(cube);
            return depth;
        }

    }
    // puts("\nPHASE 1 NOT GOOD");
    return INVALID;
}
