#ifndef CHARTREE_H
#define CHARTREE_H

#include "charNode.h"

class charTree

{

    public:

        charTree();

        virtual ~charTree();
        bool insert(char n);
        bool find (char n);
        charNode * findcharNode(char n);
        void inOrderPrint();
        void PreOrderPrint();
        void PostOrderPrint();
        bool removeKey(char k);
        charNode * findSuccessor(charNode * target);
        charNode * findPredecessor(charNode * target);

    private:
        charNode *root;
        void recInOrderPrint(charNode *start);
        void recPreOrderPrint(charNode *start);
        void recPostOrderPrint(charNode *start);

};

#endif // CHARTREE_H
