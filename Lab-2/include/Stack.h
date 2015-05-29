#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack
{
    public:
        Stack();
        Stack(int n);
        ~Stack();
        void push(int n);
        int pop();
        int peek();
    private:
        int* arr;
        int top=0;
        int maxSize=0;
};

#endif // STACK_H
