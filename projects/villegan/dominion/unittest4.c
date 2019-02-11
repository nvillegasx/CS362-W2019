/* -----------------------------------------------------------------------
 * Testing the fullDeckCount() function
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
    int numPlayer = 2;
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

    printf ("TESTING fullDeckCount():\n");
    for (p = 0; p < numPlayer; p++)
    {
        int deckCountPlayer;
        int count;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;
        // store the deck count for player
        deckCountPlayer = G.deckCount[p];
        // call the full deck count function
        count = fullDeckCount(p, 1, &G);
        // check the deck count 
        assert(G.deckCount[p] == deckCountPlayer );

#if (NOISY_TEST == 1)

        printf("PASS: Deck Count is equal to %d \n", G.deckCount[p]);
#endif
//----------
        // call the full deck count function
        count = fullDeckCount(p, 2, &G);
        // check the deck count 
        assert(G.deckCount[p] == deckCountPlayer );

#if (NOISY_TEST == 1)

        printf("PASS: Deck Count is equal to %d \n", G.deckCount[p]);
#endif
//----------
        // call the full deck count function
        count = fullDeckCount(p, 3, &G);
        // check the deck count 
        assert(G.deckCount[p] == deckCountPlayer );

#if (NOISY_TEST == 1)
        printf("PASS: Deck Count is equal to %d \n", G.deckCount[p]);
#endif
//----------

    }
    printf("All tests passed!\n\n");

    return 0;
}