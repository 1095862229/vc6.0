

//����һ���ı��ļ���д����Ϣ
//ͬ����Ļ�������Ϣһ������Ϣ������ļ�
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
    ofstream f1("example.txt");//���ļ�����д�����ļ������ھʹ�����
    if(!f1)
        return 0;//���ļ�ʧ�����������
    f1 << setw(20) << "Name: " << "Beethoven" << endl; //ʹ�ò��������д�ļ�����
    f1 << setw(20) << "song: " << "Moonlight Sonata" << endl;
    f1.close();
    return 0;      //�ر��ļ�
}
