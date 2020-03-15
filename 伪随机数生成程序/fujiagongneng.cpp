#include "pbdata.h"

void baocun1(int d,lian *head)
{
	int e;
	lian *p=head;
	ofstream outfile("data.txt",ios::app);
	if(!outfile)
	{
		cerr<<"保存文本失败"<<'\n';
		exit(1);
	}

	outfile<<d<<' ';
	for(e=0;e<d;e++)
	{
		outfile<<p->shu<<' ';
		p=p->next;
	}
	outfile<<'\n';
	outfile.close();
}

void save1(int a ,lian *head)
{
	cout<<'\n';
	cout<<"是否将生成的随机码保存至data.txt文件"<<'\n';
	cout<<"确认保存请按1,不保存请按2：";
	int i;
	cin>>i;
	while(i!=1)
		{
			if(i==2)
			{
				cout<<"文本未保存"<<'\n';
				baocun1(0,head);
				break;
			}
			cout<<"输入错误，请重新输入：";
			cin>>i;
		}

	if(i==1)
	{
		baocun1(a,head);
		cout<<"保存成功"<<'\n';
	}
}