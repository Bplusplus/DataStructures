#include "PQueue.h"

PQueue::PQueue()
{
    arr = new int[20];
    maxSize=20;
    top=0;
    //ctor
}

PQueue::PQueue(int n)
{
    arr = new int[n];
    maxSize=n;
    top=0;
    //ctor
}

PQueue::~PQueue()
{
    //dtor
}

void PQueue::addValue(int n)
{
    if(!isFull())
        {
            arr[top++] =n;
        }
}

int PQueue::removeSmallest()
{
   int small=arr[0];
   int i=0;
   int bk=0;
   if(!isEmpty())
    {
        for(int i=0;i<top;i++)
        {
            if(small>arr[i])
            {
                small=arr[i];
                bk=i+1;
            }

            i++;
        }

        for(int j=bk;j<top;j++)
        {
            arr[j]=arr[j-1];
        }

        top--;
        return small;
   }
    else return-1;
}

int PQueue::removeLargest()
{
   int large=arr[0];
   int i=0;
   int bk=0;
   if(!isEmpty())
    {
        for(int i=0;i<top;i++)
        {

            if(large<arr[i])
            {
                large=arr[i];
                bk=i+1;
            }

            i++;
        }

        for(int j=bk;j<top;j++)
        {
            arr[j]=arr[j-1];
        }
    top--;
    return large;
   }
    else return-1;
}

/*
int PQueue::getSmallest()
{
   int i=top-1;
    while(int arr[i-1]<arr[i])
    {

    }
}

void PQueue::getLargest()
{

}
*/
bool PQueue::isEmpty()
{
    if(top==0)
        return true;
    else
        return false;
}
bool PQueue::isFull()
{
    if(top==maxSize)
        return true;
    else return false;
}
