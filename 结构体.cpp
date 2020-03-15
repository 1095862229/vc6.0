#include <iostream>
#include <iomanip>
using namespace std;
struct student
{
	int num;
	char name[20];
	int score[3];
};
int main()
{
    const int n=5;
    student stu[n];
    void input(student [],int );
    void print(student [],int );
    input(stu,n);
    print(stu,n);
    return 0;
}

void input(student [],int n)
{
	int i=0,j=0;
	for(;i<n;i++)
	{
		cin>>student[i].num>>student[i].name;
		for(j=0;j<3;i++)
		{
			cin>>student[i].score[j];
		}
	}
}
void print(student [],int n)
{
	int i=0,j=0;
	for(;i<n;i++)
	{
		cout<<student[i].num<<' '<<student[i].name<<' ';
		for(j=0;j<3;i++)
		{
			cout<<student[i].score[j];
			if(j<2)
				cout<<' ';
			else cout<<'\n';

		}
	}

}
