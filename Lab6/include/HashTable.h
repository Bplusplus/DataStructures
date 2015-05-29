#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <stdio.h>
#include "Node.h"
using std::string;

class HashTable
{
    public:
        HashTable();
        HashTable(int n);
        ~HashTable();
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

#endif // HASHTABLE_H
