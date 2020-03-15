//读文本文件的示例 ---逐个字符读取

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("d:\\try.txt");
    if (!fin) {
      cout << "File open error!\n";
      return 0;
    }
    char c;
    while ((c=fin.get()) != EOF) //注意结束条件的判断
       cout << c;
    fin.close();
    return 0;
}
