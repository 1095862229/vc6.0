//д���ı��ļ���ʾ��
//Ϊ�ܹ���ȷ����д���ļ��ĸ����ݣ������ݼ����Ҫ�зָ�
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream f("d:\\try.txt", ios::out); //�����
    f << 1234 << ' ' << 3.14 << 'A' << "How are you"; //д������
    f.close();
    f.open("d:\\try.txt", ios::in);   //������
    int i;
    double d;
    char c;
    char s[20];
    f >> i >> d >> c;      //��ȡ����
    f.getline(s,20);
    cout << i << endl;     //��ʾ������
    cout <<d << endl;
    cout << c << endl;
    cout << s << endl;
    f.close();
    return 0;
}
