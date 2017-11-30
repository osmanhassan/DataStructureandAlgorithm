#include<iostream>
using namespace std;
const int n = 10;
const int n1 = 1024;
int arr[n];
int parr[n];
int parrt[n1];
int flag = 0,i1,c=-3;
int p;
int sum(int f, int l){
	if (f == 0)
		return parr[l];
	return parr[l] - parr[f - 1];
}
void add_segment(int value, int f, int l, int i = 1){
	if (i < n1){
		if (f <= l){
			if (f != l)
			{
				parrt[i] = value;
				add_segment(sum(f, (f + l) / 2), f, (f + l) / 2, 2 * i);
				add_segment(sum((f + l) / 2 + 1, l), (f + l) / 2 + 1, l, 2 * i + 1);
			}
			else
				parrt[i] = value;
		}
	}
}
void changing_node_value(int bagno, int value, int f, int l, int i = 1){
	if (i < n1){
		if (f <= l){
			if (f != l)
			{
				changing_node_value(bagno, value, f, (f + l) / 2, 2 * i);
				changing_node_value(bagno, value, (f + l) / 2 + 1, l, 2 * i + 1);
			}
			else{
				flag++;
				if (flag == bagno){
					i1 = i;
					if (parrt[i] >= value){
						p = parrt[i] - value;
						c = 0;
					}
					else{
						p = value - parrt[i];
						c = 1;
					}
					parrt[i] = value;
				}
			}
		}
	}
}
void print(int i = 1){
	if (i < n1){
		if (parrt[i] != -1){
			print(2 * i);
			cout << parrt[i] << " ";
			print(2 * i + 1);
		}
	}
}
void changing_tree_value(int i = i1 / 2){
	if (i> 0){
		if (c == 0)
			parrt[i] = parrt[i] - p;
		if (c == 1)
			parrt[i] = parrt[i] + p;
		changing_tree_value(i / 2);
	}
}
void take_from_segment(int f, int l, int f1, int l1, int i = 1){
	if (i <= n1){
		if (f <= l){
			if (f >= f1&&l1 >= l){
				if (l1 - f1 != l - f){
					p = p+parrt[i];
					take_from_segment(0, n - 1, f1, f-1, 1);
				}
				else{
					p = p+parrt[i];
				}
			}
			else{
			if (l1 <= (f + l) / 2)
				take_from_segment(f, (f + l) / 2, f1, l1, 2 * i);
			else
				take_from_segment((f + l) / 2 + 1, l, f1, l1, 2 * i + 1);
			}
			
		}
		
	}
	
}
void main(){
	cout << "enter the bag amounts : " << endl;
for (int i = 0; i <n; i++)
		cin >> arr[i];
	for (int i = 0; i < n1; i++)
		parrt[i] = -1;
	int s = 0;
	for (int i = 0; i < n; i++){
		parr[i] = arr[i] + s;
		s = parr[i];
	}
	add_segment(sum(0, n-1 ), 0, n-1);
	cout << "current tree : ";
	print();
    cout <<endl<<endl<< "which bag do you want to change :";
	int bn;
	cin >> bn;
	cout <<"which amount do you want to push :";
	int am;
	cin >> am;
	changing_node_value(bn, am, 0, n-1 );
	changing_tree_value();
	cout << "current tree : ";
	print();
	p = 0;
	cout <<endl<<endl<< "enter first bag number of the searching range :";
	int rf;
	cin >> rf;
	cout << "enter last bag number of the searching range :";
	int rl;
	cin >> rl;
	cout << "the sum of bag " << rf << " to " << rl << " is : ";
	take_from_segment(0, n-1 ,rf, rl);
	cout << p<<endl<<endl;
}