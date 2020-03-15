//读文本文件的示例 ---逐行字符读取

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("d:\\try.txt");
    if(!fin){
        cout<<"File open error!\n";
        return 0;
    }
    char c[80];
    while(fin.get(c,80,'\0')!=NULL)
        cout<<c; //注意结束条件的判断
    fin.close();
    return 0;
    }
