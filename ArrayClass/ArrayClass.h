#ifndef ARRAYCLASS_H_INCLUDED
#define ARRAYCLASS_H_INCLUDED

#include <iostream>
#include <string>
#include <exception>


class ArrayClass
{
public:
    ArrayClass();
    ArrayClass(int n);
    ~ArrayClass();

    void start();

    bool addElem(int n);
    bool delElem();
    int howMany();
    void curElems();
    void delDups();

    char getInput() const{ return input;};
    void setInput(char c){input=c;};
    int getArrayS() const{ return arrayS;};
    void setArrayS(int n){arrayS=n;};
    int getLargest() const {return largest;};
    void setLargest(int n){largest=n;};

private:
    char input;
    int arrayS=0;
    int* elements;
    int bookmark=0;
    int largest=0;
    };



#endif // ARRAYCLASS_H_INCLUDED
