#include "pbdata.h"

int dt;

void suiji()
{
	int i;   
	srand((unsigned)time(NULL));  
	cout<<"Ten random numbers from "<<MIN<<  
	" to "<<MAX<<" :/n"<<endl;     
	for(i=0; i<10; i++)          //���������  
	{  
	cout<<MIN + rand() % (MAX + MIN - 1)<<"  ";   
	}  
	cout<<endl;  
}

void tou()
{
	cout<<"***********************************************"<<'\n';
	cout<<"                ���������		    	"<<'\n';
	cout<<"***********************************************"<<'\n';
	cout<<"��ѡ���ܼ������س���������"<<'\n';
	cout<<'\n';
	cout<<"1������ʮλ�����     2����������λ�����"<<'\n';
}