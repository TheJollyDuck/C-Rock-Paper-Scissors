


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RPS.h"

void welcome();
short choices();


int main(void) {
    srand(time(NULL));
    welcome();

    playerChoices cpu = {0, NULL, 0 , 0};
    playerChoices player = {0, NULL, 0 , 0};

    bool repeat = true;

    while (repeat) {
        short outcome;
        short choice = choices();

        switch (choice) {
            case 1:
            case 2:
            case 3:

                outcome = checkMoves(&cpu, &player, choice);
                printf("\n");
                
                switch (outcome) {
                    case 1: // Player wins
                        printf("The player wins!\n");
                        incrementWins(&player);
                        incrementLoss(&cpu);
                        break;
                    
                    case 2: // CPU wins
                        printf("The Computer wins!\n");
                        incrementWins(&cpu);
                        incrementLoss(&player);
                        break;
                    
                    case 3: // tie
                        printf("Draw!\n");
                        break;
                    
                    default:
                        printf("ERROR: Invalid outcome\n");
                        break;
                }

                break;

            case 4:
                printDetails(&cpu, &player);
                break;

            case 5:
                printf("Exiting game...\n");
                repeat = false;
                break;
                
            default:
                printf("Invalid choice... \n");
                break;
        }
    }



    printf("Program Completed!\n");
    return 0;
}


void welcome() {

    printf(
        "\n"
        "[]=================================[]\n"
        "||Welcome to Rock, Paper, Scissors!||\n"
        "||         By TheJollyDuck         ||\n"
        "[]=================================[]\n"
        "\n"


        );

}

short choices() {
    short choice;
    printf(
        "\n"
        "Pick your choices:\n"
        "[1] Rock\n"
        "[2] Paper\n"
        "[3] Scissors\n"
        "[4] Print Moves\n"
        "[5] Exit Game \n\n"
        "[int] "
    );

    scanf("%hd", &choice);
    return choice;
}