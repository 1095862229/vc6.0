
int main()
{
    int stringcmp(char *,char *);
    int m;
    char str1[80],str2[80],*p1,*p2;
    cin>>str1;
    cin>>str2;
    p1=&str1[0];
    p2=&str2[0];
    m=stringcmp(p1,p2);
    cout<<m<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int stringcmp(char *p,char *q)
{
	int i=0;
	for(;*(p+i)!='\0' ||*(q+i)!='\0';i++)
	{
		if(*(p+i)==*(q+i))
			continue;
		else return *(p+i)-*(q+i);
	}
	return 0;

}
