//���ı��ļ���ʾ�� ---�����ַ���ȡ

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
        cout<<c; //ע������������ж�
    fin.close();
    return 0;
    }
