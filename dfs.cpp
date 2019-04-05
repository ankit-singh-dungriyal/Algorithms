//Depth First Search (DFS) for the following graph 
/* (0)-----(1)
    |     / |  \
	|   /   |  (2)
    | /     |  /
   (4)-----(3)
*/

#include<bits/stdc++.h>
using namespace std;

//creating adjacency list
void add(vector<int>adj[],int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void print(vector<int>adj[],int n)
{
	
	cout<<"graph ( Adjacency list ):\n";
	for(int i=0;i<n;i++)
	{
		for(auto x:adj[i])
		{
			cout<<x<<"->";
		}
		cout<<endl;
	}
}

//function to do dfs for the graph
void dfs_ut(vector<int>adj[],int i, vector<bool>&visited)
{
	visited[i]=true;
	cout<<i<<", ";
	for(int j=0;j<adj[i].size();j++)
	{
		if(visited[adj[i][j]]==false)
		dfs_ut(adj,adj[i][j],visited);
	}
}

//function that call dfs_ut() for all unvisited verticies. 
void dfs(vector<int>adj[],int n)
{
	cout<<"Depth Search Traversal starting from node '0':\n";
	vector<bool>visited(n);
	for(int i=0;i<n;i++)
	visited[i]=false;	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		dfs_ut(adj,i,visited);
	}
}

main()
{
int n=5;
vector<int>adj[n];
add(adj,0,1);
add(adj,0,4);
add(adj,1,2);
add(adj,1,3);
add(adj,1,4);
add(adj,2,3);
add(adj,3,4);
print(adj,n);
cout<<endl;
dfs(adj,n);
}
