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
	cout<<"\nbefore source and destination write"<<endl;
	system("cat map.txt");
	ofstream fout;
	fout.open("map.txt",ios::app);
	fout<<s<<" "<<d;
	fout.close();
	cout<<"\nafter source and destination write"<<endl;
	system("cat map.txt");
	system("g++ floyd.cpp -std=c++11 -o floyd.o");
	system("./floyd.o <map.txt");
	cout<<"\nafter executing floyd.cpp"<<endl;
	system("cat map.txt");
	system("mv init.dot.png test");
	for(int i=0;i<3;i++)
	{
		usleep(9000000);
		system("g++ refresh.cpp -std=c++11 -o refresh.o");
		cout<<"\nrefresh compiled";
		cout<<"\nbefore"<<i<<"th refresh"<<endl;
		system("cat map.txt");
		system("./refresh.o <map.txt");
		cout<<"\nafter"<<i<<"th refresh"<<endl;
		system("cat map.txt");
		cout<<"\nmap refresed successfully"<<endl;
	}
	cout<<"final map.txt"<<endl;
	system("cat map.txt");
	system("cd test");
	system("ls");
	system("mv test/init.dot.png test/../");
	system("cd ..");
}

