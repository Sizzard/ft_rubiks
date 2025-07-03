#include "rubik.h"

char g_actions[18][4];
char g_edge_pos[12][4];
char g_edge_color[12][4];
char g_corner_pos[8][4];

t_cube scramble_cube(CUBE, char **instructions) {
    for(size_t i = 0; instructions[i]; i++) {
        // printf("INSTRUCTION : %s\n", instructions[i]);
        cube = handle_action(cube, get_action(instructions[i]));
        // print_cube(cube);
    }
    return cube;
}

void print_tab(char **tab) {
    if (tab) {
        for(size_t i = 0; tab[i]; i++) {
            printf("%s\n", tab[i]);
        }
    }
}

int main(int ac, char **av) {
    
    t_cube cube;
    t_cube scrambled_cube;
    // uint8_t corner_table[2187];
    // uint8_t slice_table[2048];
    char **instructions;
    
    if (ac != 2) {
        fprintf(stderr, "Error: Arg\n");
        return 1;
    }
    
    cube = init_rubiks();
    instructions = ft_split(av[1], ' ');
    // print_tab(instructions);

    if (!instructions) {
        fprintf(stderr, "Error: Not enough memory\n");
        return 1;
    }

    for (size_t i = 0; instructions[i]; i++) {
        if (get_action(instructions[i]) == INVALID) {
            free_tab(instructions);
            fprintf(stderr, "Error: Invalid action\n");
            return 1;
        }
    }


    // fill_corner_table(cube, corner_table);
    
    scrambled_cube = scramble_cube(cube, instructions);

    print_cube(scrambled_cube);

    scrambled_cube = solve_cube(scrambled_cube);
    
    // uint8_t phase_1_moves = IDA_algorithm(cube);

    // printf("phase_1_moves : %d\n", phase_1_moves);

    free_tab(instructions);
    return 0;
}