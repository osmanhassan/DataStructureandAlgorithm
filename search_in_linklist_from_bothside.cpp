#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head = NULL;
node*tail = NULL;
void add(int value){
	node*newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (head == NULL){
		head = newnode;
		tail = newnode;
	}
	else{
		node*t = head;
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newnode;
		t->next->prev = t;
		tail = t->next;
	}
}
void search_both_end(int value){
	int c = 0;
	if (head == NULL){
		cout << "search is not possible,list is empty" << endl;
	}
	else{
		if (head->next == NULL&&head->data == value){
			c++;
			cout << value << " is found after " << c << " sarch" << endl;
		}
		else{
			node*h = head; node*t = tail;
			while (h != t && t->next != h){
				c++;
				if (h->data == value || t->data == value){
					if (h->data == value){
						cout << value << " is found after " << c << " searches" << " from head search" << endl; break;
					}
					else{
						cout << value << " is found after " << c << " searches" << " from tail search" << endl; break;
					}
				}
				else
					t = t->prev;
					h = h->next;
			}
			if ((h == t&&h->data != value) || t->next == h){
				cout << "value is not found " << endl;
			}
			if (h == t&&h->data == value){
				c++;
				cout << value << " is found after " << c << " searches " << "from both head and tail search" << endl;
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
	add(7);
	print();
	add(5);
	print();
	add(9);
	print();
	add(3);
	print();
	add(1);
	print();
	add(11);
	print();
	search_both_end(9);
	
}