//读文本文件的示例 ---read函数读取

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("d:\\try.txt");
    if(!fin){
        cout<<"File open error!\n";
        return 0 ;
    }
    char c[80];
    while(!fin.eof())    //判断文件是否读结束
    {
        fin.read(c,80);
        cout.write(c,fin.gcount());
    }
    fin.close();
    return 0;
}
