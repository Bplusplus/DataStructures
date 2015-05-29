#include <iostream>
#include "Heap.h"
using namespace std;
Heap::Heap()
{
    curSize=0;
    //ctor
}

Heap::~Heap()
{
    //dtor
}

bool Heap::insert(int n)
{
    if(curSize==maxSize)
        return false;
    heap[curSize++]=n;
    trickleUp();
    return true;
}
int Heap::remove()
{
    int retVal = heap[0];
    heap[0]= heap[--curSize];
    trickleDown();
    return retVal;
}

void Heap::trickleUp()
{

    int curIndex=curSize-1;
    int parent = (curIndex-1)/2;
    while(curIndex > 0 && heap[parent] > heap[curIndex])
    {
        int temp = heap[curIndex];
        heap[curIndex]=heap[parent];
        heap[parent]=temp;
        curIndex=parent;
        parent=(curIndex-1)/2;
    }
}

void Heap::trickleDown()
{
    int curIndex =0;
    int leftChild = curIndex * 2 +1;
    int rightChild = leftChild + 1;

    int largestChild;
    while(leftChild<curSize)
    {


        if(rightChild >= curSize || heap[leftChild] < heap[rightChild])
            largestChild= leftChild;
        else
            largestChild=rightChild;
        if(heap[largestChild] < heap[curIndex])
        {
            int temp = heap[curIndex];
            heap[curIndex] =heap[largestChild];
            heap[largestChild] = temp;

            curIndex =largestChild;
            leftChild = curIndex * 2 +1;
            rightChild = leftChild + 1;
        }
        else
            break;
        }
}
bool Heap::isEmpty()
{
    if(curSize==0)
        return true;
    else return false;

}
