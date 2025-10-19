#include <stdlib.h>
#include <stdio.h>
#include "robot.h" 

void print_grid(char *grid) //création de la grille
{
    printf("%c |%c |%c \n", grid[0], grid[1], grid[2]);
    printf("--------\n");
    printf("%c |%c |%c \n", grid[3], grid[4], grid[5]);
    printf("--------\n");
    printf("%c |%c |%c \n", grid[6], grid[7], grid[8]);
}

int game(int numero)
{
    int choice;
    char grid[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int win = 0;
    int turn = 0; // 0 = joueur, 1 = robot

    while (win == 0)
    {
        print_grid(grid);

        if (turn == 0) {
            // Tour du joueur
            printf("Choisissez un numero de case entre 1 et 9 : ");
            scanf("%d", &choice);

            if(choice < 1 || choice > 9 || grid[choice-1] != ' ') {
                printf("Case invalide, recommencez.\n");
                continue;
            }

            grid[choice - 1] = 'O';

            // Vérification victoire joueur
            if((grid[0] == 'O' && grid[1] == 'O' && grid[2] == 'O') ||
               (grid[3] == 'O' && grid[4] == 'O' && grid[5] == 'O') ||
               (grid[6] == 'O' && grid[7] == 'O' && grid[8] == 'O') ||
               (grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O') ||
               (grid[2] == 'O' && grid[4] == 'O' && grid[6] == 'O')) 
            {
                print_grid(grid);
                printf("Vous avez gagné !\n");
                win = 1;
                break;
            }
        } else {
            // Tour du robot
            int move = robot(grid); 
            printf("Le robot joue en case %d\n", move);
            grid[move - 1] = 'X';

            // Vérification victoire robot
            if((grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X') ||
               (grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X') ||
               (grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X') ||
               (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X') ||
               (grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X')) {
                print_grid(grid);
                printf("Le robot a gagné !\n");
                win = 1;
                break;
            }
        }

        // Match nul (grille pleine)
        int full = 1;  

        if(grid[0] == ' ' || grid[1] == ' ' || grid[2] == ' ' ||
        grid[3] == ' ' || grid[4] == ' ' || grid[5] == ' ' ||
        grid[6] == ' ' || grid[7] == ' ' || grid[8] == ' ') 
        {
        full = 0; 
        }

        if(full == 1) {
        print_grid(grid);
        printf("Match nul !\n");
        break;
}


        // on passe au tour suivant
        turn = 1 - turn;
    }
    return(numero); 
}
