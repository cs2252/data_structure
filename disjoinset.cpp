#include <bits/stdc++.h>
using namespace std;
class dsd{
    public:
    vector<int> p;
    vector<int> rank;
    dsd(int n)
    {
        p.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int root(int a)
    {
        if(a==p[a])
            return a;
        p[a]=root(p[a]);
        return p[a];
    }
    void unite(int a,int b)
    {
        a=root(a);
        b=root(b);
        if(a==b)
            return ;
        if(rank[a]==rank[b])
        {
            ++rank[a];
            p[b]=a;
        }
        else if(rank[a]>rank[b])
        {
            p[b]=a;
        }
        else
        {
            p[a]=b;
        }
    }
};
int main()
{
    dsd d(5);
    d.unite(3,2);
    for(int i=0;i<5;i++)    
        cout<<d.p[i]<<endl;
    return 0;
}