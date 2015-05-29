#ifndef STRINGNODE_H
#define STRINGNODE_H
#include <string>

using std::string;

class StringNode

{

    public:

        StringNode(string n)
        {
            iData=n;
            left=nullptr;
            right=nullptr;
        }

        ~StringNode(){}


        StringNode * getLeft(){return left;}

        StringNode * getRight(){return right;}

        void setLeft(StringNode *l){left =l;}
        void setRight(StringNode *r){right =r;}

        string getData(){return iData;}

    private:
        string iData;
        StringNode *left;
        StringNode *right;

};

#endif // STRINGNODE_H
