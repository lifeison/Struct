#include <iostream>
#include <windows.h>
using namespace std;
 
class Node
{
public:
    int number;
    Node* next;
    Node* last;
};
 
void spisok(const char*);
 
void main()
{
    short action = -1;
    Node* head = NULL;
    Node* tail = NULL;
    Node* ptrLast = NULL;
 
    while (1)
    {       
        spisok("1. Добавить Элемент\n");
        spisok("2. Просмотр Списка Слева Направо\n");
        spisok("3. Просмотр Списка Справа Налево\n");
        spisok("4. Удалить Голову\n");
        spisok("5. Удалить Хвост\n");
        spisok("6. Поиск Элемента\n");
        spisok("0. Выход\n\n");
        spisok("Ваш Выбор: ");
        cin>>action;
 
        if (action == 0)
        {
            system("CLS");
            break;
        }
 
        if (action == 1)
        {
            system("CLS");
            int numb = -1;
            spisok("Введите Число: ");
            cin>>numb;
            Node* ptr = new Node;
            ptr->number = numb;
            ptr->next = NULL;
            tail = ptr;
            if (head == NULL)
            {
                head = ptr;
                ptrLast = ptr;
                ptr->last = NULL;
                system("CLS");
                continue;
            }
            ptr->last = ptrLast;
            ptrLast->next = ptr;
            ptrLast = ptr;
            system("CLS");
            continue;
        }
 
        if (action == 2)
        {
            system("CLS");
            Node* ptr = NULL;
            if (head == NULL)
            {
                spisok("\t!!! СПИСОК ПУСТ !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("* * * * * СПИСОК: СЛЕВА НАПРАВО * * * * *\n\n");
            ptr = head;
            while (1)
            {
                cout<<ptr->number<<" ";
                if (ptr->next == 0)
                    break;
                ptr = ptr->next;
            }
            cout<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action == 3)
        {
            system("CLS");
            Node* ptr = NULL;           
            if (head == NULL)
            {
                spisok("\t!!! СПИСОК ПУСТ !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("* * * * * СПИСОК: СПРАВА НАЛЕВО * * * * *\n\n");
            ptr = tail;
            while (1)
            {
                cout<<ptr->number<<" ";
                if (ptr->last == 0)
                    break;
                ptr = ptr->last;
            }
            cout<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action == 4)
        {
            system("CLS");
            Node* ptrDelete = NULL;         
            if (head == NULL)
            {
                spisok("\t!!! СПИСОК ПУСТ !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            if (head->next == NULL)
            {
                head = NULL;
                tail = NULL;
                delete head;
                continue;
            }
            ptrDelete = head;
            head = ptrDelete->next;
            head->last = NULL;
            delete ptrDelete;
            continue;
        }
 
        if (action == 5)
        {
            system("CLS");
            Node* ptrDelete = NULL;
            if (tail == NULL)
            {
                spisok("\t!!! СПИСОК ПУСТ !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            if (tail->last == NULL)
            {
                head = NULL;
                tail = NULL;
                delete tail;
                continue;
            }           
            ptrDelete = tail;
            tail = ptrDelete->last;
            tail->next = NULL;
            ptrLast = tail;
            delete ptrDelete;
            continue;
        }
 
        if (action == 6)
        {
            system("CLS");
            Node* ptr = NULL;
            int key = -1;
            if (head == NULL)
            {
                spisok("\t!!! СПИСОК ПУСТ !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("Введите Элемент Для Поиска: ");
            cin>>key;           
            ptr = head;
            while (1)
            {
                if (key == ptr->number)
                {
                    spisok("\n\t!!! ЭЛЕМЕНТ НАЙДЕН !!!\n");
                    break;
                }
                if (ptr->next == NULL)
                {
                    spisok("\n\t!!! ЭЛЕМЕНТ НЕ НАЙДЕН !!!\n");
                    break;
                }
                ptr = ptr->next;
            }
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action > 6)
        {
            system("CLS");
            spisok("\t!!! НЕВЕРНЫЙ ВЫБОР. ПОВТОРИТЕ ВВОД !!!\n\n");
            system("PAUSE");
            system("CLS");
            continue;
        }
    }
}
 
void spisok(const char* rus)
{
    char word[100];
    CharToOem(rus, word);
    cout<<word;
}