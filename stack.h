#include <stdlib.h>

#define DEFAULT_STACK_VAL 0

typedef char stack_val_t;
typedef struct s_stack {
    stack_val_t val;
    struct s_stack* next;
} t_stack;

size_t stack_size(const t_stack *head);

void stack_push(t_stack **head, stack_val_t x);

int stack_pop(t_stack **head, stack_val_t *ret);

void stack_foreach(const t_stack *head, void (*f)(stack_val_t));
