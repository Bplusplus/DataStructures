#include <iostream>
#include <ctime>

#include "Heap.h"
#include "PrioirityQ.h"
#include "HashTable.h"
#include "HashTableLL.h"

using namespace std;

int main()
{
    Heap myHeap;
    srand(time(nullptr));
    int random[100];
    int counter=0;
    for(int i=0;i<50;i++)
        {
        random[i]=rand() % 1000;
        myHeap.insert(random[i]);
        }
    for(int i=0;i<50;i++)
        {
        cout<<myHeap.remove()<<' ';
        counter++;
        if(counter==9)
            {
                counter=0;
                cout<<endl;
            }
        }
        cout<<endl;
        cout<<endl;

cout<<"PriorityQ code starts here"<<endl;
        PrioirityQ Q;
        for(int i=0;i<50;i++)
        {
        random[i]=rand() % 100;
        Q.insert(random[i]);
        }
    for(int i=0;i<50;i++)
        {
        cout<<Q.remove()<<' ';
        counter++;
        if(counter==9)
            {
                counter=0;
                cout<<endl;
            }
        }
        cout<<endl;

        cout<<"HashTable Testing Begins here"<<endl;
/*
    Node * aNode;
    string aKey;
    int size, n, keysPerCell;
    bool done = false;
    char choice;
                                    // get sizes
    cout << "Enter size of hash table: ";
    cin >> size;

    keysPerCell = 10;
                                    // make table
    HashTable theHashTable(size);




    while( !done )                   // interact with user
    {
        cout << "Enter first letter of ";
        cout << "show, insert, remove, find, or quit: ";
        cin >> choice;
         switch(choice)
         {

            case 's':
                theHashTable.displayTable();
                break;

            case 'i':
                cout << "Enter key value to insert: ";
                cin >> aKey;
                aNode = new Node(aKey);
                theHashTable.insert(aNode);
                break;

            case 'r':
                cout << "Enter key value to remove: ";
                cin >> aKey;
                aNode = theHashTable.remove(aKey);
                if(aNode != nullptr)
                {
                    cout << "Found and removed " << aKey << endl;
                    delete aNode;
                }

                else
                    cout << "Could not find " << aKey << endl;

                break;

            case 'f':
                cout << "Enter key value to find: ";
                cin >> aKey;
                aNode = theHashTable.find(aKey);
                if(aNode != nullptr)
                    cout << "Found " << aKey << endl;
                else
                    cout << "Could not find " << aKey << endl;
                break;

            case 'q':
                done = true;
                break;
            default:
                cout << "Invalid entry\n";
        }  // end switch
    }  // end while
*/

    Node * aNode;
    string aKey;
    int size, n, keysPerCell;
    bool done = false;
    char choice;
                                    // get sizes
    cout << "Enter size of hash table: ";
    cin >> size;

    keysPerCell = 10;
                                    // make table
    HashTableLL theHashTable(size);




    while( !done )                   // interact with user
    {
        cout << "Enter first letter of ";
        cout << "show, insert, remove, find, or quit: ";
        cin >> choice;
         switch(choice)
         {

            case 's':
                theHashTable.displayTable();
                break;

            case 'i':
                cout << "Enter key value to insert: ";
                cin >> aKey;
                aNode = new Node(aKey);
                theHashTable.insert(aNode);
                break;

            case 'r':
                cout << "Enter key value to remove: ";
                cin >> aKey;
                aNode = theHashTable.remove(aKey);
                if(aNode != nullptr)
                {
                    cout << "Found and removed " << aKey << endl;
                    delete aNode;
                }

                else
                    cout << "Could not find " << aKey << endl;

                break;

            case 'f':
                cout << "Enter key value to find: ";
                cin >> aKey;
                aNode = theHashTable.find(aKey);
                if(aNode != nullptr)
                    cout << "Found " << aKey << endl;
                else
                    cout << "Could not find " << aKey << endl;
                break;

            case 'q':
                done = true;
                break;
            default:
                cout << "Invalid entry\n";
        }  // end switch
    }  // end while

    return 0;
}
