#ifndef HASHTABLELL_H
#define HASHTABLELL_H
#include <iostream>
#include <string>
#include <stdio.h>
#include "Node.h"
using std::string;

class HashTableLL
{
    public:
        HashTableLL();
        HashTableLL(int n);
        ~HashTableLL();
        void insert(Node * item);
        int hashStr(string key);
        Node * remove(string key);
        Node * find(string key);
        void displayTable();


    private:
        const static int defaultSize=33;
        int arraySize;
        int numItems;
        Node ** HashArray;
        Node * nonItem;


};

#endif // HASHTABLELL_H
