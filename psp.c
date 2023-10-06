#include <stack.h>
#include <stdio.h>

int main()
{
    t_stack *stck;
    char ch;
    int n = 0;
    while (ch != '\n')
    {
        ch = getchar();
        if(ch == '(')
            stack_push(&stck, '(');
        else if (ch == ')' && stack_pop(&stck) == -1)
            break;
    }
    if(stack_pop(&stck) == -1)
    {
        printf("Right");
    }
    else
    {
        printf("Not right");
    }
    return 0;
}
