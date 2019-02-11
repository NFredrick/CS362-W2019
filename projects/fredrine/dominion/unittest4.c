#include "dominion.h"
#include <stdio.h>

int updateCoins(int player, struct gameState *state, int bonus);

void testUpdateCoins() {
	int player = 0;
	int bonus = 1;
	struct gameState state;
	state.handCount[player] = 5;
	state.hand[player][0] = copper;
	state.hand[player][1] = copper;
	state.hand[player][2] = silver;
	state.hand[player][3] = gold;
	state.hand[player][4] = gold;

	updateCoins(player, &state, bonus);

	if (state.coins == 11) {
		printf("updateCoins(): PASSED, coins counted correctly\n");
	} else {
		printf("updateCoins(): FAILED, coins counted incorrectly\n");
	}
}

int main() {
	testUpdateCoins();
	return 0;
}
