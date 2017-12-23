#include "stack.h"
#include "VM.h"
using namespace std;

const int N = 4;
int code[N] = { 0x18, 0x16, 0x20, 0x00 };

int main() {
	VM mashine;
	for (int i = N - 1; i >= 0; i--) {
		mashine.set_instruction(code[i]);
	}

	mashine.carry_out();

	mashine.set_instruction(0x30);

	mashine.carry_out();


	return 0;
}
