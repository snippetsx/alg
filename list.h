typedef struct s_list {
  int val;
  struct s_list* next;
} t_list;

size_t list_size(const t_list *head);

void list_push(t_list **head, int x);

int list_pop(t_list **head);

void list_insert(t_list *head, unsigned n, int val);

void list_remove(t_list **head);

void list_foreach(const t_list *head, void (*f)(int));

void list_push_back(t_list** head, int val);

