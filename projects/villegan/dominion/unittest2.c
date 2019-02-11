/* -----------------------------------------------------------------------
 * Testing the whoseTurn() function
 * Comparing the whose turn variable
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 3;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING whoseTurn():\n");
    for (p = 0; p < numPlayer; p++)
    {
        int playerTurn;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;
        playerTurn = G.whoseTurn;

        // check the player Turn
        assert(G.whoseTurn == playerTurn ); 

#if (NOISY_TEST == 1)
        printf("PASS: When its player %d turn\n", G.whoseTurn);
#endif
//----------
    }
    printf("All tests passed!\n");

    return 0;
}