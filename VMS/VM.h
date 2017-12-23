#pragma once
#include "stack.h"

class VM {
private:
	stack DS;
	stack IS;
	int prs[2];

	int get_instruction();
	int get_data();
	void set_data(int);
	void decode(int); 
	bool eval();

public:
	void set_instruction(int);
	void carry_out();
};
