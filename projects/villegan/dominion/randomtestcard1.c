
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
    int handCount;
    int currPlayer;
    srand(time(NULL));
    int passedAll = 1;
    int handPos;
    // random number of players
    int numPlayer = rand() % 3 + 2;

    printf ("TESTING great_hall_case():\n");
    for (p = 0; p < 4; p++)
    {
        currPlayer = rand() % numPlayer;

        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        int actionCards;

        // 0 if the game initialized correctly
        if( r != 0)
        {
            printf("FAILED: Error initializing game.\n");
            continue;
        }
        
        // set players Turn
        G.whoseTurn = currPlayer;

        // randomize the handcount and action cards
        actionCards = rand() % (10 + 1);
        G.numActions = actionCards;
        handCount = (rand() % 5) + 1;
        G.handCount[currPlayer] = handCount;
        handPos = (rand() % 5) + 1;

        // store the values of hand count and actions before the function call
        handCount = G.handCount[currPlayer];
        actionCards = G.numActions;
        
        // call the great hall case functions
        assert(great_hall_case(currPlayer, &G, handPos) == 0);

        // compare the handcount before and after the function call
        if(G.handCount[currPlayer] == handCount){
            printf("PASS: when hand count is %d \n", G.handCount[currPlayer]);
        }
        else
        {
            printf("FAIL: Hand count is incorrect.\n");
            passedAll = 0;
        }
        
        // compare the number of action cards after the function call
        if(G.numActions == actionCards + 1)
        {
            printf("PASS: when action count is %d \n", G.numActions);
        }
        else{
            printf("FAIL: Number of action cards incorrect.\n");
            passedAll = 0;

        }
    }
    if(passedAll)
        printf("All tests passed!\n\n");

    return 0;
}