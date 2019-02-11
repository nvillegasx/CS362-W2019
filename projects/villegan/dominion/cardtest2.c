/* -----------------------------------------------------------------------
 * Testing Function: adventurer_case()
 * Testing the number of cards in the deck
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
    int temphand[MAX_HAND];
    int z;
    int cardDrawn;
    int deckCount = -1;

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING adventurer_case():\n");
    for (p = 0; p < numPlayer; p++)
    {

        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;
        // sets the deck count
        deckCount = G.deckCount[p];
        // calls the adventurer case
        assert(adventurer_case(&G, p, &cardDrawn, temphand, &z) == 0);

        // checks to see if the deck count is greater than 0
        assert(G.deckCount[p] > 0);

#if (NOISY_TEST == 1)

        printf("PASS: when deck count is equal to %d which is greater than 0\n", G.deckCount[p]);
#endif


    }
    printf("All tests passed!\n\n");

    return 0;
}