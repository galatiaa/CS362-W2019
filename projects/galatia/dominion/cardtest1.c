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
	int count1=numHandCards(&G);
	int value=smithCard(0,0,&G,0);
	int count2=numHandCards(&G);
	count1+=3;
	printf("Testing for end of function: expected: 0, actual: %d\n", value);
	printf("Testing number of cards after use: expected: %d, actual: %d\n", count1, count2);
	if(value!=0 || count1!=count2){
		printf("TESTING FAILED\n");
	}
	else{
		printf("TESTING SUCCEEDED\n");
	}
}
