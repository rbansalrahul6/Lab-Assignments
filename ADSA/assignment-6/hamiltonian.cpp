#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V;

/* A utility function to check if the vertex v can be added at
   index 'pos' in the Hamiltonian Cycle constructed so far (stored
   in 'path[]') */
bool isSafe(vector<int> adj[],int v,int path[],int pos)
{
	 /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
	int u = path[pos-1],i;
	for(i=0;i<adj[u].size();i++)
	{
		if(adj[u][i]==v)
			break;
	}
	if(i==adj[u].size())
		return false;
	/* Check if the vertex has already been included.
      This step can be optimized by creating an array of size V */
	for(int i=0;i<pos;i++)
		if(path[i]==v)
			return false;
	return true;
}
/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(vector<int> adj[],int path[],int pos)
{
	/* base case: If all vertices are included in Hamiltonian Cycle */
	if(pos==V)
	{
		// And if there is an edge from the last included vertex to the
        // first vertex (check if cucle is completed)
        int u = path[pos-1]; //last included vertex
        int v = path[0]; //first vertex
        int i;
        for(i=0;i<adj[u].size();i++)
        {
        	if(adj[u][i]==v)
        		return true;
        }
        if(i==V)
        	return false;
	}
	// Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 0 as we included 0 as starting point in in hamCycle()
    for(int v=1;v<V;v++)
    {
    	if(isSafe(adj,v,path,pos))
    	{
    		path[pos]=v;
    		/* recur to construct rest of the path */
    		if(hamCycleUtil(adj,path,pos+1)==true)
    			return true;
    		/* If adding vertex v doesn't lead to a solution,
               then remove it */
    		path[pos]=-1;
    	}
    }
    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return false */
    return false;
}

bool hamCycle(vector<int> adj[])
{
	int path[V];
	memset(path,-1,V);
	path[0]=0;
	if(hamCycleUtil(adj,path,1)==false)
	{
		cout<<"No solution\n";
		return false;
	}
	//print
	for(int i=0;i<V;i++)
		cout<<path[i]<<" ";
	cout<<path[0];
	cout<<endl;
	return true;
}

int main()
{
	int e;
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
	hamCycle(a);
	cout<<endl;
}