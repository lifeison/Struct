#include <conio.h>
#include <iostream>
#include <locale.h>
 using namespace std;
struct QUEUE //структура очередь
{
    int info;
    QUEUE *next;
};
 
int EmptyQ(QUEUE *first) //проверка пустоты очереди
{
    if ((first)==NULL)
    return 1;
    else
    return 0;
}
 
void AddQ(QUEUE ** last) //добавление элемента 
{
    QUEUE *tmp = new QUEUE;
    tmp->info=rand()%100;
    tmp->next=NULL;
    (*last)->next=tmp;
    *last=tmp;
}
 
void DelQ(QUEUE *first, QUEUE ** last) //удаление из очереди 
{
    QUEUE *tmp=first->next;
    if(first->next==NULL)
    *last=first;
    delete tmp;
}
 
void ShowQ(QUEUE *first) //просмотр очереди
{
    QUEUE *tmp=first->next;
    while(tmp!=NULL)
    {
        cin>>tmp->info;
        tmp=tmp->next;
    }
}
 
void ClearQ(QUEUE *first, QUEUE ** last) //очистка очереди 
{
    QUEUE *tmp;
    while(first->next!=NULL)
    {
        tmp=first->next;
        first->next = tmp;
        delete tmp;
    }
   * last=first;
}
 
int main()
{
    setlocale(0, "rus");
    QUEUE *first, *last;
    int n;
    char d;
    do
    {
        cout<<"1. Добавление элементов в конец очереди \n"<<endl;
        cout<<"2. Удаление элемента из начала очереди \n"<<endl;
        cout<<"3. Вывод элементов \n"<<endl;
        cout<<"0. Выход \n"<<endl;
        cout<<"Выбранное действие: "<<endl;
        cin>> d;
        switch(d)
        {
            case 1:
            AddQ(&last);
            cout<<"\nЭлемент добавлен в конец очереди \n"<<endl;
            break;
 
            case 2:
            if (EmptyQ(first)==1)
            cout<<"\nОчередь пустая \n";
            else
            {
                DelQ(first,&last);
                cout<<"\nЭлемент удален из очереди \n"<<endl;
            }
            break;
 
            case 3:
            if (EmptyQ(first)==1)
            cout<<"\nОчередь пустая \n"<<endl;
            else
            {
               cout<<"\nЭлементы очереди: "<<endl;
                ShowQ(first);
                cout<<"\n";
            }
            break;
 
            case 0:
            ClearQ(first,&last);
            break;
            default: cout<<"\nОшибка!\n"<<endl; break;
          }
       }while(d!=0);
    _getch();
}
