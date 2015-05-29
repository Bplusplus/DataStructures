#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;


class Node
{

    public:
        Node(){iData ="_";next=nullptr;}
        Node(string ii){iData = ii; next=nullptr;}
        string getKey(){ return iData; }

        Node * getNext(){return next;}
        void setNext(Node * target){next =target;}
    private:
        string iData;
        Node * next;

};

#endif // NODE_H
