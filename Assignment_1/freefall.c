// Author: Celine Lin z5311209
// Date: 6.7.20
// UNSW Freefall assignment.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1

// TODO: Add any extra #defines here.
#define NUM_COMMANDS 4
void printMap(int map[SIZE][SIZE], int playerX);

// TODO: Add any extra function prototypes here.

void placeStone(int map[SIZE][SIZE], int commands[NUM_COMMANDS]);
void movePlayer(int *playerX, int commands[], int lines);
void fireLaser(int *playerX, int commands[], int map[SIZE][SIZE], int *endloop);
void shiftDown(int map[SIZE][SIZE], int commands[NUM_COMMANDS]);
void winCondition(int map[SIZE][SIZE], int commands[NUM_COMMANDS], int *endloop);
void lostCondition(int map[SIZE][SIZE], int commands[NUM_COMMANDS], int *endloop, int playerX);
void verticalFilp(int map[SIZE][SIZE], int *notFlip);
void TNT(int map[SIZE][SIZE], int *posC, int *posR);


int main (void) {
    // This line creates our 2D array called "map" and sets all
    // of the blocks in the map to EMPTY.
    int map[SIZE][SIZE] = {EMPTY};
    
    // This line creates out playerX variable. The player starts in the
    // middle of the map, at position 7.
    int playerX = SIZE / 2;
    int lines;
    int commands[NUM_COMMANDS];
    int endloop = 0;
    int notFlip = 0;
    
    printf("How many lines of stone? ");
    
    // TODO: Scan in the number of lines of blocks.
    scanf("%d", &lines);
    
    printf("Enter lines of stone:\n");
    
    // TODO: Scan in the lines of blocks.    
    int cur_line = 0;
    while (cur_line < lines) {//scanf placing stone for "line" times
        //scanf four commands
        scanf("%d %d %d %d", 
        &commands[0], &commands[1], &commands[2], &commands[3]);
        //row          colume         length        value
        //then run the map to place the stones
        placeStone(map, commands);
        cur_line++;
    }
    
    int scanned_result = 0;
    printMap(map, playerX);
    while (endloop == 0) {//the real game starts
    //scanf the first command
        scanned_result = scanf("%d", &commands[0]);
        if (scanned_result == EOF) {
            endloop = 1;
        } else if (commands[0] == 1) {
        //if the frst command is one, then P/player is moving
        //scanf the second command to see the moving direction
        // of the player
            scanf("%d", &commands[1]);
            movePlayer(&playerX, commands, lines);
        } else if (commands[0] == 2) {
        //if the first command is two, the player would fire lasers
        //TNT function is in the fireLaser function
            fireLaser(&playerX, commands, map, &endloop);
        } else if (commands[0] == 3) {
        //if the first command is three, the stones would shift down
            shiftDown(map, commands);
        } else if (commands[0] == 4) {
        //if the first command is four, the stones would flip
        //and it can only loop once (by adding the endloop "notFlip")
            verticalFilp(map, &notFlip);
        } else if (commands[0] == 5) {

        }   
        
    // TODO: Scan in commands until EOF.
    // After each command is processed, you should call printMap.   
       if (scanned_result != EOF) {
            printMap(map, playerX);
            winCondition(map, commands, &endloop);
            lostCondition(map, commands, &endloop, playerX);  
        }
        
     }
    return 0;
}

// Print out the contents of the map array. Then print out the player line
// which will depends on the playerX variable.
void printMap(int map[SIZE][SIZE], int playerX) {

    // Print values from the map array.
    int posR = 0;
    while (posR < SIZE) {
        int posC = 0;
        while (posC < SIZE) {
            printf("%d ", map[posR][posC]);
            posC++;
        }
        printf("\n");
        posR++;
    }    
    
    // Print the player line.
    posR = 0;
    while (posR < playerX) {
        printf("  ");
        posR++;
    }
    printf("P\n");
}

void placeStone(int map[SIZE][SIZE], int commands[NUM_COMMANDS]) {
    //if row/colume/length/value is negative, ignore it.
    if (commands[0] < 0 || commands[1] < 0 || commands[0] >= SIZE || commands[1] >= SIZE) {
    //(the start position + the length of stones) should not be longer
    //than the map        
    } else if (commands[1] + commands[2] <= SIZE) {
        int counter = 0;
        while (counter < commands[2]) {//start looping
           map[commands[0]][commands[1] + counter] = commands[3];
           //map[start row][start colume] is equal to the value
           counter++;
        }
    }
}

void movePlayer(int *playerX, int commands[NUM_COMMANDS], int lines) {
    if (commands[1] == 1) {//go right, add two spaces before P
        *playerX = *playerX + 1;
    } else if (commands[1] == -1) {
    //go left, subtracted two spaces before P
        *playerX = *playerX - 1;
    } else {//playerX remain the same
        *playerX = SIZE / 2;
    }
}

