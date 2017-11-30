#include<iostream>
using namespace std;
const int n = 11; int arr[n];
void quicksort(int f, int l){
	if (f < l){
		int i = f, j = l;
		int pv = arr[f];
	top:
		if (i>j)
			goto swap;
		while (arr[i] <= pv){
			i++;
		}
		while (arr[j] > pv){
			j--;
		}
		if (i > j)
			goto swap;
		if (arr[i] > arr[j]){
			int s = arr[i];
			arr[i] = arr[j];
			arr[j] = s;
		}
		goto top;
	swap:
		int s = arr[f];
		arr[f] = arr[j];
		arr[j] = s;
		quicksort(f, j-1);
		quicksort(j+1, l);
	}
}
void main(){
	cout << "enter " << n << " inteegers" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << '\n';
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << '\n';
}