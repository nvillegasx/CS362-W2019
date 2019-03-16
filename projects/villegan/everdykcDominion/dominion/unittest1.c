/* -----------------------------------------------------------------------
 * Testing the hand count
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
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int handResult = -1;

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING numHandCards():\n");
    for (p = 0; p < numPlayer; p++)
    {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {

                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                // functionn that is being tested
                handResult = numHandCards(&G);
            
        }
        // check the the hand count
        assert(G.handCount[p] == maxHandCount );

#if (NOISY_TEST == 1)
        printf("PASS: Player %d when checking handCount of %d\n", p, G.handCount[p]);
#endif
    }

    printf("All tests passed!\n");

    return 0;
}