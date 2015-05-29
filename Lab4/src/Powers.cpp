#include "Powers.h"
#include <iostream>

using std::cout;
using std::endl;

Powers::~Powers()
{
    //dtor
}

int Powers::calcPower(int n, int p)
{
    cout<<"Input is now"<<' '<<n<<' '<<"Power is now"<<' '<<p<<endl;

    if(p==1)
    {
        cout<<"I'm done let's go back up"<<endl<<endl;
        n=n*temp;
        temp=1;
       return(n);
    }
    else if(p % 2==1 && p!=1)
    {
        isOdd=true;
        cout<<"I'm odd"<<' '<<p<<' '<<"input equals "<<n<<endl;
        temp=temp*n;
        n=n*n;
        cout<<n<<endl;
        return(calcPower(n,p/2));
    }
    else
    {
         cout<<"I'm even"<<' '<<p<<' '<<"input equals "<<n<<endl;
         return(calcPower(n*n,p/2));
    }


}
