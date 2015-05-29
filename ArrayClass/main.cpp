
#include "ArrayClass.h"
#include <ctime>
using namespace std;

int main()
{
    int n=100;
    int input=0;
	char menuInput='z';
	bool valid=false;
while(!valid)
{
	cout << "Welcome to the Arraymaster 5000."<< endl;
	cout << "Firstly, how big should our array be?"<<endl;
	cin >> n;
/*
| input validation code from forum user Reguba
| forum post found here : http://www.cplusplus.com/forum/beginner/26821/
*/
    if(cin.fail()) //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter an Integer only." << endl;
			valid = false; //The cin was not an integer so try again.
		}
    else
        valid=true;
}
	ArrayClass Array1(n);

   while(menuInput != ('q' | 'Q'))
{
	cout <<endl<< "Thanks, now please give me a command in the form of a letter." << endl;
	cout <<"Avaiable commands:" << endl;
	cout << "n - Insert an integer to the array"<<endl;
	cout << "r - Removes an integer to the array"<<endl;
	cout << "s - Returns size of the array currently"<<endl;
	cout << "l - Returns largest element in the array currently"<<endl;
	cout << "p- Prints out all of the elements currently in the array"<<endl;
	cout << "c- Prints out a reduced version of the array, removing all duplicate entries in the array"<<endl;
	cout <<"d - Deletes current array "<<endl;
	cout <<"q - Quits the program "<<endl;

	cin >>menuInput;
    if(!cin.fail())
    {


	Array1.setInput(menuInput);

        switch (Array1.getInput())
        {

        case 'n' | 'N':
            cout<<"Please type your integer entry, then press return."<<endl;
            cin>>input;
            Array1.addElem(input);
             cout << Array1.howMany()<<" elements" << endl;
            break;

        case 'r' | 'R':
            Array1.delElem();
             cout << Array1.howMany()<<" elements" << endl;
            break;

        case 's' | 'S':
            cout << Array1.howMany() << endl;
            break;

        case 'l' | 'l':
            cout<<Array1.getLargest()<<endl;
            break;

        case 'p' | 'P':
            Array1.curElems();
            break;

        case 'c' | 'C':
            Array1.delDups();
            Array1.curElems();
            break;

        case 'd' | 'D':
            Array1.~ArrayClass();
            cout <<"Array Deleted. Goodbye" << endl;
            break;

        default:
            cout << "I'm sorry I don't know that command, please press any key, then enter"<<endl;
            cin >>menuInput;
            break;
        }
    }
}

     return 0;
}
