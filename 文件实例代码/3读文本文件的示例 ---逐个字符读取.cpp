//���ı��ļ���ʾ�� ---����ַ���ȡ

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
    while ((c=fin.get()) != EOF) //ע������������ж�
       cout << c;
    fin.close();
    return 0;
}
