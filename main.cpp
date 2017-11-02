#include <iostream>
#include "tree.h"
using namespace std;
int main() {
	Tree tree1;

	tree1.Add(12);
	tree1.Add(5);
	tree1.Add(3);
	tree1.Add(10);
	tree1.Add(7);
	tree1.Add(11);
	tree1.Add(6);
	tree1.Add(9);

	/*cout << "Tree height: " << tree1.GetHeight() << endl
		<< "There are" << tree1.GetNodesOnLevel(3) << " nodes on the 3rd level" << endl;*/
	return 0;
}

