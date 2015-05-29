#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Link.h"

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void addHead(char d);
        char removeHead();
    private:
        Link * head;
};

#endif // LINKEDLIST_H
