#include "dominion.h"
#include "dominion_helpers.h"
#include "test-helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int setDeck(int card1, int card1Count, int card2, int player, struct gameState *G) {
	if (G->deckCount[player] >= card1Count) {
		for (int j = 0; j < card1Count; j++) {
			G->deck[player][j] = card1;
		}
		for (int k = card1Count; k < G->deckCount[player]; k++) {
			G->deck[player][k] = card2;
		}

		return 0;
	}
	else {
		return 1;
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
