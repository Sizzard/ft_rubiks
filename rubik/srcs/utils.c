#include "../rubik.h"

void free_tab(char **tab) {
    if (tab) {
        for(size_t i = 0; tab[i]; i++) {
            free(tab[i]);
        }
        free(tab);
    }
}

// void init_colors() {
//     strcpy(g_colors[0], "\x1B[38;5;226m"); // Jaune
//     strcpy(g_colors[1], "\x1B[34m"); // Bleu
//     strcpy(g_colors[2], "\x1B[31m"); // Rouge
//     strcpy(g_colors[3], "\x1B[32m"); // Vert
//     strcpy(g_colors[4], "\x1B[38;5;208m"); // Orange
//     strcpy(g_colors[5], "\x1B[0m"); // Blanc
// }



uint8_t get_action(char *str) {
    if (str) {
        for (size_t i = 0; i < 18; i++) {
            // printf("COMPARING :%s WITH :%s\n", str, g_actions[i]);
            if (strcmp(g_actions[i], str) == 0) {
                return i;
            }
        }
    }
    return INVALID;
}



void print_cube(CUBE) {
    puts("");
    for (size_t i = 0; i < 12; i++) {
        printf("EDGE pos: %s must be : %s orientation : %d\n", g_edge_pos[cube.edges.pos[i]],  g_edge_pos[i], cube.edges.orientation[i]);
    }
    for (size_t i = 0; i < 8; i++) {
        printf("CORNER pos: %s  must be : %s orientation : %d\n", g_corner_pos[cube.corners.pos[i]], g_corner_pos[i], cube.corners.orientation[i]);        
    }
    puts("");
}
