#include<iostream>
using namespace std;

struct node{
	int data;
	node *l;
	node*r;
};
node *root = NULL;
node *t = NULL;

void add(node* t, node *n = root){

	if (n != NULL){
		if (t->data < n->data){
			if (n->l == NULL)
				n->l = t;
			else
				add(t, n->l);
		}
		else{
			if (n->r == NULL)
				n->r = t;
			else
				add(t, n->r);
		}
	}
}
void print(node*t = root){
	if (t != NULL){
		print(t->l);
		cout << t->data << " ";
		print(t->r);
	}
}

void main(){
top:
	cout << "which value do you want to add?" << endl;
	int n;
	cin >> n;
	node*newnode = new node;
	newnode->data = n;
	newnode->l = NULL;
	newnode->r = NULL;
	if (root == NULL)
		root = newnode;
	else
	    add(newnode);
	cout << "current tree inorde :";
	print();
	cout << "\n";

	cout << "for not adding more enter 'n' otherwise enter others key : ";
	char c;
	cin >> c;
	if (c != 'n')
		goto top;
}