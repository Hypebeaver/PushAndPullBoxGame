# BoxGame
Its a C programming box game that allow the player to push the box into the goal. I also implement a pull function for user to pull the box

Below is a brief what it will happen inside the box program if it is execute.

 1. I have implement a check function to check the input count of the argument and argument array from the user.

 2. The program will continue if the check is true or else the program will be exit with error print to the user.
 
 3. Map row and column will be increment by 2 which include the border space.

 4. At the same time the player and goal row and column also increment by 1 to secure them within the map.

 5. Next, the function boxLocation() will be call to generate the random row and column of the box inside the map.

 6. The mapArray will be malloc() as 2D char array.

 7. While loop is implement to iterate if the box location and goal location is not the same.

 8. Inside the while loop, function map() will be call to store map, player, goal and box location within 2D mapArray.

 9. Function mapPrint() will be call to print the map to the user.

 10. Row and column difference of player and box will be calculate.

 11. After the user input the character, another if-else will undergo to check whether the differenece of player and box row or column is equal to 1 (which next to each other).

 12. If true, then the player will move with the character input by the user and calculate again the row and column difference of the player and box.

 13. Another if-else will check the location of player and box is the same or not.

 14. If true, the function push() will be call to move the box in the direction of the player move.

 15. I have implement another if-else with #ifdef for the user to call the function pull() to pull the box if user enter "make PULL=1". 

 16. If the PULL function is define, then function pull() will be call to pull the box forward to direction of the player move.

 17. If the box and goal location are the same, end of the while loop.

 18. Function map() and function mapPrint() will be call again to show the user has win the game.

 19. The 2D map array malloc() will be free and end the program.
