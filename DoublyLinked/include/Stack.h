#ifndef STACK_H
#define STACK_H
#include "StudentList.h"

class Stack
{
    public:
        Stack(){}
        virtual ~Stack(){}
        void Push(Student * v)
        {
            room.addHead(v);
        }
        std::string Pop()
        {
            return room.removeHead();
        }
    private:
        StudentList room;
};

#endif // STACK_H
