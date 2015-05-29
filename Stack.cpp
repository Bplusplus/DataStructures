
Stack::Stack()
{
	arr= new int[];
	max_size = 10;
	top=0;
}

Stack::~Stack()
{
	//dtor
}
void Stack::push(int n)
{
	if (top < max_size)
		arr[top++] = n;
}
int Stack::pop()
{
	if(top>0)
		return(arr[—top]);
	else
		return -1;

}
int Stack::peek()
{
	if(top>0)
		return(arr[top - 1]);
	else
		return -1;

}