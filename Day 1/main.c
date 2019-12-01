#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINE_LEN 100

int main(int argc, char** argv) {
    char line[LINE_LEN];
    int total_fuel = 0;

    while (fgets(line, LINE_LEN, stdin)) {
        double mass = strtod(line, NULL);
        int fuel = ((int) floor(mass / 3)) - 2;
        total_fuel += fuel;

        while (fuel > 0) {
            fuel = ((int) floor(fuel / 3)) - 2;
            if (fuel < 0) {
                fuel = 0;
            }
            total_fuel += fuel;
        }
    }

    printf("total fuel: %d\n", total_fuel);

    return EXIT_SUCCESS;
}