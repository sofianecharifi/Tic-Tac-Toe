#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int robot(char grid[9]) 
{
    int move;
    srand(time(NULL));              // initialise le générateur aléatoire
    move = rand() % 9;              // premier tirage (0 à 8)

    while (grid[move] != ' ') 
    {
        move = rand() % 9;
    }

    return move + 1; 
}
