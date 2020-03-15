#include "pbdata.h"

int dt;

void suiji()
{
	int i;   
	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :/n"<<endl;     
	for(i=0; i<10; i++)          //产生随机数  
	{  
	cout<<MIN + rand() % (MAX + MIN - 1)<<"  ";   
	}  
	cout<<endl;  
}

void tou()
{
	cout<<"***********************************************"<<'\n';
	cout<<"                随机码生成		    	"<<'\n';
	cout<<"***********************************************"<<'\n';
	cout<<"请选择功能键，按回车键结束："<<'\n';
	cout<<'\n';
	cout<<"1、生成十位随机数     2、生成任意位随机数"<<'\n';
}