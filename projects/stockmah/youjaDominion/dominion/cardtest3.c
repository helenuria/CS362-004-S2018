// test the great hall card

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
	int pass_count = 0;


	printf("TESTING great hall card\n");

	memset(&G, 23, sizeof(struct gameState));
	initializeGame(2, k, seed, &G);

	int initHandCount = G.handCount[0];
	int initDiscardCount = G.discardCount[0];
	int initActions = G.numActions;
	cardEffect(great_hall, choice1, choice2, choice3, &G, handpos, &bonus);
	int newHandCount = G.handCount[0];
	int newDiscardCount = G.discardCount[0];
	int newActions = G.numActions;

	printf("Expect hand count to remain the same (discard plus draw one)\n");
	if (initHandCount == newHandCount) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("Expect discard to grow by one\n");
	if (initDiscardCount + 1 == newDiscardCount) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("Expect to add an action\n");

	if (initActions + 1 == newActions) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}


	if (pass_count == 3) {
		printf("All tests Passed!\n\n");
		return 0;
	}
	else {
		printf("Test suite failed\n\n");
		return 1;
	}
	return 0;
}
