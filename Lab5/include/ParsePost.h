#ifndef PARSEPOST_H
#define PARSEPOST_H
#include <iostream>
#include <string>
#include "StackX.h"
using std::cout;
using std::endl;
using std::string;
class ParsePost
{
    public:
        ParsePost(string s);
        ~ParsePost();
        int doParse();
    private:
        StackX theStack;
        string input;
};

#endif // PARSEPOST_H
