#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include "Link.h"

class DoublyList
{
    public:
        DoublyList(){head = tail = nullptr;}
        ~DoublyList();
        void addHead(char v);
        void addTail(char v);
        char deleteHead();
        char deleteTail();
        bool deleteFind(char v);
        bool isEmpty();
        bool findKey(char key);
        bool insertKey(char key);
        bool deleteKey();
        bool appendList(DoublyList * front,DoublyList * end );
        std::string displayList();

        Link * getTail(){return tail;}
        Link * getHead(){return head;}

        void setIterator(Link * iter){i=iter;}
        Link * getIterator(){return i;}
    private:
        Link * head;
        Link * tail;
        Link * i=nullptr;
};

#endif // DOUBLYLIST_H
