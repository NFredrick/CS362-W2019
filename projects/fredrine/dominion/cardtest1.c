#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int cardEffect(enum CARD, int, int, int, struct gameState*, int, int*);
void testSmithy() {
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
	cardEffect(smithy, -1, -1, -1, &state, handPos, bonus);
	int handSizePost = state.handCount[0];
	free(bonus);

	if (handSizePost - handSizePre == 2) {
		printf("smithy card: PASSED, net gain of two cards\n");
	} else {
		printf("smithy card: FAILED, net difference of %d cards instead of 2\n", handSizePost - handSizePre);
	}
}

int main() {
	testSmithy();
	return 0;
}
