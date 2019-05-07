#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<fstream>
using namespace std;

// int k=1;

int main()
{   int n;
    cin>>n;

    double adjMatrix[n][n],temp[n][n];

    // Input from map.txt
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adjMatrix[i][j];
        }
    }
    
    // // Showing input read from map.txt
    // cout<<"contents of map.txt_________ :}";
    // cout<<n<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<adjMatrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    fstream f;
    
    ofstream fA;
    f.open("count.txt",ios::in);
    f.seekg(0);
    char k;
    f.get(k);
    f.close();
    
    cout<<endl;
    // cout<<"current count is -->"<<k;
    int t=k-'0';
    // cout<<"value of int 't' is >>>>>>>>>"<<t;
    if(t==1)
    {   
        // cout<<"\t\tALERT : t=1  achieved";
        fA.open("data.txt");
        // fout1<<n<<endl;
        // fA<<n<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fA<<adjMatrix[i][j]<<" ";
            }
            fA<<endl;
        }
        fA.close();
        // cout<<"Content of data.txt/ss";
        // system("cat data.txt");
    }
    else // t!=1
    {   
        // cout<<"\t\tALERT : t!=1  state";
        
        // read from data.txt and store in temp[][]
        ifstream fin;
        fin.open("data.txt");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fin>>temp[i][j]; //>>" ";
            }
            // fin>>"\n";
        }
        fin.close();
        
        // cout<<"Contents of temp[][]--------.>>>>>>>>>."<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<temp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        // changing values
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(temp[i][j] != 2 && adjMatrix[i][j]!=2)
                {   
                    temp[i][j]=( ((t-1)*temp[i][j]) + adjMatrix[i][j] )/t;
                }
            }
        }

        
        // writing temp to data.txt
        fA.open("data.txt");
        // fout1<<n<<endl;
        // fA<<n<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fA<<temp[i][j]<<" ";
            }
            fA<<endl;
        }
        fA.close();
        // completed writing

    }


    // cout<<endl<<"FINAL CONTENTS OF data.txt";
    // for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             cout<<temp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // cout<<endl<<endl<<"FINAL CONTENTS OF data.txt";
    // system("cat data.txt");

    return 0;
}