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
    int p, r = -1;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handPos;
    int passedAll = 1;

    srand(time(NULL));
    // random number of players
    int numPlayer = rand() % 3 + 2;
    int currPlayer;

    printf ("TESTING smithy_case():\n");
    for (p = 0; p < 4; p++)
    {
        int numCards;
        int playedCards;
        int deckCount = G.deckCount[currPlayer];
        
        currPlayer = rand() % numPlayer;

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

        // randomize the handcount and cards played
        playedCards = rand() % (deckCount + 1);
        G.discardCount[currPlayer] = playedCards;
        numCards = rand() % 5 + 1;
        G.handCount[currPlayer] = numCards;
        handPos = (rand() % 5) + 1;

        // store the number of cards before smithy function is called
        numCards = G.handCount[currPlayer];
        // store the number of played cards 
        playedCards = G.playedCardCount;

        // smithy case function is called
        assert(smithy_case(&G, currPlayer, handPos) == 0);

        // tests to see if the number of cards is correct after smithy card is used
        if(G.handCount[currPlayer] == numCards + 3 - 1)
            printf("PASS: The expected hand count equals to actual num of cards\n");
        else 
        {
            printf("FAILED: The expected hand count is incorrect.\n");
            passedAll = 0;
        }
        // checks to see if the number of played cards is correct
        if(G.playedCardCount == playedCards + 1)
            printf("PASS: The played card count equals to actual num of cards played\n");
        else
        {
            printf("FAILED: The player card count is incorrect.\n");
            passedAll = 0;
        }
    }
    if(passedAll)
        printf("All tests passed!\n\n");

    return 0;
}