#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head = NULL;
void add(int value){
	node *newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		node*t = head;
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newnode;
	}
}
void print(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		node*t = head;
		cout << "current list is : ->";
		while (t != NULL){
			cout << t->data << "->";
			t = t->next;
		}
		cout << '\n';
	}
}
void sort(){
	int n=0;
	if (head == NULL){
		cout << "cant be sorted list is empty" << endl;
	}
	else{
		if (head->next == NULL){
			cout << "it is sorted" << endl;
		}
		else{
			node *t = head;
			while (t!= NULL){
				n++;
				t = t->next;
			}
			t = head;
			int s = 1,c;
			for (int i = 0; i < n - 1; i++){
					for (int j = 0; j < n - s; j++){
					if (t->data >t->next->data){
						c = t->data;
						t->data = t->next->data;
						t->next->data = c;
						
					}
					cout << '\n';
					t = t->next;	
				}
					cout << '\n';
				s++;
			  t = head;
			}
		}
	}
}

void main(){
	add(12);
	print();
	add(11);
	print();
	add(10);
	print();
	add(9);
	print();
	add(8);
	print();
	add(7);
	print();
	add(6);
	print();
	sort();
	print();

}