#include <iostream>
#include <ctime>

#include "Deque.h"
#include "Stack.h"
#include "PQueue.h"




int main()
{
    srand(time(NULL));
    int counter=0;
    int random[100];
    int n =5;


    std::cout<<"---------Deque Tests start here------------------v"<<std::endl;

    Deque Q;
    for(int i=0;i<100;i++)
        {
        random[i]=rand() % 10;
        Q.addRight(random[i]);
        counter++;
        if(counter==10)
            {
                counter=0;
                std::cout<<std::endl;
            }

        }

        std::cout<<std::endl;
        std::cout<<"Default 100 Deque filled completely listed head to tail"<<std::endl;
        std::cout<<Q.listLeftRight()<<std::endl;
        std::cout<<"Default 100 Deque filled completely listed tail to head"<<std::endl;
        std::cout<<Q.listRightLeft()<<std::endl;

         std::cout<<"Now removing a random number of elements from the left"<<std::endl;
      for(int i=0;i<random[1];i++)
        {
        std::cout<<Q.getLeft()<<std::endl;
        }

        std::cout<<"How the deque looks now, listed tail to head"<<std::endl;
        std::cout<<Q.listRightLeft()<<std::endl;

        std::cout<<"How the deque looks now, listed head to tail"<<std::endl;
        std::cout<<Q.listLeftRight()<<std::endl;

        std::cout<<"Now removing a random number of elements from the right"<<std::endl;
      for(int i=0;i<random[99];i++)
        {
        std::cout<<Q.getRight()<<std::endl;
        }
        std::cout<<std::endl<<std::endl;

        std::cout<<"How the deque looks now, listed tail to head"<<std::endl;
        std::cout<<Q.listRightLeft()<<std::endl;

        std::cout<<"How the deque looks now, listed head to tail"<<std::endl;
        std::cout<<Q.listLeftRight()<<std::endl;

    Deque Q1(n);

    for(int i=0;i<6;i++)
        {
        Q1.addRight(random[i]);

        }

        std::cout<<std::endl<<std::endl<<std::endl;

        std::cout<<Q1.listLeftRight()<<std::endl;
        std::cout<<"Deque 6 filled completely listed head to tail"<<std::endl;
        std::cout<<Q1.listRightLeft()<<std::endl;
        std::cout<<"Deque 6 filled completely listed tail to head"<<std::endl;


        std::cout<<std::endl<<std::endl<<std::endl;

        std::cout<<Q1.getLeft()<<std::endl;
        std::cout<<Q1.getLeft()<<std::endl;

        std::cout<<"How the deque looks now, listed head to tail"<<std::endl<<Q1.listLeftRight()<<std::endl;
        std::cout<<"How the deque looks now, listed tail to head"<<std::endl<<Q1.listRightLeft()<<std::endl;

        std::cout<<"Adding 9 to the array on the right four times"<<std::endl;
        Q1.addRight(9);
        Q1.addRight(9);
        Q1.addRight(9);
        Q1.addRight(9);

        std::cout<<std::endl;

        std::cout<<"How the deque looks now, listed head to tail"<<std::endl<<Q1.listLeftRight()<<std::endl;
        std::cout<<"How the deque looks now, listed tail to head"<<std::endl<<Q1.listRightLeft()<<std::endl;

std::cout<<"v--------------Stack Tests start here------------------v"<<std::endl;


    Stack S1(n);

    for(int i=0;i<5;i++)
        {
        random[i]=rand() % 10;
        S1.push(random[i]);
        }
        std::cout<<S1.peek()<<std::endl;
    for(int i=0;i<3;i++)
        {
        std::cout<<S1.pop()<<std::endl;
        }
        std::cout<<S1.peek()<<std::endl;
std::cout<<"v--------------Priority Queue Tests start here------------------v"<<std::endl;
    PQueue PQ1(n);
      for(int i=0;i<100;i++)
        {
        random[i]=rand() % 10;
        PQ1.addValue(random[i]);
        }
        for(int i=0;i<5;i++)
        {
        std::cout<<PQ1.removeSmallest()<<' ';
        }
        std::cout<<std::endl;
         for(int i=0;i<5;i++)
        {
         PQ1.addValue(random[i]);
        }
        for(int i=0;i<5;i++)
        {
        std::cout<<PQ1.removeLargest()<<' ';
        }

    return 0;
}
