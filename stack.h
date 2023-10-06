#include <stdlib.h>

#define DEFAULT_STACK_VAL 0

typedef struct s_stack {
    char val;
    struct s_stack* next;
} t_stack;

size_t stack_size(const t_stack *head);

void stack_push(t_stack **head, char x);

void stack_foreach(const t_stack *head, void (*f)(char));

void stack_foreach(const t_stack *head, void (*f)(char));
