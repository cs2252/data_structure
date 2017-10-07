#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
void visit(vector<vector<pair<int,int> > >& graph,vector<int>& visited,vector<int>& ans,int& index,int source)
{
	if(visited[source]==2)
		return ;
	if(visited[source]==1)
		{
			exit(1);
		}
		visited[source]=1;
		int i;
	for(i=0;i<graph[source].size();i++)
	{
	
		visit(graph,visited,ans,index,graph[source][i].second);
	}
	visited[source]=2;
	ans[index]=source;
	index--;
}
void topo_sort(vector<vector<pair<int,int> > >& graph,vector<int>& ans,int n)
{
	int i;
	int index=n-1;
		vector<int> vis(n+1,0);
	//visited[i]==1 means temproray marked  visited[i]=2 menas permanent visited
	for(i=1;i<=n;i++)
	{
		
		if( vis[i]==0 )
		{
//			cout<<"calling visited of node="<<i<<endl;
			visit(graph,vis,ans,index,i);
			
		}
	}
}
int main()
{
	int i,j,a,b,n,m,u,v,val;
	cin>>n>>m;
	vector<vector<pair<int,int> > > graph(n+1);
	vector<int> dist(n+1,-INF);
	vector<int> ans(n);
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>val;
		graph[a].push_back(make_pair(val,b));
	}
	topo_sort(graph,ans,n);
	//for every vertex in the topological order
	
	int s;
	cout<<"enter the starting vectex"<<endl;
	cin>>s;
	dist[s]=0;
	for(i=1;i<=n;i++)
	{
		u=ans[i];
		for(j=0;j<graph[u].size();j++)
		{
			v=graph[u][j].second;
			int wt=graph[u][j].first;
			if(dist[v]<dist[u]+wt)
			dist[v]=dist[u]+wt;
		
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}
