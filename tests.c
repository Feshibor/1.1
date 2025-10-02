#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "functions.h"

#define OK 0
#define ERROR_INVALID_INPUT 1

int flagi(const char* str, int* flag) {
    if (strcmp(str, "-h") == 0 || strcmp(str, "/h") == 0) {*flag=1; return OK;}
    if (strcmp(str, "-p") == 0 || strcmp(str, "/p") == 0) {*flag=2; return OK;}
    if (strcmp(str, "-s") == 0 || strcmp(str, "/s") == 0) {*flag=3; return OK;}
    if (strcmp(str, "-e") == 0 || strcmp(str, "/e") == 0) {*flag=4; return OK;}
    if (strcmp(str, "-a") == 0 || strcmp(str, "/a") == 0) {*flag=5; return OK;}
    if (strcmp(str, "-f") == 0 || strcmp(str, "/f") == 0) {*flag=6; return OK;}
    return ERROR_INVALID_INPUT;
}

void test_flagi() {
    int flag;
    assert(flagi("-h", &flag) == OK && flag == 1);
    assert(flagi("/h", &flag) == OK && flag == 1);
    assert(flagi("-p", &flag) == OK && flag == 2);
    assert(flagi("/p", &flag) == OK && flag == 2);
    assert(flagi("-s", &flag) == OK && flag == 3);
    assert(flagi("/s", &flag) == OK && flag == 3);
    assert(flagi("-e", &flag) == OK && flag == 4);
    assert(flagi("/e", &flag) == OK && flag == 4);
    assert(flagi("-a", &flag) == OK && flag == 5);
    assert(flagi("/a", &flag) == OK && flag == 5);
    assert(flagi("-f", &flag) == OK && flag == 6);
    assert(flagi("/f", &flag) == OK && flag == 6);
}

void test_kratnoe() {
    int count;
    long long int *result = Natural(5, &count);
    assert(result != NULL);
    assert(count > 0);
    assert(result[0] == 5);
    assert(result[count-1] == 100);
    free(result);

    result = Natural(101, &count);
    assert(result != NULL);
    assert(count == 0);
    free(result);
}

void test_prost() {
    assert(Prime(2) == 1);
    assert(Prime(7) == 1);
    assert(Prime(13) == 1);

    assert(Prime(4) == 0);
    assert(Prime(10) == 0);
    assert(Prime(15) == 0);

    assert(Prime(1) == 0);
    assert(Prime(0) == 0);
}

void test_sum() {
    assert(Summ(5) == 15);
    assert(Summ(1) == 1);
    assert(Summ(0) == 0);
    assert(Summ(10) == 55);
    assert(Summ(1LL<<62) == -1);
}

void test_factorial() {
    assert(Factorial(5) == 120);
    assert(Factorial(0) == 1);
    assert(Factorial(1) == 1);
    assert(Factorial(10) == 3628800);
    assert(Factorial(30) == -1);
}

void test_hex() {
    printf("System16 255 ( FF ");
    System16(255);
    printf("System16 10 ( A): ");
    System16(10);
    printf("System16 0 ( 0): ");
    System16(0);
}

void test_stepen() {
    printf("Power 3:\n");
    Power(3); 
}

void run_unit_tests() {
    test_flagi();
    test_kratnoe();
    test_prost();
    test_sum();
    test_factorial();
    test_hex();
    test_stepen();
    printf("All unit tests passed!\n");
}

int main() {
    run_unit_tests();
    return 0;
}
