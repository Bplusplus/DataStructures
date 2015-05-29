#ifndef HEAP_H

#define HEAP_H





class Heap

{

    public:

        Heap();

        ~Heap();
        bool insert(int n);
        int remove();
        bool isEmpty();

    private:
        void trickleUp();
        void trickleDown();
        int curSize;
        int maxSize=100;
        int heap[100];


};



#endif // HEAP_H



