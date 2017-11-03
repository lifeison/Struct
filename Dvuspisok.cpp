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
Node *first(int d)// Формирование первого элемента
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = 0;
	return pv;
}

void add(Node **pend, int d)// Добавление в конец списка
{
	Node *pv = new Node;
	pv->d = d; pv->next = 0; pv->prev = *pend;
	(*pend)->next = pv;
	*pend = pv;
}
Node *find(Node *const pbeg, int d)// Поиск элемента по ключу
{
	Node *pv = pbeg;
	while (pv)
	{
		if (pv->d == d)break;
		pv = pv->next;
	}
	return pv;
}
Node *insert(Node *const pbeg, Node **pend, int key, int d)// Вставка элемента
{
	if (Node *pkey = find(pbeg, key))
	{
		Node *pv = new Node;
		pv->d = d;
		pv->next = pkey->next;// установление связи нового узла с последующим
		pv->prev = pkey;// установление связи нового узла с предыдущим
		pkey->next = pv;// установление связи предыдущего узла с новым
		if (pkey != *pend)(pv->next)->prev = pv;// установление связи последующего узла с новым
		// Обновление указателя на конец списка,
		// если узел вставляется в конец
		else *pend = pv;
		return pv;
	}
	return 0;
}
void PrintList(Node *pbeg)// Печать списка
{
	// pv пробегает по списку, начиная с головы
	Node *pv = pbeg;
	while (pv != NULL)// пока не конец списка, печатать значение данных текущего узла 
	{
		cout << pv->d << endl;
		pv = pv->next; // перейти к следующему узлу 
	}
}
