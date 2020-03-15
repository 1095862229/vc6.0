#include<iostream>
#include <cstring>
using namespace std;


struct student
{
	char name[20];
	int num;
	char sex;
	char yuanxi[20];
};


void change(student student1[])
{
 student student2[5];
 int i=0,j=0,k;

	for(j=0;j<5;j++)
	{
		strcpy(student2[j].name,student1[j].name);
		student2[j].num=student1[j].num;
		student2[j].sex=student1[j].sex;
		strcpy(student2[j].yuanxi,student1[j].yuanxi);		
	}
	int temp=student2[0].num;
 for(i=0;i<4;i++)
 {
	 k=i;
  for(j=i+1;j<5;j++)
   if(student1[j].num<student1[k].num)
   {
	   k=j;
    temp=student1[k].num;
    student1[k].num=student1[i].num;
    student1[i].num=temp;
   }
 }
 
 
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   if(student2[i].num==student1[j].num)
   {
    strcpy(student2[i].name,student1[j].name);
    student2[i].sex=student1[j].sex;
    strcpy(student2[i].yuanxi,student1[j].yuanxi);
   }
  }
 }
 student1=student2;

  for(i=0;i<5;i++)
 {
  cout<<student2[i].name<<"    ";
  cout<<student2[i].num<<"    ";
  cout<<student2[i].sex<<"    ";
  cout<<student2[i].yuanxi<<'\n';
 }
}


void input(student student1[],int n=5)
{
 int i=0;
 for(;i<n;i++)
 {
  cin>>student1[i].name;
  cin>>student1[i].num;
  cin>>student1[i].sex;
  cin>>student1[i].yuanxi;
 }
}


void print(student student1[],int n=5)
{
  int i=0;
 for(;i<n;i++)
 {
  cout<<student1[i].name<<"    ";
  cout<<student1[i].num<<"    ";
  cout<<student1[i].sex<<"    ";
  cout<<student1[i].yuanxi<<'\n';
 }
}



int main()
{
    const int n=5;
    student stu[n];
    input(stu,n);
	change(stu);
    print(stu,n);
    return 0;
}
