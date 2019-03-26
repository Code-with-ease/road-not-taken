#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int map[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}
