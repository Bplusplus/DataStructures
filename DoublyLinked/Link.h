#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

class Link
{
     public:

        Link(char v,Link * p=nullptr, Link * n = nullptr) {value =v; next=n; prev=p;}

        ~Link(){}

        void setNext(Link * n){next =n;}
        Link * getNext(){return next;}

        void setPrev(Link * p){prev =p;}
        Link * getPrev(){return prev;}

        char getValue(){return value;}

    private:
        char value;
        Link * prev;
        Link * next;
};


#endif // LINK_H_INCLUDED
