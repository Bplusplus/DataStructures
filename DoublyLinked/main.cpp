#include <iostream>

#include "DoublyList.h"
#include "Student.h"
#include "StudentList.h"
#include "Stack.h"
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    DoublyList List;
    List.addHead('L');
    List.addHead('O');
    List.addHead('L');
    List.addTail('b');
    List.addTail('u');
    List.addTail('t');
    List.addTail('t');
    cout<<List.displayList()<<endl;
    cout<<List.deleteHead()<<endl;
    cout<<List.deleteTail()<<endl;
    cout<<List.deleteTail()<<endl;
    List.findKey('u');
    List.insertKey('Z');
    List.insertKey('W');

    cout<<"Append tester begins here"<<endl;
    DoublyList Tally;
    Tally.addHead('T');
    Tally.addHead('h');
    Tally.addHead('i');
    Tally.addHead('s');

    cout<<List.displayList()<<endl;
    cout<<Tally.displayList()<<endl;
    List.appendList(&List,&Tally);

    cout<<List.displayList()<<endl;

    cout<<"Student tester begins here"<<endl;

    Student Billy("Billy",12);
    Student Bob("Bob",13);
    Student Joe("Joe",13);

    StudentList ClassRoom;
   // Student & billy = Billy;
    ClassRoom.addHead(&Billy);
    ClassRoom.addTail(&Joe);
    ClassRoom.addHead(&Bob);
    cout<<ClassRoom.displayList();
    cout<<endl;
    Stack Room;
    Queue Line;
    Room.Push(&Billy);
    Room.Push(&Bob);
    Room.Push(&Joe);

    cout<<Room.Pop()<<' ';
    cout<<Room.Pop()<<' ';
    cout<<Room.Pop()<<' '<<endl;

    Line.Enque(&Bob);
    Line.Enque(&Joe);
    Line.Enque(&Billy);

    cout<<Line.Deque()<<' ';
    cout<<Line.Deque()<<' ';
    cout<<Line.Deque()<<' '<<endl;
    return 0;

}
