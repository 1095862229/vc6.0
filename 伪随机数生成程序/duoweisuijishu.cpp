#include "pbdata.h"


void duoweisuijishu()
{
	cout<<"�������������������ĸ�����";
	int a;
	cin>>a;
	zongcishu++;
	duowei duoweishuzu;
	duoweishuzu.cishu=zongcishu;
	int i;   
	srand((unsigned)time(0));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :"<<endl;  
	for(i=0; i<a; i++)          //���������  
	{  
	duoweishuzu.meiwei[i]=MIN + (int)MAX * rand() / (RAND_MAX + 1); 
	}

	for(i=0; i<a; i++)          //��������  
	{  
	cout<<duoweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  


/*	cout<<duoweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/
	
	  
	save(a,duoweishuzu);

}