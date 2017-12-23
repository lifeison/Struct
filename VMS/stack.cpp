#include "stack.h"

void stack::push(int input) {
	node* node_ptr = new node;
	node_ptr->data = input;
	node_ptr->next_ptr = stack_ptr;
	stack_ptr = node_ptr;
	counter++;
}

int stack::pop() {
	node* node_ptr = stack_ptr;
	int output = stack_ptr->data;
	stack_ptr = node_ptr->next_ptr;
	delete node_ptr;
	counter--;
	return output;
}
