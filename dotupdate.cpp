#include "dotupdate.h"
using namespace std;

void update(int a, int b, double val)
{
	if(val>=0 && val<=1)
	{
		ofstream fout;
		fout.open("output.dot",ios_base::app);
		if(fout)
		{
			if(val<=0.3)
			{
				fout<<a<<" -> "<<b<<"[dir=none, label=\""<<val<<"\",color= green, penwidth=\"2\"];"<<endl;
			}
			else if(val>0.3 && val<=0.7)
			{
				fout<<a<<" -> "<<b<<"[dir=none, label=\""<<val<<"\",color= yellow, penwidth=\"2\"];"<<endl;
			}
			else if(val>0.7 && val<1)
			{
				fout<<a<<" -> "<<b<<"[dir=none, label=\""<<val<<"\",color= red, penwidth=\"2\"];"<<endl;
			}
			else
			{
				fout<<a<<" -> "<<b<<"[dir=none, label=\"blocked\",color= black, penwidth=\"4\"];"<<endl;
			}
		}
		fout.close();
	}
}
