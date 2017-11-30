#include <bits/stdc++.h>
#include <functional>
using namespace std;

map<vector<vector<int> > , bool> visited;
map<vector<vector<int> > , vector<vector<int> > > parent;
vector<vector<int> > goal(3,vector<int> (3));

int counter=0;

int cost=0;

int cc=0;

int dist;


bool visit(vector<vector<int> > a)
{
	if(visited[a]==true)
		return true;
	else
		return false;
}

int reversal(vector<vector<int> > a){

	for(int i=0;i<3;i++){

		for(int j=0;j<3;j++)
		{

		    if(i>0 && i<=2){
			if(a[i][j]==((a[i-1][j])-1)){
				cc++;
			}

		}

			if(i>=0 && i<2){

                if(a[i][j]==((a[i+1][j])-1)){
				cc++;
			}

			}

             if(j>=0 && j<2){

                if(a[i][j]==((a[i][j+1])-1)){
				cc++;
			}
             }

             if(j>0 && j<=2){

                if(a[i][j]==((a[i][j-1])-1)){
				cc++;
			}


			}

		}
		}

return cc;

}






int misplace(vector<vector<int> > a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=goal[i][j])
				counter++;
		}
	}

return counter;
}


int manhattan(vector<vector<int> > a , int moves)
{
    int idealx;

    int currentx;

	d=moves;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=0)
			{
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
						if(a[i][j]==goal[k][l])

                            idealx=(i-k);

                             currentx=(j-l);

							d+=sqrt((idealx-currentx)*(idealx-currentx));
					}
				}
			}
		}
	}
	return d;
}


bool isGoal(vector<vector<int> > a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=goal[i][j])
				return false;
		}
	}

return true;
}

bool safe(int i,int j)
{
	if(i>=0 && i<=2 && j>=0 && j<=2)
	return true;
	else
	return false;
}
int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};
vector<vector<vector<int> > > neighbours(vector<vector<int> > a)
{
	pair<int,int> pos;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==0)
			{
				pos.first=i;
				pos.second=j;
				break;
			}
		}
	}
	vector<vector<vector<int> > > ans;
	for(int k=0;k<4;k++)
	{
		int cx = pos.first;
		int cy = pos.second;
		vector<vector<int> > n = a;
		if(safe(cx+dx[k],cy+dy[k]))
		{
			swap(n[cx+dx[k]][cy+dy[k]],n[cx][cy]);
			ans.push_back(n);
		}
	}

return ans;
}

typedef pair<vector<vector<int> > , int> state;

struct cmp
{
	bool operator() (state &a, state &b)
	{
		int am = manhattan(a.first,a.second);
		int bm = manhattan(b.first,b.second);
		return am>bm;
	}
};

void print_path(vector<vector<int> > s)
{

   if(parent.count(s)){
   print_path(parent[s]);

   cost++;
   }

   for(int i=0;i<3;i++)
   {
	 for(int j=0;j<3;j++)
	 {
		printf("%d ",s[i][j]);
	 }
	cout<<endl;
   }

   cout<<endl;
 return;
}

void print(vector<vector<int> > s)
{
	for(int i=0;i<3;i++)
   {
	 for(int j=0;j<3;j++)
	 {
		printf("%d ",s[i][j]);
	 }
	cout<<endl;
   }
}

void solve(vector<vector<int> > a, int moves)
 {

	priority_queue<state,vector<state>,cmp > Q;
	Q.push(state(a,moves));
	while(!Q.empty())
	{
	    int cc=0;
		vector<vector<int> > s = Q.top().first;
		Q.pop();

		visited[s]=true;

		if(s==goal)
		{
			print_path(s);
			cout<<"cost:"<<cost<<endl;

			break;
		}
		vector<vector<vector<int> > > ns = neighbours(s);
		vector<vector<vector<int> > >::iterator it;

		for(it=ns.begin();it!=ns.end();it++)
		{

			vector<vector<int> > temp = *it;
			if(!visit(temp))
			{
				parent.insert(pair<vector<vector<int> > , vector<vector<int> > >(temp,s));
				Q.push(state(temp,moves+1));
			}
		}
	}
	return;
 }

int main()
{
	vector<vector<int> > a(3,vector<int> (3));


	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Solution...\n\n";
	goal[0][0] = 1;
	goal[0][1] = 2;
	goal[0][2] = 3;
	goal[1][0] = 4;
	goal[1][1] = 0;
	goal[1][2] = 5;
	goal[2][0] = 6;
	goal[2][1] = 7;
	goal[2][2] = 8;

	solve(a,0);
}
