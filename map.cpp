#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<fstream>
#include "dotupdate.cpp"
using namespace std;
int main()
{
	int n;
	cin>>n;
	double map[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
		}
	}
	ofstream fout;
	fout.open("output.dot");
	fout<<"digraph Test {"<<endl;
	fout.close();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			update(i,j,map[i][j]);
		}
	}
	fout.open("output.dot",ios_base::app);
	fout<<"}";
	fout.close();
	system("dot -Tpng output.dot >out.dot.png");
	system("w3m out.dot.png");
}
