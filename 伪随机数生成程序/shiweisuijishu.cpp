#include "pbdata.h"


void shiweisuijishu()
{
	zongcishu++;
	duowei duoweishuzu;
	duoweishuzu.cishu=zongcishu;
	int i;   
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :"<<endl;  
	for(i=0; i<10; i++)          //保存随机数  
	{  
	duoweishuzu.meiwei[i]=(rand() % (MAX-MIN+1))+ MIN; 
	}

	for(i=0; i<10; i++)          //输出随机数  
	{  
	cout<<duoweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  


/*	cout<<duoweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/

	save(10,duoweishuzu);

}