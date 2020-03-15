#include "pbdata.h"

void shiweisuijishu()
{
	int i;   
	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :"<<endl;     
	for(i=0; i<10; i++)          //产生随机数  
	{  
	cout<<MIN + rand() % (MAX + MIN - 1)<<"  ";   
	}  
	cout<<endl;  
}