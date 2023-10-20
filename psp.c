#include <stack.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
    t_stack *stck = NULL;
    int n = 0;
    char ch = 0;
    char tmp = 0;
    int wrong = 0;

    ch = getchar();
    while (ch != '\n')
    {
        if (ch == '{' || ch == '[' || ch == '(')
        {
            stack_push(&stck, ch);
        }
        else // if (ch == '}' || ch == ']' || ch == ')')
        {
            tmp = stack_top(stck);
            if ((ch == '}' && tmp == '{') ||
                (ch == ']' && tmp == '[') ||
                (ch == ')' && tmp == '('))
            {
                stack_pop(&stck, NULL);
            }
            else
            {
                wrong = 1;
                break;
            }
        }
        ch = getchar();
    }
    if (stack_size(stck) > 0 || wrong)
        puts("Not right");
    else
        puts("Right");
    return 0;
}
