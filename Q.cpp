Queue::Queue()
{
	arr= new int[];
	max_size = 10;
	tail = 0;
	head = -1;
}

Queue::~Queue()
{
	//dtor
}

Queue::enqueue(int n)
{
 	arr[tail++]=n;
 	if(tail ==max_size)
 		tail=0;
}
Queue::dequeue()
{
 
 	return arr[++head];
 	if(head == max_size -1)
 		head = -1;
}