#include "pbdata.h"

int j,c,b=zongcishu;
int shu;

void chakanlishi()
{


	ifstream infile("data.txt",ios::in);

	if(!infile)
	{
		cerr<<"文本打开失败"<<'\n';
		exit(1);
	}
	else
	{
		for(b=1;b<=zongcishu;b++)
		{
			infile>>j;
			cout<<"第"<<b<<"组随机数为：";
			while(j-- && !infile.eof())
			{
				infile>>shu;
				cout<<shu<<' ';
			}

			cout<<'\n';

		}
		
	}

	infile.close;
}
