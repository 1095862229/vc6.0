#include "pbdata.h"


void renyishu()
{
	int max,min,a;
	cout<<"请输入范围的最小值和最大值:"<<'\n';
	cin>>min>>max;


	cout<<"请输入所需生成随机码的个数：";
	cin>>a;


	zongcishu++;
	duowei duoweishuzu;
	duoweishuzu.cishu=zongcishu;
	int i;   



	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	for(i=0; i<a; i++)          //保存随机数  
	{  
	duoweishuzu.meiwei[i]=(rand() % (max-min+1))+ min;
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