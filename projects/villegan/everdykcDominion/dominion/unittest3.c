/* -----------------------------------------------------------------------
 * Testing the isGameOver() function
 * Checking to if the province cards and the supply count
 * is greater than 0
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

    printf ("TESTING isGameOver():\n");
    for (p = 0; p < numPlayer; p++)
    {
        int provinceCards;
        int expectedCard;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;
        // store the number of province cards
        provinceCards = G.supplyCount[province];
        // call the game over function
        isGameOver(&G);
        // check the number of province cards
        assert(G.supplyCount[province] == provinceCards );

#if (NOISY_TEST == 1)

        printf("PASS: Player %d when checking emptyness of supplyCount[province] = %d\n", p, G.supplyCount[province]);
#endif
//----------
        // call the game over function
        isGameOver(&G);

        // check the supply is not empty
        for (i = 0; i < 25; i++)
        {
                expectedCard = G.supplyCount[i];
                assert(G.supplyCount[i] == expectedCard );
        }
#if (NOISY_TEST == 1)

        printf("PASS: Player %d when checking supply piles greater than 0\n", p);
#endif
//----------
    }
    printf("All tests passed!\n\n");

    return 0;
}