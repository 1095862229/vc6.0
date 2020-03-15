#include <iostream>
using namespace std;
void sort1(int *a,int *b,int *c)
{
	int x=*a,y=*b,z=*c;
	if(x<y && x<z)
		if(z<y)
		{*b=z;*c=y;}
	if(y<x && y<z)
	{
		*a=y;
		if(x>z)
		{
			*c=x;
			*b=z;
		}
		else
			*b=x;
	}
	if(z<x && z<y)
	{
		*a=z;
		if(x<y)
		{*b=x;*c=y;}
	}
}
void sort2(int &a,int &b,int &c)
{
	int x=a,y=b,z=c;
	if(x<y && x<z)
		if(z<y)
		{b=z;c=y;}
	if(y<x && y<z)
	{
		a=y;
		if(x>z)
		{
			c=x;
			b=z;
		}
		else
			b=x;
	}
	if(z<x && z<y)
	{
		a=z;
		if(x<y)
		{b=x;c=y;}
	}
}
int main()
{
    void sort1(int *,int *,int *);
    void sort2(int &,int &,int &);
    int n1,n2,n3;
    int *p1,*p2,*p3;
    int r1,r2,r3;
    cin>>n1>>n2>>n3;
    r1=n1;
    r2=n2;
    r3=n3;
    p1=&n1;
    p2=&n2;
    p3=&n3;
    sort1(p1,p2,p3);
    cout<<n1<<" "<<n2<<" "<<n3<<endl;
    sort2(r1,r2,r3);
    cout<<r1<<" "<<r2<<" "<<r3<<endl;
    return 0;
}

