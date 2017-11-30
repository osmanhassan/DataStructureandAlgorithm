#include <stdio.h>
#include<conio.h>
void main(void){
	
	int array1[5][5] = { 'A', 'B', 'C', 'D', 'E', '1', 'A', 'B', 'C', 'D', '0', '1', 'A', 'B', 'C', '0',
		'0', '1', 'A', 'B', '0', '0', '0', '1', 'A' };
	for (int i = 0; i < 5; i++){
		for (int j = i; j < 5; j++){
			printf("%c", array1[i][j]);
		}printf("\n");
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (j < i)
				printf(" ");
			else printf("%c", array1[i][j]);
		}printf("\n");
	}printf("\n");
	for (int i = 5; i >= 0; i--){
		for (int j = i; j < 5; j++){
			printf("%c", array1[i][j]);
		}printf("\n");
	}printf("\n");
	for (int i = 0; i < 5; i++){
		for (int j = i - 1; j >= 0; j--){
			printf("%c", array1[i][j]);
		}printf("\n");
	}printf("\n");
	for (int i = 1; i < 4; i++){
		for (int j = 0; j <i + 2; j++){
			if (j < i - 1)
				printf(" ");
			else printf("%c", array1[i][j]);
		}printf("\n");
	}printf("\n");
}