#include<iostream>
#include<queue>
using namespace std;
const int v = 7;
const int e = 6;
int vis[v];
int adc[v][v];
int s;
int p=0;
void bfs(int u){
	queue<int>q;
      if(u==s){
    cout<<s<<"is in the graph "<<endl;
    p=1;
    }
	q.push(u);
	vis[u] = 1;
	while (!q.empty()){
		u = q.front();
		q.pop();
		for (int i = 0; i < v; i++){
			if (adc[u][i] == 1 && vis[i == 1]){
                cout  <<u <<" "<< i <<endl ;
				q.push(i);

				vis[i] = 0;
			}
		}
		//vis[u] = 0;
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
	cout<<"enter the searching node : ";
	cin>>s;
	cout<<endl;
	for (int i = 0; i < v; i++)
		vis[i] = 1;
	for (int i = 0; i < v; i++){
		//if (vis[i] == 1)
			bfs(i);
	}
	if(p==0)
        cout<<s<<" is not in the graph"<<endl;

}
