#include "dominion.h"
#include <stdio.h>

void testIsGameOver() {
	struct gameState state;
	state.supplyCount[province] = 0;
	int result = isGameOver(&state);
	if (result == 1) {
		printf("isGameOver(): PASSED, province count is 0\n");
	} else {
		printf("isGameOver(): FAILED, game should be over\n");
	}

	int i;
	for (i = 0; i < 25; i++) {
		state.supplyCount[i] = 1;
	}
	state.supplyCount[province] = 1;

	result = isGameOver(&state);
	if (result == 0) {
		printf("isGameOver(): PASSED, cards still remaining\n");
	} else {
		printf("isGameOver(): FAILED, game is not over\n");
	}

	for (i = 0; i < 3; i++) {
		state.supplyCount[i] = 0;
	}
	result = isGameOver(&state);
	if (result == 1) {
		printf("isGameOver(): PASSED, 3 supply piles 0\n");
	} else {
		printf("isGameOver(): FAILED, game is over\n");
	}
}

int main() {
	testIsGameOver();
	return 0;
}
