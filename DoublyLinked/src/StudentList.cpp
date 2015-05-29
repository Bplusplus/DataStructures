#include <iostream>
#include <iomanip>
#include <sstream>

#include "StudentList.h"

StudentList::~StudentList()
{
    //dtor
}

void StudentList::addHead(Student * v)
{
      if(head==nullptr)
        head=tail=new StudentLink(v);
    else
    {
        StudentLink * pointer = new StudentLink(v);
        pointer ->setNext(head);
        head = pointer;
    }

}

std::string StudentList::removeHead()
{
    if(isEmpty())
       {
        throw "List empty";
       }
    StudentLink * ptr = head;
    std::string name = head->getValue()->getName();
    if(head->getNext()!=nullptr)
        head=head->getNext();
    if(tail==ptr)
        tail=nullptr;
    delete ptr;
    return name;
}

void StudentList::addTail(Student * v)
{
    if(head==nullptr)
        head=tail=new StudentLink(v);
    else
    {
        StudentLink * pointer = new StudentLink(v);
        tail->setNext(pointer);
        tail = pointer;
    }
}

 bool StudentList::isEmpty()
 {
     if(head==tail && tail==nullptr)
        return true;
     else return false;
}

std::string StudentList::findKey(std::string name)
{
    bool wrap = false;
    StudentLink * ptr;
    while(getIterator()!=nullptr)
    {
        /* if we find the key return true, else step until we reach nullptr
        no need to set i, the step through code has already done so
        and no special cases needed because we aren't removing anything*/
    if(getIterator()->getValue()->getName()==name)
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
        if(ptr->getValue()->getName()==name)
        {
            setIterator(ptr);
            return getIterator()->getValue()->getName();
        }
        else
            ptr=ptr->getNext();
    }
    return "No student of that name exists!";
    }

}


std::string StudentList::displayList()
{
    std::string output = "";
    int lineCount = 0;
    StudentLink * ptr = head;
    while(ptr!=nullptr)
    {
        std::stringstream outString;
        outString << std::setw(2) << ptr->getValue()->getName() << std::setw(2) << ptr->getValue()->getAge();
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



