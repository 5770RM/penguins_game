/*
 * KEY REMARKS
 * - the stack is implemented using sinlgly liked lists
 * - it is a generic data container - can store any type of data, by only one type at a time 
 * - to use the stack, the construtor is needed to be called - it returns a pointer to the memory allocated for the stack
 * - all memory managment is done behind the scenes, however stack deconstructor is needed to be called in order to free all the memory taken up by the stack
 */

// strucure a single node in the stack
struct stack_node {
    void *data;                 // the data stored in a node of size itemSize
    struct stack_node *next;    // pointer to the next element, NULL for the element on the bottom of the stack
};

typedef struct stack_node stack_node;

typedef struct {
    stack_node *top;    // pointer to the top of the stack
    int size;           // number of elements in the stack
    int elemSize;       // number of bytes taken up by a single element in the stack
} stack;

stack *stack_create(int elemSize);  // stack constructor
void stack_destroy(stack *s);       // stack deconstructor
int stack_empty(stack *s);
int stack_size(stack *s);
void stack_push(stack *s, void *elemAddr);
void stack_pop(stack *s);
void stack_top(stack *s, void *elemAddr);
