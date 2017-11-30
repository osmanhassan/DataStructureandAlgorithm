#include <iostream>
using namespace std;
int harr[22];
int sarr[11];
void print(int i = 1){
	if (i < 11){
		print(2 * i);
		cout << harr[i] << " ";
		print(2 * i + 1);
	}
}
void main(){
	cout << "Enter the values : " << endl;
	int n;
	for (int i = 0; i < 22; i++){
		harr[i] = -1;
	}
	for (int i = 1; i < 11; i++){
		cin >> n;
		harr[i] = n;
		int t = i;
		int s;
		
		while (n < harr[i / 2]){
			s = harr[i];
			harr[i]=harr[i / 2] ;
			harr[i / 2] = s;
			i = i / 2;
	      }
		i = t;
     }
	cout << "heap array is : ";
	for (int i = 1; i < 11; i++)
		cout << harr[i]<<" ";
	cout << endl;
	cout << "heap tree inorde : ";
	print();
	cout << endl;
	int j = 1;
	for (int i = 1; i < 11; i++){
		sarr[i] = harr[1];
		j = 1;
		int tp;
		while (harr[j]!=-1&&j < 11){
			if (harr[2 * j] == -1 && harr[j * 2 + 1] == -1){
				harr[j]=-1;
			}
			else{
				if (harr[j * 2] == -1 || harr[j * 2 + 1] == -1){
					if (harr[j * 2] == -1){
						tp = harr[j * 2 + 1];
						harr[j * 2 + 1] = harr[j];
						harr[j] = tp;
						j = j * 2 + 1;
					}
					else{
						tp = harr[j * 2];
						harr[j * 2] = harr[j];
						harr[j] = tp;
						j = j * 2;
					}
				}
				else{
					if (harr[j * 2] <= harr[j * 2 + 1]){
						tp = harr[j * 2];
						harr[j * 2] = harr[j];
						harr[j] = tp;
						j = j * 2;
					}
					else{
						tp = harr[j * 2 + 1];
						harr[j * 2 + 1] = harr[j];
						harr[j] = tp;
						j = j * 2 + 1;
					}
				}
			}
		}
	}
	cout << "sorted array is : ";
	for (int i = 1; i < 11; i++)
		cout << sarr[i]<<" ";
	cout << endl;
}
