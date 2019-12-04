#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_OF_DIGITS 6

int charToInt(char c) {
    return c - '0';
}

int main() {
    int leftIntRange = 372304;
    int rightIntRange = 847060;
    int pwdCount = 0;

    bool leftToRightFlag = false;
    bool twoAdjacentFlag = false;
    bool doubleFound = false;

    for (int num = leftIntRange; num <= rightIntRange; num++) {
        char snum[NUM_OF_DIGITS];
        sprintf(snum, "%d", num);

        leftToRightFlag = true;
        twoAdjacentFlag = false;
        doubleFound = false;

        unsigned snumLen = strlen(snum);
        int ogNum = -1;

        for (size_t i = 0; i < snumLen - 1; i++) {
            int currNum = charToInt(snum[i]);
            int nextNum = charToInt(snum[i+1]);

            // testing that the digits never decrease
            if (currNum > nextNum) {  // if they increase, break the loop
                leftToRightFlag = false;
                break;
            }

            if (currNum == ogNum && currNum == nextNum && !doubleFound) {
                twoAdjacentFlag = false;                
            }
            // testing that there are at least 2 adjacent digits
            else if (currNum == nextNum && !doubleFound) {
                twoAdjacentFlag = true;
                ogNum = currNum;

                int nextNextNum = charToInt(snum[i+2]);
                if (nextNum != nextNextNum) {
                    doubleFound = true;
                }
            }
        }

        if (leftToRightFlag && twoAdjacentFlag) {
            pwdCount++;
        }
    }

    printf("Password Count: %d\n", pwdCount);

    return EXIT_SUCCESS;
}