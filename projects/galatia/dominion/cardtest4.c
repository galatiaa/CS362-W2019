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
	int value=embargoCard(0,&G,0,0);
	printf("Testing for end of function: expeted: 0, actual: %d\n", value);
	printf("Testing for number of coins: expected: 6, actual: %d\n", G.coins);
	printf("Testing for embargo token: expected: 1, actual: %d\n", G.embargoTokens[0]);
	if(value!=0 || G.coins!=6 || G.embargoTokens[0]!=1){
		printf("TEST FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}
}
