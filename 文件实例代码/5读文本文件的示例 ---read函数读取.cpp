//���ı��ļ���ʾ�� ---read������ȡ

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
    while(!fin.eof())    //�ж��ļ��Ƿ������
    {
        fin.read(c,80);
        cout.write(c,fin.gcount());
    }
    fin.close();
    return 0;
}
