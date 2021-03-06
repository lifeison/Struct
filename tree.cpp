#pragma once
#include "tree.h"

void Tree::DeleteSubtree(Node *node) {
	if (node) {
		DeleteSubtree(node->left);
		DeleteSubtree(node->right);
		delete node;
	}
}

//template <class T>
//int Tree<T>::GetHeight(Node *node) {
//	if (node == NULL)
//		return 0;
//	int max = 0;
//	for (Node *current = node->left; current; current = current->right) {
//		int curHeight = GetHeight(current);
//		if (curHeight > max)
//			max = curHeight;
//	}
//	return max + 1;
//}
//template <class T>
//int Tree<T>::GetNodesOnLevel(Node *node, int level) {
//	if (node == NULL)
//		return 0;
//	if (level <= 0)
//		return 0;
//
//	return GetNodesOnLevel(node->left, level - 1) +
//		(level == 1) +
//		GetNodesOnLevel(node->right, level);
//}
void Tree::Add(Node* &node, const int &item) {
	if (node == NULL) {
		node = new Node(item);
	}
	else if (item < node->item) {
		Add(node->left, item);
	}
	else {
		Add(node->right, item);
	}
}
