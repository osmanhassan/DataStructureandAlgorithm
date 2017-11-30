#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
void insert_first(int value){
	node*newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		head = newnode;

	}
}
void insert_last(int value){
	node *newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		node *t = head;
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newnode;
	}

}

void insert_sorted(int value){
	if (head == NULL||head->data<=value){
		if (head->data == value)
			insert_last;
		else
		   insert_first(value);
		
	}
	else{
		node*t = head;
		if (t->next == NULL){
			if (t->data < value){
				insert_first(value);
			}
			else{
				insert_last(value);
			}
		}
		else{
			while (t->next != NULL){
				if (t->next->data < value){
					node*newnode = new node;
					newnode->data = value;
					newnode->next = t->next;
					t->next = newnode; break;
				}
				if (t->next->data == value){
					insert_after(value,t->next->data); break;
				}
				t = t->next;
			}
			if (t->next == NULL){
				insert_last(value);
			}


		}
	}

	
}
void insert_after(int value, int after){
	node*t = head;
	if (t == NULL){
		cout << "nothing is in the list" << endl;
	}
	else{
			node*newnode = new node;
			newnode->data = value;
			newnode->next = NULL;
			while (t->data != after && t->next != NULL){
				t = t->next;
			}
			if (t->data == after){
				newnode->next = t->next;
				t->next = newnode;
			}
			else{
				if (head->next == NULL&&head->data==after){}
				else{
					cout <<after<< " is not found" << endl;
				}
			}
		}
	}

void delete_last(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		node* t = head, *d = t->next;
		if (t->next == NULL){
			head = head->next;
		}
		else{
			
			while (t->next->next != NULL){
				t = t->next;
				d = d->next;
			}

			t->next=NULL;
			delete(d);
		}
		}	
}
void delete_first(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		node*d = head;
		head = head->next;
		delete(d);
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
			while (t->next != NULL && t->next->data!=value){
				t = t->next;
				d = d->next;
				}
			if (t->next == NULL){
				cout <<value<< " is not found" << endl;
			}
			else{
				t->next = t->next->next;
				d->next = NULL;
				delete(d);
			}

		}
	}

}
void print(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		cout << "list is:";
		node *t = head;
		while (t != NULL){
			cout <<  t->data << "->";
			t = t->next;
		}
		cout << endl;
	}
}
void main(){
	
	insert_first(11);
	print();
	insert_last(97);
	print();
	
}