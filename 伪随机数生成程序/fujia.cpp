#include "pbdata.h"


void lianbiao()
{
	int min=21,max=30;
	int i=11;
	zongcishu++;
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	lian * s, * p ,*head; // s指向新结点，p指向链表中最后的结点
	s = new lian ; //动态建立第一个新结点
	s->shu=zongcishu; //输入新结点数据
	head = s ;
	p=head;
	s = new lian ;//头指针初始值为NULL
	while (i-- ) //通过判断新结点数据来进行循环
	{ 
	p->next = s ; //将新结点插入已有链表的最后
	p = s ; // p指向链表中最后的结点
	s = new lian ; //动态建立一个新结点
	 s->shu =(rand() % (max-min+1))+ min; //输入新结点数据
	}
	p -> next = NULL ; //设置链表尾部为空
 //释放数据为0的结点

	s=head->next;
	s=s->next;	
	for(i=0; i<10; i++)          //输出随机数  
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