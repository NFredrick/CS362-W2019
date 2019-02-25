#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cardEffect(enum CARD, int, int, int, struct gameState*, int, int*);
int drawCard(int player, struct gameState* state);
void testSteward() {
	srand(time(NULL));
	FILE *fp = fopen("randomtestcard2.out", "w");

	int* kingCards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int kCards[10];
	int i;
	for (i = 0; i < 10; i++) {
		kCards[i] = kingCards[i];
	}
	int* bonus = malloc(sizeof(int));

	int n;
	for (n = 0; n < 1000; n++) {

		struct gameState state;
		initializeGame(2, kCards, 4, &state);

		state.whoseTurn = 0;
		int handPos = 0;
		*bonus = 0;

		int handsize = rand() % 8; // random hand

		int j;
		for (j = 0; j < handsize; j++) {
			drawCard(state.whoseTurn, &state);
		}

		int choice1 = rand() % 3; // random choice
		int handSizePre = state.handCount[0];
		int coinsPre = 0;
		int k;
		for (k = 0; k < handSizePre; k++) {
			enum CARD card = state.hand[0][i];
			if (card == copper) {
				coinsPre += 1;
			} else if (card == silver) {
				coinsPre += 2;
			} else if (card == gold) {
				coinsPre += 3;
			}
		}
			
		cardEffect(steward, choice1, -1, -1, &state, handPos, bonus);
		int handSizePost = state.handCount[0];
		int coinsPost = 0;
		for (k = 0; k < handSizePre; k++) {
			enum CARD card = state.hand[0][i];
			if (card == copper) {
				coinsPost += 1;
			} else if (card == silver) {
				coinsPost += 2;
			} else if (card == gold) {
				coinsPost += 3;
			}
		}

		if (choice1 == 0) {
			if (handSizePost - handSizePre == -3) {
				fprintf(fp, "great hall card: PASSED, net loss of 3 cards\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d cards instead of -3\n", handSizePost - handSizePre);
			}
			if (coinsPost - coinsPre == 0) {
				fprintf(fp, "great hall card: PASSED, net change of 0 coins\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d coins instead of 0\n", coinsPost - coinsPre);
			}
		} else if (choice1 == 1) {
			if (handSizePost - handSizePre == 1) {
				fprintf(fp, "great hall card: PASSED, net gain of 1 card\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d cards instead of 1\n", handSizePost - handSizePre);
			}
			if (coinsPost - coinsPre == 0) {
				fprintf(fp, "great hall card: PASSED, net change of 0 coins\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d coins instead of 0\n", coinsPost - coinsPre);
			}
		} else {
			if (handSizePost - handSizePre == 0) {
				fprintf(fp, "great hall card: PASSED, net gain of no cards\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d cards instead of 0\n", handSizePost - handSizePre);
			}
			if (coinsPost - coinsPre == 2) {
				fprintf(fp, "great hall card: PASSED, net change of 2 coins\n");
			} else {
				fprintf(fp, "great hall card: FAILED, net difference of %d coins instead of 2\n", coinsPost - coinsPre);
			}
		}
	}

	free(bonus);
	fclose(fp);
}

int main() {
	testSteward();
	return 0;
}
