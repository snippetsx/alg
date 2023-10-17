#include <stdlib.h>

#define DEFAULt_queue_VAL 0

typedef struct s_queue {
    int val;
    struct s_queue* next;
} t_queue;

size_t stack_size(const t_queue *head);

void stack_push(t_queue **head, int x);

int stack_pop(t_queue **head, int *ret);

int stack_top(t_queue *head);

void stack_foreach(const t_queue *head, void (*f)(int));