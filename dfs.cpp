#include<iostream>

using namespace std;
const int v = 7;
const int e = 6;
int s;
int f=0;
int adc[v][v];
int vis[7];
void dfs(int u){
	for (int i = 0; i < v; i++){

		if (adc[u][i] == 1 && vis[i] == 0 && f==0){
			vis[i] = 1;
			cout << u << " " << i << endl;
			if(i==s){
                cout<<s<<"is found"<<endl;
                f=1;
			}
				dfs(i);
		}

	}
}
int main(){

	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++)
			adc[i][j] = 0;
	}
	int x, y;
	cout << "enter the adjecent edge pairs : " << endl;
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
	cout<<"enter the search node : "<<endl;
	cin>>s;
	for (int i = 0; i < v; i++)
		vis[i] = 0;
	for (int i = 0; i < v; i++){
		if (vis[i] == 0){
			vis[i] = 1;
			dfs(i);
		}
	}
	if(f==0)
        cout<<s<<" is not found"<<endl;

}
