#include <iostream>
#include <vector>
using namespace std;

const int NOT_EULER = 0;
const int SEMI_EULER = 1;
const int EULER = 2;
void dfsVisit(vector<int> adj[],int s,bool vis[])
{
	vis[s] = true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!vis[adj[s][i]])
			dfsVisit(adj,adj[s][i],vis);
	}
}

bool isConnected(vector<int> adj[],int V,bool vis[]) 
{
	int i;
	for(i=0;i<V;i++)
	{
		if(adj[i].size()!=0)
			break;
	}
	if(i==V)  // no edges
		return true;
	dfsVisit(adj,i,vis);
	//check if all non-zero degree vertices got visited
	for(int i=0;i<V;i++)
	{
		if(vis[i]==false && adj[i].size()>0)
			return false;
	}
	return true;
}

int isEuler(vector<int> adj[],int V,bool vis[])
{
	if(!isConnected(adj,V,vis))
		return NOT_EULER;
	int odd=0;
	for(int i=0;i<V;i++)
	{
		if(adj[i].size()%2!=0)
			odd++;
	}
	if(odd>2)
		return NOT_EULER;
	return (odd) ? SEMI_EULER : EULER;
}
void test(int c)
{
	switch(c)
	{
		case NOT_EULER:
		cout<<"graph is not euer\n";
		break;
		case SEMI_EULER:
		cout<<"graph has euler path\n";
		break;
		case EULER:
		cout<<"graph has euler circuit\n";
		break;
	}
}
int main()
{
	int v,e;
	cout<<"Enter number of vertices and edges\n";
	cin>>v>>e;
	vector<int> a[v];
	bool vis[v];
	for(int i=0;i<v;i++)
		vis[i]=false;
	cout<<"Enter edges\n";
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int c = isEuler(a,v,vis);
	test(c);
}