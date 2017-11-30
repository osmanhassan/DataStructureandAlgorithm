#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *top = NULL;
void push(int value){
	node*newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (top == NULL){
		top = newnode;
	}
	else{
		newnode->next = top;
		top = newnode;

	}
}
void pop(){
	if (top == NULL){
		cout << "list is empty" << endl;
	}
	else{
		node*d =top;
		top = top->next;
		delete(d);
	}
}
void print(){
	if (top == NULL){
		cout << "list is empty" << endl;
	}
	else{
		cout << "list is:";
		node *t = top;
		while (t != NULL){
			cout << t->data << "->";
			t = t->next;
		}
		cout << endl;
	}
}
void main(){
	push(7);
	print();
	push(9);
	print();
	pop();
	print();

}