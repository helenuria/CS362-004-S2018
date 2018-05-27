// test the fullDeckCount function
// assumes fullDeckCount is supposed to count instances of a specific
// card, and that garden is just implemented wrong

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <time.h>

int main() {
	printf("TESTING fullDeckCount():\n");
	int pass_count = 0;

	struct{
		int deckLen;
		int handLen;
		int discardLen;
		int card;
		int expectval;
		int otherCardLen;
		const char* description;
	} testTable[] = {
		{	
			.deckLen = 2,
			.handLen = 2,
			.discardLen = 2,
			.card = 0,
			.expectval = 6, 
			.otherCardLen = 20,
			.description = "It returns deck + discard + hand if each has cards\n",
		},
		{	
			.deckLen = MAX_DECK,
			.handLen = MAX_HAND,
			.discardLen = MAX_DECK,
			.expectval = 1500, 
			.otherCardLen = 0,
			.description = "It returns deck + discard + hand if each have max cards\n",
			.card = 0,
		},
		{	
			.deckLen = 0,
			.handLen = 0,
			.discardLen = 0,
			.expectval = 0,
			.otherCardLen = 20,
			.card = 0,
			.description = "It returns 0 if there are no cards\n",
		},
		{	
			.deckLen = 2,
			.handLen = 2,
			.discardLen = 2,
			.card = 1,
			.expectval = 6, 
			.otherCardLen = 20,
			.description = "It returns deck + discard + hand for a different card\n",
		},
	};

	for (int i = 0; i < sizeof(testTable) / sizeof(testTable[0]); i++) {

		printf(testTable[i].description);
	
		struct gameState G;
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
		int seed = 1000;

		memset(&G, 23, sizeof(struct gameState));
		initializeGame(2, k, seed, &G);

		G.deckCount[0] = testTable[i].deckLen + testTable[i].otherCardLen;
		for (int j = 0; j < testTable[i].deckLen; j++) {
			G.deck[0][j] = testTable[i].card;
		}
		for (int k = testTable[i].deckLen; k < G.deckCount[0]; k++) {
			G.deck[0][k] = testTable[i].otherCardLen;
		}

		G.handCount[0] = testTable[i].handLen + testTable[i].otherCardLen;  
		for (int j = 0; j < testTable[i].handLen; j++) {
			G.hand[0][j] = testTable[i].card;
		}
		for (int k = testTable[i].handLen; k < G.handCount[0]; k++) {
			G.hand[0][k] = testTable[i].otherCardLen;
		}

		G.discardCount[0] = testTable[i].discardLen + testTable[i].otherCardLen;
		for (int j = 0; j < testTable[i].discardLen; j++) {
			G.discard[0][j] = testTable[i].card;
		}
		for (int k = testTable[i].discardLen; k < G.discardCount[0]; k++) {
			G.discard[0][k] = testTable[i].otherCardLen;
		}


		int retval = fullDeckCount(0, testTable[i].card, &G);


		if (retval == testTable[i].expectval) {
			printf("PASS: %d\n", retval);
			pass_count++;
		}
		else {
			printf("FAIL: %d\n", retval);
		}
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
