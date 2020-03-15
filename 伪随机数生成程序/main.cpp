#include "pbdata.h"

int gongnengjian,queren;
int zongcishu=0;
fujia jia;
lian *p=NULL;
int main()
{
	dingwei();
	while(1)
	{
		tou();
		cout<<'\n';
		cin>>gongnengjian;
		switch(gongnengjian)
		{

			case 1:
				cout<<'\n';
				shiweisuijishu();
				if(fanhui()==1)
					continue;


			case 2:
				cout<<'\n';
				duoweisuijishu();
				if(fanhui()==1)
					continue;

			case 3:
				cout<<'\n';
				renyifanwei();
				if(fanhui()==1)
					continue;

			case 4:
				cout<<'\n';
				renyishu();
				if(fanhui()==1)
					continue;

			case 5:
				cout<<'\n';
				chakanlishi();
				if(fanhui()==1)
					continue;

			case 6:
				cout<<'\n';
				cout<<"请确认是否要删除历史数据,确认请按1 ：";
				cin>>queren;
				if(queren==1)
				qingchushuju();
					continue;
			case 7:
				cout<<'\n';
				cout<<"操作失误";
				system( "PAUSE ");
				cout<<"还不行？";
				system( "PAUSE ");
				cout<<"哈哈，我很强！！！";
				exit(1);
			case 8:

				{	cout<<'\n';
				jia.suanfa();
				if(fanhui()==1)
					continue;}
			case 9:
				cout<<'\n';
				lianbiao();
				if(fanhui()==1)
					continue;
			default:
				cout<<"输入无效，请重新输入：";
				continue;
		}
	}
	return 0;
}