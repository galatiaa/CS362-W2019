#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int count=0;
	while(count<10){
		struct gameState G;
		int seed=1000;
		int numPlayers=2;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
		initializeGame(numPlayers, k, seed, &G);
		int randplayer=rand()%2;
		int count1=numHandCards(&G);
		int value=smithCard(0,randplayer,&G,0);
		int count2=numHandCards(&G);
		count1=count2;
		printf("count1: %d\n", count1);
		printf("count2: %d\n", count2);
		assert(value==0);
		assert(count1==count2);
		printf("TESTING SUCCEEDED\n");
		count++;
	}
}
