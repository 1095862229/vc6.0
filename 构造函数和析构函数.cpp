#include <iostream>
using namespace std;
class XiaoPing
{
private:
    int state;   //用来记录是否有参数
    int data;
public:
    XiaoPing();
    XiaoPing(int data);
    ~XiaoPing();
};
//////////////////////////////////////////////
只需完成并提交该部分代码
///////////////////////////////////////////////
XiaoPing::~XiaoPing()
{
    if(state)
        cout<<"destroy an object with a parameter:"<<data<<endl;
    else
        cout<<"destroy an object with no parameter"<<endl;
}
int main()
{
    int data;
    XiaoPing zeropara1;
    cin>>data;
    XiaoPing onepara1(data);
    XiaoPing zeropara2;
    cin>>data;
    XiaoPing onepara2(data);
    return 0;
}