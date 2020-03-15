#include <iostream>
#include <cstring>
using namespace std;
void sort(char *a,char *b)
{
	char p[88];
	strcpy(p,a);
	strcpy(a,b);
	strcpy(b,p);
}

void sort1(char *a,char *b,char *c)
{

	if(strcmp(*a,*b)>0) sort(*a,*b);
	if(strcmp(*a,*c)>0) sort(*a,*c);
	if(strcmp(*b,*c)>0) sort(*b,*c);

}
void sort2(char &a,char &b,char &c)
{

	if(strcmp(a,b)>0) sort(a,b);
	if(strcmp(a,c)>0) sort(a,c);
	if(strcmp(b,c)>0) sort(b,c);

}

int main()
{
    void sort1(char *,char *,char *);
    void sort2(string &,string &,string &);
    char s1[100],s2[100],s3[100];
    char *p1,*p2,*p3;
    string r1,r2,r3;
    cin>>s1>>s2>>s3;
    r1=string(s1);
    r2=string(s2);
    r3=string(s3);
    p1=s1;
    p2=s2;
    p3=s3;
    sort1(p1,p2,p3);
    cout<<s1<<endl<<s2<<endl<<s3<<endl;
    sort2(r1,r2,r3);
    cout<<r1<<endl<<r2<<endl<<r3<<endl;
    return 0;
}