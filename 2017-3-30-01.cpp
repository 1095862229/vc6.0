//	cout<<"ƽ���ɼ�Ϊ:"<<setiosflags(ios::fixed)<<setprecision(1)<<b<<'\n';
#include <iostream>
#include <iomanip>
using namespace std;
struct WageList
{
    char name[10];  //����
    double baseWage;   //��������
    double bonus;      //����
    double total;       //�ܶ�
};
int main( )
{
    WageList wage[100];
	int n,i;
	float aver=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>wage[i].name>>wage[i].baseWage>>wage[i].bonus;
	}
	for(i=0;i<n;i++)
	{
		wage[i].total=wage[i].baseWage+wage[i].bonus;
	}
	for(i=0;i<n;i++)
	{
		aver=aver+wage[i].total;
	}
	aver=aver/n;
    cout <<setiosflags(ios::fixed)<<setprecision(2);
    for(i=0; i<n; i++)
    {
        cout<<wage[i].name<<" "<<wage[i].baseWage<<" "<<wage[i].bonus<<" "<<wage[i].total<<endl;
    }
    cout<<"average:"<<aver<<endl;
    return 0;
}