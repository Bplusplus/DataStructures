#ifndef POWERS_H
#define POWERS_H


class Powers
{
    public:
        Powers(){isOdd=false;}
        virtual ~Powers();
        void Clear();
        int calcPower(int n, int p);



    private:
        bool isOdd;
        int temp =1;
       // int isOdd=0;

};

#endif // POWERS_H
