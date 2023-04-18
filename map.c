/*
 * NAME     : LOOIKIANJOHN
 * ID       : 19741767
 * PURPOSE  : Imlement of generate and print the map
 * DATE     : 5/4/23
 * DATE MOD : 17/4/23
*/

#include <stdio.h>
#include "color.h"
#include "map.h"
#include "macro.h"

/* Function to print the map */
void mapPrint(char **arr, int *mRow, int *mCol, int* gRow, int* gCol, int *bRow, int *bCol)
{
    int i, j;
    char* emptyColor = "red";
    char* fillColor = "green";
    char* reset = "reset";

    for (i = 0; i < *mRow; i++)
    {
        for (j = 0; j < *mCol; j++)
        {
            if ( arr[i][j] == 'B' && ISEQUAL(*gRow, *gCol, *bRow, *bCol) == TRUE )
            {
                setBackground(fillColor);
                printf("%c", arr[i][j]);
                setBackground(reset);
            }
            else if (arr[i][j] == 'G')
            {
                setBackground(emptyColor);
                printf("%c", arr[i][j]);
                setBackground(reset);
            }
            else
            {
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }

    printf("Move the box to the goal to win the game!\n");
    printf("Press w to move up\n");
    printf("Press s to move down\n");
    printf("Press a to move left\n");
    printf("Press d to move right\n");

    if ( ISEQUAL(*gRow, *gCol, *bRow, *bCol) == TRUE )
    {
        printf("\nCongratulation you have win the game!!\n\n");
    }
}

/* Function that position all the variables into 2D array */
void map(char **arr, int *mRow, int *mCol, int *pRow, int *pCol, int *gRow, int *gCol, int *bRow, int *bCol)
{
    int i, j;

    for (i = 0; i < *mRow; i++)
    {
        for (j = 0; j < *mCol; j++)
        {
            if ((i == 0 || i == *mRow - 1) || (j == 0 || j == *mCol - 1))
            {
                arr[i][j] = '*';
            }
            else if ( ISEQUAL(i, j, *pRow, *pCol) == TRUE )
            {
                arr[i][j] = 'P';
            }
            else if ( ISEQUAL(i, j, *bRow, *bCol) == TRUE )
            {
                arr[i][j] = 'B';
            }
            else if ( ISEQUAL(i, j, *gRow, *gCol) == TRUE )
            {
                arr[i][j] = 'G';
            }
            else
            {
                arr[i][j] = ' ';
            }
        }
    }
}
