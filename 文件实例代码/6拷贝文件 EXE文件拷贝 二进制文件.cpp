//拷贝文件 EXE文件拷贝
//二进制文件操作示例

#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin("helloworld.exe", ios::binary);
    if (!fin) {
        cout << "File open error!\n";
        return  0;
    }

    ofstream fout("copy.exe", ios::binary);
    char c[1024];

    while (!fin.eof())
    {
        fin.read(c, 1024);
        fout.write(c, fin.gcount());
    }

    fin.close();
    fout.close();

    cout << "Copy over!\n";
    return 0;
}
