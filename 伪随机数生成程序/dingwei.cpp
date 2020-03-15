#include "pbdata.h"

int f;
char g[99];
void dingwei()
{
	ifstream outfile("data.txt");

	if(!outfile)
	{
		cout<<"定位失败，是否选择清除历史数据："<<'\n';
		cout<<"确认清除请按1，退出本程序请按2："<<'\n';
		
		while(f)
		{
			cin>>f;
			if(f==1)	{qingchushuju();	break;}
			else if(f==2)		exit(1);
			else
				cout<<"输入无效，请重新输入：";
		}
	
	}
	outfile.seekg(ios::beg);   //(g=getchar())!=EOF
	while(!outfile.eof())
		{

			outfile.getline(g,99,'\n');
			zongcishu++;
		}
		


	
}