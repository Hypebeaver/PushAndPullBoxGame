/*
 * PURPOSE  : Implement of checking the command line range and argument
 * DATE     : 12/4/23
 * DATE MOD : 17/4/23
*/

#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "macro.h"

/* Function to check the right argv array from the command line */
int checkArgument(int* range, char *argv[], int *mRow, int *mCol, int *pRow, int *pCol, int *gRow, int *gCol)
{
    int correctArg = FALSE;

    *mRow = atoi(argv[1]);
    *mCol = atoi(argv[2]);
    *pRow = atoi(argv[3]);
    *pCol = atoi(argv[4]);
    *gRow = atoi(argv[5]);
    *gCol = atoi(argv[6]);

    if (*range != 7)
    {
        printf("Usage: ./box <map_row> <map_column> <player_row> <player_column> <goal_row> <goal_column>\n");
    }
    else
    {
        if (*mRow < 0 || *mCol < 0)
        {
            printf("Map range must not be negative\n");
        }
        else if (*mRow < 5 || *mCol < 5)
        {
            printf("Minimum map range must be 5 x 5\n");
        }
        else if (*mRow > 100 || *mCol > 100)
        {
            printf("Maximum map range is 100 x 100\n");
        }
        else if (*pRow < 0 || *pCol < 0)
        {
            printf("Player row and column must not be negative\n");
        }
        else if (*pRow >= *mRow || *pCol >= *mCol)
        {
            printf("Player location must within the map range\n");
        }
        else if (*gRow < 0 || *gCol < 0)
        {
            printf("Goal row and column must not be negative\n");
        }
        else if (*gRow >= *mRow || *gCol >= *mCol)
        {
            printf("Goal location must within the map range\n");
        }
        else if ( ISEQUAL(*pRow, *pCol, *gRow, *gCol) == TRUE )
        {
            printf("Player location and goal location must not be the same\n");
        }
        else
        {
            correctArg = TRUE;
        }
    }

    return correctArg;
}

