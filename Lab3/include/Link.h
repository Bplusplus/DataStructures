#ifndef LINK_H
#define LINK_H


class Link
{
     public:

        Link(char d, Link * n = nullptr) {data =d; next=n;}

        ~Link(){}

        void setNext(Link * n){next =n;}

        Link * getNext(){return next;}

        char getData(){return data;}

    private:
        char data;
        Link * next;
};

#endif // LINK_H
