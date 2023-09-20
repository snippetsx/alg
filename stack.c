#include <stdlib.h>
#include <stdio.h>
#include <stack.h>

size_t stack_size(const t_stack *head)
{
    size_t cnt = 0;

    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

t_stack *stack_new_element(int value, t_stack *next)
{
    t_stack *element = (t_stack*)malloc(sizeof(t_stack));
    
    if (element)
    {
        element->val = value;
        element->next = next;
    }
    return element;
}

void stack_push(t_stack **head, int val)
{
    t_stack *tmp;

    if (!head || !(tmp = stack_new_element(val, *head)))
        return ;
    *head = tmp;
}

int stack_pop(t_stack **head, int *ret)
{
    t_stack* prev = NULL;

    if (head == NULL || *head == NULL)
        return -1;

    prev = *head;
    if (ret)
        *ret = prev->val;
    (*head) = prev->next;
    free(prev);
    
    return 0;
}

void stack_foreach(const t_stack *head, void (*f)(int))
{
    if (!f)
        return ;
    while (head)
    {
        f(head->val);
        head = head->next;
    }
}