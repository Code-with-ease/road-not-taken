#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
	srand(time(NULL));
	int x=1;	
	//int x=rand()%3+1;
	system("ls");
	system("g++ map.cpp -o map.o");
	//if(x==1)
	//{
		//-- MANAV
		int source,destination;
		cin>>source>>destination;
		
		ofstream fout;
		fout.open("test/test1.txt",ios::app);
		fout<<source<<" "<<destination<<" ";
		fout.close();

		// // -----
		string text1="test/test1.txt";
		system("./map.o <'test/test1.txt'");
	     

	//}
	/*if(x==2)
	{
		string text2="test/test2.txt";
		system("./map.o <'test/test2.txt'");
	}
	if(x==3)
	{
		string text3="test/test3.txt";
		system("./map.o <'test/test3.txt'");
	}
	//system("cat out.txt");
	*/return 0;
}
