#include <iostream>
#include "Powers.h"

using std::cout;
using std::endl;

int main()
{
   Powers Calc;

    cout<<Calc.calcPower(4,9)<<" Is the final answer"<<endl;

    cout<<Calc.calcPower(4,8)<<" Is the final answer"<<endl;

    cout<<Calc.calcPower(4,10)<<" Is the final answer"<<endl;

    cout<<Calc.calcPower(4,3)<<" Is the final answer"<<endl;


    //cout<<endl<<Calc.calcPower(4,9)<<endl;

    return 0;
}
