#include<iostream>
using namespace std;
struct node{
	int age;
	int id;
	node *next;
};
node *head = NULL;
void insert_first(int value, int value1){
	node*newnode = new node;
	newnode->age = value;
	newnode->id = value1;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		head = newnode;

	}
}
void insert_last(int value,int value1){
	node *newnode = new node;
	newnode->age = value;
	newnode->id = value1;
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
void insert_after(int value,int value1, int after){
	node*t = head;
	if (t == NULL){
		cout << "nothing is in the list" << endl;
	}
	else{
		node*newnode = new node;
		newnode->age = value;
		newnode->id = value1;
		newnode->next = NULL;
		while (t->age != after && t->next != NULL){
			t = t->next;
		}
		if (t->age == after){
			newnode->next = t->next;
			t->next = newnode;
		}
		else{
			if (head->next == NULL&&head->age == after){}
			else{
				cout << after << " is not found" << endl;
			}
		}
	}
}

void push_sorted(int value,int value1){
	if (head == NULL){
		
			insert_first(value,value1);

	}
	else{
		node*t = head;
		if (t->next == NULL){
			if (t->age < value){
				insert_first(value,value1);
			}
			else{
				insert_last(value,value1);
			}
		}
		else{
			while (t->next != NULL){
				if (t->next->age < value){
					node*newnode = new node;
					newnode->age = value;
					newnode->id = value1;
					newnode->next = t->next;
					t->next = newnode; break;
				}
				if (t->next->age == value){
					
					int a = t->next->age;
					insert_after(value,value1,a); break;
				}
				t = t->next;
			}
			if (t->next == NULL){
				insert_last(value,value1);
			}


		}
	}


}
void pop(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		node*d = head;
		head = head->next;
		delete(d);
	}
}
void print(){
	if (head == NULL){
		cout << "que is empty" << endl;
	}
	else{
		cout << "que is:";
		node *t = head;
		while (t != NULL){
			cout <<"age "<< t->age<<" id "<<t->id << "->";
			t = t->next;
		}
		cout << endl;
	}
}
void main(){
	push_sorted(22, 4);
	print();
	
	push_sorted(25, 9);
	print();
	push_sorted(22, 3);
	print();
	push_sorted(23, 8);
	print();
	push_sorted(20, 1);
	print();
	push_sorted(23, 4);
	print();
	push_sorted(25, 11);
	print();
	pop();
	print();
}