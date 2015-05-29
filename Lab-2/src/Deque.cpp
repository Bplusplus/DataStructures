#include "Deque.h"
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;
Deque::Deque()  //default constructor, creates Deque of 100
{
    arr = new int[100];
	maxSize = 100;
	tail = 0;
	head = -1;
    //ctor
}
Deque::Deque(int n) //overloaded constructor, creates Deque of n-size
{
    arr= new int[n];
    maxSize=n;
    tail=-0;
    head=-1;
    //ctor
}


Deque::~Deque() //destructor
{
    //dtor
}

void Deque::addLeft(int n) //adds an int n to the head of the Deque, then moves the head
{
    if(isFull()) //checking before adding, if full display error message
    {
        std::cout<<"I'm sorry the deque is full.";
    }
     else if(head!=-1) //if we still have space,
        {
        arr[head--]=n; //add the element where head was, then decrement 'move left'
        }
     else //we are at the begining of the array
    {
        head=maxSize; //move head to the other end of the arrary,
        arr[head--]=n; //add the element where head was, then decrement/'move left'
    }

}


void Deque::addRight(int n) //adds an int n to the head of the Deque, then moves the tail
{
    if(isFull()) //checking before adding, if full display error message
    {
        std::cout<<"I'm sorry the deque is full.";
    }
    else if(tail!=maxSize) //if we still have space,
        {
        arr[tail++]=n; //add the element where tail was, then increment/'move right'
        }
    else    //we have hit the end of the array
    {
        tail=-1; //go back to the begining of the array
        arr[tail++]=n; //add the element where tail was, then increment/'move right'
    }
}

int Deque::getLeft()
{
    if (!isEmpty()) //checks if there is nothing in the Deque
        return arr[++head]; // increments head, then returns the value at head
    else
        return 0; //0 is false
}

int Deque::getRight()
{
     if (!isEmpty())    //checks if there is nothing in the Deque
        return arr[--tail]; // decrements tail, then returns the value at head
     else
        return 0; //0==false
}


bool Deque::isEmpty() //checks if there is nothing in the Deque
{
     if(tail==head+1) //If the tail is right in front of the head
            return true;
        else
            return false;
}

bool Deque::isFull() //checks if the Deque is full
{
     if( tail==head)
     {
        std::cout<<"I'm sorry the deque is full."<<std::endl;
        return true;
     }
    else if(head==-1 && tail==maxSize )
    {
        std::cout<<"I'm sorry the deque is full."<<std::endl;
        return true;
    }

    else return false;

}

string Deque::listRightLeft() //spits out the Deque from tail to head
{
        int temp1=head;
        int temp2=tail;

        string s=" ";
        while(temp2!=temp1+1)
        {
            cout<<arr[--temp2];
            s + SSTR(arr[temp2]) = s;
            s +' '=s;
            if(temp2==-1)
            {
                //if(temp2!=temp1+1)
                temp2=maxSize;
            }
        }
         return s;
}
string Deque::listLeftRight() //spits out the Deque from head to tail
{
    int temp1=head;
    int temp2=tail;
    string s= " ";
        while(temp1!=temp2-1)
        {
            cout<<arr[++temp1];
            s + SSTR(arr[temp1]) = s;
            s +' '=s;
            if (temp1==maxSize-1)
            {
                if(temp1!=temp2 -1)
                temp1=-2;
            }

        }
       return s;
}
