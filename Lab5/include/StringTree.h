#ifndef STRINGTREE_H
#define STRINGTREE_H

#include <string>
#include "StringNode.h"
using std::string;

class StringTree

{

    public:

        StringTree();

        virtual ~StringTree();
        bool insert(string n);
        bool find (string n);
        StringNode * findNode(string n);
        void inOrderPrint();
        void PreOrderPrint();
        void PostOrderPrint();

        bool removeKey(string k);
        StringNode * findSuccessor(StringNode * target);
        StringNode * findPredecessor(StringNode * target);

    private:
        StringNode *root;
        void recInOrderPrint(StringNode *start);
        void recPostOrderPrint(StringNode *start);
        void recPreOrderPrint(StringNode *start);


};

#endif // STRINGTREE_H
