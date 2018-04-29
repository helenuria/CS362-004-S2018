// test the shuffle function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("TESTING shuffle():\n");
	int pass_count = 0;
	int seed = 1000;

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(2, k, seed, &G);

	// 

	printf("Deck has the same count before and after shuffle\n");
	int initDeckCount = G.deckCount[0];
	shuffle(0, &G);
	int shuffledDeckCount = G.deckCount[0];
	if (initDeckCount == shuffledDeckCount) {
		printf("PASS\n");
		pass_count++;
	}
	else {
		printf("FAIL\n");
	}

	// 
	
	printf("Hand has the same count before and after shuffle\n");
	int initHandCount = G.handCount[0];
	shuffle(0, &G);
	int shuffledHandCount = G.handCount[0];
	if (initHandCount == shuffledHandCount) {
		printf("PASS\n");
		pass_count++;
	}
	else {
		printf("FAIL\n");
	}

	// 

	printf("Discard has the same count before and after shuffle\n");
	int initDiscardCount = G.discardCount[0];
	shuffle(0, &G);
	int shuffledDiscardCount = G.discardCount[0];
	if (initDiscardCount == shuffledDiscardCount) {
		printf("PASS\n");
		pass_count++;
	}
	else {
		printf("FAIL\n");
	}

	// 
	
	printf("Deck is in a new order after shuffle\n");
	int oldDeck[G.deckCount[0]];
	int samePosCount = 0;
	for (int i = 0; i < G.deckCount[0]; i++) {
		oldDeck[i] = G.deck[0][i];
	}
	shuffle(0, &G);
	for (int i = 0; i < G.deckCount[0]; i++) {
		if (oldDeck[i] == G.deck[0][i]) {
			samePosCount++;
		}
	}

	if (samePosCount != G.deckCount[0]) {
		printf("PASS: %d\n", samePosCount);
		pass_count++;
	}
	else {
		printf("FAIL: %d\n", samePosCount);
	}

	if (pass_count == 4) {
		printf("All tests passed!\n\n");
		return 0;
	}
	else {
		printf("Test suite failed\n\n");
		return 1;
	}
}
