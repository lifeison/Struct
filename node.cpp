#include "stack.h"
#include "stddef.h"
// node class constructor
node::node(node* prev, int data){
	this->prev = prev;
	this->data = data;
}
// "Get" method for field prev of class node
node* node::getPrev(){
	return this->prev;
}
// "Get" method for field data of class node
int node::getData(){
	return this->data;
}
