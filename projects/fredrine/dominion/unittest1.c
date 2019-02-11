#include "dominion.h"
#include <stdio.h>

void testFullDeckCount() {
	struct gameState state;
	int player = 0;
	int card = 3;
	
	state.deckCount[player] = 5;
	state.deck[player][0] = 3;
	state.deck[player][1] = 2;
	state.deck[player][2] = 1;
	state.deck[player][3] = 3;
	state.deck[player][4] = 3;

	state.handCount[player] = 4;
	state.hand[player][0] = 1;
	state.hand[player][1] = 2;
	state.hand[player][2] = 3;
	state.hand[player][3] = 3;

	state.discardCount[player] = 3;
	state.discard[player][0] = 0;
	state.discard[player][1] = 1;
	state.discard[player][2] = 3;

	int count =	fullDeckCount(player, card, &state);

	if (count == 6) {
		printf("fullDeckCount(): PASSED, correctly counted cards\n"); 
	} else {
		printf("fullDeckCount(): FAILED, counted %d instead of 6\n", count);
	}
}

int main() {
	testFullDeckCount();
	return 0;
}
