#include "pbdata.h"

void qingchushuju()
{
	ofstream outfile("data.txt");
	if(!outfile)
	{
		cout<<"自动清除数据失败，请手动清除"<<'\n';
		exit(1);
	}
	cout<<"清除数据成功"<<'\n';
	zongcishu=0;
	outfile.close();
}