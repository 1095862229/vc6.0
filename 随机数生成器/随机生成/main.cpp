#include "pbdata.h"
int gongnengjian;
int main()
{
	dt=0;
	while(1)
	{
		tou();
		cin>>gongnengjian;
		switch(gongnengjian)
		{
			case 1:
				suiji();	break;
		}
	}
	return 0;
}