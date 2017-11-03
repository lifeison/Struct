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
Node *first(int d)// ‘ормирование первого элемента
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = 0;
	return pv;
}

void add(Node **pend, int d)// ƒобавление в конец списка
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = *pend;
	(*pend)->next = pv;
	*pend = pv;
}
Node *find(Node *const pbeg, int d)// ѕоиск элемента по ключу
{
	Node *pv = pbeg;
	while (pv)
	{
		if (pv->d == d)break;
		pv = pv->next;
	}
	return pv;
}
Node *insert(Node *const pbeg, Node **pend, int key, int d)// ¬ставка элемента
{
	if (Node *pkey = find(pbeg, key))
	{
		Node *pv = new Node;
		pv->d = d;
		pv->next = pkey->next;// установление св€зи нового узла с последующим
		pv->prev = pkey;// установление св€зи нового узла с предыдущим
		pkey->next = pv;// установление св€зи предыдущего узла с новым
		if (pkey != *pend)(pv->next)->prev = pv;// установление св€зи последующего узла с новым
		// ќбновление указател€ на конец списка,
		// если узел вставл€етс€ в конец
		else *pend = pv;
		return pv;
	}
	return 0;
}
void PrintList(Node *pbeg)// ѕечать списка
{
	// pv пробегает по списку, начина€ с головы
	Node *pv = pbeg;
	while (pv != NULL)// пока не конец списка, печатать значение данных текущего узла 
	{
		cout << pv->d << endl;
		pv = pv->next; // перейти к следующему узлу 
	}
}