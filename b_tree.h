typedef struct btree_s
{
    int key;
    struct btree_s* right;
    struct btree_s* left;
} btree_t;

btree_t *b_new_node(int item);

void bfs(btree_t *root);

void b_insert(btree_t **root, int key);

btree_t b_min(btree_t **root);

btree_t b_max(btree_t **root);

int b_search(btree_t **root, int value);
