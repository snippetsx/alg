#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack.h>


int size(struct stack *pt) {
    return pt -> top + 1;
}
 
int empty(struct stack *pt) {
    return pt -> top == -1;               
}

int isFull(struct stack *pt) {
    return pt -> top == pt -> maxsize - 1;
}
 

void push(struct stack *pt, int x)
{
 
    printf("ok\n");
 
    pt -> items[++pt -> top] = x;
}
 
int top(struct stack *pt)
{
    if (empty(pt) != 0){
        printf("error\n");
    }
    else {
        return pt -> items[pt->top];
    }
}
 
int pop(struct stack *pt)
{
    if (empty(pt) != 0){
        printf("error\n");
    }
    else{
        printf("ok\n");
        return pt -> items[pt -> top--];
    }
}
