#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cardEffect(enum CARD, int, int, int, struct gameState*, int, int*);
int drawCard(int player, struct gameState* state);
void testSmithy() {
	srand(time(NULL));
	FILE *fp = fopen("randomtestcard1.out", "w");
	
	int* kingCards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int kCards[10];
	int i;
	for (i = 0; i < 10; i++) {
		kCards[i] = kingCards[i];
	}

	int n;
	for (n = 0; n < 1000; n++) {
		struct gameState state;
		initializeGame(2, kCards, 4, &state);

		state.whoseTurn = 0;
		int handPos = 0;
		int* bonus = malloc(sizeof(int));
		*bonus = 0;

		int handsize = rand() % 8;

		int j;
		for (j = 0; j < handsize; j++) {
			drawCard(state.whoseTurn, &state);
		}

		int handSizePre = state.handCount[0];
		cardEffect(smithy, -1, -1, -1, &state, handPos, bonus);
		int handSizePost = state.handCount[0];
		free(bonus);

		if (handSizePost - handSizePre == 2) {
			fprintf(fp, "smithy card: PASSED, net gain of two cards\n");
		} else {
			fprintf(fp, "smithy card: FAILED, net difference of %d cards instead of 2\n", handSizePost - handSizePre);
		}
	}

	fclose(fp);
}

int main() {
	testSmithy();
	return 0;
}
