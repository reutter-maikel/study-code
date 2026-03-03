/*
 * File: Section2.c
 * Description: implementing stacks
 */


 #include <stdio.h>
 #include <stdlib.h>

 typedef struct
 {
    int key; // Iterator
    struct StackElem *next;
 }StackElem;

 typedef struct 
 {
    StackElem *top; // Head
 }Stack;

 Stack *initializeStack()
 {
    Stack *S = malloc(sizeof *S);
    S->top = NULL;
    return S;
 }

 void push(Stack *S, int key)
 {
    StackElem *a = malloc(sizeof *a);
    a->key = key;
    a->next = S->top;
    S->top = a;
 }

 int pop(Stack *S)
 {
    StackElem *temp = S->top;
    int key = S->top->key;
    S->top = S->top->next;
    free(temp);
    return key;
 }

 void deleteStack(Stack *S)
 {
    while(S->top != NULL)
    {
        pop(S);
    }
    free(S);
 }

 void printStack(Stack *S)
 {
    StackElem *temp = S->top;
    printf("Stack: \n");
    while(temp != NULL)
    {
        printf("%d\n", temp->key);
        temp = temp->next;
    }
    printf("____________\n");
 }

 int top(Stack *S)
 {
    if (S->top == NULL) // Prüfen ob Stack leer ist
    {
        return -1; // return error
    }
    else
    {
        printf("top = %d\n", S->top->key);
        return S->top->key; // wenn nicht leer, dann wert des obersten Elements ausgegeben
    }
 }

 int main()
 {
    Stack *S = initializeStack();

    push(S,4);
    push(S,8);
    push(S,7);  
    printStack(S);
    top(S);

    pop(S);
    pop(S);
    printStack(S);
    top(S);

    push(S,9);
    printStack(S);
    top(S);

    deleteStack(S);

    return 0;
 }