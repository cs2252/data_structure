#include <bits/stdc++.h>
using namespace std;
void visit(vector<vector<int> >& graph,vector<int>& visited,vector<int>& ans,int& index,int source)
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
	
		visit(graph,visited,ans,index,graph[source][i]);
	}
	visited[source]=2;
	ans[index]=source;
	index--;
}
int main()
{
	int i,j,a,b,n,m,u,v;
	cin>>n>>m;
	vector<vector<int> > graph(n+1);
	vector<int> ans(n);
	int index=n-1;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
	}
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
	for(i=0;i<n;i++)
	cout<<ans[i]<<endl;
	return 0;
}
