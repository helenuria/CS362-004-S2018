// test the smithy card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int seed = 1000;
	int handpos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int Pass_count = 0;

	initializeGame(2, k, seed, &G);

	printf("TESTING smithy card\n");

	int initDeckCount = G.deckCount[0];
	int initHandCount = G.handCount[0];
	int initDeckCountP2 = G.deckCount[1];
	int initHandCountP2 = G.handCount[1];
	cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
	int newDeckCount = G.deckCount[0];
	int newHandCount = G.handCount[0];
	int newDeckCountP2 = G.deckCount[1];
	int newHandCountP2 = G.handCount[1];

	printf("Expect players deck to lose three cards\n");

	if (newDeckCount == initDeckCount - 3) {
		printf("Pass\n");
		Pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("Expect players hand to gain three cards\n");

	if (newHandCount == initHandCount + 2) {
		printf("Pass\n");
		Pass_count++;
	}
	else {
		printf("Fail\n");
	}
	printf("Expect other players deck not to change\n");

	if (initDeckCountP2 == newDeckCountP2) {
		printf("Pass\n");
		Pass_count++;
	}
	else {
		printf("Fail\n");
	}
	printf("Expect other players hand not to change\n");

	if (initHandCountP2 == newHandCountP2) {
		printf("Pass\n");
		Pass_count++;
	}
	else {
		printf("Fail\n");
	}

	if (Pass_count == 4) {
		printf("All tests Passed!\n\n");
		return 0;
	}
	else {
		printf("Test suite failed\n\n");
		return 1;
	}
	return 0;
}
