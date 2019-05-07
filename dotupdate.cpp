#include "dotupdate.h"
using namespace std;

void update(int a, int b, double val,double dist,double time)
{
	if(val>=0 && val<=1)
	{
		ofstream fout;
		fout.open("output.dot",ios_base::app);
		if(fout)
		{
			if(val<=0.3)
			{
				fout<<a<<" -> "<<b<<"[label=\""<<time<<"\",color= green, penwidth=\"1\"];"<<endl;
			}
			else if(val>0.3 && val<=0.7)
			{
				fout<<a<<" -> "<<b<<"[label=\""<<time<<"\",color= yellow, penwidth=\"1\"];"<<endl;
			}
			else if(val>0.7 && val<1)
			{
				fout<<a<<" -> "<<b<<"[label=\""<<time<<"\",color= red, penwidth=\"1\"];"<<endl;
			}
			else
			{
				fout<<a<<" -> "<<b<<"[label=\"blocked\",color= black, penwidth=\"2\"];"<<endl;
			}
		}
		fout.close();
	}
}
