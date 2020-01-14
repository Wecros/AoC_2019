#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intcode_program(int arr[], int element_count, int input);

int main() {
    // puzzle input
    int arr_5[] = {3,225,1,225,6,6,1100,1,238,225,104,0,1101,48,82,225,102,59,84,224,1001,224,-944,224,4,224,102,8,223,223,101,6,224,224,1,223,224,223,1101,92,58,224,101,-150,224,224,4,224,102,8,223,223,1001,224,3,224,1,224,223,223,1102,10,89,224,101,-890,224,224,4,224,1002,223,8,223,1001,224,5,224,1,224,223,223,1101,29,16,225,101,23,110,224,1001,224,-95,224,4,224,102,8,223,223,1001,224,3,224,1,223,224,223,1102,75,72,225,1102,51,8,225,1102,26,16,225,1102,8,49,225,1001,122,64,224,1001,224,-113,224,4,224,102,8,223,223,1001,224,3,224,1,224,223,223,1102,55,72,225,1002,174,28,224,101,-896,224,224,4,224,1002,223,8,223,101,4,224,224,1,224,223,223,1102,57,32,225,2,113,117,224,101,-1326,224,224,4,224,102,8,223,223,101,5,224,224,1,223,224,223,1,148,13,224,101,-120,224,224,4,224,1002,223,8,223,101,7,224,224,1,223,224,223,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,8,677,226,224,102,2,223,223,1006,224,329,101,1,223,223,107,677,677,224,1002,223,2,223,1006,224,344,101,1,223,223,8,226,677,224,102,2,223,223,1006,224,359,101,1,223,223,107,226,226,224,102,2,223,223,1005,224,374,1001,223,1,223,1108,677,226,224,1002,223,2,223,1006,224,389,101,1,223,223,107,677,226,224,102,2,223,223,1006,224,404,1001,223,1,223,1107,226,677,224,1002,223,2,223,1006,224,419,1001,223,1,223,108,677,677,224,102,2,223,223,1005,224,434,1001,223,1,223,1008,677,226,224,1002,223,2,223,1006,224,449,1001,223,1,223,7,226,677,224,1002,223,2,223,1006,224,464,1001,223,1,223,1007,677,677,224,102,2,223,223,1005,224,479,1001,223,1,223,1007,226,226,224,1002,223,2,223,1005,224,494,1001,223,1,223,108,226,226,224,1002,223,2,223,1005,224,509,1001,223,1,223,1007,226,677,224,1002,223,2,223,1006,224,524,101,1,223,223,1107,677,677,224,102,2,223,223,1005,224,539,101,1,223,223,1107,677,226,224,102,2,223,223,1005,224,554,1001,223,1,223,108,677,226,224,1002,223,2,223,1006,224,569,1001,223,1,223,1108,226,677,224,1002,223,2,223,1006,224,584,101,1,223,223,8,677,677,224,1002,223,2,223,1006,224,599,1001,223,1,223,1008,226,226,224,102,2,223,223,1006,224,614,101,1,223,223,7,677,677,224,1002,223,2,223,1006,224,629,101,1,223,223,1008,677,677,224,102,2,223,223,1005,224,644,101,1,223,223,7,677,226,224,1002,223,2,223,1005,224,659,101,1,223,223,1108,226,226,224,102,2,223,223,1006,224,674,1001,223,1,223,4,223,99,226};

    int input;
    printf("Please provide the Intcode computer with an input: ");
    scanf("%d", &input);

    // size of the array, functions to find the solution
    int element_count = (int) sizeof(arr_5) / sizeof(arr_5[0]);
    intcode_program(arr_5, element_count, input);

    return EXIT_SUCCESS;
}

void intcode_program(int arr[], int element_count, int input) {
    /** possible opcodes: 
     * @1 - adds together numbers read from two positions and stores the result in a third position
     * @2 - multiplies together numbers read from two positions and stores the result in a third position
     * @3 - takes a single integer as input and saves it to the position given by its only parameter
     * @4 - outputs the value of its only parameter
     * @5 - jump-if-true - if the first parameter is non-zero, it sets the instruction pointer to the value
     *                     from the second parameter. Otherwise, it does nothing.
     * @6 - jump-if-false - if the first parameter is zero, it sets the instruction pointer to the value 
     *                      from the second parameter. Otherwise, it does nothing.
     * @7 - less than - if the first parameter is less than the second parameter, 
     *                  it stores 1 in the position given by the third parameter. Otherwise, it stores 0.
     * @8 - equals - if the first parameter is equal to the second parameter, 
     *               it stores 1 in the position given by the third parameter. Otherwise, it stores 0.
     * @99 - halts the program
     */

    int i_skip;
    for (int i = 0; i < element_count; i += i_skip) {
        int curr_num = arr[i];
        // printf("currNum: %d, i: %d\n", curr_num, i);

        // make string from int number
        char curr_str[5];
        sprintf(curr_str, "%d", curr_num);

        // prepend 0 to the string
        while (strlen(curr_str) < 5) {
            char c[6] = "0";
            strncat(c, curr_str, 4);
            strcpy(curr_str, c);
        }

        char D = curr_str[3];
        char E = curr_str[4];

        // decide the opcode
        int opcode = -1;
        if (D == '0') {
            for (int i = 1; i <= 8; i++) {
                if (E == (i + '0')) {
                    opcode = i;
                    break;
                }
            }
        } else if (D == '9' && E == '9') {
            opcode = 99;
        } else {
            opcode = -1;
        }

        int param_arr[3];
        int param_mode_arr[3];
        for (int j = 0, k = 2; j < 3; j++, k--) {
            if (curr_str[k] == '0') {
                // printf("yesyes\n");
                param_arr[j] = arr[i + j + 1];
                param_mode_arr[j] = 0;
            }
            else {
                param_arr[j] = i + j + 1;
                param_mode_arr[j] = 1;
            }
        }

        switch (opcode) {
            case 1:
                arr[param_arr[2]] = arr[param_arr[0]] + arr[param_arr[1]];
                i_skip = 4;
                continue;
            case 2:
                arr[param_arr[2]] = arr[param_arr[0]] * arr[param_arr[1]];
                i_skip = 4;
                continue;
            case 3:
                arr[param_arr[0]] = input;
                i_skip = 2;
                continue;
            case 4:
                printf("OUTPUT: %d\n", arr[param_arr[0]]);
                i_skip = 2;
                continue;
            case 5:
                if (arr[param_arr[0]] != 0) {
                    i = arr[param_arr[1]];
                    i_skip = 0;
                } else {
                    i_skip = 3;
                }
                continue;
            case 6:
                if (arr[param_arr[0]] == 0) {
                    i = arr[param_arr[1]];
                    i_skip = 0;
                } else {
                    i_skip = 3;
                }
                continue;
            case 7:
                if (arr[param_arr[0]] < arr[param_arr[1]])
                    arr[param_arr[2]] = 1;
                else
                    arr[param_arr[2]] = 0;
                    
                i_skip = 4;
                continue;
            case 8:                
                if (arr[param_arr[0]] == arr[param_arr[1]]) {
                    arr[param_arr[2]] = 1;
                }
                else
                    arr[param_arr[2]] = 0;
                i_skip = 4;
                continue;
            case 99:
                break;
            default:
                fprintf(stderr, "ERR: wrong opcode\n");
                return;
                break;
        }
        break;
    }
}