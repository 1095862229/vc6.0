#include "pbdata.h"
void baocun(int d,duowei duoweishu)
{
	int e;
	ofstream outfile("data.txt",ios::app);
	if(!outfile)
	{
		cerr<<"±£´æÎÄ±¾Ê§°Ü"<<'\n';
		exit(1);
	}

	outfile<<d<<' ';
	for(e=0;e<d;e++)
		outfile<<duoweishu.meiwei[e]<<' ';
	outfile<<'\n';
	outfile.close();
}



