

//创建一个文本文件并写入信息
//同向屏幕上输出信息一样将信息输出至文件
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
    ofstream f1("example.txt");//打开文件用于写，若文件不存在就创建它
    if(!f1)
        return 0;//打开文件失败则结束运行
    f1 << setw(20) << "Name: " << "Beethoven" << endl; //使用插入运算符写文件内容
    f1 << setw(20) << "song: " << "Moonlight Sonata" << endl;
    f1.close();
    return 0;      //关闭文件
}
