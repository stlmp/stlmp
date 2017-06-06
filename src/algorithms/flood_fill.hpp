#include <iostream>
using namespace std;

// defining dimensions of image
#define M 8
#define N 8

void flood_fill_util(int screen[][N], int x, int y, int prevC, int newC){
	// Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
 
    // Replace the color at (x, y)
    screen[x][y] = newC;
 
    // Recur for north, east, south and west
    flood_fill_util(screen, x+1, y, prevC, newC);
    flood_fill_util(screen, x-1, y, prevC, newC);
    flood_fill_util(screen, x, y+1, prevC, newC);
    flood_fill_util(screen, x, y-1, prevC, newC);
}

void flood_fill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    flood_fill_util(screen, x, y, prevC, newC);
}