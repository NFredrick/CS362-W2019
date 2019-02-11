#include "dominion.h"
#include <stdio.h>

void testInitializeGame() {
	int numPlayers = 2;
	int kCards[10]; 
	int* kingCards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int i;
	for (i = 0; i < 10; i++) {
		kCards[i] = kingCards[i];
	}

	struct gameState state;
	int result = initializeGame(numPlayers, kCards, 4, &state);

	if (result == 0) {
		printf("initializeGame(): PASSED, initialized correctly\n");
	} else {
		printf("initializeGame(): FAILED, initialization failed\n");
	}

	if (state.supplyCount[curse] == 10) {
		printf("initializeGame(): PASSED, curse cards initialized correctly\n");
	} else {
		printf("initializeGame(): FAILED, curse cards initialized incorrectly\n");
	}
	if (state.supplyCount[estate] == 8 &&
			state.supplyCount[duchy] == 8 &&
			state.supplyCount[province] == 8) {
		printf("initializeGame(): PASSED, victory cards initialized correctly\n");
	} else {
		printf("initializeGame(): FAILED, victory cards initialized incorrectly\n");

	}
	if (state.supplyCount[copper] == 46 &&
			state.supplyCount[silver] == 40 &&
			state.supplyCount[gold] == 30) {
		printf("initializeGame(): PASSED, treasure cards initialized correctly\n");
	} else {
		printf("initializeGame(): FAILED, treasure cards initialized incorrectly\n");
	}
}

int main() {
	testInitializeGame();
	return 0;
}
