#include<iostream>
using namespace std;
const int n = 10;
int arr[n]; int arr1[n];
void merge(int f, int mid, int l, int llan, int rlan){
	int i = f, j = mid + 1, k = f, b = 0, c = 0;
	while (b < llan && c <rlan){
		if (arr[i] <= arr[j]){
			arr1[k] = arr[i];
			i++;
			k++;
			b++;
		}
		else{
			arr1[k] = arr[j];
			j++;
			k++;
			c++;
		}
	}
	while (b < llan){
		arr1[k] = arr[i];
		i++;
		k++;
		b++;
	}
	while (c< rlan){
		arr1[k] = arr[j];
		j++;
		c++;
		k++;
	}
	for (int i = f; i <= l; i++){
		arr[i] = arr1[i];
	}
}
void mergesort(int f, int l){
	if (f<l){
		int mid = (f + l) / 2;
		mergesort(f, mid);
		mergesort(mid + 1, l);
		merge(f, mid, l, mid + 1 - f, l - mid);
	}
}
void main(){
	cout << "enter " << n << " integers" << endl;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << endl;
	mergesort(0, n - 1);
	cout << "after merge sort in ascending order :";
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

}