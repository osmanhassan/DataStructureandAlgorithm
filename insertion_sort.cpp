#include<iostream>
using namespace std;
void main(){
	int arr[10]; int n = 0;
	while (n != 10){
		cin >> arr[n];
		n++;
	}
	int s = 1, n1 = 10;
	for (int i = 1; i < n1 ; i++){
		cout << "phase : " << i << endl;
		for (int j =i; j >0; j--){
			if (arr[j]>arr[j - 1]){
				int s = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = s;
			}
			for (int i = 0; i < 10; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		s++;
		cout << endl << endl;
	}
	cout << "after sorting : " << endl;
	for (int i = 0; i < 10; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
