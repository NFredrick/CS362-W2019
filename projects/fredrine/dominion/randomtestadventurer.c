#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cardEffect(enum CARD, int, int, int, struct gameState*, int, int*);
int drawCard(int player, struct gameState* state);
void testAdventurer() {
	srand(time(NULL));
	FILE *fp = fopen("randomtestadventurer.out", "w");

	int* kingCards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int kCards[10];
	int i;
	for (i = 0; i < 10; i++) {
		kCards[i] = kingCards[i];
	}

	int n;
	for (n = 0; n < 1; n++) {

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

		int treasurePre = 0;
		for (i = 0; i < state.handCount[0]; i++) {
			enum CARD card = state.hand[0][i];
			if (card == copper || card == silver || card == gold) {
				treasurePre++;
			}
		}
		cardEffect(adventurer, -1, -1, -1, &state, handPos, bonus);
		int treasurePost = 0;
		for (i = 0; i < state.handCount[0]; i++) {
			enum CARD card = state.hand[0][i];
			if (card == copper || card == silver || card == gold) {
				treasurePost++;
			}
		}
		free(bonus);

		if (treasurePost - treasurePre == 2) {
			fprintf(fp, "adventurer card: PASSED, net gain of two cards\n");
		} else {
			fprintf(fp, "adventurer card: FAILED, net difference of %d treasure cards instead of 2\n", treasurePost - treasurePre);
		}

	}
	
	fclose(fp);
}

int main() {
	testAdventurer();
	return 0;
}
