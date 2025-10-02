#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

long long int* Natural(int x, int *count) {
    int capacity = 1;  
    long long int *arr = malloc(sizeof(long long int) * capacity);
    if (!arr) {
        return NULL;
    }

    int idx = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % x == 0) {
            if (idx >= capacity) {
                capacity = idx + 1; 
                long long int *new_arr = realloc(arr, sizeof(long long int) * capacity);
                if (!new_arr) {
                    free(arr);
                    return NULL;
                }
                arr = new_arr;
            }
            arr[idx++] = i;
        }
    }
    *count = idx;
    return arr;
}

void printArray(long long int *arr, int count) {
    if (count == 0) {
        printf("no multiples\n");
        free(arr);
        return;
    }

    printf("multiples: ");
    for (int i = 0; i < count; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    free(arr);
}

long long int Factorial(long long int Number) {
    long long int factorial = 1; 
    for (long long int i = 1; i <= Number; ++i) {
        if (factorial > LLONG_MAX / i) {
            printf("overflow, maximum factorial 20\n");
            return -1;
        } else {
            factorial *= i;
        }
    }
    return factorial;
}

long long Summ(long long int Number) {
    long long summ = 0;
    for (long long int i = 1; i <= Number; ++i) {
        if (LLONG_MAX - summ < i) {
            printf("overflow, maximum sum 6074000999\n");
            return -1; 
        }
        summ += i;
    }
    return (long long)summ;
}


int Prime(long long int Number) {
    if (Number < 2) {
        return 0;
    } else {
        for (long long int i = 2; i * i <= Number; ++i) {
            if (Number % i == 0) {
                return 0;
            }
        }
    }
    return 1; 
}

void System16(int x) {
    if (x == 0) { 
        printf("0\n"); 
        return; 
    } else {
        int capacity = 32;
        char *hex = malloc(capacity);
        int idx = 0;
        while (x > 0) {
            int rem = x % 16;
            if (rem < 10) {
                hex[idx++] = '0' + rem;
            } else {
                hex[idx++] = 'A' + rem - 10;
            }
            x /= 16;
        }
        for (int i = idx - 1; i >= 0; i--) {
            printf("%c", hex[i]);
        }
        printf("\n");
        free(hex);
    }
}

void Power(int x) {
    for (int i = 1; i <= 10; i++) {
        for (int j = x; j >= 1; j--) {
            long long int val = pow(i, j);
            printf("%lld ", val);
        }
        printf("\n");
    }
}
