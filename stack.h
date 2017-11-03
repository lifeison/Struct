#include "node.h"
class stack{
	node* top;
	int size;
public:
	stack();//Class constructor
	~stack();//Class destructor
	int pop();
	void push(int);
};
