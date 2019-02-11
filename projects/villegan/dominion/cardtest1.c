/* -----------------------------------------------------------------------
 * Testing Function:  smithy_case()
 * Goal is to test the hand count and the number of cards played
 *
 * ----------------------------------------------------------------------- */


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

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING smithy_case():\n");
    for (p = 0; p < numPlayer; p++)
    {
        int numCards;
        int playedCards;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        assert( r == 0);
        // set players Turn
        G.whoseTurn = p;  

        // store the number of cards before smithy function is called
        numCards = G.handCount[p];
        // store the number of played cards 
        playedCards = G.playedCardCount;

        // smithy case function is called
        assert(smithy_case(&G, p, 0) == 0);

        // tests to see if the number of cards is correct after smithy card is used
        assert(G.handCount[p] == numCards + 3 - 1);

#if (NOISY_TEST == 1)

        printf("PASS: The expected hand count equals to actual num of cards\n");
#endif

        // checks to see if the number of played cards is correct
        assert(G.playedCardCount == playedCards + 1);

#if (NOISY_TEST == 1)

        printf("PASS: The played card count equals to actual num of cards played\n");
#endif

    }
    printf("All tests passed!\n\n");

    return 0;
}