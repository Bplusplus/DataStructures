class Queue
{
	public:
		Queue();
		~Queue();
		void enqueue(int n);
		int dequeue();
	private:
		int *arr;
		int head;
		int tail;
}