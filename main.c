# gcc -o main main.c
# ./main

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int grid[ROWS][COLS];

void initialize_grid() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void next_generation() {
    int i, j, k, l;
    int neighbors;
    int next_grid[ROWS][COLS];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = 0;
            for (k = i - 1; k <= i + 1; k++) {
                for (l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < ROWS && l >= 0 && l < COLS && !(k == i && l == j)) {
                        neighbors += grid[k][l];
                    }
                }
            }

            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                next_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                next_grid[i][j] = 1;
            } else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

int main() {
    initialize_grid();

    int i;
    for (i = 0; i < 100; i++) {
        system("cls");
        print_grid();
        next_generation();
        usleep(100000);
    }

    return 0;
}
