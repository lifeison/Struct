#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//TODO


node* generate_test_data() {
    node* item = (node*) malloc(sizeof(node));

    item->data = 8888;
    item->junk.mem_chunk = MEM_CHUNK_TEST_VALUE;
    item->junk.ratio = RATIO_TEST_VALUE;
    strncpy(item->junk.chunk_dump, CHUNK_DUMP_TEST_VALUE, DUMP_MAX_SIZE);
    item->prev = NULL;

    return item;
}


void delete_test_data(node *data) {
    free(data);
}
