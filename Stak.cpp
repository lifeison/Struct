#include <iostream>
 
using namespace std;
 
struct node_s
{
    int dat;
    node_s*prev;
};
 
void push(int, node_s**);
int pop(node_s**);
void output(node_s*);
 
int main()
{
    const int N = 10;
    node_s *top(NULL);
 
    for (int i = 0; i < N; i++){
        push(i, &top);
    }
 
    //output(top);
 
    for (int i = 0; i<N; ++i){
        cout << pop(&top);
    }
 
    //output(top);
 
    system("pause");
    return 0;
}
 
void push(int dat, node_s **top)
{
     node_s*curr = new node_s;
    curr->dat = dat;
    if (*top == NULL){
        curr->prev = NULL;
    }
    else{
        curr->prev = *top;
    }
 
    *top = curr;
}
 
int pop(node_s **top)
{
    int tmp = (**top).dat;
 
    if (*top == NULL)
        return -1;
    node_s *tmp_top = *top;
    *top = (**top).prev;
    delete tmp_top;
    return tmp;
}
 
void output(node_s *top)
{
    while (top != NULL)
    {
        cout << top->dat;
        top = top->prev;
    }
}
