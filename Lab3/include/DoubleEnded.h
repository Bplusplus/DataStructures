#ifndef DOUBLEENDED_H
#define DOUBLEENDED_H

#include "link.h"
class DoubleEnded
{
    public:
        DoubleEnded();
        ~DoubleEnded();
        void addHead(char d);
        void addTail(char d);
        bool find(char d);
        char  removeHead();
        bool deleteItem(char d);
    private:
        Link * head;
        Link * tail;
};



#endif // DOUBLEENDED_H
