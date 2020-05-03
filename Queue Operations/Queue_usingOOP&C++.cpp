#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity 
#define SIZE 5

// Class for queue
class queue
{
	int *arr;		// array to store elements
	int capacity;	// maximum capacity 
	int front;		// front points to front element of queue 
	int rear;		// rear points to last element of queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE); 	// constructor
	~queue();   				// destructor

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize queue
queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete arr;
}

// function to remove front element 
void queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

// function to add an item in queue
void queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// function to return front element
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

//  function to return the size of 
int queue::size()
{
	return count;
}

// function to check if the queue is empty or not
bool queue::isEmpty()
{
	return (size() == 0);
}

// function to check if the queue is full or not
bool queue::isFull()
{
	return (size() == capacity);
}

// main function
int main()
{
	
	queue q;\\object declaration of the class queue

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	
	cout << "Front element is: " << q.peek() << endl;
	q.dequeue();

	cout << "Queue size is " << q.size() << endl;

	
	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}
