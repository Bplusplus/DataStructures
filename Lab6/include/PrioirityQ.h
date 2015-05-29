#ifndef PRIOIRITYQ_H
#define PRIOIRITYQ_H
#include "Heap.h"

class PrioirityQ
{
    public:
        PrioirityQ(){}
        virtual ~PrioirityQ(){}
        void insert(int val){theHeap.insert(val);}
        int remove()
        {
            if(theHeap.isEmpty())
                return(-1);
            else
                 return(theHeap.remove());
        }
        int peek()
        {
            if(theHeap.isEmpty())
                return(-1);
            else
            {
               int temp = theHeap.remove();
               theHeap.insert(temp);
               return(temp);
            }
        }
        bool isEmpty()
        {
            if(theHeap.isEmpty())
                return false;
            else return true;
        }

    private:
        Heap theHeap;
};

#endif // PRIOIRITYQ_H
