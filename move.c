/*
 * NAME     : LOOIKIANJOHN
 * ID       : 19741767
 * PURPOSE  : Implement of receiving command line argument to execute the program
 * DATE     : 12/4/23
 * DATE MOD : 17/4/23
*/

#include <stdio.h>
#include "move.h"

/* Function that move the player with specific character within the location of the map */
void move(char* wasd, int* mRow, int* mCol, int* pRow, int* pCol)
{
    if (*wasd == 'w')
    {
        if (*pRow > 1)
        {
            *pRow = *pRow - 1;
        }
    }
    else if (*wasd == 'a')
    {
        if (*pCol > 1)
        {
            *pCol = *pCol - 1;
        }
    }
    else if (*wasd == 's')
    {
        if (*pRow < *mRow - 2)
        {
            *pRow = *pRow + 1;
        }
    }
    else if (*wasd == 'd')
    {
        if (*pCol < *mCol - 2)
        {
            *pCol = *pCol + 1;
        }
    }
}

/* Function that push the box with specific character within  location of the map*/
void push(char* wasd, int* mRow, int* mCol, int* pRow, int* pCol, int* bRow, int* bCol)
{
    if (*wasd == 'w')
    {
        if (*bRow > 1)
        {
            *bRow = *bRow - 1;
        }
        else
        {
            *pRow = *pRow + 1;
        }
    }
    else if (*wasd == 'a')
    {
        if (*bCol > 1)
        {
            *bCol = *bCol - 1;
        }
        else
        {
            *pCol = *pCol + 1;
        }
    }
    else if (*wasd == 's')
    {
        if (*bRow < *mRow - 2)
        {
            *bRow = *bRow + 1;
        }
        else
        {
            *pRow = *pRow - 1;
        }
    }
    else if (*wasd == 'd')
    {
        if (*bCol < *mCol - 2)
        {
            *bCol = *bCol + 1;
        }
        else
        {
            *pCol = *pCol - 1;
        }
    }
}
