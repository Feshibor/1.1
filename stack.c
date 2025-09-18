#include "stack.h"


Stack* createStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->begin = NULL;
    stack->size = 0;
    return stack;
}

Node* createNode(long long int value, Node *next, Node *prev) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    node->prev = prev;
    return node;
}

void stackAdd(Stack *stack, long long int value) {
    Node *node = createNode(value, stack->begin, NULL);
    if (stack->begin == NULL) {
        stack->begin = node;
    } else {
        stack->begin->prev = node;
        stack->begin = stack->begin->prev;
    }
    stack->size++;
}

void printQueueMultiples(Stack *stack) {
    Node *current = stack->begin;
    if (current == NULL){
        printf("no multiples");
    } else {
        printf("multiples: ");
    }
    while (current != NULL) {
        printf("%lld ", current->value);
        current = current->next;
    }
    printf("\n");
}

void destroyStack(Stack *stack) {
    Node *current = stack->begin;
    while (current->next != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

Stack* Natural(int x) {
    Stack* stack = createStack();
    for (int i = 1; i < 101; i++) {  
        if ((i%x)==0){
            stackAdd(stack,i);
        }
    }
    return stack;
}

long long int Factorial(long long int Number){
    long long int factorial=1; 
    for (int i = 1; i <= Number; ++i){
        factorial = factorial*i;
        if (factorial<0){
            printf("overflow, maximum factorial ");
            return 20;
        }
    }
    return factorial;
}

unsigned long long int Summ(long long int Number){
    unsigned long long int summ=0; 
    for (long long int i = 1; i <= Number; ++i){
        if (ULLONG_MAX-summ<i){
            printf("overflow, maximum sum ");
            return 6074000999;
        }
        summ = summ+i;
        
    }
    return summ;
}

int Prime(long long int Number){
    for (int i = 2; i <= sqrt(Number); ++i) {
        if (Number % i == 0) {
            return 0; 
        }
    }
    return 1; 
}


void printStack(Stack *stack) {
    printf("number in hexadecimal system: ");
    Node *current = stack->begin;
    while (current != NULL) {
        if (current->value == 10){
            printf("A ");
        }else if (current->value == 11){
            printf("B ");
        }else if (current->value == 12){
            printf("C ");
        }else if (current->value == 13){
            printf("D ");
        }else if (current->value == 14){
            printf("E ");
        }else if (current->value == 15){
            printf("F ");
        } else if (current->value < 10){
            printf("%lld ", current->value);
        }
        current = current->next;
    }
    printf("\n");
}

void System16(int x) {
    Stack* stack = createStack();
    while(x>0){
        stackAdd(stack,x%16);
        x=x/16;
    }
    printStack(stack);
}


void printStack1(Stack *stack) {
    Node *current = stack->begin;
    long long int a;
    while (current != NULL) {
        printf("%lld ", current->value);
        a = current->value;
        while (abs(a/10)<100000000){
            printf(" ");
            a=a*10;
        }
        current = current->next;
    }
    printf("\n");
}

void Power(int x) {
    long long int a;
    for (int i = 1; i <= 10; i++){
        Stack* stack = createStack();
        for (int j = x; j >= 1; j--){
            a=pow(i,j);
            stackAdd(stack,a);
        }

        printStack1(stack);
        destroyStack(stack);
    }
}

