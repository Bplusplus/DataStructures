#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <cstring>


class Deque
{

	public:
		Deque();
		Deque(int n);
		~Deque();


        void addLeft(int x);
        void addRight(int x);

        int getLeft();
        int getRight();

        bool isEmpty();
        bool isFull();

        std::string listRightLeft();
        std::string listLeftRight();

    private:
        int *arr;
        int head;
		int tail;
        int maxSize;


};


#endif // Deque_H_INCLUDED

