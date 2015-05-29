#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>
#include <cstring>

class PQueue
{
    public:
        PQueue();
        PQueue(int n);
        ~PQueue();

        void addValue(int n);
        //int getSmallest();
        //int getLargest();
        int removeSmallest();
        int removeLargest();
        bool isEmpty();
        bool isFull();

    private:
        int *arr;
        int maxSize;
        int top;
};

#endif // PQUEUE_H
