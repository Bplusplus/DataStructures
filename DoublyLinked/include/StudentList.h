#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"
#include "StudentLink.h"

class StudentList
{
    public:
        StudentList(){head = tail =nullptr;}
        ~StudentList();
        void addHead(Student * v);
        std::string removeHead();
        void addTail(Student * v);
        bool isEmpty();
        std::string findKey(std::string name);
        std::string displayList();


        void setIterator(StudentLink * iter){i=iter;}
        StudentLink * getIterator(){return i;}
      private:
          StudentLink * head;
          StudentLink * tail;
          StudentLink * i=nullptr;
};

#endif // STUDENTLIST_H
