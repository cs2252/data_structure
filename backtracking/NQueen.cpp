#include<bits/stdc++.h>
using namespace std;
bool solveOneQueenUtil(int n,int row ,vector<pair<int,int> >& position)
{
	if(n==row)
	return true;
	bool safe;
	int col,i;
	for(col=0;col<n;col++)
	{
		safe=true;
		for(i=0;i<row;i++)
		{
			if(position[i].second==col||position[i].first-position[i].second==row-col||position[i].first+position[i].second==row+col)
			{
				safe=false;
				break;
			}
		}
		if(safe)
		{
		position[row]=make_pair(row,col);
		if(solveOneQueenUtil(n,row+1,position))
		return true;
		}
	}
	return false;
}
bool solveOneQueen(int n,vector<pair<int,int> >& position)
{
	if(solveOneQueenUtil(n,0,position))
	return true;
	else
	return false;
}
int main()
{
	int i,j,k,n;
	cout<<"enter the no of rows in the board\n";
	cin>>n;
	vector<pair<int,int> > position(n);
	if(solveOneQueen(n,position))
	for(i=0;i<n;i++)
	cout<<position[i].first<<"   "<<position[i].second<<endl;
	else
	cout<<"there is no such arrangement"<<endl;
	return 0;
}
