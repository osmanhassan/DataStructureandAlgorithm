#include<iostream>
using namespace std;
class que{
public:
	int data;
	que*front;
	que*rear;
	que*next;
	que(){
		front = NULL;
		rear = NULL;
	}
	void push(int value){
		que*newnode = new que;
		newnode->data = value;
		newnode->next = NULL;
		if (front == NULL){
			front = newnode;
			rear = newnode;
		}
		else{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void pop(){
		if (front == NULL){
			cout << "cant pop,que is empty" << endl;
		}
		else{
			que*t = front;
			front = front->next;
			delete(t);
		}
	}
	void print(){
		if (front == NULL){
			cout << "que is empty" << endl;
		}
		else{
			que*t = front;
			cout << "current que :";
			while (t != rear->next){
				cout << t->data << "->";
				t = t->next;

			}
			cout << endl;
		}
	}
};

void main(){
	que q;
	q.print();
	q.push(9);
	q.print();
	q.push(7);
	q.print();
	q.push(11);
	q.print();
	q.push(13);
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