#include "pbdata.h"


void duoweisuijishu()
{
	cout<<"请输入所需生成随机码的个数：";
	int a;
	cin>>a;
	zongcishu++;
	duowei duoweishuzu;
	duoweishuzu.cishu=zongcishu;
	int i;   
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :"<<endl;  
	for(i=0; i<a; i++)          //保存随机数  
	{  
	duoweishuzu.meiwei[i]=MIN + (int)MAX * rand() / (RAND_MAX + 1); 
	}

	for(i=0; i<a; i++)          //输出随机数  
	{  
	cout<<duoweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  


/*	cout<<duoweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/
	
	  
	save(a,duoweishuzu);

}