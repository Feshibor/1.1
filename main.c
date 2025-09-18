#include "stack.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("ARGUMENTS ERROR");
        return 1;
    }
    char *end;
    long int Number = strtol(argv[1], &end, 10);
    if (*end != '\0') {
        printf("NUMBER ERROR\n");
        return 1;
    }
    //printf("%s\n", argv[2]);
    //printf("%ld\n", Number);

    if(strcmp(argv[2], "-h") == 0){
        Stack* stackper1 = Natural(Number);
        printQueueMultiples(stackper1);
        destroyStack(stackper1);
    } else if(strcmp(argv[2], "-p") == 0){
        printf(Prime(Number) ? "prime\n" : "composite\n");
    } else if(strcmp(argv[2], "-s") == 0){
        System16(Number);
    } else if(strcmp(argv[2], "-e") == 0){
        if (Number>10){
            printf("Number is greater than 10\n");
        } else {
            Power(Number);
        }
    } else if(strcmp(argv[2], "-a") == 0){
        printf("%llu\n", Summ(Number));
    } else if(strcmp(argv[2], "-f") == 0){
        printf("%lld\n", Factorial(Number));
    } else {
        printf("FLAG ERROR");
        return 1;
    }
    return 0;
}
