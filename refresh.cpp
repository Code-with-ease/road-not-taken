#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "dotupdate.cpp"
#define INF 99999
using namespace std;
int main()
{
    srand(time(NULL));
    int n;
    ofstream fout1;
    cin>>n;
    double adjMatrix[n][n] ,distance[n][n],adjMatrix2[n][n];

   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adjMatrix[i][j];
            adjMatrix2[i][j]=adjMatrix[i][j];

            if(adjMatrix[i][j]==2 || adjMatrix[i][j]==1)
                    adjMatrix2[i][j]=INF;
            //if(adjMatrix[i][j]==1)adjMatrix2[i][j]=-1;
        }
  }

 for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {

           cin>>distance[i][j];
           if(distance[i][j]==10000 || adjMatrix2[i][j]==INF)
                distance[i][j]=INF;
           //if(adjMatrix2[i][j]==-1)distance[i][j]=-1;
    }
  }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adjMatrix[i][j]!=2)
			{
				int x=rand()%5+1;
				if(x==1 && adjMatrix[i][j]>=0.2)
					adjMatrix[i][j]-=0.2;
				else if((x==2||x==1) && adjMatrix[i][j]>=0.1)
					adjMatrix[i][j]-=0.1;
				else if(x==3 || x==2 || x==1 || ((x==4||x==5) && adjMatrix[i][j]==1))
					adjMatrix[i][j]-=0;
				else if((x==4||x==5) && adjMatrix[i][j]<=0.9)
					adjMatrix[i][j]+=0.1;
				else
					adjMatrix[i][j]+=0.2;
			}
		}
	}

	for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(distance[i][j]!=INF || adjMatrix2[i][j]!=INF)
                    adjMatrix2[i][j]=(distance[i][j])/((int)(10-10*adjMatrix2[i][j]));
            }
        }			
	int source,destination;
	cin>>source>>destination;
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
    fout1.close();
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
    return 0;
}
