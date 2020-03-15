#include<iostream>
using namespace std;
class Q
{
public:
	void set_value();	  
	int get_Max();
private:
  int n;
  int a[100];
};
void Q::set_value()		
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
}
int Q::get_Max()
{
	int i;
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	return max;
}
int main()
{
  Q b1;
  b1.set_value();
  cout<<b1.get_Max()<<endl;
  return 0;
}