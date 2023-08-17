#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct queue {
        int *data;  
        int low;
        int high;
        int count;
        int max;
};

struct queue *init(size_t size)
{
        struct queue * q = calloc (1, sizeof (struct queue));
        q->data = calloc (size, sizeof (int));
        q->low = q->high = size - 1;
        q->max = size;

        return q;
}

void enqueue (struct queue *q, int a)
{

        if (q->count == q->max) {
                printf ("not enough queue size\n");
                return;
        }

        q->data[q->low--] = a;
        q->count++;

        if (q->low < 0) {
                q->low = q->max - 1;
        }

}

int dequeue (struct queue *q)
{
        int a = q->data[q->high--];
        q->count--;

        if (q->high < 0) {
                q->high = q->max - 1;
        }

        return a;
}
int main(){
    struct queue *q =  init(10);
    char s[4] = "";
    int x;
    while (strcmp(s, "exit" ) != 0){
        scanf("%s", &s);
        if(strcmp(s, "push") == 0){
            scanf("%d", &x);
            enqueue(q, x);
        }
        else if(strcmp(s, "pop") == 0){
           dequeue(q);
        }
    }
    printf("bye");
}