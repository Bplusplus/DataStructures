#ifndef NODE_H
#define NODE_H


class Node

{

    public:

        Node(int n)
        {
            iData=n;
            left=nullptr;
            right=nullptr;
        }

        ~Node(){}


        Node * getLeft(){return left;}

        Node * getRight(){return right;}

        void setLeft(Node *l){left =l;}
        void setRight(Node *r){right =r;}

        int getData(){return iData;}

    private:
        int iData;
        Node *left;
        Node *right;

};

#endif // NODE_H
