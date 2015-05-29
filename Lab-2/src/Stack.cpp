#include "Stack.h"
using namespace std;
Stack::Stack()
{
    arr = new int[100];
    maxSize=100;
    top=0;
    //ctor
}

Stack::Stack(int n)
{
    arr = new int[n];
    maxSize=100;
    top=0;
    //ctor
}

Stack::~Stack()
{
    //dtor
}
void Stack::push(int n)
{
    arr[++top]=n;
    cout<<"there is now "<<top<<" items on the stack"<<endl;
}

int Stack::pop()
{
    cout<<"there is now "<<top-1<<" items on the stack"<<endl;
    return arr[top--];
}
int Stack::peek()
{
    return arr[top];
}
