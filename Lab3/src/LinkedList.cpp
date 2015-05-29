#include "Link.h"
#include "LinkedList.h"

        // initialize pointer to head

LinkedList::LinkedList()

{
    head=nullptr;
}
        // delete any remaining Links

LinkedList::~LinkedList()

{

}
        // create new Link containing value v
        // and insert it at the head of the List
void LinkedList::addHead(char d)
{
    if(head==nullptr)
    {
        head= new Link(d,nullptr);
    }
    else
    {
        head= new Link(d,head);
    }
}


    // remove Link at head of List
    // return value it contains
char LinkedList::removeHead()
{
    if(head==nullptr)
    {
        return -1;
    }
    else
    {
        char temp = head->getData();
        Link * ptr=head;
        head = head ->getNext();
        delete ptr;
        return temp;
    }
}
