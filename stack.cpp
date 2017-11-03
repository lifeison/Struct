#include "node.h"
#include "stddef.h"
// stack class constructor. Initialises both private fields with standart constants
stack::stack(){
	size = 0;
	top = NULL;
}
// stack class destructor
stack::~stack(){
	for (int i = 0; i < this->size; i++){
		node* old_top = this->top;
		this->top = this->top->getPrev();
		delete old_top;//Delete old top
	}
}
// Method needed to push data to the top
void stack::push(int data){
	this->top = new node(this->top, data);
	if (this->top == NULL){
		throw "ERROR! Couldn't allocate memory for an element.";
	}
	this->size++;//Incrementing size of the stack
}
// Method needed to delete the top of stack and return its current useful data
int stack::pop(){
	if (this->size == 0){
		throw "ERROR! The stack is already empty.";
	}
	else{
		int r_data = this->top->getData();//Saving data of the old top needed to return
		node* old_top = this->top;//Extracting old top from the stack
		this->top = this->top->getPrev();//Setting a new top of the stack
		this->size--;//Decreasing size
		delete old_top;//Deallocating memory for the top node of the stack
		return r_data;//Returning useful data of the old top
	}
}
