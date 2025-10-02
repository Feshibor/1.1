#include "functions.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("ARGUMENTS ERROR\n");
        return 1;
    }

    char *end;
    long int Number = strtol(argv[1], &end, 10);

    if (*end != '\0') {
        printf("NUMBER ERROR\n");
        return 1;
    }

    if (Number == LONG_MAX) {
        printf("POSSIBLE OVERFLOW\n");
        return 1;
    }

    if (strcmp(argv[2], "-h") == 0) {
        int count;
        long long int *arr = Natural(Number, &count);
        if (!arr) {
            printf("Memory allocation error\n");
            return 1;
        }
        printArray(arr, count); 
    } else if (strcmp(argv[2], "-p") == 0) {
        printf(Prime(Number) ? "prime\n" : "composite\n");
    } else if (strcmp(argv[2], "-s") == 0) {
        System16(Number);
    } else if (strcmp(argv[2], "-e") == 0) {
        if (Number > 10) {
            printf("Number is greater than 10\n");
        } else {
            Power(Number);
        }
    } else if (strcmp(argv[2], "-a") == 0) {
        long long int x = Summ(Number);
        if (x == -1){
            return 1;
        }
        printf("%lld\n", x);
    } else if (strcmp(argv[2], "-f") == 0) {
        long long int x = Factorial(Number);
        if (x == -1){
            return 1;
        }
        printf("%lld\n",x );
    } else {
        printf("FLAG ERROR\n");
        return 1;
    }

    return 0;
}
