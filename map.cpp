#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<fstream>
#include "dotupdate.cpp"
#include<stdio.h>
#define N 15
#define INF 999999
using namespace std;
int main()
{

    int n;
    cin>>n;
    ofstream fout;
    fout.open("map.txt");
    fout<<n<<endl;
    fout.close();
    double adjMatrix[N][N] ,distance[N][N],adjMatrix2[N][N];
   fout.open("map.txt",ios::app);
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>adjMatrix[i][j];
            adjMatrix2[i][j]=adjMatrix[i][j];
	    fout<<adjMatrix2[i][j]<<" ";
            if(adjMatrix[i][j]==2 || adjMatrix[i][j]==1)
                    adjMatrix2[i][j]=INF;
            //if(adjMatrix[i][j]==1)adjMatrix2[i][j]=-1;
        }
	fout<<"\n";
  }

 for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {

           cin>>distance[i][j];
           if(distance[i][j]==10000 || adjMatrix2[i][j]==INF)
           {
                fout<<"10000"<<" ";
                        distance[i][j]=INF;
           }
	       else
		        fout<<distance[i][j]<<" ";
    }
    fout<<endl;
  }

for(int i=0;i<N;i++)
    	{
	        for(int j=0;j<N;j++)
	        {
	            if(distance[i][j]!=INF || adjMatrix2[i][j]!=INF)
	                adjMatrix2[i][j]=(distance[i][j])/((int)(10-10*adjMatrix2[i][j]));
	        }
    	}

    fout.close();
    //ofstream fout;
    fout.open("output.dot");
    fout<<"digraph Test {"<<endl;
    fout.close();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            update(i,j,adjMatrix[i][j],distance[i][j],adjMatrix2[i][j]);
        }
    }
    fout.open("output.dot",ios_base::app);
    fout<<"}";
    fout.close();
    system("dot -Tpng output.dot >out.dot.png");
 
    //system("firefox index.html");

    return 0;
}
