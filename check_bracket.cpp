#include<iostream>
using namespace std;
struct node{
	char data;
	node *next;
};
node* head = NULL;
void push(char value){
	node * newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
     }
	else{
		newnode->next = head;
	}
}
void pop(){
	node*t = head;
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		if (head->next == NULL){
			head = NULL;
			delete(t);
		}
		else
		head = head->next;
		delete(t);
	}
}
void main(){
	char n;
	start:
	for (int i = 0; i < 100; i++){
		cin >> n;
		if (n == 'e'){
			break;
		}
		if (n >= '0'&&n <= '9'){
			goto start;
		}
		else{
			if (n == '('){
				push(n);
				goto start;
			}
			else if (n == '+' || n == '-' || n == '*' || n == '/'){
				push(n);
				goto start;
			}
			else if (n == ')'){
				node*t = head;
				while (t->data != '('){
					if (t->next == NULL){
						cout << "expression is wrong,missing a '('" << endl; goto thank;
					}
					pop();
					t = t->next;
				}
				pop();
				goto start;
			}
		}
	}
	node *t = head;
	while (t != NULL){
		if (t->data == '('){
			cout << "expression wrong,has an extra '('" << endl; goto thank;
		}
		t = t->next;
	}
	cout << "expression is currect" << endl;
thank:
	cout << "thank you" << endl;
}