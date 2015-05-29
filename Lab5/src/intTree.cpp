#include "intTree.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

intTree::intTree(){root=nullptr;}

intTree::~intTree()

{

    //dtor

}


bool intTree::insert(int n)
{
    if(root ==nullptr)
    {
        root = new intNode(n);
        return true;
    }
    intNode * current =root;
    intNode * parent;
    while (true)
    {
        int data = current->getData();
        if(n<data)
        {
            parent=current;
            current = current->getLeft();
            if(current==nullptr)
            {
                parent->setLeft(new intNode(n));
                return true;
            }
        }
        if(n>data)
        {

            parent=current;
            current= current->getRight();
            if(current==nullptr)
            {
                parent->setRight(new intNode(n));
                return true;
            }
        }
        if(n==data)
        {


            if(current->getStatus()==false)
            {
                current->flickSwitch();
                current->increase();
               // cout<<current->getAmount()<<endl;
                return true;
            }
            else
            {
                current->increase();
                return true;
            }

        }


    }
    return false;
}


bool intTree::find(int n)
{

    intNode * current =root;

    while (current !=nullptr)
    {
        int data = current->getData();

        if(n<data)
        {
            current = current->getLeft();
        }
        if(n>data)
        {
            current= current->getRight();
        }

        if(n==data && current->getStatus()==true && current->getAmount()>0)
            return true;
    }
    return false;
}


int intTree::findNext(int n)
{
    if(find(n))
        return n;
    else
    {
         intNode * current =root;
         intNode* parent=root;
         int curLargest=-1;

        while (current !=nullptr )
        {
            int data = current->getData();
            if(n < data)
            {
                if(current->getStatus())
                    curLargest=data;
                parent=current;
                current = current->getLeft();

            }
            else if(n > data)
            {

                parent=current;
                current= current->getRight();
            }
        }

        if(parent->getData()>n && parent->getStatus())
            return(parent->getData());
        else if(curLargest!=-1)
            return curLargest;
        else return(-1);
    }


}

int intTree::removeNext(int n)
{
    int num=findNext(n);
   // cout<<"I'm removing "<<num<<endl;
    if(num!=-1)
        removeKey(num);
    return num;
}



intNode * intTree::findNode(int n)
{

    intNode * current =root;

    while (current !=nullptr)
    {
        int data = current->getData();
        if(n<data)
        {
            current = current->getLeft();
        }
        if(n>data)
        {
            current= current->getRight();
        }
        if(n==data)
        return current;
    }
    return nullptr;
}


bool intTree::removeKey(int k)
{
    if(!find(k))
    {
        return false;
    }
    else
    {
        intNode * target=findNode(k);
        target->reduce();
        if(target->getAmount()>0)
            return true;
        else
            {
                target->flickSwitch();
                return true;
            }

    }


}
void intTree::display(intNode * node)
{

    if(node->getStatus())
    {
        cout<<node->getData()<<' ';
    }
    else
    {
       cout<<' ';
    }
}

void intTree::inOrderPrint()
{
  recInOrderPrint(root);
}

void intTree::recInOrderPrint(intNode * start)
{
    if(start==nullptr)
        return;
    recInOrderPrint(start->getLeft());
    display(start);

    recInOrderPrint(start->getRight());

}
void intTree::PreOrderPrint()
{
  recPreOrderPrint(root);
}

void intTree::recPreOrderPrint(intNode * start)
{
    if(start==nullptr)
        return;
    display(start);
    recPreOrderPrint(start->getLeft());
    recPreOrderPrint(start->getRight());

}
void intTree::PostOrderPrint()
{
  recPostOrderPrint(root);
}

void intTree::recPostOrderPrint(intNode * start)
{
    if(start==nullptr)
        return;
    display(start);
    recInOrderPrint(start->getRight());
    recPostOrderPrint(start->getLeft());

}
