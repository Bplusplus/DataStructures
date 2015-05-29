#include "Tree.h"
#include <iostream>
using std::cout;
using std::endl;


Tree::Tree(){root=nullptr;}

Tree::~Tree()

{

    //dtor

}


bool Tree::insert(int n)
{
    if(root ==nullptr)
    {
        root = new Node(n);
        return true;
    }
    Node * current =root;
    Node * parent;
    while (true)
    {
        int data = current->getData();
        if(n<data)
        {
            parent=current;
            current = current->getLeft();
            if(current==nullptr)
            {
                parent->setLeft(new Node(n));
                return true;
            }
        }
        if(n>data)
        {

            parent=current;
            current= current->getRight();
            if(current==nullptr)
            {
                parent->setRight(new Node(n));
                return true;
            }
        }
        if(n==data)
        return false;



    }
}


bool Tree::find(int n)
{

    Node * current =root;

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
        return true;
    }
    return false;
}


Node * Tree::findNode(int n)
{

    Node * current =root;

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


Node * Tree::findSuccessor(Node * target)
{
    Node * parent = target;
    Node * successor = target;
    Node * curr = target->getRight();

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


bool Tree::removeKey(int k)
{
    if(root==nullptr)
    {
        return false;
    }

    Node * current = root;
    Node * parent =root;
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
        Node * successor = findSuccessor(current);
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

void Tree::inOrderPrint()
{
  recInOrderPrint(root);
}

void Tree::recInOrderPrint(Node * start)
{
    if(start==nullptr)
        return;
    recInOrderPrint(start->getLeft());
    cout<<start->getData()<<' ';
    recInOrderPrint(start->getRight());

}

void Tree::PreOrderPrint()
{
  recPreOrderPrint(root);
}

void Tree::recPreOrderPrint(Node * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPreOrderPrint(start->getLeft());
    recPreOrderPrint(start->getRight());

}

void Tree::PostOrderPrint()
{
  recPostOrderPrint(root);
}

void Tree::recPostOrderPrint(Node * start)
{
    if(start==nullptr)
        return;
    cout<<start->getData()<<' ';
    recPostOrderPrint(start->getRight());
    recPostOrderPrint(start->getLeft());

}
