// https://informatics.msk.ru/mod/statements/view.php?id=207&chapterid=55#1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct stack
{
    int maxsize;
    int top;
    int *items;
};
 
struct stack* newstack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
 
    return pt;
}
 

int size(struct stack *pt) {
    return pt->top + 1;
}
 
int empty(struct stack *pt) {
    return pt->top == -1;               
}

int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;
}
 

void push(struct stack *pt, int x)
{
 
    printf("ok\n");
 
    pt->items[++pt->top] = x;
}
 
int top(struct stack *pt)
{
    if (empty(pt) != 0){
        printf("error\n");
    }
    else {
        return pt->items[pt->top];
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
 
int main()
{
    struct stack *st = newstack(100);
    char s[10] = "";
    int x;
    while (strcmp(s, "exit" ) != 0){
        scanf("%s", &s);
        if(strcmp(s, "push") == 0){
            scanf("%d", &x);
            push(st, x);
        }
        else if(strcmp(s, "pop") == 0){
           pop(st);
        }
        else if(strcmp(s, "top") == 0){
           printf("%d", top(st));
        }
        else if(strcmp(s, "empty") == 0){
            if(empty(st) == 0){
                printf("NO\n");
            }
            else if(empty(st) != 0){
                printf("YES\n");
            }
        }
    }
    printf("bye");
    return 0;
}