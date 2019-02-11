/*
 * Testing the hand card count and the action cards
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

    printf ("TESTING great_hall_case():\n");
    for (p = 0; p < numPlayer; p++)
    {

        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        int actionCards;

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;

        // store the values of hand count and actions before the function call
        handCount = G.handCount[p];
        actionCards = G.numActions;
        
        // call the great hall case functions
        assert(great_hall_case(p, &G, 0) == 0);

        // compare the handcount before and after the function call
        assert(G.handCount[p] == handCount);

#if (NOISY_TEST == 1)

        printf("PASS: when hand count is %d \n", G.handCount[p]);
#endif
        // compare the number of action cards after the function call
        assert(G.numActions == actionCards + 1); 
        
#if (NOISY_TEST == 1)

        printf("PASS: when action count is %d \n", G.numActions);
#endif


    }
    printf("All tests passed!\n\n");

    return 0;
}