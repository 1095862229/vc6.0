#include "pbdata.h"


void renyifanwei()
{
	int max,min;
	cout<<"请输入范围的最小值和最大值:"<<'\n';
	cin>>min>>max;



	zongcishu++;
	duowei shiweishuzu;
	shiweishuzu.cishu=zongcishu;
	int i;   



	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	for(i=0; i<10; i++)          //保存随机数  
	{  
	shiweishuzu.meiwei[i]=(rand() % (max-min+1))+ min;
	}

	for(i=0; i<10; i++)          //输出随机数  
	{  
	cout<<shiweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  


/*	cout<<shiweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/

	save(10,shiweishuzu);

}