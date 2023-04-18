/*
 * NAME     : LOOIKIANJOHN
 * ID       : 19741767
 * PURPOSE  : Implement of receiving command line argument to execute the box game program
 * DATE     : 12/4/23
 * DATE MOD : 17/4/23
*/

#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "macro.h"
#include "map.h"
#include "move.h"
#include "randomBox.h"
#include "terminal.h"
#include "pull.h"

int main(int argc, char* argv[])
{
    int i;
    char enter;
    int rightRange, rightArgument;
    int mapRow, mapCol, playerRow, playerCol, goalRow, goalCol, boxRow, boxCol;
    int rowDiff, colDiff;
    char** mapArray;

    rightRange = checkRange(&argc);

    if (rightRange == TRUE)
    {
        rightArgument = checkArgument(&argc, argv, &mapRow, &mapCol, &playerRow, &playerCol, &goalRow, &goalCol);

        if (rightArgument == TRUE)
        {
            /* Map row and column are increment by 2 to store the border of the map.
               As the map row and column +2, player and goal will be increment by 1 to secure the player and the goal are within the map.
               boxLocation function is call to random generate the location of the box position. */
            mapRow = mapRow + 2;
            mapCol = mapCol + 2;
            playerRow = playerRow + 1;
            playerCol = playerCol + 1;
            goalRow = goalRow + 1;
            goalCol = goalCol + 1;
            boxLocation(&mapRow, &mapCol, &playerRow, &playerCol, &goalRow, &goalCol, &boxRow, &boxCol);
            
            mapArray = (char**)malloc(mapRow * sizeof(char*));

            for (i = 0; i < mapRow; i++)
            {
                mapArray[i] = (char*)malloc(mapCol * sizeof(char));
            }
            
            system("clear");

            /* While loop is used to iterate over if the box is not inside the goal */
            while ( NOTEQUAL(boxRow, boxCol, goalRow, goalCol) == TRUE )
            {
                /* Update and print the map to show the current map to the user */
                map(mapArray, &mapRow, &mapCol, &playerRow, &playerCol, &goalRow, &goalCol, &boxRow, &boxCol);
                mapPrint(mapArray, &mapRow, &mapCol, &goalRow, &goalCol, &boxRow, &boxCol);

                /* rowDiff and colDiff are used to get the difference of the position between the player and the box */
                rowDiff = abs(playerRow - boxRow);
                colDiff = abs(playerCol - boxCol);

                disableBuffer();
                scanf(" %c", &enter);
                enableBuffer();

                /* If-else is used to check whether the player position is +1 next to the box position before the player move.
                   As the player move, another If-else will undergo to check current player position and box position is the same or not.
                   If it does, then push function will be call to move the box to the same direction as the player move. */
                if ( ISEQUAL(rowDiff, playerCol, 1, boxCol) == TRUE || ISEQUAL(colDiff, playerRow, 1, boxRow) == TRUE )
                {
                    move(&enter, &mapRow, &mapCol, &playerRow, &playerCol);
                    rowDiff = abs(playerRow - boxRow);
                    colDiff = abs(playerCol - boxCol);

                    if ( ISEQUAL(playerRow, playerCol, boxRow, boxCol) == TRUE)
                    {
                        push(&enter, &mapRow, &mapCol, &playerRow, &playerCol, &boxRow, &boxCol);
                    }

                    /* Within this IF-else, an #ifdef is added as conditional statement to let user to define PULL when user need to call PULL function */
                    #ifdef PULL
                    else if ( ISEQUAL(rowDiff, playerCol, 2, boxCol) == TRUE || ISEQUAL(colDiff, playerRow, 2, boxRow) == TRUE)
                    {
                        pull(&mapRow, &mapCol, &playerRow, &playerCol, &boxRow, &boxCol);
                    }
                    #endif
                }
                else
                {
                    move(&enter, &mapRow, &mapCol, &playerRow, &playerCol);
                }

                system("clear");
            }

            /* Updated and print the map that the player successfully push/pull the box into the goal */
            map(mapArray, &mapRow, &mapCol, &playerRow, &playerCol, &goalRow, &goalCol, &boxRow, &boxCol);
            mapPrint(mapArray, &mapRow, &mapCol, &goalRow, &goalCol, &boxRow, &boxCol);

            /* free 2D malloc() */
            for (i = 0; i < mapRow; i++)
            {
                free(mapArray[i]);
            }

            free(mapArray);
        }
    }

    return 0;
}
