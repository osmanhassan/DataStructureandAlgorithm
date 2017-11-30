#include<iostream>
using namespace std;
void main(){
	int arr[10]; int n = 0,n1;
	while (n != 10){
		cin >> arr[n];
		n++;
	}
	n1 = 10;
	for (int i = 0; i < n1-1; i++){
		cout << "phase : " << i+1 << endl;
		for (int j = i; j < n1-1; j++){
			if (arr[i]>arr[j + 1]){
				int s = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = s;
			}
			
			for (int i = 0; i < 10; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << "after sorting :" << endl;
	for (int i = 0; i < 10; i++){
		cout << arr[i]<<" ";
	}
	cout << endl;
}
