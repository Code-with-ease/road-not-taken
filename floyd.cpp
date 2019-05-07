#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<fstream>
#include<vector>
#include "dotupdate.cpp"
#include<stdio.h>
#define N 15
#define INF 99999
using namespace std;

int sou,dest;

void watch_time(double ti,double adjMatrix[][N],vector<int> &path_vec)
{
    ti=0;
    for(int i=1;i<path_vec.size();i++)
    {
        ti+=adjMatrix[sou][path_vec[i]];
        cout<<"TIME"<<adjMatrix[sou][path_vec[i]]<<endl;
        cout<<"S D"<<sou<<" "<<path_vec[i]<<endl;
        sou=path_vec[i];

    }
    ti+=adjMatrix[sou][dest];
        cout<<"TIME"<<ti<<adjMatrix[sou][dest]<<endl;
        cout<<"S D"<<sou<<" "<<dest<<endl;
        //cout<<"TIME"<<ti<<endl;
        

}
void printPath(double adjMatrix2[][N],double path[][N], int v, int u,vector<int> &path_vec)
{
    if (path[v][u] == v)
        return;
    //cout<<"cost"<<cost[v][u]<<endl;
    printPath(adjMatrix2,path,v,path[v][u],path_vec);
    path_vec.push_back(path[v][u]);
    cout << path[v][u] << " ";
}

void printSolution(double adjMatrix2[][N], double cost[N][N],double path[N][N],int i , int j)
{
    vector<int> path_vect;
    path_vect.push_back(i);
    int ti=0 , sou=i , dest=j;
    /*for (int v = 0; v < N; v++)
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
*/
    cout<<"THE TIME TAKEN IS "<<cost[i][j]<<endl;
    cout<<"The min cost path:- ";
    printPath(adjMatrix2,path,i, j,path_vect);
    watch_time(ti,adjMatrix2,path_vect);
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
    printSolution(adjMatrix, cost, path,i,j);
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
	                adjMatrix2[i][j]=(distance[i][j])/((int)(80-80*adjMatrix2[i][j]));
	        }
    	}
    	int source,destination;
	cin>>source>>destination;

    /*cout<<"THE MATRIX OF TIME"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<adjMatrix2[i][j]<<" ";
        }
        cout<<endl; 
    }*/
 	
    FloydWarshell(adjMatrix2,distance,source,destination);
	
    ofstream fout1;
    fout1.open("map.txt");
    fout1<<n<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		fout1<<adjMatrix[i][j]<<" ";
    	}
    	fout1<<endl;
    }
    for(int i=0;i<n;i++)
    {
	 for(int j=0;j<n;j++)
	 {
	 	if(distance[i][j]==10000 ||adjMatrix2[i][j]==INF)
			fout1<<"10000"<<" ";
		else
			fout1<<distance[i][j]<<" ";
	 }
	 fout1<<endl;
    }

    fout1<<source<<" "<<destination;  
}

