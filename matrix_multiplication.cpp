#include<iostream>
using namespace std;
void main(){
	const int i=3, j=1,x=1,y=3;
	if (j == x){
		int a[i][j], b[x][y], r[i][y] = { 0 };
		cout << "insert the values of matrics A:" << endl;
		for (int r = 0; r < i; r++){
			for (int c = 0; c < j; c++){
				cin >> a[r][c];
			}
			cout << endl;
		}
		cout << endl;
		cout << "insert the values of matrics B:" << endl;
		for (int r = 0; r < x; r++){
			for (int c = 0; c < y; c++){
				cin >> b[r][c];
			}
			cout << endl;
		}
		cout << endl;
		for (int rc = 0; rc < i; rc++){
			for (int i1 = 0; i1 < y; i1++){
				for (int j1 = 0; j1 < x; j1++){
					r[rc][i1] = r[rc][i1] + ((a[rc][j1] )* (b[j1][i1]));
				}
			}
		}
		for (int i1 = 0; i1 < i; i1++){
			
			for (int j1 = 0; j1 < y; j1++){
				cout << r[i1][j1] << "     ";
			}
			cout << endl;
		}
	}
	else
		cout << "multiplication is not possible" << endl;
		}
	
