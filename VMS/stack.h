#pragma once
#include <iostream>

struct node {
	int data;
	node* next_ptr;
};

class stack {
	node* stack_ptr = NULL;
public:
	int counter = 0;
	//stack();
	//~stack();
	void push(int);
	int pop();
};
