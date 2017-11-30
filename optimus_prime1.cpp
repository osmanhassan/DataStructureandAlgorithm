//#include<math.h>
#include<iostream>
using namespace std;
void main(){
	int n;
	for (int i = 3; i < 20; i=i + 2){
		n = i;
		int c=0,j=0,d3 = 0;
		while (n != 0){
			c++;
			d3 == d3 + n % 10;
			if (c == 1 && d3 == 5){
				break; 
			}
			n = n / 10;
		}
		if (d3 % 3 != 0){
			if (i % 7 != 0){
				cout << i << endl;
			}
		}

	}
}