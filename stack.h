struct stack
{
    int maxsize;
    int top;
    int *items;
};

struct stack* newstack(int capacity);

int size(struct stack *pt);

int empty(struct stack *pt);

int isFull(struct stack *pt);

void push(struct stack *pt, int x);

int top(struct stack *pt);

int pop(struct stack *pt);