#include "VM.h"

void VM::set_instruction(int input){
	this->IS.push(input);
}

void VM::set_data(int input) {
	this->DS.push(input);
}

int VM::get_data() {
	return this->DS.pop();
}

int VM::get_instruction() {
	return this->IS.pop();
}

void VM::decode(int instruction) {
	prs[0] = instruction >> 4;
	prs[1] = instruction & 0x0F;
}

bool VM::eval() {
	if (this->IS.counter != 0) {
		decode(get_instruction());
	}
	else {
		return 0;
	}
	int term, yaterm;

	switch (prs[0]) {
	case 0:
		return 0;
	case 1:
		set_data(prs[1]); 
		break;
	case 2:
		term = get_data();
		yaterm = get_data();
		set_data(term + yaterm);
		break;
	case 3:
		for (; this->DS.counter;) {
			std::cout << get_data() << std::endl;
		}
		break;
	default:
		return 0;
	}
	return 1;
}

void VM::carry_out() {
	bool flag = 1;
	for (; flag;) {
		flag = eval();
	}
}
