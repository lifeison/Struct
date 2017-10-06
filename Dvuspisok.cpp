#include <stdio.h>
#include <stdlib.h>
#include <iostream>                    
#include <clocale>                    

using namespace std;

struct node
{
	int data;                          // значение ячейки
	node* prev;                        // предыдущий элемент
	node* next;						   // следующий элемент
};

struct roster
{
	int size;                           
	node* up;                           // первый элемент
	node* down;                         // последний элемент
};

void push_back(roster *R);                // добавление в конец
int pop_back(roster *R);                  // удаление из конца
void push_front(roster *R);               // добавление в начало
int pop_front(roster *R);                 // удаление из начала
void step_by_step(roster *R);             // сводит воедино всё, что выше
void insert(roster *R);					// вставка в любое место
void output(roster *R);					// вывод двусписка
void sort(roster *R);

int main()
{
	setlocale(LC_ALL, "Rus");           
	roster Roster;                          // макет cписка 
	Roster.size = 0;                      
	Roster.up = NULL;                     // обнуление вершины
	Roster.down = NULL;					// обнуление низа
	step_by_step(&Roster);
	system("pause");
	return 0;
}

void step_by_step(roster *R)
{
	int n;
	cout << "Введите количество элементов в список: ";
	cin >> n;
	cout << "Добавление элемента в список: " << endl;
	for (int i = 0; i < n; i++)
	{
		push_back(R);
		push_front(R);
	}
}

void push_front(roster *R)				
{
	int value;							
	cin >> value;						
	node* value_pointer = new node;		
	value_pointer->data = value;		
	value_pointer->prev = R->up;		// адрес предыдущей ячейки = адрес вершины(старой)
	R->up = value_pointer;				// получение адреса для первого элемента, который станет вершиной(новой)
	R->size++;							// увеличение элементов в списке путем добавления нового
}

int pop_front(roster *R)					
{
	int value_temp = 0;					// временная переменная для хранения вершины(старой)
	node *value_pointer;				// указатель на структуру, которую удалим
	value_pointer = R->up;				// адрес вершины(старой) приравнивается к указателю 
	value_temp = R->up->data;			// в врем. значении хранится значение вершины по адресу вершины(старой)
	R->up = value_pointer->prev;		// предыдущ. элемент станет вершиной(новой)
	delete value_pointer;				// освобождаем память в которой находится вершина(старая)
	R->size--;							// уменьшение элементов в списке путем удаление старого
	return value_temp;					// возвращаем значение вершины(старой)
}

void push_back(roster *R)
{
	int value;							// значение вводимой переменной
	cin >> value;						// ввод переменной
	node* value_pointer = new node;		// выделение памяти под новую ячейку в списке
	value_pointer->data = value;		// получение введенного числа
	value_pointer->next = R->down;		// адрес следующ. ячейки = адрес низа(старого)
	R->down = value_pointer;			// получение адреса для последнего элемента, который станет низом(новым)
	R->size++;							// увеличение элементов в списке путем добавление нового
}

int pop_back(roster *R)
{
	int value_temp = 0;					// временная переменная для хранения низа(старого)
	node *value_pointer;				// указатель на структуру, которую удалим
	value_pointer = R->down;			// адрес низа(старого) приравнивается к указателю 
	value_temp = R->down->data;			// в врем. значении хранится значение низа по адресу низа(старого)
	R->down = value_pointer->next;		// следующий элемент станет низом(новым)
	delete value_pointer;				// освобождаем память в которой находится низ(старый)
	R->size--;							// уменьшение элементов в списке путем удаление старого
	return value_temp;					// возвращаем значение низа(старого)
}

void insert(roster *R)
{
	//
}

void output(roster *R)
{
	//
} 

void sort(roster *R)
{
	//
}
