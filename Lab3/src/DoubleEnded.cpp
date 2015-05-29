#include "Link.h"
#include "DoubleEnded.h"
 // methods for double ended
// singly Linked List

// initialize pointers to head and tail

DoubleEnded::DoubleEnded()

{

    head = tail = nullptr;

}



    // delete any remaining Links

DoubleEnded::~DoubleEnded()

{

    Link * ptr = head;

    while ( ptr != nullptr )

    {

        Link * temp = ptr;

        ptr = ptr->getNext();

        delete temp;

    }

}



    // create new Link containing value v

    // and insert it at the head of the List

void DoubleEnded::addHead(char d)

{

    if ( head == nullptr )

        head = tail = new Link (d, nullptr);

    else

        head = new Link (d, head);

}



    // return true if the List contains

    // a Link with the value v

bool DoubleEnded::find(char d)

{

        // if nothing in list, go away

    if ( head == nullptr )

        return false;



        // otherwise walk down list searching

        // if find true, if reach end, false

    Link *ptr = head;



    while ( ptr != nullptr )

    {

        if ( ptr->getData() == d )

            return true;

        else

            ptr = ptr->getNext();

    }



    return false;

}



    // remove Link at head of List

    // return value it contains

char DoubleEnded::removeHead()

{

    if ( head == nullptr )

    {

        // List empty, do something intelligent

        throw "List empty!!";



    }



        // non-empty list, so remove it

    char temp = head->getData();

    Link * ptr = head;



    head = head->getNext();



        // if List now empty, reset

        // tail pointer

    if ( head == nullptr )

        tail = nullptr;



        // clean up and go home

    delete ptr;

    return temp;

}



    // Look for link containing v

    // if found, delete and return true

    // else return false

bool DoubleEnded::deleteItem(char d)

{

        // list empty, obviously not there

    if ( head == nullptr )

        return false;



        // in first Link,

        // properly update head

        // if single item, update tail also

    if ( head->getData() == d )

    {

        Link * temp = head;

        head = head->getNext();

        if ( head == nullptr )

            tail = nullptr;

        delete temp;

        return true;

    }



        // not in first, now walk the List

        // if removing last, update tail

    Link * ptr = head->getNext();

    Link * last = head;



    while ( ptr != nullptr )

    {

        if ( ptr->getData() == d )

        {

            last->setNext(ptr->getNext());

            if ( last->getNext() == nullptr )

                tail = last;

            delete ptr;

            return true;

        }

        last = ptr;

        ptr = ptr->getNext();

    }



    return false;

}



    // create new link containing value v

    // and insert at tail

    // special case empty list

void DoubleEnded::addTail(char d)

{

    if ( head == nullptr )

    {

        head = tail = new Link(d, nullptr);

        return;

    }



    Link * temp = new Link(d, nullptr);

    tail->setNext(temp);

    tail = temp;

    return;

}





