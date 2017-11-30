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
void insert_first(int value){
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
			head = newnode;
		}
		else{
			node *t = head;
			while (t->next != head){
				t = t->next;
			}

			newnode->next = head;
			t->next = newnode;
			head = newnode;
		}

	}
}
void insert_after(int value,int after){
	
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL&&head->data==after){
			insert_last(value);
		}
		else{
			
			node *t = head;
			while (t->next != head&&t->data!=after){
				t = t->next;
			}
			if (t->next == head){
				if (t->data == after){
					node *newnode = new node;
					newnode->data = value;
					newnode->next = NULL;
					newnode->next = t->next;
					t->next = newnode;
				}
				else
					cout << "after value is not found" << endl;
				
			}
			else{
				node *newnode = new node;
				newnode->data = value;
				newnode->next = NULL;
				newnode->next = t->next;
				t->next = newnode;
				
			}

			
		}

	}
}
void delete_first(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL || head->next == head){
			head= NULL;
		}
		else{
			node *t = head; node*d = t->next;
			while (t->next != head){
				t = t->next;
				d = d->next;
			}
			t->next = head->next;
			head = head->next;
			delete(d);

		}
	}
}
void delete_last(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL || head->next == head){
			head = NULL;
		}
		else{
			node *t = head; node*d = t->next;
			while (t->next->next != head){
				t = t->next;
				d = d->next;
			}
			t->next = head;
			delete(d);

		}
	}
}
void delete_value(int value){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if ((head->next == NULL || head->next == head)&&head->data==value){
			head = NULL;
		}
		else{
			if (head->data == value){
				delete_first();
			}
			else{
				node *t = head; node*d = t->next;
				while (t->next != head){
					if (t->next->data == value)
						break;
					t = t->next;
					d = d->next;
				}
				if (t->next->data == value){
					t->next = d->next;
					delete(d);
				}
				else
					cout << "value is not found" << endl;
			}
			

		}
	}
}
void print(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL||head->next==head){
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
	print();
	insert_last(7);
	print();
	insert_last(10);
	print();
	insert_last(15);
	print();
	insert_first(9);
	print();
	delete_last();
	print();
	delete_first();
	print();
	delete_value(10);
	print();
	delete_value(7);
	print();
	delete_value(1);
	print();
	

	
}
