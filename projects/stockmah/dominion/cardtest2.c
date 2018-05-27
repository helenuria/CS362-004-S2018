// test the adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include "test-helpers.h"
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


	printf("TESTING adventurer card\n");


	printf("When the deck has at least 2 treasure cards...\n");
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(2, k, seed, &G);
	setDeck(copper, 2, province, &G);
	setHand(adventurer, 1, province, &G);

	int initTreasureCount = handCount(0, copper, &G);
	int initAdventureCount = handCount(0, adventurer, &G);
	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
	int newTreasureCount = handCount(0, copper, &G);
	int newAdventureCount = handCount(0, adventurer, &G);

	printf("Expect your hand to gain two treasure cards\n");

	if (newTreasureCount == initTreasureCount + 2) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("Expect your hand to lose an adventure card\n");

	if (newAdventureCount == initAdventureCount - 1) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("When the full deck (including discard) has only 1 treasure card...\n");
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(2, k, seed, &G);
	setDeck(copper, 1, province, &G);
	setHand(adventurer, 1, province, &G);

	initTreasureCount = handCount(0, copper, &G);
	initAdventureCount = handCount(0, adventurer, &G);
	int initDeckCount = G.deckCount[0];
	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
	newTreasureCount = handCount(0, copper, &G);
	newAdventureCount = handCount(0, adventurer, &G);
	int newDeckCount = G.deckCount[0];

	printf("Expect discard pile to be shuffled and added to deck\n");
	if (initDeckCount != newDeckCount) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	printf("Expect your hand to gain one treasure card\n");
	if (newTreasureCount == initTreasureCount + 1) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}
	
	printf("When the full deck (including discard) has no treasure cards...\n");
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(2, k, seed, &G);
	setDeck(copper, 0, province, &G);
	setHand(adventurer, 1, province, &G);

	initTreasureCount = handCount(0, copper, &G);
	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
	newTreasureCount = handCount(0, copper, &G);

	printf("Expect hand to gain no treasure cards\n");
	if (initTreasureCount == newTreasureCount) {
		printf("Pass\n");
		pass_count++;
	}
	else {
		printf("Fail\n");
	}

	if (pass_count == 5) {
		printf("All tests Passed!\n\n");
		return 0;
	}
	else {
		printf("Test suite failed\n\n");
		return 1;
	}
	return 0;
}
