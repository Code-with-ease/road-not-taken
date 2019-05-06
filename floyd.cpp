#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<fstream>
#include "dotupdate.cpp"
#include<stdio.h>
#define N 15
#define INF 99999
using namespace std;

void printPath(double path[][N], int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}

void printSolution(double cost[N][N], double path[N][N],int i , int j)
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (cost[v][u] == INF)
                cout << "\tINF";
            else
                printf("%.2f\t",cost[v][u]);
        }
        cout << endl;
    }

    cout<<"The min cost path:- ";
    printPath(path, i, j);
}

void FloydWarshell(double adjMatrix[][N],double distance[][N],int i,int j)
{
    double cost[N][N], path[N][N];
    double temp1 , temp2;

    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                {
                    path[v][u] = 0;
                }
            else if (cost[v][u] != INF)
                {
                    path[v][u] = v;
                }
            else
                {
                    path[v][u] = -1;
                }
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                temp1 = cost[v][k] + cost[k][u] ;
                temp2 = distance[v][k]+distance[k][u];

                if (cost[v][k] != INF && cost[k][u] != INF &&  distance[v][k]!=INF && distance[u][k]!=INF && temp1*temp2 < cost[v][u]*distance[v][u] )
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    distance[v][u]=distance[v][k]+distance[k][u];
                    path[v][u] = path[k][u];
                }
            }
        }
    }
    printSolution(cost, path,i,j);
    cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	double adjMatrix[N][N] ,distance[N][N],adjMatrix2[N][N];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>adjMatrix[i][j];
			adjMatrix2[i][j]=adjMatrix[i][j];
			if(adjMatrix[i][j]==2 || adjMatrix[i][j]==1)
			   adjMatrix2[i][j]=INF;
		}
	}
	 for(int i=0;i<N;i++)
	 {
	    for(int j=0;j<N;j++)
	    {

		   cin>>distance[i][j];
		   if(distance[i][j]==1000 || adjMatrix2[i][j]==INF)
		        distance[i][j]=INF;
	    }
	 }
	
	for(int i=0;i<N;i++)
    	{
	        for(int j=0;j<N;j++)
	        {
	            if(distance[i][j]!=INF || adjMatrix2[i][j]!=INF)
	                adjMatrix2[i][j]=(distance[i][j])/((int)(10-10*adjMatrix2[i][j]));
	        }
    	}
    	int source,destination;
	cin>>source>>destination;
 	FloydWarshell(adjMatrix2,distance,source,destination);
	
    ofstream fout;
    fout.open("map.txt");
    fout<<n<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		fout<<adjMatrix[i][j]<<" ";
    	}
    	fout<<endl;
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		fout<<distance[i][j]<<" ";
    	}
    	fout<<endl;
    }
    fout<<source<<" "<<destination;   //Writes 0 0 in map.txt
}

