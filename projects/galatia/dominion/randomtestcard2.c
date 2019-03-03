#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	int count=0;
	while(count<10){
	struct gameState G;
	int seed=1000;
	int numPlayers=2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(numPlayers, k, seed, &G);
	int randplayer=rand()%2;
	int value=greatHallCard(randplayer,&G,0);
	assert(value==0);
	assert(G.numActions==2);
	assert(numHandCards(&G)==5);
	printf("TESTING SUCCEEDED\n");
	count++;
	}
}
