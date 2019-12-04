#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int charToInt(char c) {
    return c - '0';
}

int main() {
    int leftIntRange = 372304;
    int rightIntRange = 847060;
    int pwdCount = 0;

    bool twoAdjacentFlag = false;
    bool leftToRightFlag = false;

    for (int num = leftIntRange; num <= rightIntRange; num++) {
        char snum[6];
        sprintf(snum, "%d", num);
        leftToRightFlag = true;
        twoAdjacentFlag = false;

        for (size_t i = 0; i < strlen(snum) - 1; i++) {
            char currPos = snum[i];
            int currNum = charToInt(currPos);
            char nextPos = snum[i+1];
            int nextNum = charToInt(nextPos);

            // testing that the digits never decrease
            if (currNum > nextNum) {  // if they increase, break the loop
                leftToRightFlag = false;
                break;
            }

            // testing that there are at least 2 adjacent digits
            if (currNum == nextNum) {
                twoAdjacentFlag = true;
            }
        }

        if (leftToRightFlag && twoAdjacentFlag) {
            pwdCount++;
        }
    }

    printf("Password Count: %d\n", pwdCount);

    return EXIT_SUCCESS;
}