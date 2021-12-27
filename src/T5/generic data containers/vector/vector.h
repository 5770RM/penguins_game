/*
 * KEY REMARKS
 * - the vector is implemented using dynamic arrays
 * - it is a generic data container,  but it can store only one type of data at a time 
 * - to use the vector, the construtor is needed to be called - it returns a pointer to the memory allocated for it
 * - all memory managment is done behind the scenes, however deconstructor is needed to be called in order to free all the memory taken up by the vector
 * - doubling technique is used in case of vector saturation
*/

typedef struct {
    void *elems;        // pointer to the data
    int elemSize;       // number of bytes a single element takes
    int logLength;      // number of elements in the vector
    int allocLength;    // for how many elements the vector allocated memory 
} vector;

vector *vector_create(int elemSize);
void vector_destroy(vector *v);
int vector_empty(vector *v);
int vector_size(vector *v);
void vector_push(vector *v, void *elemAddr);
void vector_pop(vector *v);
void vector_back(vector *v, void *elemAddr);
void vector_at_n(vector *v, void *elemAddr, int n);

