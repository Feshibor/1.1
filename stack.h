#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    long long int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Stack {
    Node *begin;
    int size;
} Stack;

Stack* createStack();
Node* createNode(long long int value, Node *next, Node *prev);
void stackAdd(Stack *stack, long long int value);
void destroyStack(Stack *stack);
void printQueueMultiples(Stack *stack);
void printStack(Stack *stack);
void printStack1(Stack *stack);
Stack* Natural(int x);
long long int Factorial(long long int Number);
unsigned long long int Summ(long long int Number);
int Prime(long long int Number);
void System16(int x);
void Power(int x);

#endif
