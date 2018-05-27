// test the isGameOver function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("TESTING isGameOver():\n");
	int pass_count = 0;
	int retval;

	struct{
		int provinceCount;
		int supplyCount[4];
		int expectval;
		const char* description;
	} testTable[] = {
		{	
			.provinceCount = 5, 
			.supplyCount = {5, 5, 5, 5},
			.expectval = 0, 
			.description = "It returns 0 if province count is positive " 
				"and at least 3 supply counts are postive\n",
		},
		{	
			.provinceCount = 0, 
			.supplyCount = {5, 5, 5, 5},
			.expectval = 1, 
			.description = "It returns 1 if province count is zero\n",
		},
		{	
			.provinceCount = 5, 
			.supplyCount = {0, 0, 0, 5},
			.expectval = 1, 
			.description = "It returns 1 if 3 supply counts are 0\n",
		},
		{	
			.provinceCount = 5, 
			.supplyCount = {0, 0, 0, 0},
			.expectval = 1, 
			.description = "It returns 1 if more than 3 supply counts are 0\n",
		},
	};

	for (int i = 0; i < sizeof(testTable) / sizeof(testTable[0]); i++) {

		printf(testTable[i].description);

		struct gameState G;
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
		int seed = 1000;
		int supplyPiles[4] = {estate, copper, duchy, curse};

		memset(&G, 23, sizeof(struct gameState));
		initializeGame(2, k, seed, &G);

		G.supplyCount[province] = testTable[i].provinceCount;
		for (int j = 0; j < 5; j++) {
			G.supplyCount[supplyPiles[j]] = testTable[i].supplyCount[j];
		}

		retval = isGameOver(&G);

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
