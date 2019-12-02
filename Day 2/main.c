#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intcode_program(int[], int);

int main() {
    int c;
    char number[1000];
    int i = 0;
    int comma_count = 0;
    while ((c = fgetc(stdin)) != EOF) {
        if (c == ',')
            comma_count++;
        number[i] = c;
        i++; 
    }

    char* token;
    const char s[2] = ",";

    int arr[comma_count+1];
    i = 0;
    token = strtok(number, s);

    while (token != NULL) {
        arr[i] = atoi(token);
        token = strtok(NULL, s);
        i++;
    }

    for (int i = 0; i < comma_count + 1; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");

    int arr_1202[] = {1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,2,23,6,27,2,6,27,31,2,13,31,35,1,10,35,39,2,39,13,43,1,43,13,47,1,6,47,51,1,10,51,55,2,55,6,59,1,5,59,63,2,9,63,67,1,6,67,71,2,9,71,75,1,6,75,79,2,79,13,83,1,83,10,87,1,13,87,91,1,91,10,95,2,9,95,99,1,5,99,103,2,10,103,107,1,107,2,111,1,111,5,0,99,2,14,0,0};
    int element_count = (int) sizeof(arr_1202) / sizeof(arr_1202[0]);

    for (int noun = 0; noun <= 99; noun++) {
        for (int verb = 0; verb <= 99; verb++) {
            int intcode_arr[] = {1,noun,verb,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,2,23,6,27,2,6,27,31,2,13,31,35,1,10,35,39,2,39,13,43,1,43,13,47,1,6,47,51,1,10,51,55,2,55,6,59,1,5,59,63,2,9,63,67,1,6,67,71,2,9,71,75,1,6,75,79,2,79,13,83,1,83,10,87,1,13,87,91,1,91,10,95,2,9,95,99,1,5,99,103,2,10,103,107,1,107,2,111,1,111,5,0,99,2,14,0,0};
            intcode_program(intcode_arr, element_count);
        }
    }

    printf("\n");
    return EXIT_SUCCESS;
}

void intcode_program(int arr[], int element_count) {
    int noun = arr[1];
    int verb = arr[2];
    for (int i = 0; i < element_count; i+=4) {
        if (arr[i] == 1) {
            arr[arr[i+3]] = arr[arr[i+1]] + arr[arr[i+2]];
        } else if (arr[i] == 2) {
            arr[arr[i+3]] = arr[arr[i+1]] * arr[arr[i+2]];
        } else if (arr[i] == 99) {
            break;
        } else {
            fprintf(stderr, "ERR: wrong input\n"); 
            return;
        }
    }

    // find output 19690720
    int output = 19690720;
    if (arr[0] == output) {
        printf("Solution found! noun: %d, verb: %d", noun, verb);
    }
}
