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

  /*  for(int v=0;v<N;v++)
    {
        for(int u=0;u<N;u++)
        {
            if(distance[v][u]==INF)
                cout<<"INF";
            else
                cout<<distance[v][u]<<" ";
        }
        cout<<endl;
    }*/
    cout<<"The min cost path:- ";
    printPath(path, i, j);
}

void FloydWarshell(double adjMatrix[][N],double distance[][N],int i,int j)
{
    double cost[N][N], path[N][N] ,dist_path[N][N];
    double temp1 , temp2;

    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                {
                    path[v][u] = 0;
                    dist_path[v][u]=0;
                }
            else if (cost[v][u] != INF)
                {
                    path[v][u] = v;
                    dist_path[v][u]=v;
                }
            else
                {
                    path[v][u] = -1;
                    dist_path[v][u]=-1;
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
                    dist_path[v][u]=dist_path[k][u];
                }
           /* if(distance[v][k]!=INF && distance[u][k]!=INF && distance[v][u]>distance[v][k]+distance[k][u])
                {
                    distance[v][u]=distance[v][k]+distance[k][u];
                    dist_path[v][u]=dist_path[k][u];
                }*/
            }
        }
    }
    printSolution(cost, path,i,j);
    cout<<"The min distance path:- ";
    printPath(dist_path,i,j);
    cout<<endl;
}

int main()
{

    int n;
    cin>>n;
    double adjMatrix[N][N] ,distance[N][N],adjMatrix2[N][N];

   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>adjMatrix[i][j];
            adjMatrix2[i][j]=adjMatrix[i][j];

            if(adjMatrix[i][j]==2 || adjMatrix[i][j]==1)
                    adjMatrix2[i][j]=INF;
            //if(adjMatrix[i][j]==1)adjMatrix2[i][j]=-1;
        }
  }

 for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {

           cin>>distance[i][j];
           if(distance[i][j]==1000 || adjMatrix2[i][j]==INF)
                distance[i][j]=INF;
           //if(adjMatrix2[i][j]==-1)distance[i][j]=-1;
    }
  }
   int can=0;
   //for(;;){
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(distance[i][j]!=INF || adjMatrix2[i][j]!=INF)
                adjMatrix2[i][j]=(distance[i][j])/((int)(10-10*adjMatrix2[i][j]));
        }
  }

   FloydWarshell(adjMatrix2,distance,7,12);


    ofstream fout;
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
    //if(can==0)
	system("firefox index.html");
    //can++;
     /*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j]!=2)
				{
					int x=rand()%5+1;
					if(x==1 && map[i][j]>=0.2)
						map[i][j]-=0.2;
					else if((x==2||x==1) && map[i][j]>=0.1)
						map[i][j]-=0.1;
					else if(x==3 || x==2 || x==1 || ((x==4||x==5) && map[i][j]==1))
						map[i][j]-=0;
					else if((x==4||x==5) && map[i][j]<=0.9)
						map[i][j]+=0.1;
					else
						map[i][j]+=0.2;
				}
			}
			cout<<endl;
		}
    }*/

    return 0;
}

