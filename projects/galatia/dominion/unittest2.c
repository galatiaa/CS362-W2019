#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	struct gameState G;
	int seed=1000;
	int numPlayers=2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(numPlayers, k, seed, &G);
	int value=numHandCards(&G);
	printf("Testing the number of cards in hand: expected: 5 actual: %d\n", value);
	if(value!=5){
		printf("TESTING FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}
}
