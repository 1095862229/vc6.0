#include<iostream>
#include<iomanip>
using namespace std;
class Product
{
private:
	int num;
	int quantity;
	double price;
	static float discount;
	static float sum;
	static int n;
public:
	static void display();
	//static void average();
	Product(int,int,double);
	Product();
	void total();
	
};
float Product::discount=0.05;
float Product::sum=0;
int Product::n=0;
/*void Product::average()
{
	aver=sum/(float)n;
}*/

Product::Product()
{
	sum=0;
	quantity=0;
	price=0;
}

void Product::total()
{
	if(quantity>10) sum=sum+quantity*price*(1-discount)*0.98;
	else	sum=sum+quantity*price*(1-discount);
	n=n+quantity;
}

void Product::display()
{
//	average();
	cout<<sum<<'\n';
	cout<<sum/n<<'\n';
}

Product::Product(int num,int quantity,double price):
num(num),quantity(quantity),price(price){}


int main()
{
    const int NUM =10;
    Product Prod[10];
    int m,i;
    cin>>m;
    int num;
    int quantity;
    float price;
    for(i=0; i<m; i++)
    {
        cin>>num>>quantity>>price;
        Product temp(num,quantity,price);
        Prod[i]=temp;
    }
    for(i=0; i<m; i++)
        Prod[i].total();
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(2);
    Product::display();
    return 0;
}