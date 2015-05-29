#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue(){}
        virtual ~Queue(){}
        void Enque(Student * v)
        {
            room.addTail(v);
        }
        std::string Deque()
        {
            return room.removeHead();
        }
    private:
        StudentList room;
};

#endif // QUEUE_H
