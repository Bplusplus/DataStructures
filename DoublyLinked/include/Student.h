
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class	Student{
    private:
    std::string	name;
    int	age;

    public:
    Student(){name="";age=0;}
    Student(std::string n,int a){name =	n; age = a;}
    ~Student(){}
    void setName(std::string n){name = n;}
    std::string	getName	()	{return	name;}
    void setAge(int	a){age = a;}
    int	getAge(){return	age;}
};
#endif // STUDENT_H

