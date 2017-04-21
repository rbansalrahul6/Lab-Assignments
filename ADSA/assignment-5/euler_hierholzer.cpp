#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void printCircuit(vector<int> adj[],int V)
{
	//to store number of edges emerging from a vertex (degree)
	unordered_map<int,int> edge_count;
	for(int i=0;i<V;i++)
	{
		edge_count[i] = adj[i].size();
	}
	if(V==0)
		return; //empty graph
	//stack for current path (since we've to reverse the current path later)
	stack<int> curr_path;
	//vector to store final circuit
	vector<int> circuit;
	//start from any vertex
	curr_path.push(0);
	int curr_v = 0; //current vertex

	while(!curr_path.empty())
	{
		//if there is some remaining edge from curr_v
		if(edge_count[curr_v])
		{
			//push the vertex
			curr_path.push(curr_v);
			//find next vertex
			int next_v = adj[curr_v].back();
			//remove that edge
			edge_count[curr_v]--;
			adj[curr_v].pop_back();
			//move to next vertex
			curr_v = next_v;
		}
		//otherwise backtrack to find remaining circuit
		else
		{
			circuit.push_back(curr_v);
			curr_v = curr_path.top();
			curr_path.pop();
		}
	}
	//got the circuit,print it in reverse
	for(int i=circuit.size()-1;i>=0;i--)
	{
		cout<<circuit[i];
		if(i)
			cout<<" -> ";
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
		//a[y].push_back(x);
	}
	printCircuit(a,v);
	cout<<endl;
}