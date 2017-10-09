#include <bits/stdc++.h>
using namespace std;
void printAllPathUtil(vector<vector<pair<int,int> > >& graph,vector<int>& visited,vector<int>& path,int u,int dest,int& index)
{
	visited[u]=true;
	path[index]=u;
	index++;
	if(u==dest)
	{
		for(int i=0;i<index-1;i++)
		{
			cout<<path[i]<<"-->";
		}
		cout<<path[index-1]<<endl;
		
	}
	else
	{
		int i;
		for(i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i].second;
			if(!visited[v])
			{
				printAllPathUtil(graph,visited,path,v,dest,index);
			}
		}
	}
	visited[u]=false;
	index--;
}
void printAllPath(vector<vector<pair<int,int> > >& graph,int n,int source,int dest)
{
	vector<int> visited(n+1,0);
//	visited[source]=1;
	vector<int> path(n+1);
	int index=0;
	printAllPathUtil(graph,visited,path,source,dest,index);
	
	
}

int main()
{
	int n,m,a,b,val,i,j,k;
	cin>>n>>m;
	vector<vector<pair<int,int> > > graph(n+1);
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>val;
		graph[a].push_back(make_pair(val,b));
		graph[b].push_back(make_pair(val,a));
	}
	int source,dest;
	cin>>source>>dest;
	printAllPath(graph,n,source,dest);
}
