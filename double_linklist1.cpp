#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
node *head = NULL;
void insert_first(int value){

	node*newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;

	}
}
void insert_last(int value){

	node* newnode = new node;
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		node* t=head;
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newnode;
		t->next->prev = t;
	}

}
void insert_sorted(int value){

	if (head == NULL||head->data<value){
		insert_first(value);
	}
	else{
		
		node*t = head;
		if (t->next == NULL){
			if (t->data <= value){
				insert_first(value);
			}
			else{
				insert_last(value);
			}
		}
		else{
			while (t->next != NULL){
				if (t->next->data <= value){
					node*newnode = new node;
					newnode->data = value;
					newnode->next = t->next;
					t->next = newnode;
					t->next->prev = t;
					t->next->next->prev = t->next; break;
				}
				t = t->next;
			}
			if(t->next==NULL)
			{
				insert_last(value);
			}
		}
	}
}
void insert_after(int value, int after){
	if (head == NULL){
		cout << "nothing is in the list" << endl;;
	}
	else{
		node*t = head;
		while (t->data != after&&t->next != NULL){
			t = t->next;
		}
		if (t->data == after){

			if (t->next == NULL){
				insert_last(value);
			}
			else{
				node*newnode = new node;
				newnode->data = value;
				newnode->next = t->next;
				newnode->prev = t;
				t->next= newnode;
				newnode->next->prev = newnode;
			}
		}

		else{
			cout <<after<< " is not found" << endl;
		}
	}
}
void delete_first(){

	if (head == NULL){
		cout << "nothing in the list" << endl;
	}
	else{
		node*d = head;
		//head->next->prev = NULL;
		head = head->next;
		delete(d);
	}
}
void delete_last(){

	if (head == NULL){
		cout << "nothing in the list" << endl;
	}
	else{
		node*t = head,*d=t->next;
		if (t->next == NULL){
			head = head->next;
		}
		else{
			while (t->next->next != NULL){
				d = d->next;
				t = t->next;
			}
			t->next->prev = NULL;
			t->next = NULL;
			delete(d);
		}
	}
}
void delete_value(int value){
	if (head == NULL){
		cout << "nothing is in the list" << endl;
	}
	else{
		if (head->data == value){
			delete_first();
		}
		else{
			node*t=head,*d=t->next;
			while (t->next->data != value&&t->next == NULL){
				t = t->next;
				d = d->next;
			}
			if (t->next->data == value){
				d->next->prev = t;
				t->next = d->next;
				delete(d);
			}
			else{
				cout <<value<< " is not found" << endl;
			}
		}
	}

}
void print(){

	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		cout << "the list is:";
		node *t = head;
		while (t != NULL){
			cout << t->data << "<->";
			t = t->next;
		}
		cout << endl;
	}
}
void main(){
	insert_sorted(3);
	insert_sorted(6);
	insert_sorted(9);
	insert_sorted(7);
	insert_sorted(1);
	insert_after(2, 7);
	print();
	delete_value(9);
	print();
	delete_last();
	print();
	insert_after(1, 2);
	print();

}