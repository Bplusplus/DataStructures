#include "ParsePost.h"
#include <string>
ParsePost::ParsePost(string s)
{ input = s; }

ParsePost::~ParsePost()
{
    //dtor
}

int ParsePost::doParse()
{
   StackX * theStack = new StackX(20); // make new stack
    char ch;
    int j;
    int num1, num2, interAns;
    for(j=0; j<input.length(); j++) // for each char,
    {
        ch = input[j]; // read from input
        theStack->displayStack("For "+ch+' '); // *diagnostic*
        if(ch >= '0' && ch <= '9') // if itÕs a number
            theStack->push( (int)(ch-'0') ); // push it
        else // itÕs an operator
        {
            num2 = theStack->pop(); // pop operands
            num1 = theStack->pop();
            switch(ch) // do arithmetic
            {
            case '+':
                interAns = num1 + num2;
                break;
            case '-':
                interAns = num1 - num2;
                break;
            case '*':
                interAns = num1 * num2;
                break;
            case '/':
                interAns = num1 / num2;
                break;
            default:
                interAns = 0;
            } // end switch
        theStack->push(interAns); // push result
        }   // end else
    } // end for
    interAns = theStack->pop(); // get answer
    return interAns;
} // end doParse()
