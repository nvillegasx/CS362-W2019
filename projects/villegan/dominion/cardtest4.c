/* -----------------------------------------------------------------------
 * Testing the number of buy cards and the hand count
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
    int handCount;

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING council_room_case():\n");
    for (p = 0; p < numPlayer; p++)
    {

        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        int buyCards;

        // 0 if the game initialized correctly
        assert( r == 0);
        G.whoseTurn = p; // set players Turn

        // store the number of hand count and buy cards
        handCount = G.handCount[p];
        buyCards = G.numBuys;
        
        // call the council room case function
        assert(council_room_case(p, &G, 0) == 0);

        // check the number of hand count before and after the function call
        assert(G.handCount[p] == handCount + 3);

#if (NOISY_TEST == 1)

        printf("PASS: when hand count is %d \n", G.handCount[p]);
#endif
        // check the number of buy cards
        assert(G.numBuys == buyCards + 1);
        
#if (NOISY_TEST == 1)

        printf("PASS: when buy count is %d \n", G.numBuys );
#endif

    }
    printf("All tests passed!\n\n");

    return 0;
}