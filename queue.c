#include <stdlib.h>
#include <stdio.h>
#include <queue.h>

size_t queue_size(const t_queue *head)
{
    size_t cnt = 0;

    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

t_queue *queue_new_element(int value, t_queue *next)
{
    t_queue *element = (t_queue*)malloc(sizeof(t_queue));
    
    if (element)
    {
        element->val = value;
        element->next = next;
    }
    return element;
}

void queue_push(t_queue **head, int val)
{
    t_queue *tmp;

    if (!head || !(tmp = queue_new_element(val, *head)))
        return ;
    *head = tmp;
}

int queue_pop(t_queue **head, int *ret)
{
    t_queue* prev = NULL;

    if (head == NULL || *head == NULL)
        return -1;

    prev = *head;
    if (ret)
        *ret = prev->val;
    (*head) = prev->next;
    free(prev);
    
    return 0;
}

int queue_top(t_queue *head)
{
    if (!head)
        return DEFAULT_QUEUE_VAL;
    return head->val; 
}

void queue_foreach(const t_queue *head, void (*f)(int))
{
    if (!f)
        return ;
    while (head)
    {
        f(head->val);
        head = head->next;
    }
}

void queue_pop(t_queue** head, int val)
{
    t_queue* temp = (t_queue*)malloc(sizeof(t_queue));
    t_queue* iterator = *head;

    temp->val = val;
    temp->next = NULL;

    if (iterator == NULL)
    {
        *head = temp;
        return;
    }
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = temp;
}