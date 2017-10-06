#include <conio.h>
#include <iostream>
#include <locale.h>
 using namespace std;
struct QUEUE //ñòðóêòóðà î÷åðåäü
{
    int info;
    QUEUE *next;
};
 
int EmptyQ(QUEUE *first) //ïðîâåðêà ïóñòîòû î÷åðåäè
{
    if ((first)==NULL)
    return 1;
    else
    return 0;
}
 
void AddQ(QUEUE ** last) //äîáàâëåíèå ýëåìåíòà 
{
    QUEUE *tmp = new QUEUE;
    tmp->info=rand()%100;
    tmp->next=NULL;
    (*last)->next=tmp;
    *last=tmp;
}
 
void DelQ(QUEUE *first, QUEUE ** last) //óäàëåíèå èç î÷åðåäè 
{
    QUEUE *tmp=first->next;
    if(first->next==NULL)
    *last=first;
    delete tmp;
}
 
void ShowQ(QUEUE *first) //ïðîñìîòð î÷åðåäè
{
    QUEUE *tmp=first->next;
    while(tmp!=NULL)
    {
        cin>>tmp->info;
        tmp=tmp->next;
    }
}
 
void ClearQ(QUEUE *first, QUEUE ** last) //î÷èñòêà î÷åðåäè 
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
        cout<<"1. Äîáàâëåíèå ýëåìåíòîâ â êîíåö î÷åðåäè \n"<<endl;
        cout<<"2. Óäàëåíèå ýëåìåíòà èç íà÷àëà î÷åðåäè \n"<<endl;
        cout<<"3. Âûâîä ýëåìåíòîâ \n"<<endl;
        cout<<"0. Âûõîä \n"<<endl;
        cout<<"Âûáðàííîå äåéñòâèå: "<<endl;
        cin>> d;
        switch(d)
        {
            case 1:
            AddQ(&last);
            cout<<"\nÝëåìåíò äîáàâëåí â êîíåö î÷åðåäè \n"<<endl;
            break;
 
            case 2:
            if (EmptyQ(first)==1)
            cout<<"\nÎ÷åðåäü ïóñòàÿ \n";
            else
            {
                DelQ(first,&last);
                cout<<"\nÝëåìåíò óäàëåí èç î÷åðåäè \n"<<endl;
            }
            break;
 
            case 3:
            if (EmptyQ(first)==1)
            cout<<"\nÎ÷åðåäü ïóñòàÿ \n"<<endl;
            else
            {
               cout<<"\nÝëåìåíòû î÷åðåäè: "<<endl;
                ShowQ(first);
                cout<<"\n";
            }
            break;
 
            case 0:
            ClearQ(first,&last);
            break;
            default: cout<<"\nÎøèáêà!\n"<<endl; break;
          }
       }while(d!=0);
    _getch();
}
