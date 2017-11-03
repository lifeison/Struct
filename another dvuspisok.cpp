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
        spisok("1. �������� �������\n");
        spisok("2. �������� ������ ����� �������\n");
        spisok("3. �������� ������ ������ ������\n");
        spisok("4. ������� ������\n");
        spisok("5. ������� �����\n");
        spisok("6. ����� ��������\n");
        spisok("0. �����\n\n");
        spisok("��� �����: ");
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
            spisok("������� �����: ");
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
                spisok("\t!!! ������ ���� !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("* * * * * ������: ����� ������� * * * * *\n\n");
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
                spisok("\t!!! ������ ���� !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("* * * * * ������: ������ ������ * * * * *\n\n");
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
                spisok("\t!!! ������ ���� !!!\n\n");
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
                spisok("\t!!! ������ ���� !!!\n\n");
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
                spisok("\t!!! ������ ���� !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            spisok("������� ������� ��� ������: ");
            cin>>key;           
            ptr = head;
            while (1)
            {
                if (key == ptr->number)
                {
                    spisok("\n\t!!! ������� ������ !!!\n");
                    break;
                }
                if (ptr->next == NULL)
                {
                    spisok("\n\t!!! ������� �� ������ !!!\n");
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
            spisok("\t!!! �������� �����. ��������� ���� !!!\n\n");
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