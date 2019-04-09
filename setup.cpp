#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));	
	int x=2;
	system("g++ map.cpp -o map.o");
	if(x==1)
	{
		string text1="test/test1.txt";
		system("./map.o <'test/test1.txt'");
	}
	if(x==2)
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
	return 0;
}
