#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po pop_back
typedef long long ll;

bool biper(vector<int> v[],int i, bool vis[],bool color[])
{
 	vis[i]=true;
 	for(auto x:v[i])
 	{
 		if(!vis[x])
 		{
 			color[x]=!color[i];
 			if(!biper(v,x,vis,color))
 			return false;
		 }
		 else if(color[x]==color[i])
		 return false;
		 
	 }
	 return true;
}
bool bipertite(vector<int> v[], bool vis[],bool color[],int n)
{
	for(int i=0;i<n;i++)
	if(!vis[i])
	if(!biper(v,i,vis,color))
	return false;
	return true;
}

int main() {
	int n,m;
	int x,y;
	cout<<"\n Enter number of nodes and edges respectively: ";
	cin>>n>>m; 
	vector<int>v[n];
	bool vis[n]={false};
	bool color[n]={false};
	cout<<"\n Enter nodes for each edge: ";
	for(int i=0;i<m;i++)
	{cin>>x>>y;
	x--;y--;
	v[x].pb(y);v[y].pb(x);
	}
	
	if(bipertite(v,vis,color,n))
	cout<<"graph is bipertite";
	else
	cout<<"graph is not bipertite";
return 0;
}

