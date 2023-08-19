typedef struct s_list {
  int val;
  struct s_list* next;
} t_list;

void list_push(t_list **head, int x);

int list_pop(t_list **head);

void list_insert(t_list *head, unsigned n, int val);

void list_remove(t_list **head);

void list_print(const t_list *head);
