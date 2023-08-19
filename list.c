#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <list.h>

void list_push(t_list **head, int x){
    t_list *tmp;

    if (!head || !(tmp = (t_list*) malloc(sizeof(t_list))))
        return ;
    tmp->val = x;
    tmp->next = *head;
    *head = tmp;
}

int list_pop(t_list **head){
    t_list* prev = NULL;
    int x;

    if (head == NULL) {
        exit(-1);
    }
    prev = *head;
    x = prev->val;
    (*head) = (*head)->next;
    free(prev);
    return x;
}

void list_insert(t_list *head, int n, int val){
    int i = 0;
    t_list *tmp;
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (t_list*) malloc(sizeof(t_list));
    tmp->val = val;
    if (head->next) {
        tmp->next = head->next;
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

void list_remove(t_list **head) {
    while ((*head)->next) {
        list_pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

void list_print(const t_list *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


