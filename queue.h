struct queue {
        int *data;  
        int low;
        int high;
        int count;
        int max;
};

struct queue *init(size_t size);

void enqueue (struct queue *q, int a);

int dequeue (struct queue *q);


