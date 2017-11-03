#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int d;
	Node *next;
	Node *prev;
};
Node * first(int d);
void add(Node **pend, int d);
Node * find(Node * const pbeg, int i);
Node *insert(Node *const pbeg, Node **pend, int key, int d);
void PrintList(Node *pbeg);
int main()
{
	return 0;
	_getch();
}
Node *first(int d)// ������������ ������� ��������
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = 0;
	return pv;
}

void add(Node **pend, int d)// ���������� � ����� ������
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = *pend;
	(*pend)->next = pv;
	*pend = pv;
}
Node *find(Node *const pbeg, int d)// ����� �������� �� �����
{
	Node *pv = pbeg;
	while (pv)
	{
		if (pv->d == d)break;
		pv = pv->next;
	}
	return pv;
}
Node *insert(Node *const pbeg, Node **pend, int key, int d)// ������� ��������
{
	if (Node *pkey = find(pbeg, key))
	{
		Node *pv = new Node;
		pv->d = d;
		pv->next = pkey->next;// ������������ ����� ������ ���� � �����������
		pv->prev = pkey;// ������������ ����� ������ ���� � ����������
		pkey->next = pv;// ������������ ����� ����������� ���� � �����
		if (pkey != *pend)(pv->next)->prev = pv;// ������������ ����� ������������ ���� � �����
		// ���������� ��������� �� ����� ������,
		// ���� ���� ����������� � �����
		else *pend = pv;
		return pv;
	}
	return 0;
}
void PrintList(Node *pbeg)// ������ ������
{
	// pv ��������� �� ������, ������� � ������
	Node *pv = pbeg;
	while (pv != NULL)// ���� �� ����� ������, �������� �������� ������ �������� ���� 
	{
		cout << pv->d << endl;
		pv = pv->next; // ������� � ���������� ���� 
	}
}