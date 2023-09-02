#include <stdlib.h>
#include <stdio.h>
#include <list.h>


size_t list_size(const t_list *head)
{
    size_t cnt = 0;

    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void list_push(t_list **head, int x)
{
    t_list *tmp;

    if (!head || !(tmp = (t_list*) malloc(sizeof(t_list))))
        return ;
    tmp->val = x;
    tmp->next = *head;
    *head = tmp;
}

int list_pop(t_list **head)
{
    t_list* prev = NULL;
    int ret;

    if (head == NULL || *head == NULL)
    {
        return -1;
    }
    prev = *head;
    ret = prev->val;
    (*head) = prev->next;
    free(prev);
    return ret;
}

void list_insert(t_list *head, unsigned n, int val)
{
    unsigned i = 0;
    t_list *tmp;

    while (i < n && head->next)
    {
        head = head->next;
        i++;
    }
    tmp = (t_list*) malloc(sizeof(t_list));
    tmp->val = val;
    if (head->next)
    {
        tmp->next = head->next;
    }
    else
    {
        tmp->next = NULL;
    }
    head->next = tmp;
}

void list_remove(t_list **head)
{
    if (!head || !*head)
        return ;
    while ((*head)->next)
    {
        list_pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

void list_foreach(const t_list *head, void (*f)(int))
{
    if (!f)
        return ;
    while (head)
    {
        f(head->val);
        head = head->next;
    }
}

void list_push_back(t_list** head, int val)
{
    t_list* temp = (t_list*)malloc(sizeof(t_list));
    t_list* iterator = *head;

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