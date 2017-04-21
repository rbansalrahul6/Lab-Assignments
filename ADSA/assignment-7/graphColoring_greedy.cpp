/* graph coloring using greedy method
for undirected graph
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void greedyColoring(vector<int> adj[],int V)
{
	int col[V]; //to store colors
	for(int i=0;i<V;i++)
		col[i] = -1;
	col[0]=0; //assign first color to first vertex
	//temorary array to store availability of colors
	//for a color c if unavailable[c] is true means c is assigned to some of its adjacent vertex
	bool unavailable[V];
	memset(unavailable,false,V);
	//assign colors to remaining vertices
	for(int i=1;i<V;i++)
	{
		//process all adjacent vertices and mark their colors as unavailable
		for(int j=0;j<adj[i].size();j++)
		{
			int x = adj[i][j];
			if(col[x]!=-1)
				unavailable[col[x]]=true;
		}
		//find first available color
		int cr;
		for(cr=0;cr<V;cr++)
		{
			if(unavailable[cr]==false)
				break;
		}
		col[i]=cr;
		//reset values to false for next iteration
		memset(unavailable,false,V);
	}
	//print result
	for(int i=0;i<V;i++)
	{
		cout<<"Vertex "<<i<<"    "<<"Color "<<col[i]<<endl;
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
	greedyColoring(a,v);
	cout<<endl;
}