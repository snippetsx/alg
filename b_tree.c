#include <stdio.h>
#include <stdlib.h>
#include <b_tree.h>

// stdin
// stdout
// stderr

// Передача параметров в функцию
// 1. По значению
// 2. По ссылке


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

btree_t *queue[100];
int head = 0;
int tail = 0;
void bfs(btree_t *root)
{
    queue[0] = root;
    ++tail;

    while (head != tail)
    {
        if (queue[head])
        {
            queue[tail++] = queue[head]->left;
            queue[tail++] = queue[head]->right;
            
            printf("%p\n"
                   "______________________\n"
                   "| %18d |\n"
                   "| %18p |\n"
                   "| %18p |\n"
                   "______________________\n\n\n", queue[head], queue[head]->key, queue[head]->left, queue[head]->right);
        }
        ++head;
    }
}

void b_insert(btree_t **root, int key)
{
    btree_t *node = NULL;
    btree_t *walker;
    // int inserted = 0;

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
            continue;
        }
        else if (walker->key > value)
        {
            walker = walker->left;
            continue;
        }
        else{
            return 1;
        }
    }
    return 0;

}
