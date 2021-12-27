/*
 * KEY REMARKS
 * - the queue is implemented using doubly liked lists
 * - it is a generic data container - can store any type of data, by only one type at a time 
 * - to use the queue, the construtor is needed to be called - it returns a pointer to the memory allocated for the queue
 * - all memory managment is done behind the scenes, however deconstructor is needed to be called in order to free all the memory taken up by the queue
 */
struct queue_node {
    void *data;
    struct queue_node *next;    // the first element points to NULL
    struct queue_node *prev;    // the last element points to NULL
};

typedef struct queue_node queue_node;

typedef struct {
    queue_node *front;  // pointer to the front  
    queue_node *back;   // pointer to the front  
    int size;           // number of elements in the stack
    int elemSize;
} queue;

queue *queue_create(int elemSize);
void queue_destroy(queue *q);
int queue_empty(queue *q);
void queue_push(queue *q, void *elemAddr);
void queue_pop(queue *q);
void queue_front(queue *q, void *elemAddr);
