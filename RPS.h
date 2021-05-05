


#ifndef RPS_INCL
#define RPS_INCL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uit;

typedef struct playerChoices {
    size_t numPlays;

    int *choices;    
    int numWins;
    int numLoss;

} playerChoices;

typedef enum possibilities {
    win  = 1,
    loss = 2,
    draw = 3
} possibilities;

void playerMove(playerChoices *, short);
void incrementWins(playerChoices *);
void incrementLoss(playerChoices *);
short checkMoves(playerChoices *, playerChoices *, short);

void printPlayerDetails(playerChoices *);
void printDetails(playerChoices *, playerChoices *);

#endif