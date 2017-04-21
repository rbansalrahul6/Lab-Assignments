#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/* for euler circuit
a deleted vertex is replaced by -1
*/

void rmEdge(vector<int> adj[],int u,int v) //remove edge u-v
{
	//replace v by -1 in adjList of u
	for(int i=0;i<adj[u].size();i++)
	{
		if(adj[u][i]==v)
		{
			adj[u][i]=-1;
			break;
		}
	}
	//replace u by -1 in adjList of v
	for(int i=0;i<adj[v].size();i++)
	{
		if(adj[v][i]==u)
		{
			adj[v][i]=-1;
			break;
		}
	}
}
//counting number of nodes reachable from u
int dfsCount(vector<int> adj[],int u,bool vis[])
{
	vis[u] = true;
	int count=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int t = adj[u][i];
		if(t!=-1 && !vis[t])
			count+=dfsCount(adj,t,vis);
	}
	return count;
}
//check if edge u-v can be considered as next edge in euler tour
bool isEdgeValid(vector<int> adj[],int u,int v,int V)
{
	// 1) if v is only adjacent vertex of u
	int count=0;
	for(int i=0;i<adj[u].size();i++)
	{
		if(adj[u][i]!=-1)
			count++;
	}
	if(count==1)
		return true;
	// 2) if there are multiple adjacent nodes,then u-v is not bridge
	/* to check if u-v is bridge*/
	// 2(a) count no. of vertices reachable from u
	bool vis[V];
	memset(vis,false,V);
	int count1 = dfsCount(adj,u,vis);
	// 2(b) remove u-v and count nodes reachable from u after this
	rmEdge(adj,u,v);
	memset(vis,false,V);
	int count2 = dfsCount(adj,u,vis);
	//add edge back to graph
	adj[u].push_back(v);
	adj[v].push_back(u);
	//compare count1 and count2
	return (count1>count2) ? false : true;
}

void printEuler(vector<int> adj[],int u,int V) //u is starting vertex
{
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		//if edge u-v exists and is valid
		if(v!=-1 && isEdgeValid(adj,u,v,V))
		{
			cout<<u<<"-"<<v<<" ";
			rmEdge(adj,u,v);
			printEuler(adj,v,V);
		}
	}
}
int main()
{
	int v,e;
	cout<<"Enter number of vertices and edges\n";
	cin>>v>>e;
	vector<int> a[v];
	cout<<"Enter edges\n";
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	/* starting vertex is 0 for euler circuit
	for euler path start with odd-degree vertex
	*/
	printEuler(a,0,v); 
	cout<<endl;
}