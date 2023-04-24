/*
 * PURPOSE  : Implement of receiving command line argument to execute the program
 * DATE     : 12/4/23
 * DATE MOD : 17/4/23
*/

#include <stdio.h>
#include "move.h"

/* Function that move the player with specific character within the location of the map.
   Player will move around with 'w', 'a', 's' and 'd' characters.
   If-else is used to determine the player move with the input character. 
   Another If-else is also implement to check the player is +1/-1 next to the border or not. */
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

/* Function that push the box by the player within the location of the map 
   Player will move around with 'w', 'a', 's' and 'd' characters.
   If-else is used to determine the box move with the input character. 
   Another If-else is also implement to check the box is +1/-1 next to the border or not.
   If the box and player is at the border of the map and at the same position, player will -1/+1 back to previous position. */
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

/* Function that let the player to pull the box within the location of the map
   If-else is used to determine the row or column of the player is away from the box or not. 
   If it is, then another If-else will undergo to check whether the box is +2/-2 next to the border. */
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

