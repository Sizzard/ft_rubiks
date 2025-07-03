#include "../rubik.h"

void free_tab(char **tab) {
    if (tab) {
        for(size_t i = 0; tab[i]; i++) {
            free(tab[i]);
        }
        free(tab);
    }
}

void init_colors() {
    strcpy(g_colors[0], "\x1B[38;5;226m"); // Jaune
    strcpy(g_colors[1], "\x1B[34m"); // Bleu
    strcpy(g_colors[2], "\x1B[31m"); // Rouge
    strcpy(g_colors[3], "\x1B[32m"); // Vert
    strcpy(g_colors[4], "\x1B[38;5;208m"); // Orange
    strcpy(g_colors[5], "\x1B[0m"); // Blanc
}

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

void init_cube(CUBE) {
    // int i = 1;
    for (size_t face = 0; face < 6; face++) {
        for(size_t row = 0; row < 3; row++) {
            for(size_t column = 0; column < 3; column++) {
                cube[face][row][column] = face;
                // cube[face][row][column].orientation = 0;
                // cube[face][row][column] = i++;
            }
        }
    }
}

void print_cube(CUBE) {
    puts("");
    
    for (size_t face = 0; face < 6; face++) {
        // printf("Face : %s\n", g_colors[face]);
        for(size_t row = 0; row < 3; row++) {
            for(size_t column = 0; column < 3; column++) {
                printf("%s ■ %s", g_colors[cube[face][row][column]], g_colors[WHITE]);
                // printf("%d ", cube[face][row][column]);
            }
            puts("");
        }
        puts("");
    }
}
