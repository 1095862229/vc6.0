#ifndef pbdata_h
#define pbdata_h

#include <iostream>  
#include   <stdlib.h>      
#include   <time.h> 
#include  <fstream>
using namespace std;  
/*************************************************************///变量定义
#define MIN 0    //随机数产生的最小值      
#define MAX 9    //随机数产生的最大值

extern int zongcishu;
extern int a;


struct duowei
{
	int cishu;
	int meiwei[99];
};


struct lian
{
	int shu;
	lian *next;
};





/*************************************************************///函数声明
void shiweisuijishu();
void duoweisuijishu();
void renyifanwei();
void renyishu();
void tou();
int fanhui();
void save(int,duowei);
void chakanlishi();
void baocun(int ,duowei);
void qingchushuju();
void dingwei();
void baocun1(int ,lian *);
void save1(int ,lian *);
void lianbiao();




class fujia
{
public:
	void suanfa()
	{
	int min=11,max=20;
	zongcishu++;
	duoweishuzu.cishu=zongcishu;
	int i;   
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	for(i=0; i<10; i++)          //保存随机数  
	{  
	duoweishuzu.meiwei[i]=(rand() % (max-min+1))+ min; 
	}

	for(i=0; i<10; i++)          //输出随机数  
	{  
	cout<<duoweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  



	save(10,duoweishuzu);
	}
private:
	duowei duoweishuzu;
};


#endif