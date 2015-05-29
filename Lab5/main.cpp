#include <iostream>
#include <fstream>
#include <string>

#include "intTree.h"
#include "charTree.h"
#include "StringTree.h"
#include "Tree.h"


using namespace std;

int main()
{
/*
    Tree MadTree;

    MadTree.insert(24);
    MadTree.insert(12);
    MadTree.insert(13);
    MadTree.insert(100);
    MadTree.insert(52);
    MadTree.insert(121);
    MadTree.insert(6);
    MadTree.inOrderPrint();
    cout<<endl;
    MadTree.PreOrderPrint();
    cout<<endl;
    MadTree.PostOrderPrint();
    cout<<endl;
    MadTree.removeKey(100);
    cout<<endl;
    MadTree.inOrderPrint();
    cout<<endl;
    MadTree.PreOrderPrint();
    cout<<endl;
    MadTree.PostOrderPrint();
    cout<<endl;
    cout<<endl;
*/

    intTree HappyTree;
    HappyTree.insert(50);
    HappyTree.insert(25);
    HappyTree.insert(75);
    HappyTree.insert(30);
    HappyTree.insert(20);
    HappyTree.insert(60);
     HappyTree.insert(64);
    HappyTree.insert(80);
    HappyTree.inOrderPrint();
    cout<<endl;
    HappyTree.PreOrderPrint();
    cout<<endl;
    HappyTree.PostOrderPrint();
    cout<<endl;
    cout<<HappyTree.findNext(50)<<endl;
    cout<<HappyTree.findNext(31)<<endl;
    cout<<HappyTree.findNext(59)<<endl;
    cout<<HappyTree.findNext(74)<<endl;
    cout<<HappyTree.findNext(100)<<endl;



    cout<<endl;
/*
    cout<<"StringTree testing starts now"<<endl;

    StringTree SadTree;

    SadTree.insert("middle");
    SadTree.insert("grape");
    SadTree.insert("apple");
    SadTree.insert("house");
    SadTree.insert("pine");
    SadTree.insert("tree");
    SadTree.insert("never");
    SadTree.inOrderPrint();
    cout<<endl;
    SadTree.PreOrderPrint();
    cout<<endl;
    SadTree.PostOrderPrint();
    cout<<endl;
    SadTree.removeKey("middle");
    SadTree.inOrderPrint();


    charTree GladTree;

    cout<<endl;

    GladTree.insert('a');
    GladTree.insert('b');
    GladTree.insert('c');
    GladTree.insert('z');
    GladTree.insert('y');
    GladTree.insert('x');
    GladTree.insert('w');
    GladTree.inOrderPrint();
    cout<<endl;
    GladTree.PreOrderPrint();
    cout<<endl;
    GladTree.PostOrderPrint();
    cout<<endl;
    GladTree.removeKey('c');
    GladTree.inOrderPrint();
*/

cout<<endl<<"Dwarf test starts bellow"<<endl;
    intTree DwarfTree;

// open the file for reading
	ifstream myfile ("/Users/gibari/Desktop/School/DataStructures/Lab5/diamond_input.txt", ios::in);

		// if was not able to open, go away
	if (!myfile.is_open())
	{
		cout << "Unable to open file";
		return 1;
	}

	int numDiamonds;
	int numTaxes;
	int * diamonds;
	int * taxes;
	bool done = false;
	bool paid =true;

	while (!done )
	{
			// get the number of diamonds
			// if -1 done with input
		myfile >> numDiamonds;
		if ( numDiamonds == -1 )
		{
			done = true;
			break;
		}

			// allocate space to save diamonds
			// and get them
		diamonds = new int[numDiamonds];
		for ( int i = 0; i < numDiamonds; i++ )
		{
			myfile >> diamonds[i];
		}
        for ( int i = 0; i < numDiamonds; i++ )
		{
		    cout<<diamonds[i]<<endl;
			DwarfTree.insert(diamonds[i]);
		}
			// get the number of taxes
		myfile >> numTaxes;

			// allocate space to save taxes
			// and get them
		taxes = new int[numTaxes];
		for( int i = 0; i < numTaxes; i++ )
		{
			myfile >> taxes[i];
		}

        for(int i=0;i<numTaxes;i++)
        {
            if(DwarfTree.findNext(taxes[i])==-1)
            {
                paid=false;
            }
            cout<<DwarfTree.removeNext(taxes[i])<<endl;
        }
        if(paid) cout<<"PASS"<<endl;

        else cout<<"FAIL"<<endl;

        paid=true;
			// show what we got
		cout << " There were " << numDiamonds << " diamonds read: ";
		for ( int i = 0; i < numDiamonds; i++ )
		{
			cout << diamonds[i] << " ";
		}
		cout << endl;
		cout << " There were " << numTaxes << " taxes read: ";
		for ( int i = 0; i < numTaxes; i++ )
		{
			cout << taxes[i] << " ";
		}
		cout << endl << endl;

			// delete allocated space
		delete [] diamonds;
		delete [] taxes;

	}

	cout << "Done with file \n";


		// close the file before quitting
	myfile.close();







    return 0;
}
