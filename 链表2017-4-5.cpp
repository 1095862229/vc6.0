#include <iostream>
#include <iomanip>
using namespace std;
struct student
{
	int num;
	float score;
	student *next;
};

student *creatlink()                //建立
{
	student *p,*s,*head;
	s=new student;
	cin>>s->num;
	cin>>s->score;
	head=NULL;
	while(s->num!=0 && s->score!=0)
	{
		if(head==NULL)	head=s;
		else p->next=s;
		p=s;
		s=new student;
		cin>>s->num;
		cin>>s->score;
	}
	p->next=NULL;
	delete s;
	return head;
}

student *dellink(student *head,long number)								//删除
{
	student *p,*q;
	p=head;
	while(p->num!=number)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	delete p;
	return head;
}

/*student *insertlink(student *head,student *stu)							//插入
{
	student *p,*s;
	p=head;
	if(stu->num<p->num)
	{
		head=stu;
		stu->next=p;
	}
	while(p->num<stu->num)
	{
		s=p;
		p=p->next;
		if(p=NULL)
		{
			s->next=stu;
			stu->next=NULL;
			return head;
		}
	}
	stu->next=p;
	s->next=stu;
	return head;
}*/



student *insertlink(student *head,student *a)  
{student *p,*h,*s;  
s=h=head;  
p=new student ;  
p->num=a->num;  
p->score=a->score;  
p->next=NULL;  
if(p->num<head->num)  
{head=p;  
p->next=h;return head;}  
while(1)  
{if(h->num>p->num)  
{  
p->next=h;  
s->next=p;return head;}  
s=h;  
h=h->next;  
if(h==NULL)  
{s->next=p;p->next=NULL;return head;}  
}  
}  

void printlink(student *head)									//输出
{
	student *p;
	p=head;
	while(p!=NULL)
	{
		cout<<p->num<<' '<<p->score<<'\n';
		p=p->next;
	}
}

void freelink(student *head)								//释放
{
	student *p;

	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}

}





int main()
{
    student *creatlink(void);
//    student *insertlink(student *,student *);
//    void printlink(student *);
//    void freelink(student *);
    student *head,stu;
    long del_num;
    head=creatlink();
    cin>>del_num;
    head=dellink(head,del_num);
    cin>>stu.num>>stu.score;
    head=insertlink(head,&stu);
    cin>>stu.num>>stu.score;
    head=insertlink(head,&stu);
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(2);
    printlink(head);
    freelink(head);
    return 0;
}