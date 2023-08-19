#include <stdio.h>
#include <list.h>

int main()
{
    t_list *head = NULL;

    list_push(&head, 1);
    list_push(&head, 2);
    list_push(&head, 3);
    list_push(&head, 4);
    list_push(&head, 5);
    list_print(head);
    list_pop(&head);
    list_print(head);
    list_insert(head, 4, 34);
    list_print(head);
    return 0;
}
