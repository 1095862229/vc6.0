#include "pbdata.h"


void lianbiao()
{
	int min=21,max=30;
	int i=11;
	zongcishu++;
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	lian * s, * p ,*head; // sָ���½�㣬pָ�����������Ľ��
	s = new lian ; //��̬������һ���½��
	s->shu=zongcishu; //�����½������
	head = s ;
	p=head;
	s = new lian ;//ͷָ���ʼֵΪNULL
	while (i-- ) //ͨ���ж��½������������ѭ��
	{ 
	p->next = s ; //���½�����������������
	p = s ; // pָ�����������Ľ��
	s = new lian ; //��̬����һ���½��
	 s->shu =(rand() % (max-min+1))+ min; //�����½������
	}
	p -> next = NULL ; //��������β��Ϊ��
 //�ͷ�����Ϊ0�Ľ��

	s=head->next;
	s=s->next;	
	for(i=0; i<10; i++)          //��������  
	{  
		cout<<s->shu<<"  ";  
		s=s->next;
	}  
	cout<<endl;  

	delete s ;

	s=head->next;
	s=s->next;
	save1(10,s);
/*	cout<<duoweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/

	delete s;

	
}