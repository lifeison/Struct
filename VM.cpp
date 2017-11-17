#include "iostream"
using namespace std;

int prs[4];
int registres[4];
int ip = 0;
int code[] = { 0x1064, 0x11C8, 0x2201, 0x0000 };

int fetch(){
	return code[ip++];
}

void decode(int instraction){
	int shift = 12;
	int mask = 0xF000;
	for (int i = 0; i < 4; i++){
		prs[i] = (instraction & mask) >> shift;

		shift -= 4;
		mask >>= 4;
		mask |= 0x0000;
	}
}

bool eval(){
	switch (prs[0]){
	case 0:
		return 0;
	case 1:
		registres[prs[1]] = prs[2] * 16 + prs[3];
		break;
	case 2:
		registres[prs[1]] = registres[prs[2]] + registres[prs[3]];
		break;
	default:
		cout << "error" << endl;
		return 0;
	}

	return 1;
}

int main(){
	bool flag = 1;
	for (;flag;){
		decode(fetch());
		flag = eval();
	}
	for (int i = 0; i < 4; i++){
		cout << registres[i] << endl;
	}
	return 0;
}
