#ifndef INTTREE_H
#define INTTREE_H
#include <string>
#include "intNode.h"

using std::string;
class intTree

{

    public:

        intTree();

        virtual ~intTree();
        bool insert(int n);
        bool find (int n);
        int findNext(int n);
        int removeNext(int n);
        intNode * findNode(int n);
        void display(intNode * node);
        void inOrderPrint();
        void PreOrderPrint();
        void PostOrderPrint();
        bool removeKey(int k);
        intNode * findSuccessor(intNode * target);
        intNode * findPredecessor(intNode * target);


    private:
        intNode *root;
        void recInOrderPrint(intNode *start);
        void recPreOrderPrint(intNode *start);
        void recPostOrderPrint(intNode *start);




};
#endif // INTTREE_H
