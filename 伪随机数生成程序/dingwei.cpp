#include "pbdata.h"

int f;
char g[99];
void dingwei()
{
	ifstream outfile("data.txt");

	if(!outfile)
	{
		cout<<"��λʧ�ܣ��Ƿ�ѡ�������ʷ���ݣ�"<<'\n';
		cout<<"ȷ������밴1���˳��������밴2��"<<'\n';
		
		while(f)
		{
			cin>>f;
			if(f==1)	{qingchushuju();	break;}
			else if(f==2)		exit(1);
			else
				cout<<"������Ч�����������룺";
		}
	
	}
	outfile.seekg(ios::beg);   //(g=getchar())!=EOF
	while(!outfile.eof())
		{

			outfile.getline(g,99,'\n');
			zongcishu++;
		}
		


	
}