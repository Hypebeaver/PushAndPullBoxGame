/*
 * PURPOSE  : Implement of random generate box location inside the map
 * DATE     : 14/4/23
 * DATE MOD : 17/4/23
*/

#include <stdlib.h>
#include <time.h>
#include "macro.h"
#include "randomBox.h"

/*call this function just ONCE at the beginning of your program before using the random number generator */
void initRandom()
{
    srand(time(NULL));
}

/* Will return random integer between *low* and *high* inclusive.
   If the low is larger than the high, it will return -1 instead.
   In theory, it still works with negative *low* and *high* (as long as low is not larger than high), but for this assignment you will most likely not need the negative number.
   Please ensure you call initRandom function once before starting using this function. */
int randomGenerator(int low, int high)
{
    int number = -1;

    if(low <= high)
    {
        number = (rand() % (high-low+1)) + low;
    }

    return number;
}

/* Function that generate box row and box column */
void boxLocation(int *mRow, int *mCol, int *pRow, int *pCol, int *gRow, int *gCol, int *bRow, int *bCol )
{
    initRandom();

    /* do-while loop is used to generate right box row and column which not the same as player and goal position */
    do
    {
        *bRow = randomGenerator(3, *mRow - 3);
        *bCol = randomGenerator(3, *mCol - 3);
    }
    while ( ISEQUAL(*bRow, *bCol, *pRow, *pCol) == TRUE || ISEQUAL(*bRow, *bCol, *gRow, *gCol) == TRUE );

}
