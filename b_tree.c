#include <stdio.h>
#include <stdlib.h>
#include <b_tree.h>

btree_t *b_new_node(int item) {
    btree_t *temp = (btree_t *)malloc(sizeof(btree_t));
    if(!temp)
    {
        return NULL;
    }
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// void b_print(btree_t *root) {
//     if (root != NULL) {
//         b_print(root->left);
//         printf("%d -> ", root->key);
//         b_print(root->right);
//     }
// }

void b_insert(btree_t **root, int key)
{
    btree_t *node = NULL;
    btree_t *walker;

    if (root == NULL)
        return ;
    
    if (!(node = b_new_node(key)))
        return ;
    if (*root == NULL)
        *root = node;
    else
    {
        // walker->right = node;  // *node ----- btree_t
        // walker->left = node;
        
        walker = *root;
        while (walker) // while (!inserted)
        {
            if (key == walker->key)
                walker = NULL;
            else if (key > walker->key)
            {
                if (walker->right)
                    walker = walker->right;
                else
                {
                    walker->right = node;
                    walker = NULL;
                }
            }
            else
            {
                if (walker->left)
                    walker = walker->left;
                else
                {
                    walker->left = node;
                    walker = NULL;
                }
            }
        }
    }
}

btree_t b_min(btree_t **root)
{
    btree_t *walker;
    walker = *root;
    while(walker->left)
    {
        walker = walker->left;
    }
    return *walker;
}

btree_t b_max(btree_t **root)
{
    btree_t *walker;
    walker = *root;
    while(walker->right)
    {
        walker = walker->right;
    }
    return *walker;
}

int b_search(btree_t **root, int value) //Почти бинпоиск. Если элемент существует, выведет 1, иначе 0
{
    btree_t *walker;
    walker = *root;
    while(walker){
        if(walker->key < value)
        {
            walker = walker->left;
        }
        if (walker->key > value)
        {
            walker = walker->left;
        }
        else{
            return NULL;
        }
    }
    return 0;
}
