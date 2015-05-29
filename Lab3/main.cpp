#include <iostream>
#include "Link.h"
#include "DoubleEnded.h"
using namespace std;

int main()
{
    DoubleEnded Double;
    Double.addHead('Z');
    Double.addTail('z');
    cout<<Double.removeHead();
    return 0;
}
