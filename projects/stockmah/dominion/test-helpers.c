#include "dominion.h"
#include "dominion_helpers.h"
#include "test-helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void setDeck(int card1, int card1Count, int card2, struct gameState *G) {
		for (int j = 0; j < card1Count; j++) {
			G->deck[0][j] = card1;
		}
		for (int k = card1Count; k < G->deckCount[0]; k++) {
			G->deck[0][k] = card2;
		}
}

void setHand(int card1, int card1Count, int card2, struct gameState *G) {
		for (int j = 0; j < card1Count; j++) {
			G->hand[0][j] = card1;
		}
		for (int k = card1Count; k < G->handCount[0]; k++) {
			G->hand[0][k] = card2;
		}
}

void setDiscard(int card1, int card1Count, int card2, struct gameState *G) {
		for (int j = 0; j < card1Count; j++) {
			G->discard[0][j] = card1;
		}
		for (int k = card1Count; k < G->discardCount[0]; k++) {
			G->discard[0][k] = card2;
		}
}

int deckCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->deckCount[player]; i++)
	{
		if (state->deck[player][i] == card) count++;
	}

	return count;
}
int handCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == card) count++;
	}

	return count;
}
int discardCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == card) count++;
	}

	return count;
}
