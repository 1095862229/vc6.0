#include<iostream.h>
//using namespace std;
class Fraction
{
public:
	void output();
	Fraction(){fenzi=0;fenmu=0;};
	Fraction(int a,int b):fenzi(a),fenmu(b){}
	friend Fraction operator+(Fraction & a,Fraction &b);
	friend Fraction operator-(Fraction & a,Fraction &b);
	friend Fraction operator*(Fraction & a,Fraction &b);
	friend Fraction operator/(Fraction & a,Fraction &b);
	friend istream & operator>>(istream & input,Fraction & a);
	friend void tongfen(Fraction & a,Fraction &b);
	operator int(){return fenzi;}
private:
	int fenzi;
	int fenmu;
	int flag;
};
void tongfen(Fraction & a,Fraction &b)
{
	int m;
	int n;
	int r;
	int gongyinshu;
	if(a.fenmu>b.fenmu)
	{	m=a.fenmu;	n=b.fenmu;}
	else {m=b.fenmu;	n=a.fenmu;}
	for(;r!=0;)
	{
		r=m%n;
		m=n;
		n=r;
	}
	gongyinshu=n;
	m=a.fenmu/gongyinshu;
	n=b.fenmu/gongyinshu;
	a.fenmu=a.fenmu*n;
	a.fenzi=a.fenzi*n;
	b.fenmu=b.fenmu*m;
	b.fenzi=b.fenzi*m;
}
Fraction operator+(Fraction &a,Fraction &b)
{
	tongfen(a,b);
	return Fraction(a.fenzi+b.fenzi,a.fenmu+b.fenmu);
}


Fraction operator-(Fraction &a,Fraction &b)
{
	tongfen( a,b);
	return Fraction(a.fenzi-b.fenzi,a.fenmu-b.fenmu);
}


Fraction operator*(Fraction &a,Fraction &b)
{
	tongfen(a,b);
	return Fraction(a.fenzi*b.fenzi,a.fenmu*b.fenmu);
}


Fraction operator/(Fraction &a,Fraction &b)
{
	tongfen(a,b);
	return Fraction(a.fenzi*b.fenmu,a.fenmu*b.fenzi);
}


istream & operator>>(istream & input,Fraction & a)
{
	input>>a.fenzi>>a.fenmu;
	return input;
}


void Fraction::output()
{
	if(fenzi==fenmu)
	{	
		cout<<fenzi/fenmu;

	}
	else if(fenzi==-fenmu)
		cout<<fenzi/fenmu;
	else
	cout<<fenzi<<'/'<<fenmu;
}
int main()
{
   Fraction f1,f2,f3;
   while(cin>>f1>>f2) {
      if(f1==0&&f2==0)
        break; 
      f3=f1-f2;
      f3.output();
     f3=f1/f2;
      f3.output();
      cout<<endl;
   }
   return 0;
}


