/**
 * File contains definitions of stack node structure and
 * operations on stack
 */

#include "stacktest.h"


#define DUMP_MAX_SIZE 50


// Structure with some junk data for testing purposes
typedef struct junk_load_s {
    int mem_chunk;
    double ratio;
    char chunk_dump[DUMP_MAX_SIZE];
} junk_load;


// Stack node structure
typedef struct node_s {
    int data;
    junk_load junk;
    struct node_s *prev;
} node;


// void push();

// int pop();

node* generate_test_data();

void delete_test_data(node *data);
