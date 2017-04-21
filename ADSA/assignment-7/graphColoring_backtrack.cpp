#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V;
//to check if assigning color c to v is safe or not
bool isSafe(vector<int> adj[],int v,int col[],int c)
{
	for(int i=0;i<adj[v].size();i++)
	{
		if(col[adj[v][i]]==c)
			return false;
	}
	return true;
}

bool graphColoringUtil(vector<int> adj[],int col[],int m,int v)
{
	//base case - if all vertices get coloerd ,return true
	if(v==V)
		return true;
	//otherwise try to color v using different colors
	for(int c=1;c<=m;c++)
	{
		//check if color assignment is safe
		if(isSafe(adj,v,col,c))
		{
			col[v]=c;
			//recursively try to color rest of vertices
			if(graphColoringUtil(adj,col,m,v+1)==true)
				return true;
			//if assigning c doesn't lead to solution,remove it
			col[v]=0;
		}
	}
	//if no color can be assigned to this vertex,return false
	return false;
}

bool graphColoring(vector<int> adj[],int m)
{
	int col[V];
	memset(col,0,V);
	if(graphColoringUtil(adj,col,m,0)==false)
	{
		cout<<"No solution\n";
		return false;
	}
	//print solution
	for(int i=0;i<V;i++)
		cout<<"Vertex "<<i<<"    "<<"Color "<<col[i]<<endl;
	return true;
}

int main()
{
	int e,m;
	cout<<"Enter number of vertices and edges\n";
	cin>>V>>e;
	vector<int> a[V];
	cout<<"Enter edges\n";
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cout<<"enter max colors\n";
	cin>>m;
	graphColoring(a,m);
	cout<<endl;
}