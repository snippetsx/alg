#include <b_tree.h>

int b_tree_test1()
{
    btree_t *root;
    b_insert(&root, 20);
    b_insert(&root, 16);
    b_insert(&root, 28);
    b_insert(&root, 50);
    b_insert(&root, 3);
    b_insert(&root, 42);
    b_insert(&root, 35);
    b_insert(&root, 44);
    b_insert(&root, 76);
    b_insert(&root, 24);
    printf("%d", b_search(root, 4));
    printf("%d", b_search(root, 50));
    printf("%d", b_min(root));
    printf("%d", b_min(root));
    return 0;
}
