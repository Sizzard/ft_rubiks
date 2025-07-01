#include "rubik.h"

char g_colors[6][16];
char g_actions[18][4];

void rotate(CUBE, uint8_t action) {
    handle_action(cube, action);
}

void scramble_cube(CUBE, char **instructions) {
    for(size_t i = 0; instructions[i]; i++) {
        rotate(cube, get_action(instructions[i]));
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
    
    uint8_t cube[6][3][3];
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
    
    scramble_cube(cube, instructions);
    puts("");
    print_cube(cube);
    printf("SOLVED : %d\n", is_solved(cube));
    printf("SOLVED : %d\n", is_phase_1_good(cube));    

    free_tab(instructions);
    return 0;
}