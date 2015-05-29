 #include "HashTable.h"
using std::cout;
using std::endl;
HashTable::HashTable()
{
    arraySize=33;
    HashArray = new Node * [arraySize];
    nonItem = new Node("_");
    for ( int i = 0; i < arraySize; i++ )
                HashArray[i] =nullptr;
}

HashTable::HashTable(int n)
{
    arraySize=n;
    numItems=0;
    HashArray = new Node * [arraySize];
    nonItem = new Node("_");

    for ( int i = 0; i < arraySize; i++ )
                HashArray[i] =nullptr;
}

HashTable::~HashTable()
{
    delete HashArray;
}

int HashTable::hashStr(string key)
{
    int hashVal = 0;
    for(int j=0; j<key.length(); j++) // left to right
    {
        int letter = key.at(j) - 96; // get char code
        hashVal = (hashVal * 27 + letter) % arraySize; // mod
    }
    return hashVal;
}

void HashTable::displayTable()
{
    cout<<("Table: ");
    for(int j=0; j<arraySize; j++)
    {
        if(HashArray[j]!=nullptr)
            cout<<(HashArray[j]->getKey() + ' ');
        else
            cout<<("** ");
    }
    cout<<' ';
}

void  HashTable::insert(Node * item) // insert a string
                                    // (assumes table not full)
{
    if(numItems ==arraySize -1)
    {
        cout<<"array is full, can not insert!"<<endl;
        return;
    }
    string key =item->getKey();
    int hashVal = hashStr(key); // hash the key
                                // until empty cell or -1,
    while(HashArray[hashVal] != nullptr && HashArray[hashVal]!= nonItem)
    {
        ++hashVal; // go to next cell
        hashVal %= arraySize; // wraparound if necessary
    }
    HashArray[hashVal] = item; // insert item
    numItems++;
} // end insert()

Node * HashTable::find(string key) // find item with key
{
    int hashVal = hashStr(key); // hash the key
    while(HashArray[hashVal]!=nullptr) // until empty cell,
    { // found the key?
    if(HashArray[hashVal]->getKey() == key)
        return HashArray[hashVal]; // yes, return item
    ++hashVal; // go to next cell
    hashVal %= arraySize; // wraparound if necessary
    }
return nullptr;
}

Node * HashTable::remove(string key) // find item with key
{
    int hashVal = hashStr(key); // hash the key
    while(HashArray[hashVal]!=nullptr) // until empty cell,
    { // found the key?
    if(HashArray[hashVal]->getKey() == key)
        {
            Node * temp = HashArray[hashVal]; // save item
            HashArray[hashVal] = nonItem;       // remove item
            numItems--;                         // decrement count
            return temp;                        // return item
        }
    ++hashVal; // go to next cell
    hashVal %= arraySize; // wraparound if necessary
    }
return nullptr;
}
