#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node * head = NULL;

void insert_last(int value){
	node *newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		if (head->next == NULL){
			newnode->next = head;
			head->next = newnode;

		}
		else{
			node *t = head;
			while (t->next != head){
				t = t->next;
			}

			newnode->next = head;
			t->next = newnode;
		}

	}
}
void delete_value(int value){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{

		if (head->data == value){
			node*d = head;
			head = head->next;
			delete(d);
		}
		else{
			node* t = head; node*d = t->next;
			while (t->next != NULL && t->next->data != value){
				t = t->next;
				d = d->next;
			}
			if (t->next == NULL){
				cout << value << " is not found" << endl;
			}
			else{
				t->next = t->next->next;
				d->next = NULL;
				delete(d);
			}

		}
	}

}
void delete_1_skip_1(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL || head->next == head){
			head = NULL;
		}
		else{
			node*t = head;
			while (t->next != head){
				delete_value(t->next->data);
				t = t->next;
				if (t == head)
					break;
			}
		}
	}
}
void print(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL || head->next == head){
			cout << "current list is : " << head->data << "->" << endl;

		}
		else{
			node *t = head;
			cout << "current list is : ";
			while (t->next != head){
				cout << t->data << "->";
				t = t->next;
			}
			cout << t->data;
			cout << endl;
		}
	}
}
void main(){
	insert_last(2);
	print();
	insert_last(3);
	print();
	insert_last(4);
	print();
	insert_last(5);
	print();
	insert_last(6);
	print();
	insert_last(7);
	print();
	delete_1_skip_1();
	print();
	delete_1_skip_1();
	print();
	delete_1_skip_1();
	print();
	delete_1_skip_1();
	print();

}