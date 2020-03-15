#include <iostream>
using namespace std;
int main()
{
    int getHeight(float height[],int n,float result[]);
    float height[100],result[100];
    int i,num,n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>height[i];
    num=getHeight( height,n,result);
//   for(i=0; i<num; i++)
//        cout<<i+1<<":"<<result[i]<<endl;
	cout<<num<<'\n';
    return 0;
}

int getHeight(float height[],int n,float result[])
{
	int i=0,max=height[0],geshu=0,weizhi;
	for(;i<n;i++)
	{
		if(max<height[i])
		{
			max=height[i];
			weizhi=i;
		}
	}
	for(i=0;i<n;i++)
	{
		if(max==height[i])
			geshu++;
	}
	cout<<geshu<<'\n';
        return geshu;
}