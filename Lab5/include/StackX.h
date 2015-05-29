#ifndef STACKX_H
#define STACKX_H
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



class StackX
{

    public:

        StackX(){arr = new int[100];maxSize=100;top=0;}
        StackX(int n){arr = new int[n];maxSize=n;top=0;};

        ~StackX(){}
        void push(int n){arr[++top]=n;}

        int pop(){return arr[top--];}
        int peek(){return arr[top];}
        bool isEmpty()
        {
            if(top==0)
                return true;
            else
                return false;
        }
        int size(){return top;}
        int PeekN(int n){return arr[n];}
        void displayStack(string s)
        {
            cout<<s;
            cout<<"Stack (bottom-->top): ";
            for(int j=0; j<size(); j++)
            {
                cout<<PeekN(j);
                cout<<' ';
            }
            cout<<endl;
        }
    private:
        int* arr;
        int top=0;
        int maxSize=0;

};
#endif // STACKX_H
