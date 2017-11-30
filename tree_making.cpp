#include<math.h>
#include<iostream>
using namespace std;

struct node{
	int data;
	node*l;
	node*r;
};
node*root = NULL;

int nl = 0; 
node*epn=NULL;

int power(int power, int base = 2){
	int s = base, i = 1;
	if (power == 0)
		return 1;
	if (power == 1)
		return base;
	while (i < power){
		s = s*base;
		i++;
	}
	return s;
}
void howmany_nodes_in_level(int el, int cl = 0, node*t = root){
	if (t != NULL){
		if (cl == el)
			nl++;
		howmany_nodes_in_level(el, cl + 1, t->l);
		howmany_nodes_in_level(el, cl + 1, t->r);
	}
}
void expected_parent_node(int el, int cl = 0, node*t = root){
	if (t!= NULL&&epn==NULL){
		if (cl == el && (t->l == NULL || t->r == NULL)){
			epn = t;
		}
		expected_parent_node(el, cl + 1, t->l);
		expected_parent_node(el, cl + 1, t->r);
	}
}
void add(int val){
	node *newnode = new node;
	newnode->data = val;
	newnode->l = NULL;
	newnode->r = NULL;

	if (root == NULL){
		root = newnode;
	}
	else{
		node *t = root;
		int pl = -1;
		while (t->l != NULL){
			pl++;
			t = t->l;
		}
		howmany_nodes_in_level(pl+1);
		if (nl < power(pl + 1)){
			expected_parent_node(pl);
			if (epn->l == NULL)
				epn->l = newnode;
			else
				epn->r = newnode;
		}
		else
			t->l = newnode;
	}
	nl = 0;
	epn = NULL;
}
void print(node*t=root){
	if (t != NULL){
		print(t->l);

		cout << t->data<<" ";
		
		print(t->r);
	}
}
void main(){
top:
	int val;
	cout << "which value do you want to add ?" << endl;
	cin >> val;
	add(val);
	cout << "current tree inorder: ";
	print();
	cout << endl;
	cout << "do you want to add more,press 'y' for yes and others key for no : ";
	char c;
	cin >> c;
	if (c == 'y')
		goto top;

}