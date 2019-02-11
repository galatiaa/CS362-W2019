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
	int value=greatHallCard(0,&G,0);
	printf("Testing for end of function: expected: 0, actual: %d\n", value);
	printf("Testing for number of actions: expected: 2, actual: %d\n", G.numActions);
	printf("Testing for number of cards after function: expected: 5, actual: %d\n", numHandCards(&G));
	if(value!=0 || G.numActions!=2 || numHandCards(&G)!=5){
		printf("TEST FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}

}
