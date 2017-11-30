#include<iostream>
using namespace std;

int arr[10];
void main(){
	const int n = 9;
	int value, li = n-1, fi = 0, c = 0;
	cout << "enter the array" << endl;
	for (int i = 0; i <=n; i++){
		cin >> arr[i];
	}
	cout << "enter the searching value" << endl;
	cin >> value;
	while (fi <=li){
		c++; 
		if (arr[(fi+li)/2] == value){
			cout << value << " is found after " << c << " searches in position " << (fi+li)/2 << endl; break;
		}
		else if (value>arr[(fi+li)/2]){
			fi = (fi+li)/2+1;
			
		}
		else{
			li= (fi+li)/2-1;
		}

	}
	if (fi>li){
		cout << value << " is not found" << endl;
	}
}