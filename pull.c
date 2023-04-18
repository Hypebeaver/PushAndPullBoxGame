/*
 * NAME     : LOOIKIANJOHN
 * ID       : 19741767
 * PURPOSE  : Implement of pull method to the box
 * DATE     : 15/4/23
 * DATE MOD : 15/4/23
*/

#include <stdio.h>
#include "pull.h"

/* FUnction that let the player to pull the box */
void pull(int* mRow, int* mCol, int* pRow, int* pCol, int* bRow, int* bCol)
{
    if (*pRow < *bRow)
    {
        if (*bRow > 2)
        {
            *bRow = *bRow - 1;
        }
    }
    else if (*pRow > *bRow)
    {
        if (*bRow < *mRow - 3)
        {
            *bRow = *bRow + 1;
        }
    }
    else if (*pCol < *bCol)
    {
        if (*bCol > 2)
        {
            *bCol = *bCol - 1;
        }
    }
    else
    {
        if (*bCol < *mCol - 3)
        {
            *bCol = *bCol + 1;
        }
    }
}
