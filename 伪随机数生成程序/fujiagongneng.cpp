#include "pbdata.h"

void baocun1(int d,lian *head)
{
	int e;
	lian *p=head;
	ofstream outfile("data.txt",ios::app);
	if(!outfile)
	{
		cerr<<"�����ı�ʧ��"<<'\n';
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
	cout<<"�Ƿ����ɵ�����뱣����data.txt�ļ�"<<'\n';
	cout<<"ȷ�ϱ����밴1,�������밴2��";
	int i;
	cin>>i;
	while(i!=1)
		{
			if(i==2)
			{
				cout<<"�ı�δ����"<<'\n';
				baocun1(0,head);
				break;
			}
			cout<<"����������������룺";
			cin>>i;
		}

	if(i==1)
	{
		baocun1(a,head);
		cout<<"����ɹ�"<<'\n';
	}
}