#include<iostream>
using namespace std;
int arr[10];
void binary_search(int f, int l,int value){
	if (l >= f){
		if (arr[(f + l) / 2] == value){
			cout << value << " is found at " << (f + l) / 2 <<" th index" <<endl;;
		}
		else{
			if (value > arr[(f + l) / 2])
				binary_search((f + l) / 2 + 1, l, value);
			else
				binary_search(f, (f + l) / 2 - 1, value);
		}
	}
	else
		cout << value << " is not found" << endl;
	
}
void main(){
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	int val;
	cin >> val;
    binary_search(0, 10 - 1, val);
}