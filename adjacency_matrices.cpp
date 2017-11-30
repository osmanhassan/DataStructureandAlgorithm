#include<iostream>
#include<queue>
using namespace std;
const int v = 7;
const int e = 5;
void main(){
	int adc[v][v];
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++)
			adc[i][j] = 0;
	}
	int x, y;
	cout << "enter the adjecent edge pairs : "<<endl;
	for (int i = 0; i < e; i++){
		cin >> x >> y;
		adc[x][y] = 1;
		adc[y][x] = 1;
	}
	cout << "adjecency list is :" << endl;
	for (int i = 0; i < v; i++){
		cout << i << " : ";
		for (int j = 0; j < v; j++){
			if (adc[i][j] == 1)
				cout << j << " ";
		}
		cout << endl;
	}

}