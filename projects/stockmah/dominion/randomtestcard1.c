#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int checkGreatHall(struct gameState *post, int handPos, int player) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int r = cardEffect(great_hall, 0, 0, 0, post, handPos, NULL);

	drawCard(player, &pre);
	pre.numActions++;
	discardCard(handPos, player, &pre, 0);

	if (memcmp(&pre, post, sizeof(struct gameState)) != 0) {
		// test failed
		return 1;
	}

	if (r != 0) {
		// test failed
		return 1;
	}
	
	// test passed
	return 0;
}

int main() {
	
	struct gameState G;
	SelectStream(2);
	PutSeed(3);
	
	printf("Testing Great Hall\n");

	int passed = 0;
	int failed = 0;

	for(int i = 0; i < 2000; i++) {
		for(int j = 0; j < sizeof(struct gameState); j++) {
			((char*)&G)[j] = floor(Random() * 256);
		}
		G.whoseTurn = floor(Random() * 2);
		int p = G.whoseTurn;
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		G.playedCardCount = floor(Random() * MAX_DECK);
		int h = floor(Random() * G.handCount[p]);

		int ret = checkGreatHall(&G, h, p);
		if (ret == 0) {
			passed++;
		} else {
			failed++;
		}
	}

	printf("Tests Passed: %d\nTests Failed: %d\n\n", passed, failed);
	return 0;
}
