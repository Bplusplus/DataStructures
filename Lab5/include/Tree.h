#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree

{

    public:

        Tree();

        virtual ~Tree();
        bool insert(int n);
        bool find (int n);
        Node * findNode(int n);
        void inOrderPrint();
        void PreOrderPrint();
        void PostOrderPrint();
        bool removeKey(int k);
        Node * findSuccessor(Node * target);
        Node * findPredecessor(Node * target);

    private:
        Node *root;
        void recInOrderPrint(Node *start);
        void recPreOrderPrint(Node *start);
        void recPostOrderPrint(Node *start);

};

#endif // TREE_H
