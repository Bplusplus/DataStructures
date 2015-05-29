#include "HashTableLL.h"
using std::cout;
using std::endl;
HashTableLL::HashTableLL()
{
    arraySize=33;
    HashArray = new Node * [arraySize];
    nonItem = new Node("_");
    for ( int i = 0; i < arraySize; i++ )
                HashArray[i] =nullptr;
}

HashTableLL::HashTableLL(int n)
{
    arraySize=n;
    numItems=0;
    HashArray = new Node * [arraySize];
    nonItem = new Node("_");

    for ( int i = 0; i < arraySize; i++ )
                HashArray[i] =nullptr;
}

HashTableLL::~HashTableLL()
{
    delete HashArray;
}

int HashTableLL::hashStr(string key)
{
    int hashVal = 0;
    for(int j=0; j<key.length(); j++) // left to right
    {
        int letter = key.at(j) - 96; // get char code
        hashVal = (hashVal * 27 + letter) % arraySize; // mod
    }
    return hashVal;
}

void HashTableLL::displayTable()
{
    cout<<("Table: ");
    Node * current=nullptr;
    for(int j=0; j<arraySize; j++)
    {
        current=HashArray[j];
        while(current!=nullptr)
            {
                if(current!=nonItem)
                        cout<<(current->getKey() + ' ');
                    else
                        cout<<("** ");
                    current=current->getNext();
            }
        cout<<endl;
    }
    cout<<' ';
}

void  HashTableLL::insert(Node * item) // insert a string
                                    // (assumes table not full)
{

    string key =item->getKey();
    int hashVal = hashStr(key); // hash the key
    Node * current = HashArray[hashVal];
    if(HashArray[hashVal]==nullptr)
        HashArray[hashVal] = item; // insert item
    else
    {
    while(current->getNext()!=nullptr && current->getNext()!=nonItem)
            current=current->getNext();
    current->setNext(item);
    }

    numItems++;
} // end insert()

Node * HashTableLL::find(string key) // find item with key
{
    int hashVal = hashStr(key); // hash the key
    Node * current = HashArray[hashVal];

    if(current->getKey() == key)
        return current; // yes, return item
   else
    {
        while(current->getNext()!=nullptr)
        {
            if(current->getKey()==key)
                return current;
            current=current->getNext();
        }
    }
return nullptr;
}

Node * HashTableLL::remove(string key) // find item with key
{
    int hashVal = hashStr(key); // hash the key
     Node * current = HashArray[hashVal];
     Node * prev = current;
        while(current->getNext()!=nullptr)
        {
            if(current->getKey()==key)
            {
                Node * temp = current; // save item
                Node * next =current->getNext();
                current = nonItem;      // remove item
                prev->setNext(nonItem);
                nonItem->setNext(next);
                numItems--;            // decrement count
                return temp;           // return item
            }
            prev=current;
            current=current->getNext();
        }

return nullptr;
}
