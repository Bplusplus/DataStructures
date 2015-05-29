#include "charTree.h"
#include <iostream>

using std::cout;
using std::endl;


charTree::charTree(){root=nullptr;}

charTree::~charTree()

{

    //dtor

}


bool charTree::insert(char n)
{
    if(root ==nullptr)
    {
        root = new charNode(n);
        return true;
    }
    charNode * current =root;
    charNode * parent;
    while (true)
    {
        char data = current->getData();
        if(n<data)
        {
            parent=current;
            current = current->getLeft();
            if(current==nullptr)
            {
                parent->setLeft(new charNode(n));
                return true;
            }
        }
        if(n>data)
        {

            parent=current;
            current= current->getRight();
            if(current==nullptr)
            {
                parent->setRight(new charNode(n));
                return true;
            }
        }
        if(n==data)
        return false;



    }
}


bool charTree::find(char n)
{

    charNode * current =root;

    while (current !=nullptr)
    {
        char data = current->getData();
        if(n<data)
        {
            current = current->getLeft();
        }
        if(n>data)
        {
            current= current->getRight();
        }
        if(n==data)
        return true;
    }
    return false;
}


charNode * charTree::findcharNode(char n)
{

    charNode * current =root;

    while (current !=nullptr)
    {
        char data = current->getData();
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


charNode * charTree::findSuccessor(charNode * target)
{
    charNode * parent = target;
    charNode * successor = target;
    charNode * curr = target->getRight();

    while(curr!=nullptr)
    {
        parent=successor;
        successor =curr;
        curr = curr->getLeft();
    }
    if(successor != target->getRight())
    {
        parent->setLeft(successor->getRight());
        successor->setRight(target->getRight());
    }
    return(successor);
}


bool charTree::removeKey(char k)
{
    if(root==nullptr)
    {
        return false;
    }

    charNode * current = root;
    charNode * parent =root;
    bool isLeft = true;

    while(current->getData()!=k)
    {
        parent=current;
        if(k<current->getData())
        {
            isLeft = true;
            current =current->getLeft();
        }
        else
        {
            isLeft=false;
            current=current->getRight();
        }
        if(current==nullptr)
            return false;
    }
    if(current->getLeft()==nullptr && current->getRight()==nullptr) // Case1 noDe is a leaf
    {
        if(current==root)
            root=nullptr;
        else if(isLeft)                                            //Pop of the leaf if it's on the left
        {
            parent->setLeft(nullptr);
        }
        else                                                        //Pop of the leaf if it's on the right
        {
            parent->setRight(nullptr);
        }
    }
    else if(current->getLeft()!=nullptr && current->getRight()!=nullptr) // Case2 node has two children
    {
        charNode * successor = findSuccessor(current);
        if(current==root)
            root=successor;
        else if(isLeft)
            parent->setLeft(successor);
        else
            parent->setRight(successor);
        successor->setLeft(current->getLeft());
    }
    else                                                                // Case3 node has one child
    {
        if(current->getRight()==nullptr) //if no right child replace with left subtree
        {
            if(current==root)
            {
                root=current->getLeft();
            }
            else if(isLeft)
            {
                parent->setLeft(current->getLeft());                        //Rescue the child, Give it to the grandparents

            }
            else
            {
                parent->setRight(current->getLeft());                       //Rescue the child, Give it to the grandparents
            }
        }
        if(current->getLeft()==nullptr) //if no left child replace with right subtree
        {
            if(current==root)
            {
                root=current->getRight();
            }
            else if(isLeft)
            {
                parent->setLeft(current->getRight());                        //Rescue the child, Give it to the grandparents
            }
            else
            {
                parent->setRight(current->getRight());                       //Rescue the child, Give it to the grandparents
            }
        }
    }
    delete current;
    return true;
}

void charTree::inOrderPrint()
{
  recInOrderPrint(root);
}

void charTree::recInOrderPrint(charNode * start)
{
    if(start==nullptr)
        return;
    recInOrderPrint(start->getLeft());
    cout<<start->getData()<<' ';
    recInOrderPrint(start->getRight());

}

void charTree::PreOrderPrint()
{
  recPreOrderPrint(root);
}

void charTree::recPreOrderPrint(charNode * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPreOrderPrint(start->getLeft());
    recPreOrderPrint(start->getRight());

}

void charTree::PostOrderPrint()
{
  recPostOrderPrint(root);
}

void charTree::recPostOrderPrint(charNode * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPostOrderPrint(start->getRight());
    recPostOrderPrint(start->getLeft());

}
