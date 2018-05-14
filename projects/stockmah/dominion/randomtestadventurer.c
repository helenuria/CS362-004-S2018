#include <signal.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "test-helpers.h"
#include <math.h>

int checkAdventurer(struct gameState *post, int handPos, int player) {
	struct gameState *pre = malloc(sizeof(struct gameState));
	memcpy(pre, post, sizeof(struct gameState));

	int r = cardEffect(adventurer, 0, 0, 0, post, handPos, NULL);
	
	// get treasure card count in deck/discard
	int goldCount = deckCount(player, gold, pre) + discardCount(player, gold, pre);
	int silverCount = deckCount(player, silver, pre) + discardCount(player, silver, pre);
	int copperCount = deckCount(player, copper, pre) + discardCount(player, copper, pre);
	int treasureCount = goldCount + silverCount + copperCount;

	// get count of the treasure cards in pre hand
	int goldHandPre = handCount(player, gold, pre);
	int silverHandPre = handCount(player, silver, pre);
	int copperHandPre = handCount(player, copper, pre);
	int treasureHandPre = goldHandPre + silverHandPre + copperHandPre;

	// get count of the treasure cards in post hand
	int goldHandPost = handCount(player, gold, post);
	int silverHandPost = handCount(player, silver, post);
	int copperHandPost = handCount(player, copper, post);
	int treasureHandPost = goldHandPost + silverHandPost + copperHandPost;

	// if pre deck had at least 2 treasure cards
	// then post deck hand should have 2 more treasure cards
	if (treasureCount >= 2) {
		if (treasureHandPost != treasureHandPre + 2) {
			return 1;
		}
	}
	
	// if pre deck and discard had one treasure cards
	// then hand should gain one treasure card
	if (treasureCount == 1) {
		if (treasureHandPost != treasureHandPre + 1) {
			return 1;
		}
	}

	// if pre deck and discard had no treasure cards
	// then hand should gain no treasure cards
	if (treasureCount == 0) {
		if (treasureHandPost != treasureHandPre) {
			return 1;
		}
	}

	// in all cases, expect adventurer to be discarded
	int discardedAdventurerCountPre = discardCount(player, adventurer, pre);
	int discardedAdventurerCountPost = discardCount(player, adventurer, post);

	if (discardedAdventurerCountPost != discardedAdventurerCountPre + 1) {
		return 1;
	}

	if (r != 0) {
		return 1;
	}

	return 0;
}

void __gcov_flush(void);

int main() {
	struct{
		int treasureType;
		int treasureNum;
		int otherType;
	} testTable[] = {
		{
			.treasureType = gold,
			.treasureNum = 3,
			.otherType = 3,
		},
		{
			.treasureType = gold,
			.treasureNum = 2,
			.otherType = 3,
		},
		{
			.treasureType = silver,
			.treasureNum = 3,
			.otherType = 3,
		},
		{
			.treasureType = silver,
			.treasureNum = 2,
			.otherType = 3,
		},
		{
			.treasureType = copper,
			.treasureNum = 3,
			.otherType = 3,
		},
		{
			.treasureType = copper,
			.treasureNum = 2,
			.otherType = 3,
		},
		{
			.treasureType = gold,
			.treasureNum = 1,
			.otherType = 3,
		},
		{
			.treasureType = gold,
			.treasureNum = 0,
			.otherType = 3,
		},
		{
			.treasureType = silver,
			.treasureNum = 1,
			.otherType = 3,
		},
		{
			.treasureType = silver,
			.treasureNum = 0,
			.otherType = 3,
		},
		{
			.treasureType = copper,
			.treasureNum = 1,
			.otherType = 3,
		},
		{
			.treasureType = copper,
			.treasureNum = 0,
			.otherType = 3,
		},
	};

	struct gameState* G= malloc(sizeof(struct gameState));
	SelectStream(2);
	PutSeed(3);
	
	printf("Testing Adventurer\n");

	int passed = 0;
	int failed = 0;
	int ret = 0;

	for (size_t n = 0; n < sizeof(testTable) / sizeof(testTable[0]); n++) {
		for(int i = 0; i < 200; i++) {
			for(size_t j = 0; j < sizeof(struct gameState); j++) {
				((char*)G)[j] = floor(Random() * 256);
			}
			G->whoseTurn = floor(Random() * 2);
			int p = G->whoseTurn;
			G->deckCount[p] = floor(Random() * MAX_DECK);
			if (G->deckCount[p] < 3) {
				G->deckCount[p] = 3;
			}
			G->discardCount[p] = floor(Random() * MAX_DECK);
			G->handCount[p] = floor(Random() * MAX_HAND);
			G->playedCardCount = floor(Random() * MAX_DECK);
			int h = floor(Random() * G->handCount[p]);

			int setDeckRet = setDeck(testTable[n].treasureType, testTable[n].treasureNum, 
					testTable[n].otherType, p, G);
			
			if (setDeckRet == 0) {
				ret = checkAdventurer(G, h, p);
			} else {
				printf("Failed to set deck\n");
				exit(1);
			}

			if (ret == 0) {
				passed++;
			} else {
				failed++;
			}
			__gcov_flush();
		}
	}

	printf("Tests Passed: %d\nTests Failed: %d\n\n", passed, failed);
	return 0;
}
