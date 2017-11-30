#include<iostream>
using namespace std;
char arr[100];
void post(int i ){
	if (arr[i] != 'z'&&i<100){
		post(2 * i);
		post(2 * i + 1);
		cout << arr[i] << " ";
	}
}
void main(){
	char c1='l';
	for (int i = 1; i <= 100; i++)
		arr[i] = 'z';
	int i = 98;
	int c = 0;
	while(i>1){
		cin >> arr[i];
		if (arr[i] == 'h'){
			arr[i] = 'z';
			break;
		}
		if (c1 == 'l'){
			i = i / 2;
			c1 = 'p';
		}
		else{
			if (c1 == 'p'){
				i = 2 * i + 1;
				c1 = 'r';
			}
			else{
				if (c1 == 'r'){
					i = (i / 2) / 2;
					c1 = 'p';
				}
			}
		}
		
	}
	c = 1;
	while (c <100){
		if (arr[c] != 'z')
			break;
	}
	post(c);
}