#ifndef INTNODE_H
#define INTNODE_H


class intNode
{
    public:

        intNode(int n)
        {
            iData=n;
            left=nullptr;
            right=nullptr;
            isActive=true;
            numElems=1;
        }

        ~intNode(){}


        intNode * getLeft(){return left;}

        intNode * getRight(){return right;}

        void setLeft(intNode *l){left =l;}
        void setRight(intNode *r){right =r;}
        void flickSwitch(){isActive=!isActive;}
        bool getStatus(){return isActive;}
        int getData(){return iData;}
        int getAmount(){return numElems;}
        void reduce(){numElems= --numElems;}
        void increase(){numElems= ++numElems;}


    private:
        int iData;
        intNode *left;
        intNode *right;
        bool isActive;
        int numElems;
};

#endif // INTNODE_H
