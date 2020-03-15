#include<iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	int num;
	char sex;
	string yuan;
};
void paixu(int a[],student stu1[]);

int main()
{
	student stu[5];
	int num1[5];
	int i=0;
	for(;i<5;i++)
	{
		cin>>stu[i].name>>stu[i].num>>stu[i].sex>>stu[i].yuan;
		num1[i]=stu[i].num;
	}
	paixu(num1,stu);
	return 0;
}


void paixu(int a[],student stu1[])
{
	int i,j;
	int n=0,m=0;
	student stu2[5];
	int b[5];
	for(i=0;i<5;i++)
	{
		b[i]=a[i];
	}
	
	int min;

	for(m=0;m<5;m++)
	{
		 min=b[0];
		 j=0;
		for(i=1;i<5-m;i++)
		{
			if(min>b[i])
			{
				min=b[i];
				j=i;
			}
		}
	//	cout<<min<<"    "<<'\n';
		for(i=0;i<5;i++)
		{
			if(min==stu1[i].num)
			{stu2[n].name=stu1[i].name;
			stu2[n].num=stu1[i].num;
			stu2[n].sex=stu1[i].sex;
			stu2[n].yuan=stu1[i].yuan;}
		}
		for(i=j;i<4-m;i++)
		{
			b[i]=b[i+1];
		}
	/*	for(i=0;i<5-m;i++)
		{
			cout<<b[i]<<' ';
		}
		cout<<'\n';*/
		n=n+1;
	}

	for(i=0;i<5;i++)
	{
		cout<<stu2[i].name<<"    "<<stu2[i].num<<"    "<<stu2[i].sex<<"    "<<stu2[i].yuan<<'\n';
	}

}