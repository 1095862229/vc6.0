#include "pbdata.h"

int j,c,b=zongcishu;
int shu;

void chakanlishi()
{


	ifstream infile("data.txt",ios::in);

	if(!infile)
	{
		cerr<<"�ı���ʧ��"<<'\n';
		exit(1);
	}
	else
	{
		for(b=1;b<=zongcishu;b++)
		{
			infile>>j;
			cout<<"��"<<b<<"�������Ϊ��";
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
