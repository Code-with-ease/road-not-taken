#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<fstream>
using namespace std;

// int k=1;

int main()
{
    cout<<endl<<endl<<endl;
    int n=15;
    double temp[n][n];
    ifstream f1;
    f1.open("data.txt");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f1>>temp[i][j]; 
        }
    }
    
    // cout<<"temp matrix";
    f1.close();


     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(temp[i][j] >= 0.83 && i!=j && temp[i][j]!=2 && temp[i][j]!=1)
            {
                cout<<"New Road suggested from '"<<i<<"' to '"<<j<<"' (Average Congestion : "<<temp[i][j]<<" )"<<endl; 
            }
        }
      
    }
    // system("cat data.txt");
    
    return 0;
}