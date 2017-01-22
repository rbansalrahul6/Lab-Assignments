#include <iostream>
using namespace std;
bool vis[1000];
int a[1000][1000];
void dfs_visit(int v,int i)
{
	vis[i]=true;
	for(int j=0;j<v;j++)
	{
		if(a[i][j]==1 && !vis[j])
			dfs_visit(v,j);
	}
	cout<<i+1<<" ";
}
void dfs(int v)
{
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
			dfs_visit(v,i);
	}
}

int main()
{
	int v,e;
	cout<<"Enter number of vertices and edges"<<endl;
	cin>>v>>e;
	//initializations
	for(int i=0;i<v;i++)
		vis[i]=false;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			a[i][j]=0;
	int p,q;
	cout<<"Enter edges"<<endl;
	for(int i=0;i<e;i++)
	{
		cin>>p>>q;
		a[p-1][q-1]=1;
	}
	//printing adjacency list
	cout<<"Adjacency list is:"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<i+1<<"-> ";
		for(int j=0;j<v;j++)
		{
			if(a[i][j]==1)
				cout<<j+1<<" ";
		}
		cout<<endl;
	}
	//dfs
	cout<<"dfs traversal"<<endl;
	dfs(v);
	cout<<endl;
	return 0;
}