#include "rubik.h"

char g_colors[6][16];
char g_actions[18][4];

void scramble_cube(CUBE, char **instructions) {
    for(size_t i = 0; instructions[i]; i++) {
        // printf("INSTRUCTION : %s\n", instructions[i]);
        handle_action(cube, get_action(instructions[i]));
        // print_cube(cube);
    }
}

void print_tab(char **tab) {
    if (tab) {
        for(size_t i = 0; tab[i]; i++) {
            printf("%s\n", tab[i]);
        }
    }
}

int main(int ac, char **av) {
    
    // t_facelet cube[6][3][3];
    uint8_t cube[6][3][3];
    uint8_t corner_table[2187];
    uint8_t slice_table[2048];
    char **instructions;
    
    init_actions();

    if (ac != 2) {
        fprintf(stderr, "Error: Arg\n");
        return 1;
    }

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

    init_colors();
    init_cube(cube);

    fill_corner_table(cube, corner_table);
    (void)slice_table;
    
    scramble_cube(cube, instructions);

    print_cube(cube);

    
    // uint8_t phase_1_moves = IDA_algorithm(cube);

    // printf("phase_1_moves : %d\n", phase_1_moves);

    free_tab(instructions);
    return 0;
}