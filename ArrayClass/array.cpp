#include <cstring>
#include "ArrayClass.h"
using namespace std;

ArrayClass::ArrayClass() // creates an array of 100 elements.

{

	elements= new int[100];
	setArrayS(100);

}

ArrayClass::ArrayClass(int n) // creates an array of n elements.

{

	elements= new int[n];
	setArrayS(n);

}



ArrayClass::~ArrayClass()

{

}



bool ArrayClass::addElem(int n) // adds int n to the array in the next available spot, returns false if not possible.

{
    if(bookmark<=arrayS+1)
    {
    elements[bookmark]=n;
        if(n>=largest)
        {
            largest=n;

        }
    cout<<"This array has "<<arrayS - (bookmark+1)<<" spaces left."<<endl;

       if(bookmark==arrayS-1)
        {
        cout<<"This array is now full, please delete some elements before adding more"<<endl;
        return true;
        }

        else
        {
        bookmark++;
        return true;
        }
    }

    else
    {
    cout<<"This array is full so we cannot add any elements at this time, please delete some elements and try again"<<endl;
        return false;
    }

}



bool ArrayClass::delElem() // deletes the last added elements, returns false if array is empty.

{

    if(bookmark!=0)
        {
            bookmark--;
            return true;
        }
        else return false;
}



int ArrayClass::howMany() // returns the number of elements in the array.

{

	return bookmark;

}

void ArrayClass::curElems()
{
    int counter=0;
    for(int i=0; i < bookmark ;i++)
    {
        cout<<elements[i]<<' ';
        counter++;
        if(counter==10)
            {
            cout<<endl;
            counter=0;
            }

    }
}

void ArrayClass::delDups()
{
    for(int i=1;i<bookmark;i++)
    {
        bool dups=false;
        for (int j=0;(j < i) && (dups==false);j++)
       {
            if(elements[i]==elements[j]) dups=true;

            if(!dups) cout<<elements[i]<<' ';

       }
    }

}



