

#include<iostream>
using namespace std;
const int size = 5;            //this program will be able to push (size-1) numbers of value;
int arr[size];

class circular{
public:
	int front;
	int rear;
	circular(){
		front = 0;
		rear = 0;
	}
	void enque(int value)
	{
		int next_rear = (rear + 1) % size;
		if (next_rear == front)
		{
			cout << "Cannot add, Queue full" << endl;
		}
		else
		{
			arr[rear] = value;
			rear = next_rear;
		}
	}
	void deque()
	{
		if (front == rear)
		{
			cout << "Cannot remove, Queue empty" << endl;
		}
		else
		{
			front = (front + 1) % size;
		}
	}
	void print()
	{
		cout << "Current Queue: ";
		for (int i = front; i != rear; i=(i+1)%size)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}

	void print1()
	{
		cout << "Current index: ";
		for (int i = front; i != rear; i = (i + 1) % size)
		{
			cout << i << "  ";
		}
		cout << endl;
	}

};

void main(){
	circular q;
	q.deque();
	q.enque(2);
	q.print();
	q.deque();
	q.print();
	q.enque(1);
	q.print();
	q.enque(2);
	q.print();
	q.enque(3);
	q.print();
	q.enque(4);
	q.print();
	q.deque();
	q.print();
	q.deque();
	q.print();
	q.enque(5);
	q.print();
	q.enque(6);
	q.print();
	q.enque(9);
	q.print1();

}