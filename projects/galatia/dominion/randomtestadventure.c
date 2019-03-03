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
	int count=0;
	while(count<100){
		int randomz=rand()%10;
		int randomPlayer=rand()%2;
		int advenTest=advCard(randomz, 0, randomPlayer, 0, &G, k);
		assert(advenTest==0);
		if(advenTest==0){
			printf("Test Succeeded\n");
		}
		count++;
	}
}
