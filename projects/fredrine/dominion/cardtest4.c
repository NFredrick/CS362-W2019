#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int cardEffect(enum CARD, int, int, int, struct gameState*, int, int*);
void testGreatHall() {
	int* kingCards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int kCards[10];
	int i;
	for (i = 0; i < 10; i++) {
		kCards[i] = kingCards[i];
	}
	struct gameState state;
	initializeGame(2, kCards, 4, &state);

	state.whoseTurn = 0;
	int handPos = 0;
	int* bonus = malloc(sizeof(int));
	*bonus = 0;
	int handSizePre = state.handCount[0];
	int actionsPre = state.numActions;
	cardEffect(great_hall, -1, -1, -1, &state, handPos, bonus);
	int handSizePost = state.handCount[0];
	int actionsPost = state.numActions;
	free(bonus);

	if (handSizePost - handSizePre == 0) {
		printf("great hall card: PASSED, net gain of no cards\n");
	} else {
		printf("great hall card: FAILED, net difference of %d cards instead of 0\n", handSizePost - handSizePre);
	}

	if (actionsPost - actionsPre == 1) {
		printf("great hall card: PASSED, plus one actions\n");
	} else {
		printf("great hall card: FAILED, net difference of %d actions instead of 2\n", actionsPost - actionsPre);
	}
}

int main() {
	testGreatHall();
	return 0;
}