void fireLaser(int *playerX, int commands[NUM_COMMANDS], int map[SIZE][SIZE], int *endloop) {
    int counter = 0;
    //loop from the bottom of the map
    int posR = SIZE - 1;
    int posC;
    //firstly, set the endloop to 1, this is use for TNT function
    *endloop = 1;
    while (counter < 3 && *endloop == 1 && posR >= 0) {
    //the player would fire three stones, so the counter < 3
    //posR should loop SIZE times
        if (map[posR][*playerX] == 1 || map[posR][*playerX] == 2) {
        //the stones are 1s and 2s
        //therefore, if the function loop to the stone
        //the stones will become 0
        //for values greater than 2
        //it is the TNT, so it will be running in the TNT function
            map[posR][*playerX] = 0;
            counter++;
        } else if (map[posR][*playerX] > 2) {
        //TNT function
            posC = *playerX;
            TNT(map, &posC, &posR);
            //if the player fired at the TNT, 
            //the fire loop should stop.
            *endloop = 0;
        }
        posR--;
    }
    //if the player did not fire the TNT, 
    //the game is going back to the main function
    //so endloop must equals 0 to loop in the main function
    *endloop = 0;
}

void shiftDown(int map[SIZE][SIZE], int commands[NUM_COMMANDS]) {
    //start looping from the bottom right cornner
    int posR = SIZE - 1;
    int posC = SIZE - 1;
    int tmp;
    while (posR > 0) {
        posC = SIZE - 1;
        while (posC > 0) {
            if (map[posR][posC] != 0) {
            //found the stones (values that are not zero)
            //swap numbers
                tmp = map[posR][posC];
                //replace the stones with 0
                map[posR][posC] = 0;
                //put the stones in the lower row
                map[posR + 1][posC] = tmp;
                posC--;
            } else {
                posC--;
            }
        }
        posR--;
    }
}

void winCondition(int map[SIZE][SIZE], int commands[NUM_COMMANDS], int *endloop) {
    int posC = 0;
    int posR = 0;
    *endloop = 1;
    //start from top left corner
    //search for stones
    while (posR < SIZE && *endloop == 1) {
        posC = 0;
        while (posC < SIZE && *endloop == 1) {
        //if the loop found the stone
            if (map[posR][posC] != 0) {
            //break the loops
            //and return to the main function
            //the main function will keep running as endloop = 0
                *endloop = 0;
            } 
            posC++;
        }
        posR++;
    }
    //if there is no stones in the game
    //the game won
    //and endloop = 1 will break the main function
    if (*endloop == 1) {
    printf("Game Won!\n");
    }
}

void lostCondition(int map[SIZE][SIZE], int commands[NUM_COMMANDS], int *endloop, int playerX) {
    int posC = SIZE - 1;
    while (posC > 0 && *endloop == 0) {
    //start from the bottom right corner of the map
    //searching for stones
        if (map[SIZE -1][posC] != 0) {
            scanf("%d", &commands[0]);
            //if the last row have stones
            //the game lost
            if (commands[0] == 3) {
            //print the map and "game lost"
                printMap(map, playerX);
                printf("Game Lost!\n");
                //end the main loop
                *endloop = 1;
            } else {
                //print the map and return to the main function
                printMap(map, playerX);
                *endloop = 0;
                break;
            }
        }
        posC--;
    }
}

void verticalFilp(int map[SIZE][SIZE], int *notFlip) {
    //start from the top left corner
    int posR = 0;
    int posC = 0;
    //int another 2D array
    int tmp[SIZE][SIZE] = {EMPTY};
    if (*notFlip == 0) {
        while (posR < SIZE) {
            posC = 0;
            while (posC < SIZE) {
            //put the initial map into another tmp 2D array(map)
                tmp[posR][posC] = map[posR][posC];
                posC++;
            }
            posR++;
        }
        //restart
        posC = 0;
        posR = 0;
        while (posR < SIZE) {
            posC = 0;
            while (posC < SIZE) {
            //put the tmp 2D array(map) into the map 
            //by fliping the rows
                map[posR][posC] = tmp[SIZE - 1 - posR][posC];
                posC++;
            }
            posR++;
        }
        //the function can only run once
        *notFlip = 1;
    }
}

void TNT(int map[SIZE][SIZE], int *posC, int *posR) {
    //the number of map[*posR][*posC] is the radius
    int radius = map[*posR][*posC];
    int counterR = 0;
    int counterC;
    int dR, dC;
    while (counterR < SIZE) {
        counterC = 0;
        while (counterC < SIZE) {
        //the distance from the centre
            dR = counterR - *posR;
            dC = counterC - *posC;
            if (dC * dC + dR * dR < radius * radius) {
            //if the distance is less that than the radius
            //it should become zero
                map[counterR][counterC] = 0;
            }
            counterC++;
        }
        counterR++;
    }
}

