//
// Created by manparvesh on 12/25/18.
//
#import "../../include/stlmp.h"

// defining dimensions of image
#define M 8
#define N 8

void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC) {
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newC;

    // Recur for north, east, south and west
    floodFillUtil(screen, x + 1, y, prevC, newC);
    floodFillUtil(screen, x - 1, y, prevC, newC);
    floodFillUtil(screen, x, y + 1, prevC, newC);
    floodFillUtil(screen, x, y - 1, prevC, newC);
}

void stlmp::algorithms::FloodFill(int screen[][N], int x, int y, int newC) {
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}