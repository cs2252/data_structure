#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//DISJOINT SET DATA STRUCTURE
const int maxn = 200000;
int Rank[maxn];
int p[maxn];
int num;

void init(int n) {
    num= n;
    fill(Rank, Rank + num+1, 0);
    for (int i = 1; i <=num; i++) p[i] = i;
}

int root(int x) {
    return x == p[x] ? x : (p[x] = root(p[x]));
}

void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (Rank[a] < Rank[b]) swap(a, b);
    if (Rank[a] == Rank[b]) ++Rank[a];
    p[b] = a;
}//DISJOINT SET DATA STRUCTURE COMPLETE
struct triple
{
	int first;
	int second;
	int third;
};
bool mycomp(triple a,triple b)
{
	if(a.third<b.third)
        return true;
    else if(a.third>b.third)
        return false;
        else if(a.first+a.second<b.first+b.second)
            return true;
            else return false;
}



bool iscycle(vector<pair<int,int> >& edge,int n,int vertex)
{

	int i;
	init(vertex);
	for(i=0;i<n;i++)
	{
  //      cout<<"i am in for loop of iscycle funciton"<<endl;
		int u=edge[i].first;
		int v=edge[i].second;
  //      cout<<u<<"   "<<v<<endl;
  //      cout<<"root of u="<<root(u)<<endl;
  //      cout<<"root of v="<<root(v)<<endl;
		if(root(u)==root(v))
        {
  //          cout<<"returning true"<<endl;
            return true;
        }
		unite(u,v);
	}
  //  cout<<"returning false"<<endl;
	return false;
}



void remove(int a,int b,vector<vector<pair<int,int> > >& v)
{
    
    for(int i=0;i<v[a].size();i++)
    {
        if(v[a][i].second==b)
        {vector<pair<int,int> >::iterator it=v[a].begin();
         it=it+i;
        v[a].erase(it);
        }
    }
    for(int i=0;i<v[b].size();i++)
    {
        if(v[b][i].second==a)
        {
            vector<pair<int,int> >::iterator it=v[b].begin();
            it=it+i;
            v[b].erase(it);
        }
    }
    
}
   
int main()
{

	int n,m,a,b,val,i,j;
	int weight=0;
	cin>>n>>m;
	vector<triple> edge(m);
	vector<vector<pair<int,int> > > graph(n+1);
	vector<vector<pair<int,int> > > tree(n+1);
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>val;
		edge[i].first=a;
		edge[i].second=b;
		edge[i].third=val;
		graph[a].push_back(make_pair(val,b));
		graph[b].push_back(make_pair(val,a));
	}
	//sort all the edges
	sort(edge.begin(),edge.end(),mycomp);
	vector<pair<int,int> > tree_edge(n);
	int count=0;
	for(i=0;i<m;i++)
	{
		int u=edge[i].first;
		int v=edge[i].second;
		int wt=edge[i].third;
		tree[u].push_back(make_pair(wt,v));
		tree[v].push_back(make_pair(wt,u));
		tree_edge[count].first=u;
		tree_edge[count].second=v;
		if(iscycle(tree_edge,count+1,n))
		remove(u,v,tree);
		else
		{
    //        cout<<"condition satisfied"<<endl;
		  count++;
		  weight+=wt;
		}
		if(count==n-1)
		break;
	}
    cout<<weight<<endl;
	//cout<<"weigth of the minumum spanning tree="<<weight<<endl;
	return 0;
	
	
}
