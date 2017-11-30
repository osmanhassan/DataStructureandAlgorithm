#include<iostream>
using namespace std;
const int size = 10;
int quee[size];


class que{
public:
	int front;
	int	rear;
	
	que(){
		front = 0;
		rear = 0;
	}
	

	void push(int value){
		if (rear < size){
			quee[rear] = value;
			rear++;
		}
		else
			cout << "cant push que full" << endl;
	}

	bool is_empty(){
		if (front == rear){
			return true;
		}
		else
			return false;
	}
	int frontval(){
		if (!is_empty()){
			return quee[front];
		}
	}
	void pop(){
		if (!is_empty()){
			frontval();
			front++;
		}
		else
			cout << "que is empty" << endl;
	}
	void print(){
		if (!is_empty()){
			cout << "current que :";
			for (int i = front; i < rear; i++){
				cout << quee[i] << "->";
			}
			cout << '\n';
		}
		else
			cout << "que is empty" << endl;
	}
};

void main(){
	que q;
	q.push(5);
	q.print();
	q.push(9);
	q.print();
	q.push(4);
	q.print();
	q.push(3);
	q.print();
	q.push(12);
	q.print();
	q.push(25);
	q.print();
	q.push(8);
	q.print();
	q.push(7);
	q.print();
	q.push(14);
	q.print();
	q.push(21);
	q.print();
	q.push(21);

	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();
	q.pop();


}