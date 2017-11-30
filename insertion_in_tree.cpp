#include<iostream>
using namespace std;
const int n1 = 10;
const int n = 1024 ;
int f = 0;
int arr[n];
void add(int value, int i = 1){
	if (arr[i] != -1){
		if (arr[i] < value)
			add(value, 2 * i + 1);
		else
			add(value, 2 * i);
	}
	else
		arr[i] = value;
	}
	
void print(int i = 1){
	if (i <= n){
		if (arr[i] != -1){
			print(2 * i);
			cout << arr[i] << " ";
			print(2 * i + 1);
		}
	}
}
void search(int n, int i = 1){
	if (i <= n){
		if (arr[i] != -1){
			if (arr[i] == n){
				f++;
				cout << n << " is found at " << i << " th index" << endl;
			}
			else{
				if (arr[i]<n)
				search(n, 2 * i+1);
				else
				search(n,2 * i );
			}
		}
	}
}
void main(){
	cout << "you can add " << n1 << " values in the tree " << endl;
	int i = 0;
	while (i < n){
		arr[i] = -1;
		i++;
	}
	int j = 0;
	char c;
	top:
	cout << "which value will be added : ";
	cin >> i;
	add(i);
	j++;
	cout << "current tree in inorder method :";
	print();
	cout << endl << "do you want to add more ? enter 'y' for yes enter others key for no" << endl;
	cin >> c;
	if (c == 'y'){
		if (j == n1){
			cout << "added "<<n1<<" elements "<<"cant add more" << endl;
			goto end;
		}
		goto top;
	}
end:;
	int n;
	cout << " for searching enter 's' :";
	cin >> c;
	if (c == 's'){
search:
		cout<<endl << " which value will be seached : ";
		cin >> n;
		search(n);
		if (f == 0)
			cout << n << " is not found " << endl;
		cout << " enter 'y' for more searching :";
		cin >> c;
		if (c == 'y')
			goto search;
	}
}