#include "pbdata.h"


void renyifanwei()
{
	int max,min;
	cout<<"�����뷶Χ����Сֵ�����ֵ:"<<'\n';
	cin>>min>>max;



	zongcishu++;
	duowei shiweishuzu;
	shiweishuzu.cishu=zongcishu;
	int i;   



	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<min<<  
	" to "<<max<<" :"<<endl;  
	for(i=0; i<10; i++)          //���������  
	{  
	shiweishuzu.meiwei[i]=(rand() % (max-min+1))+ min;
	}

	for(i=0; i<10; i++)          //��������  
	{  
	cout<<shiweishuzu.meiwei[i]<<"  ";   
	}  
	cout<<endl;  


/*	cout<<shiweishuzu.cishu<<'\n';
	cout<<zongcishu<<'\n';*/

	save(10,shiweishuzu);

}