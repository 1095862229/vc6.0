#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int str1[],str2[],n,m,i=0;
	int *p=str1;
	cin>>n>>m;
	for(;i<n;i++)
		str1[i]=i+1;
	for(;n>=1;n--)
	{
		i=0;j=1;
		for(;i<m;i++)
		{
			if(*(p+i)==0){continue; i=i-1;}
			if(i=m-1) *(p+i)=0;
		}

	}




    return 0;
}
