#include "pbdata.h"


void renyishu()
{
	int max,min,a;
	cout<<"�����뷶Χ����Сֵ�����ֵ:"<<'\n';
	cin>>min>>max;


	cout<<"�������������������ĸ�����";
	cin>>a;


	zongcishu++;
	duowei duoweishuzu;
	duoweishuzu.cishu=zongcishu;
	int i;   



	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	for(i=0; i<a; i++)          //���������  
	{  
	duoweishuzu.meiwei[i]=(rand() % (max-min+1))+ min;
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