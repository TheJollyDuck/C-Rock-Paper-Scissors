



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RPS.h"

void playerMove(playerChoices *player, short choice) {
    player->numPlays++; 
    player->choices = realloc(player->choices, player->numPlays * sizeof(int));
    player->choices[player->numPlays-1] = choice;
}

void incrementWins (playerChoices *player) {
    player->numWins++;
}

void incrementLoss (playerChoices *player) {
    player->numLoss++;
}

short checkMoves(playerChoices *cpu, playerChoices *player, short playerChoice) {
    short cpuChoice = rand() % 3 +1;
    //debug line
    /*printf("%hd", cpuChoice);*/
    // end
    possibilities outcome;
    playerMove(cpu, cpuChoice);
    playerMove(player, playerChoice);

    switch (playerChoice) {

        case 1:

            if (cpuChoice == 1) {
                outcome = draw;
            } else if (cpuChoice == 2) {
                outcome = loss;
            } else {
                outcome = win;
            }           
            break;

        case 2:

            if (cpuChoice == 1) {
                outcome = win;
            } else if (cpuChoice == 2) {
                outcome = draw;
            } else {
                outcome = loss;
            }  
            break;
        
        case 3:

            if (cpuChoice == 1) {
                outcome = loss;
            } else if (cpuChoice == 2) {
                outcome = win;
            } else {
                outcome = draw;
            }  
            break;  

        default:
            break;
    }
    
    return outcome;
}

void printPlayerDetails(playerChoices *player) {
    printf("\n");
    printf("Number of Wins: \t%d\n", player->numWins);
    printf("Number of Losses: \t%d\n", player->numLoss);

    printf(
        "Here are the choices of the player:\n\n"
        "["
    );

    for (uit i = 0; i < player->numPlays; i++) {
        // printf("Choice %d: %s\n", i+1, "Banana");
        if (i % 5 == 0) {
            printf("\n");
        }

        printf("%d: ", i +1);
        //debugging
        /*printf("%d", player->choices[i]);*/
        //end
        switch(player->choices[i]) {
            case 1:
                printf("Rock, ");
                break;

            case 2:
                printf("Paper, ");
                break;

            case 3:
                printf("Scissors, ");
                break;

            default:
                printf("\n[ERROR] : INVALID CHOICE [printPlayerDetails()]\n\n");
                break;
        }
    }
    printf("\n]\n");
}

void printDetails(playerChoices *cpu, playerChoices *player) {
    printf("Number of Plays: \t%zu\n", player->numPlays);
    printf("Printing all the players' move:\n");
    printPlayerDetails(cpu);
    printPlayerDetails(player);
}