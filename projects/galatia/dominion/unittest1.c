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
	printf("Testing playCard():\n");
	G.phase=1;
	int value=playCard(1,1,1,1,&G);
	printf("Testing phase: expected: -1, actual: %d\n", value);
	G.phase=0;
	G.numActions=0;
	value=playCard(1,1,1,1,&G);
	printf("Testing action number: expected: -1, actual: %d\n", value);
	G.numActions=3;
	G.hand[0][0]=steward;
	value=playCard(0,1,2,3,&G);
	printf("Testing end action number: expected: 2, actual: %d\n", G.numActions);
	printf("Testing for end of function: expected: 0, actual: %d\n", value);
	if(value!=0 || G.numActions!=2){
		printf("TESTING FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}
}
