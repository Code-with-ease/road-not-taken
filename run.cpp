#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	system("g++ setup.cpp -std=c++11 -o setup.o");
	system("./setup.o");
	system("gnome-terminal -e 'firefox index.html'");
	cout<<"\nsetup.cpp successfully executed"<<endl;
	int s,d;	
	cout<<"\nEnter the source and Destination:-";
	cin>>s>>d;
	cout<<s<<" "<<d<<endl;
	ofstream fout;
	fout.open("map.txt",ios::app);
	fout<<s<<" "<<d;
	fout.close();
	system("g++ floyd.cpp -std=c++11 -o floyd.o");
	system("mv init.dot.png test");
	for(int i=0;i<3;i++)
	{
		system("./floyd.o <map.txt");
		usleep(9000000);
		system("g++ refresh.cpp -std=c++11 -o refresh.o");
		cout<<"\nrefresh compiled";
		system("./refresh.o <map.txt");
		cout<<"\nmap refresed successfully"<<endl;
	}
	system("cd test");
	system("mv test/init.dot.png test/../");
	system("cd ..");
}


