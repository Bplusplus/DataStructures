#ifndef CHARNODE_H
#define CHARNODE_H



class charNode

{

    public:

        charNode(char n)
        {
            iData=n;
            left=nullptr;
            right=nullptr;
        }

        ~charNode(){}


        charNode * getLeft(){return left;}

        charNode * getRight(){return right;}

        void setLeft(charNode *l){left =l;}
        void setRight(charNode *r){right =r;}

        char getData(){return iData;}

    private:
        char iData;
        charNode *left;
        charNode *right;

};


#endif // CHARNODE_H
