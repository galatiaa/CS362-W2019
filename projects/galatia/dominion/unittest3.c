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
	int value=handCard(0,&G);
	printf("Testing the card in hand: expected: 4 actual: %d\n", value);
	if(value!=4){
		printf("TESTING FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}
}
