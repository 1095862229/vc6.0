//写读文本文件的示例
//为能够正确读出写入文件的各数据，各数据间最好要有分隔
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream f("d:\\try.txt", ios::out); //输出流
    f << 1234 << ' ' << 3.14 << 'A' << "How are you"; //写入数据
    f.close();
    f.open("d:\\try.txt", ios::in);   //输入流
    int i;
    double d;
    char c;
    char s[20];
    f >> i >> d >> c;      //读取数据
    f.getline(s,20);
    cout << i << endl;     //显示各数据
    cout <<d << endl;
    cout << c << endl;
    cout << s << endl;
    f.close();
    return 0;
}
