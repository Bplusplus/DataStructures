#include <iostream>
#include <iomanip>
#include <sstream>

#include "DoublyList.h"
#include "Link.h"


DoublyList::~DoublyList()
{
    //dtor
}

void DoublyList::addHead(char v)
{
    if(head==nullptr)
        head=tail=new Link(v,nullptr,nullptr);
    else
    {
        Link * pointer = new Link(v,nullptr,nullptr);
        pointer ->setNext(head);
        head->setPrev(pointer);
        head = pointer;
    }
}

char DoublyList::deleteHead()
{
    if(isEmpty())
       {
        throw "List empty";
       }
    Link * ptr = head;
    char value = head->getValue();
    if(head->getNext()!=nullptr)
        head->getNext()->setPrev(nullptr);
    head=head->getNext();
    if(tail==ptr)
        tail=nullptr;
    delete ptr;
    return value;
}

void DoublyList::addTail(char v)
{
    if(head==nullptr)
        head=tail=new Link(v,nullptr,nullptr);
    else
    {
        Link * pointer = new Link(v,nullptr,nullptr);
        pointer ->setPrev(tail);
        tail->setNext(pointer);
        tail = pointer;
    }
}
char DoublyList::deleteTail()
{
    if(isEmpty())
        {
        // throw "List empty";
        }
    Link * ptr = tail;
    char value = tail->getValue();
    if(head->getPrev()!=nullptr)
        tail->getPrev()->setNext(nullptr);
    tail=tail->getPrev();
    if(head==ptr)
        head=nullptr;
    delete ptr;
    return value;
}

bool DoublyList::deleteFind(char v)
{
    Link * ptr = head;
    while(ptr!=nullptr)

    {
        if(ptr->getValue()==v)
        {
            if(ptr==head)
            {
                deleteHead();
                return true;
            }
            if(ptr==tail)
            {
                deleteTail();
                return true;
            }
            ptr->getNext()->setPrev(ptr->getPrev());
            ptr->getPrev()->setNext(ptr->getNext());
            delete ptr;
            return true;
        }
    ptr=ptr->getNext();
    }
    return false;
}

 bool DoublyList::isEmpty()
 {
     if(head==tail && tail==nullptr)
        return true;
     else return false;
}

bool DoublyList::findKey(char key)
{
    bool wrap = false;
    Link * ptr;
    while(getIterator()!=nullptr)
    {
        /* if we find the key return true, else step until we reach nullptr
        no need to set i, the step through code has already done so
        and no special cases needed because we aren't removing anything*/
        if(getIterator()->getValue()==key)
        {
            wrap=true;
            ptr = getIterator()->getNext();
        }
        else
            ptr=head;
        while(ptr!=nullptr || wrap)
            if(ptr==nullptr)
            {
                wrap=false;
                ptr=head;
            }
        else
        {
            if(ptr->getValue()==key)
            {
                setIterator(ptr);
                return true;
            }
        else
            ptr=ptr->getNext();
        }
    }
    return false;

}

bool DoublyList::insertKey(char key)
{

    if(getIterator()==head)
    {
        addHead(key);
        return true;
    }
    else if(getIterator()==tail)
    {
        addTail(key);
        return true;

    }
    else if(getIterator()==nullptr)
    {
        return false;
    }
    else
    {
        Link * ptr = new Link(key,(getIterator()->getPrev()),(getIterator()->getNext()));
        ptr->getNext()->setPrev(ptr);
        ptr->getPrev()->setNext(ptr);
        return true;
    }
}
bool DoublyList::deleteKey()
{

    if(getIterator()==head)
    {
        setIterator(nullptr);
        deleteHead();
        return true;
    }
    else if(getIterator()==tail)
    {
        setIterator(nullptr);
        deleteTail();
        return true;

    }
    else if(getIterator()==nullptr)
    {
        return false;
    }
    else
    {
        Link * ptr = getIterator();
        ptr->getNext()->setPrev(ptr->getPrev());
        ptr->getPrev()->setNext(ptr->getNext());
        delete ptr;
        setIterator(nullptr);
        return true;
    }
}

bool DoublyList::appendList(DoublyList * front,DoublyList * end )
{
    if(front==end && front==nullptr)
        return false;
    Link * endPtr = end->getHead();
    while(endPtr!=nullptr)
    {
        front->addTail(end->deleteHead());
    }
    return true;
}

std::string DoublyList::displayList()
{
    std::string output = "";
    int lineCount = 0;
    Link * ptr = head;
    while(ptr!=nullptr)
    {
        std::stringstream outString;
        outString << std::setw(6) << ptr->getValue();
        output += outString.str();
        lineCount++;
        if ( lineCount >= 10 )
        {
            lineCount = 0;
            output += "\n";
        }
        ptr=ptr->getNext();
    }
    output += "\n";
    return output;

}

