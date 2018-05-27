#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int setDeck(int card1, int card1Count, int card2, int player, struct gameState *G);

void setHand(int card1, int card1Count, int card2, struct gameState *G);

void setDiscard(int card1, int card1Count, int card2, struct gameState *G);

int deckCount(int player, int card, struct gameState *state);

int handCount(int player, int card, struct gameState *state);

int discardCount(int player, int card, struct gameState *state);
