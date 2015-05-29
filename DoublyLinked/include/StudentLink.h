#ifndef STUDENTLINK_H
#define STUDENTLINK_H

#include "Student.h"
class StudentLink
{
    public:
        StudentLink(Student * v){value =v; next=nullptr;}
        ~StudentLink(){}
        void setNext(StudentLink * n){next =n;}
        StudentLink * getNext(){return next;}
        Student * getValue(){return value;}

    private:
        Student * value;
        StudentLink * next;
};

#endif // STUDENTLINK_H
