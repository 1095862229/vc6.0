#include "pbdata.h"

void qingchushuju()
{
	ofstream outfile("data.txt");
	if(!outfile)
	{
		cout<<"�Զ��������ʧ�ܣ����ֶ����"<<'\n';
		exit(1);
	}
	cout<<"������ݳɹ�"<<'\n';
	zongcishu=0;
	outfile.close();
}