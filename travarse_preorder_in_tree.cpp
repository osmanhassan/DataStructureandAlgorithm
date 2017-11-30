#include<iostream>
using namespace std;
struct node{
	int data;
	node*lptr;
	node*rptr;
};
node*root = NULL;
node*t = NULL;
int flag1 = 0;
int flag2 = 0;
int hm = 0;
 void nodes_in_level(node*n, int el, int cl){
	 cl++;
	 if (n != NULL){
		 if (cl == el){
			 cout << n->data<<"^";
			 flag1++;
		 }
		 else{
			 nodes_in_level(n->lptr, el, cl);
			 nodes_in_level(n->rptr, el, cl);
		 }
	 }

 }
void search_node_inlevel(node*l,int value,int el,int cl){
	cl++;
	if (l != NULL){
		
		if ( l->data==value&&cl==el){
			t = l;
			flag2++;;
		}
		else {
			search_node_inlevel(l->lptr,value,el,cl);
			search_node_inlevel(l->rptr,value,el,cl);
		}
	}
	
}
void n_howmany(node*l,int value,int el,int cl){
	cl++;
	if (l != NULL){

		if (cl == el){
			if(l->data == value)
			hm++;
		}
		else {
			 n_howmany(l->lptr, value, el, cl);
			 n_howmany(l->rptr, value, el, cl);
		}
	}
}
void search_same_node_inlevel(node*l, int value, int el, int cl,int h){
	cl++;
	if (l != NULL){

		if (l->data == value&&cl == el){
			hm++;
			if (hm == h){
				t = l;
			}
		}
		else {
			search_same_node_inlevel(l->lptr, value, el, cl,h);
			search_same_node_inlevel(l->rptr, value, el, cl,h);
		}
	}

}
void add(int val){
	node*newnode = new node;
	newnode->data = val;
	newnode->lptr = NULL;
	newnode->rptr = NULL;
	if (root == NULL){
		root = newnode;
	}
	else{
	add:
		int la;
		cout << "after whitch level you want to add" << endl;
		cin >> la;
		if (la == 0){
			node*temp = root;
			newnode->lptr = root->lptr;
			newnode->rptr = root->rptr;
			root = newnode;
			delete(temp);
		}
		else{
			nodes_in_level(root, la, 0);
			if (flag1 != 0){
				flag1 = 0;
				cout << " are in level " << la << endl;
			add_1:
				cout << "after whitch node you want to add" << endl;
				int n;
				cin >> n;
				
				search_node_inlevel(root, n, la, 0);
				
				if (flag2 != 0){
					flag2 = 0;
					n_howmany(root, n, la, 0);
					if (hm > 1){
						cout << n << " is " << hm << " times in the list" << endl;
						hm = 0;
						int t;
						cout << val << " will be inserted after which " << n << endl;
						cin >> t;
						search_same_node_inlevel(root, n, la, 0, t);
					}
					hm = 0;
					cout << "add node left or right?enter l for left r for right" << endl;
					char s;
				sw:
					cin >> s;

					switch (s)
					{
					case 'l':
						if (t->lptr != NULL){
							char c;
							cout << "do you want to replace " << t->lptr->data << " by " << newnode->data << endl;
							cout << "enter y for yes others key for no" << endl;
							cin >> c;
							if (c == 'y'){
								node*temp = t->lptr;
								newnode->lptr = t->lptr->lptr;
								newnode->rptr = t->lptr->rptr;
								t->lptr = newnode;
								delete(temp);
							}
							else{
								flag1 = 0;
								flag2 = 0;
								goto add;
							}
						}
						else
							t->lptr = newnode; break;
					case 'r':
						if (t->rptr != NULL){
							char c;
							cout << "do you want to replace " << t->rptr->data << " by " << newnode->data << endl;
							cout << "enter y for yes others key for no" << endl;
							cin >> c;
							if (c == 'y'){
								node*temp = t->rptr;
								newnode->lptr = t->rptr->lptr;
								newnode->rptr = t->rptr->rptr;
								t->rptr = newnode;
								delete(temp);
							}
							else{
								flag1 = 0;
								flag2 = 0;
								goto add;
							}
						}
						else
							t->rptr = newnode; break;
					default:
						cout << "wrong entry,try again" << endl; goto sw;
					}

				}
				else{
					cout << "no " << n << " node in the level " << la << " try again..." << endl;
					flag2 = 0;
					goto add_1;
				}
			}
			else{
				cout << "there is no level " << la << " in thhe tree try again..." << endl;
				flag1 = 0;
				goto add;
			}
		}
	}
	cout << "current tree : ";
}
void print(node*p){
	if (root == NULL){
		cout << "tree is empty" << endl;
	}
	else{
		if (p != NULL){
			cout << p->data<<"<";
			print(p->lptr);
			print(p->rptr);
		}
	}
	
}
void main(){
	int v; char c;
	print(root);
add:
	cout << "which value will be added ?" << endl;
	cin >> v;
	add(v);
	print(root);
	cout << endl;
	cout << "do you want to add more ? enter y for yes otherwise eneter others key" << endl;
	cin >> c;
	if (c == 'y')
		goto add;
}