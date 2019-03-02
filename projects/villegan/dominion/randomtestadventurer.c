
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
// random
#include <time.h>
#include <stdlib.h>

int main() {

    int seed = 1000;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    int temphand[MAX_HAND];
    int z;
    int cardDrawn;
    int deckCount = -1;
    int passedAll = 1;
    srand(time(NULL));
    // random number of players
    int numPlayer = rand() % 3 + 2;
    int currPlayer;


    printf ("TESTING adventurer_case():\n");
    // iterations to be ran
    for (p = 0; p < 4; p++)
    {
        // choose a random player
        currPlayer = rand() % numPlayer;

        // deckCount = G.deckCount[currPlayer];
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // 0 if the game initialized correctly
        if( r != 0)
        {
            printf("FAILED: Error initializing game.\n");
            continue;
        }
        // set players Turn
        G.whoseTurn = currPlayer;

        // randomize deck count size
        deckCount = rand() % (MAX_DECK + 1);
        G.deckCount[currPlayer] = deckCount;

        // sets the deck count
        deckCount = G.deckCount[currPlayer];
        // calls the adventurer case
        assert(adventurer_case(&G, currPlayer, &cardDrawn, temphand, &z) == 0);

        // checks to see if the deck count is greater than 0
        if(G.deckCount[currPlayer] > 0)
            printf("PASS: when deck count is equal to %d which is greater than 0\n", G.deckCount[currPlayer]);
        else
        {
            printf("FAILED: Deck count incorrect.\n");
            passedAll = 0;
        }
        
    }
    if(passedAll)
        printf("All tests passed!\n\n");

    return 0;
}