#include "StringTree.h"
#include "StringNode.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

StringTree::StringTree(){root=nullptr;}

StringTree::~StringTree()

{

    //dtor

}


bool StringTree::insert(string n)
{
    if(root ==nullptr)
    {
        root = new StringNode(n);
        return true;
    }
    StringNode * current =root;
    StringNode * parent;
    while (true)
    {
        string data = current->getData();
        if(n<data)
        {
            parent=current;
            current = current->getLeft();
            if(current==nullptr)
            {
                parent->setLeft(new StringNode(n));
                return true;
            }
        }
        if(n>data)
        {

            parent=current;
            current= current->getRight();
            if(current==nullptr)
            {
                parent->setRight(new StringNode(n));
                return true;
            }
        }
        if(n==data)
        return false;



    }
}


bool StringTree::find(string n)
{

    StringNode * current =root;

    while (current !=nullptr)
    {
        string data = current->getData();
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


StringNode * StringTree::findNode(string n)
{

    StringNode * current =root;

    while (current !=nullptr)
    {
        string data = current->getData();
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

StringNode * StringTree::findSuccessor(StringNode * target)
{
    StringNode * parent = target;
    StringNode * successor = target;
    StringNode * curr = target->getRight();

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


bool StringTree::removeKey(string k)
{
     if(root==nullptr)
    {
        return false;
    }

    StringNode * current = root;
    StringNode * parent =root;
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
        StringNode * successor = findSuccessor(current);
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

void StringTree::inOrderPrint()
{
  recInOrderPrint(root);
}

void StringTree::recInOrderPrint(StringNode * start)
{
    if(start==nullptr)
        return;
    recInOrderPrint(start->getLeft());
    cout<<start->getData()<<' ';
    recInOrderPrint(start->getRight());

}

void StringTree::PreOrderPrint()
{
  recPreOrderPrint(root);
}

void StringTree::recPreOrderPrint(StringNode * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPreOrderPrint(start->getLeft());
    recPreOrderPrint(start->getRight());

}

void StringTree::PostOrderPrint()
{
  recPostOrderPrint(root);
}

void StringTree::recPostOrderPrint(StringNode * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPostOrderPrint(start->getRight());
    recPostOrderPrint(start->getLeft());


}
