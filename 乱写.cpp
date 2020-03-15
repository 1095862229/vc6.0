#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h> 
#include<time.h>
#define N sizeof(struct Account)   //宏定义 
#define M sizeof(struct income_and_expenditure)

struct income_and_expenditure      //收支情况 
{
	float iae;     //收入或支出 
	char ch;    //-号代表支出，+号代表收入 
	int year;    //年月日 
	int month;
	int day;
	int num;    //标号 
	char source_or_aim[50];    // 收入来源或支出目的 
	struct income_and_expenditure *next;       // 指针域 ，后接 
	struct income_and_expenditure *pre;   //前驱 
};
typedef struct income_and_expenditure IAE;   
typedef IAE *IAEP;


struct Account       //账户信息 
{
	char name[10];       //账号昵称 
	char password[18];       //密码 
	struct Account *next;   //指针域 
};
typedef struct Account Acc;
typedef Acc *Accp;

//好多自定义函数~~
Accp ff();                     //将存账号的文件里的内容输出到链表中
IAEP ss();                   //将存账单的文件里的内容输出到链表中 
void signin();               //登陆或注册 
void login();                 // 注册账号 
void logon();                  // 账号登陆  
void menu();                 //菜单 
void over();                  //退出系统 
void color(short x);                 //控制颜色 
void HideCursor();          //隐藏光标
void toxy(int x, int y);    //将光标移动到X,Y坐标处
void amend_password();         //修改密码 
void add_information();       //添加信息 
void print_information();     //账单明细 
void find_information();     //查找信息 
void delete_information();   //删除信息 
void amend_information();    //修改信息 
void save_account(Accp p);    //保存账号
void save_information(IAEP p); //保存信息 


char _name[20],_password[18];       //全局变量记住当前登陆账户 


void color(short x)
{
	if(x>=0&&x<=15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
} 

void HideCursor()     //隐藏光标
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //将光标移动到X,Y坐标处
{
COORD pos = { x , y };
HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(Out, pos); 
}

Accp ff()               //将存账号的文件里的内容输出到链表中
{
	FILE *fp;       //文件指针 
	int n=0;
	Accp head=NULL;
	Accp p2,p;
	fp=fopen("account","r");     //以只读的方式打开文件 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))        //判断文件位置标志是否移动到文件末尾 
	{
	   n++;
	   	p=(Accp)malloc(N);
	   fread(p,N,1,fp);
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //创建链表 
	    {
	    	p2->next=p;
	    	p2=p;
		}
    }
    p2->next=NULL;
    fclose(fp);
    return head;
}


void menu()     //菜单 
{
	system("cls");    //清屏 
	system("color 70");
	do{
		char t;
		toxy(50,5);
		printf(" 个人财务管理软件");
		toxy(50,6);
		printf("当前账户为：%s",_name);
		toxy(48,8);
		printf("|     1.添加信息      |");
		toxy(48,10);
		printf("|     2.修改信息      |");
		toxy(48,12);
		printf("|     3.删除信息      |");
		toxy(48,14);
		printf("|     4.账单明细      |");
		toxy(48,16);
		printf("|     5.查找信息      |");
		toxy(48,18);
		printf("|     6.修改密码      |"); 
		toxy(48,20);
		printf("|     7.退出系统      |");
		t=getch();                    //利用不回显函数，输入t，可以不用手动按回车键 
		switch(t)
		{
			case '1':add_information();break;
			case '2':amend_information();break;
			case '3':delete_information();break;
			case '4':print_information();break;
			case '5':find_information();break;
			case '6':amend_password();break;
			case '7':over();break;
			default :;break;
		}
    }while(1);       //永远为真 
}

void signin()       //登陆或注册 
{
	system("cls");
	HideCursor();    //隐藏光标
	char t;
	color(2);
	toxy(50,5);
	printf("个人财务管理软件");
	toxy(44,8);
	printf("****************************");
	toxy(45,10);
	printf("请输入（1：登陆；2：注册.)");
	toxy(44,12);
	printf("****************************");
	while(1)
	{
		t=getch();
		switch(t)
		{
			case '1':logon();break;
			case '2':login();break;
			default :break;
		}
	}
}

void logon()      // 账号登陆 
{
	system("cls");
	HideCursor();
	Accp p,head;
	head=ff();
    do{
    	HideCursor();       //隐藏光标 
    	color(12);
	    p=head;
	    char t,c,k;
	    int i=0;
		toxy(50,5);
		printf("个人财务管理软件");
		toxy(45,6);
		printf("--------------------------");
		toxy(45,8);
		printf("     登陆状态       ");
		toxy(45,10);
		printf("*  请输入您的账号：");
		gets(_name);
		toxy(45,12);
		printf("*  请输入您的密码：");
		for(;;)              //此处为输入密码不回显操作 
		{
			k=getch();       //输入k 
			if(k=='\r')      //如果输入k为回车，则跳出循环 
			{
				break;
			}
			else if(k=='\b')  //如果输入k为删除键 
			{
				if(i>0)       //如若密码还没完全删除 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //如果输入的k既不是删除键，也不是回车键 
			{
				_password[i]=k;   //把k的值赋给_password[i]; 
				printf("*");      //输出*号，保护用户隐私 
				i++;              //密码位数加1 
			}
		}
		_password[i]='\0';
		while(p!=NULL&&strcmp(p->name,_name)!=0)   //遍历链表，寻找当前输入的账户的账号 
		{
			p=p->next;
		}
		if(p!=NULL)   //如果p不为空 
		{
	    	if(strcmp(p->password,_password)==0)     //如果输入的密码正确 
			{
				toxy(48,16);
				printf("正在登陆....");
				Sleep(500);      //暂停0.5秒
				system("cls");
				system("color 72");
				toxy(48,10);
				printf("登陆成功！");
				break;    //跳出循环
			}
			else      //如果输入的密码错误
			{ 
				toxy(48,16);
				printf("正在登陆....");
				Sleep(500);
				system("cls");
				system("color 72");
				toxy(46,8);
				printf("-------------------------");
				toxy(46,9);
				printf("|                       |");
				toxy(46,10);
				printf("| 密码错误！是否继续？  |");
				toxy(46,12);
				printf("| 1.是             2.否 |");
				toxy(46,13);
				printf("|                       |");
				toxy(46,14);
				printf("-------------------------");
				while(1)
				{
					t=getch();  //输入t    
					if(t=='1')          
					{
						system("cls");  //清屏 
						system("color 72"); 
						break;
					}
					else if(t=='2')     //如果输入t为n，进入开始界面 
					{
						signin();break;
					}
				}
			} 
	   }
	   else              //如果p为空，即输入的账号不正确 
	   {
	   	    toxy(48,16);
	   	    printf("正在登陆....");
	   	    Sleep(500);
	   	    system("cls");
	   	    system("color 72");
	   	    toxy(46,8);
	   	    printf("-------------------------");
	   	    toxy(46,9);
	   	    printf("|                       |");
	   		toxy(46,10);
			printf("|  账号错误！是否继续？ |");
			toxy(46,11);
			printf("|                       |");
			toxy(46,12);
			printf("|  1.是            2.否 |"); 
			toxy(46,13);
			printf("|                       |");
			toxy(46,14);
			printf("-------------------------");
			while(1)
			{
				c=getch();
				if(c=='1')
				{  
					system("cls");
					system("color 72");
					break;
				}
				else if(c=='2')
				{
					signin();break;
				}
			}
	   }
    }while(1);      //永远为真 
   Sleep(500);      //暂停0.5秒 
   menu();         //账号密码均正确，进入主菜单 
}

void login()        //注册账号 
{
	system("cls");
	HideCursor();       //隐藏光标 
	Accp p1;
	p1=(Accp)malloc(N);     //向内存申请一段空间 
	do{
		HideCursor();
		color(11);
		char name[20],password[18],againpassword[18],c,k;
		int i=0;; 
		toxy(50,5);
		printf("个人财务管理软件");
		toxy(45,6);
		printf("-------------------------");
		toxy(45,8);
		printf("   正在注册");
		toxy(45,10);
		printf("*  请输入账号：");
		gets(name);
		toxy(45,12);
		printf("*  请输入密码：");
		for(;;)              //此处为输入密码不回显操作 
		{
			k=getch();       //输入k 
			if(k=='\r')      //如果输入k为回车，则跳出循环 
			{
				break;
			}
			else if(k=='\b')  //如果输入k为删除键 
			{
				if(i>0)       //如若密码还没完全删除 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //如果输入的k既不是删除键，也不是回车键 
			{
				password[i]=k;   //把k的值赋给_password[i]; 
				printf("*");      //输出*号，保护用户隐私 
				i++;              //密码位数加1 
			}
		}
		password[i]='\0';
		i=0;
		toxy(45,14);
		printf("*  请确认您的密码：");
		for(;;)              //此处为输入密码不回显操作 
		{
			k=getch();       //输入k 
			if(k=='\r')      //如果输入k为回车，则跳出循环 
			{
				break;
			}
			else if(k=='\b')  //如果输入k为删除键 
			{
				if(i>0)       //如若密码还没完全删除 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //如果输入的k既不是删除键，也不是回车键 
			{
				againpassword[i]=k;   //把k的值赋给_password[i]; 
				printf("*");      //输出*号，保护用户隐私 
				i++;              //密码位数加1 
			}
		}
		againpassword[i]='\0';
		if(strcmp(password,againpassword)==0)        //如果输入的两次密码均正确 
		{
			strcpy(p1->name,name);
			strcpy(p1->password,password);
			toxy(48,16);
			printf("正在注册....");
			Sleep(500);
			system("cls");
			system("color 72");
			toxy(48,10);
			printf("注册成功！");
			Sleep(500);         //暂停0.5秒 
			break;              //跳出循环 
		}
		else    //如果输入的两次密码不同 
		{
			toxy(48,16);
			printf("正在注册....");
			Sleep(500);
			system("cls");
			system("color 72");
			toxy(46,8);
			printf("-----------------------------");
			toxy(46,9);
			printf("|                           |");
			toxy(46,10);
			printf("|  注册失败！是否继续注册？ |");
			toxy(46,11);
			printf("|                           |");
			toxy(46,12);
			printf("|  1.是               2.否  |"); 
			toxy(46,13);
			printf("|                           |");
			toxy(46,14);
			printf("-----------------------------");
			while(1)
			{
				c=getch();
				if(c=='1')
				{
					system("cls");
					system("color 72");
					break;
				}
				else if(c=='2')
				{
					signin();
					break;
				}
			}
		}
	}while(1);    //永远为真 
	save_account(p1);     //调用函数，将p1所指向的内容存储到文件中 
	toxy(48,12);
	printf("正在自动为您登陆....");
	Sleep(500);
	menu();    //注册成功后进入主菜单 
}

/*修改密码
方法比较笨，这里是先将储存在文件中的账户信息
输出在一个链表中，遍历链表，寻找当前登陆的账户账号，修改该节点的p->password，
再将修改后的链表存到文件中，需要注意的是修改之后再存到文件中需要将该文件中的内容
清空*/ 
void amend_password()        //修改密码 
{ 
	system("cls");         //清屏 
	system("color 74");    //看着舒服的颜色 
	HideCursor();  
	Accp p,head;       //隐藏光标，看着更舒服 
	head=ff();
	FILE *fp;
    do
    {
    	HideCursor();       //隐藏光标，看着舒服 
    	p=head;
    	char password[18],newpassword[18],t,k;
    	int i=0;
    	toxy(50,5);          //将光标移动到坐标为（50，5）的位置 
		printf("个人财务管理软件");
		toxy(50,8);
		printf("修改密码");
		toxy(48,10);
		printf("请输入旧密码：");
		for(;;)              //此处为输入密码不回显操作 
		{
			k=getch();       //输入k 
			if(k=='\r')      //如果输入k为回车，则跳出循环 
			{
				break;
			}
			else if(k=='\b')  //如果输入k为删除键 
			{
				if(i>0)       //如若密码还没完全删除 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //如果输入的k既不是删除键，也不是回车键 
			{
				password[i]=k;   //把k的值赋给_password[i]; 
				printf("*");      //输出*号，保护用户隐私 
				i++;              //密码位数加1 
			}
		}
		password[i]='\0';
		i=0;
		toxy(48,12);
		printf("请输入新密码：");
		for(;;)              //此处为输入密码不回显操作 
		{
			k=getch();       //输入k 
			if(k=='\r')      //如果输入k为回车，则跳出循环 
			{
				break;
			}
			else if(k=='\b')  //如果输入k为删除键 
			{
				if(i>0)       //如若密码还没完全删除 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //如果输入的k既不是删除键，也不是回车键 
			{
				newpassword[i]=k;   //把k的值赋给_password[i]; 
				printf("*");      //输出*号，保护用户隐私 
				i++;              //密码位数加1 
			}
		}
		newpassword[i]='\0';
		while(p!=NULL&&strcmp(p->name,_name)!=0)//遍历链表，寻找当前登陆账户的账号 
		{
			p=p->next;
		}
		if(p!=NULL)                   //如果p不为空 
		{
			if(strcmp(p->password,password)==0)          //如果旧密码输入正确 
			{
				strcpy(p->password,newpassword);         //将旧密码改为新密码 
				break;                                   //跳出循环 
			}
			else                                         //如果旧密码输入错误 
			{
				system("cls");
				system("color 72");
				toxy(46,8);
				printf("--------------------------");
				toxy(46,9);
				printf("|                        |");
				toxy(46,10);
				printf("|  密码错误！是否继续？  |");
				toxy(46,11);
				printf("|                        |");
				toxy(46,12);
				printf("|  1.是           2.否   |");
				toxy(46,13);
				printf("|                        |");
				toxy(46,14);
				printf("--------------------------");
				while(1)
				{
					t=getch();                              //输入t 
					if(t=='1')
					{
						system("cls");
						system("color 72");
						break;
					}
					else if(t=='2')
					  menu();
				}
			}
		}
	}while(1);                                //永远为真 
	p=head->next;                           //使p指向第二个结点 
	fp=fopen("account","w");                  //先清空原文件内容再将修改后的信息写入文件 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	if(fwrite(head,N,1,fp)!=1)                 //将head所指向的数据写入fp所指向的文件 
	{
		printf("file write error\n");
	}
	fclose(fp);                         //关闭文件 
	fp=fopen("account","a");          // 打开account文件，方式为追加 
	while(p!=NULL)                    //p不为空就执行循环体 
	{
		if(fwrite(p,N,1,fp)!=1)            //将p所指向的1个大小为N的数据结构写入fp所指向的文件 
	    {
		printf("file write error\n");
	    }
	    p=p->next;                     //使p指向下一个结点 
	}
	fclose(fp);              //关闭文件 
	toxy(48,14);
	printf("修改成功！正在跳转...");
	Sleep(500);       //暂停0.5秒 
}

 
void save_account(Accp p1)     //将p1所指向的内容存储到文件中 
{
	FILE *fp;       //文件指针 
	fp=fopen("account","a");    //以追加的方式打开文件 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	if(fwrite(p1,N,1,fp)!=1)    //将p1所指向的1个大小为N的数据结构写入fp所指向的文件中 
	{
		printf("file write error\n");
	}
	fclose(fp);        //关闭文件 
}

IAEP ss()             //将存账单的文件里的内容输出到链表中 
{
	FILE *fp;              //文件指针
	int n=0; 
	IAEP head=NULL;
	IAEP p,p2,pr=NULL;
	fp=fopen(_name,"rb");//打开文件，方式为只读 
	if(fp==NULL)            //如果打开为空 
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))         // feof函数可以检查文件读写位置标志是否移动到文件末尾，feof(fp)检查fp所指向的文件是否结束，如果是 
	{                        //则函数值为真，否则为假，即"!feof(fp)"为真，在while循环中检查 "!feof(fp)"为真，就执行循环体 
	   n++;
	   p=(IAEP)malloc(M);   //向内存申请一段空间 
	   fread(p,M,1,fp);      //从fp所指向的文件读入1个大小为M的数据，存储到p所指向的空间中 
	   if(n==1) 
	   {
	      head=p;
	      p2=p;
	      head->pre=NULL;
	      
	    }
	    else                //创建双向链表 
	    {
	    	pr=p2;          //pr是p的前驱结点 
	    	p->pre=p2;
	    	p2->next=p;
	    	p2=p;
		}
    }
    if(pr!=NULL)
    {
	    pr->next=NULL;
	}
	fclose(fp);
	return head;
 }
 
void add_information()     //添加信息 
{
	do
	{
		system("cls");              //清屏 
		system("color 75");       //颜色 
		HideCursor();             //隐藏光标 
		IAEP p;                    
		char t;            
		toxy(50,5); 
		printf("个人账户管理软件");
		p=(IAEP)malloc(M);         //申请一段大小为M 的空间 
		toxy(44,8);
		printf("请输入金额：");
		scanf("%f",&p->iae);
		getchar();              //吸收回车键 
		toxy(44,10);
		printf("请输入收支类型（-代表支出，+代表收入）："); 
		scanf("%c",&p->ch);
		getchar();
		toxy(44,12);
		printf("请输入时间（年 月 日）：");
		scanf("%d%d%d",&p->year,&p->month,&p->day);
		getchar();
		toxy(44,14);
		printf("请输入收入来源或支出目的：");
		gets(p->source_or_aim); 
		save_information(p);             //保存p到文件中 
		toxy(44,16);
		printf("正在保存....");
		Sleep(500);               //暂停0.5秒 
		system("cls");
		system("color 73");
		toxy(46,8);
	    printf("-------------------------");
	    toxy(46,9);
		printf("|                       |");
		toxy(46,10);
		printf("| 保存成功！是否继续？  |");
		toxy(46,12);
		printf("| 1.是             2.否 |");
		toxy(46,13);
		printf("|                       |");
		toxy(46,14);
		printf("-------------------------");
		while(1)     
		{
			t=getch();  //输入t    
			if(t=='1')          
			{ 
				break;
			}
			else if(t=='2')     //如果输入t为2，进入菜单 
			{
				menu();break;
			}
		}
	}while(1);  //永远为真 
}

void print_information()     //输出账单 
{
	system("cls");         //清屏 
	system("color 76");    //看着舒服的颜色 
	HideCursor();          //隐藏光标，看着更舒服 
	FILE *fp;              //文件指针 
	int n=0; 
	int i=12;
	char t;
	float sum=0,sum1=0,sum2=0;
	IAEP head=NULL;
	IAEP p,p2,pr=NULL;
	fp=fopen(_name,"rb");//打开文件，方式为只读 
	if(fp==NULL)            //如果打开为空 
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))         // feof函数可以检查文件读写位置标志是否移动到文件末尾，feof(fp)检查fp所指向的文件是否结束，如果是 
	{                        //则函数值为真，否则为假，即"!feof(fp)"为真，在while循环中检查 "!feof(fp)"为真，就执行循环体 
	   n++;
	   p=(IAEP)malloc(M);   //向内存申请一段空间 
	   fread(p,M,1,fp);      //从fp所指向的文件读入1个大小为M的数据，存储到p所指向的空间中 
	   if(n==1) 
	   {
	      head=p;
	      p2=p;
	      head->pre=NULL;
	      
	    }
	    else                //创建双向链表 
	    {
	    	pr=p2;          //pr是p的前驱结点 
	    	p->pre=p2;
	    	p2->next=p;
	    	p2=p;
		}
		//printf("%d.%d.%-12d%c%-24f%s\n",p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
    }
    fclose(fp);             //关闭fp所指向的文件
    toxy(50,5);
	printf("个人账户管理软件");
	toxy(54,7);
	printf("账单明细(按0返回)");
	toxy(30,8);
	printf("----------------------------------------------------------------");
	toxy(30,9);
	printf("时     间          金   额                 收入来源或支出目的");
	toxy(30,10);
	printf("----------------------------------------------------------------");
	if(pr!=NULL)
	{ 
	    pr->next=NULL; 
	    p=pr;
		while(p!=NULL)
		{
			toxy(30,i);
			printf("%d.%d.%-12d%c%-24f%s\n",p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
			if(p->ch=='+')
			{
				sum1+=p->iae;
			}
			else if(p->ch=='-')
			{
				sum2-=p->iae;
			}
			sum=sum1+sum2;
			i++;
			p=p->pre;
		}
		toxy(30,11);
		printf("总   计： %f    总支出： %f    总收入： %f",sum,sum2,sum1);
	}
	else if(pr==NULL)
	{
		toxy(50,11);
		printf("您还没记录任何信息哦~");
	}
	while(1)
	{
		t=getch();
		if(t=='0')
		{
			menu();break;
		}
	}
 } 

void find_information()     //查找信息
{
	
	system("cls");         //清屏 
	system("color 77");    //看着舒服的颜色 
	HideCursor();          //隐藏光标，看着更舒服 
	int i=15;
	char t;
	int year,month,day;
	IAEP p;
	p=ss();
	toxy(50,5);
	printf("个人账户管理软件");
	toxy(54,7);
	printf("查找信息");
	toxy(40,9);
	printf("请输入您要查找的信息（输入年月日，空格隔开）：");
	toxy(50,10);
	scanf("%d%d%d",&year,&month,&day);
	getchar(); 
	toxy(30,12);
	printf("----------------------------------------------------------------");
	toxy(30,13);
	printf("时     间          金   额                 收入来源或支出目的");
	toxy(30,14);
	printf("----------------------------------------------------------------");
	while(p!=NULL)
	{
		if(p->year==year&&p->month==month&&p->day==day)
		{
			toxy(30,i);
		    printf("%d.%d.%-12d%c%-24f%s\n",p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
		    i++;
		}
		p=p->next;
	}
	if(i==15)
	{
		toxy(50,i);
		printf("没有找到相应的信息~");
	}
	toxy(54,i+1);
	printf("按0返回主菜单！");
	while(1)
	{
		t=getch();
		if(t=='0')
		{
			menu();break;
		}
	}
 } 
 

void delete_information()    //删除信息 
{
	do{
		system("cls");
		system("color 79");
		HideCursor();                 //隐藏光标 
		FILE *fp;           //文件指针 
		int year,month,day,i,j;
		int c;
		char t,k,ch; 
		IAEP p,head,pr=NULL;
		head=ss();                  //调用ss()函数，将该函数的返回值赋给head 
		toxy(50,5);
		printf("个人账户管理软件");
		toxy(54,7);
		printf("删除信息");
		toxy(40,9);
		printf("请输入您要查找的信息（输入年月日，空格隔开）：");
		toxy(50,10);
		scanf("%d%d%d",&year,&month,&day);       //输入年月日 
		toxy(30,12);
		printf("----------------------------------------------------------------");
		toxy(30,13);
		printf("时     间          金   额                 收入来源或支出目的");
		toxy(30,14);
		printf("----------------------------------------------------------------");
		i=15;j=0;            //给i，j初始化 
		p=head;               //注意，再次使p重新指向第一个结点，不要忘了 
		while(p!=NULL)
		{
			if(p->year==year&&p->month==month&&p->day==day)
			{
				toxy(28,i);
				j++;                        //j是标记被搜索的信息 
			    printf("%d: %d.%d.%-12d%c%-24f%s\n",j,p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
			    p->num=j;                   //将j赋值给p->num 
			    i++;
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			toxy(50,i);
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();
				if(ch=='0')
				{
					menu();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			toxy(50,i);
			printf("请输入您要删除的信息的标号：");
			scanf("%d",&c);
			getchar();
			i++;
			if(c<=j)              //如果c<=j，即输入正确 
			    break;
			else if(c>j)         //否则，输入错误 
			{
				toxy(50,i);
				printf("没有找到您所要删除的信息，请重新输入！");
				i++;
				Sleep(500);      //暂停0.5秒 
			}
		}
		toxy(46,16);
		printf("-------------------------");
		toxy(46,17);
		printf("|                       |");
		toxy(46,18);
		printf("|       确认删除？      |");
		toxy(46,19);
		printf("| 1.确认         2.取消 |");
		toxy(46,20);
		printf("|                       |");
		toxy(46,21);
		printf("-------------------------");
		while(1)
		{
			p=head;               //每一次遍历链表之前，记得将p指向头结点 
			pr=NULL;
			t=getch();             //输入t 
			if(t=='1')                           //如果输入t=1，即选择确认删除选项 
			{
				while(p!=NULL&&p->num!=c)
				{
					pr=p;                     //pr记录p的前驱结点 
					p=p->next;               //p指向下一节点 
				}
				if(p!=NULL)
				{
					if(pr==NULL)                //如果pr=NULL，即删除的结点为第一个结点 
					{                                 
						head=p->next;
					}
					else                         //否则，删除其他结点 
					{
						pr->next=p->next;
					}
				}
				free(p);                  //释放p 
				break;                   //跳出循环 
			}
			else if(t=='2')              //如果输入t=2，即选择取消删除选项 
			{
				system("cls");         //清屏 
				toxy(46,8);
				printf("------------------------------");
				toxy(46,9);
				printf("|                            |");
				toxy(46,10);
				printf("|  返回删除界面还是回主菜单  |");
				toxy(46,11);
				printf("| 1.删除界面      2.主菜单   |");
				toxy(46,12);
				printf("|                            |");
				toxy(46,13);
				printf("------------------------------");
				while(1)                    //死循环为了防止其他按键的干扰 
				{
					k=getch();               //输入K 
					if(k=='1')
					    break;
					else if(k=='2')        //如果输入k=2，回到主菜单 
					    menu();
				}
				if(k=='1')
				   break;
			}
		}
		if(t=='1')                  
		{                            
			fp=fopen(_name,"wb");                  //先清空原文件内容再将修改后的信息写入文件 
			if(fp==NULL)
			{
				printf("cannot open file\n");
			}
			if(fwrite(head,M,1,fp)!=1)                 //将head所指向的数据写入fp所指向的文件 
			{
				printf("file write error\n");
			}
			fclose(fp);                         //关闭文件
			if(head!=NULL)                        //如果头指针不为空 
			{
				p=head->next;                //使p指向第二个结点 
				fp=fopen(_name,"ab");          // 打开文件，方式为追加 
				while(p!=NULL)                    //p不为空就执行循环体 
				{
					if(fwrite(p,M,1,fp)!=1)            //将p所指向的1个大小为N的数据结构写入fp所指向的文件 
				    {
					printf("file write error\n");
				    }
				    p=p->next;                     //使p指向下一个结点 
				}
				fclose(fp);              //关闭文件 
			}
			system("cls");
			system("color 75");
			toxy(48,16);
			printf("正在删除，请稍后....");
			Sleep(500);
			system("cls");
			toxy(48,16);
			printf("删除成功！自动跳转到菜单....");
			break;
		}
	}while(1);//永远为真 
	Sleep(500);
	menu();
}


void amend_information()   //修改信息 
{
	system("cls");         //清屏 
	system("color 79");    //看着舒服的颜色 
	HideCursor();          //隐藏光标，看着更舒服
	IAEP p,head;
	FILE *fp;
	int i=15,j=0,c; 
	int year,day,month,newyear,newday,newmonth;
	char source_or_aim[50];
	char ch,cc,t;
	int aie;
	head=ss();
	p=head;
	do
	{
		system("cls");
		toxy(50,5);
		printf("个人账户管理软件");
		toxy(54,7);
		printf("修改信息");
		toxy(40,9);
		printf("请输入您要修改的信息（输入年月日，空格隔开）：");
		toxy(50,10);
		scanf("%d%d%d",&year,&month,&day);
		getchar();
		toxy(30,12);
		printf("----------------------------------------------------------------");
		toxy(30,13);
		printf("时     间          金   额                 收入来源或支出目的");
		toxy(30,14);
		printf("----------------------------------------------------------------");
		i=15;j=0;
		while(p!=NULL)   //将每个结点的p->num都赋为0，以免后面数据干扰 
		{
			p->num=0;
			p=p->next;
		}
		p=head;      //重新让p指向head 
		while(p!=NULL)
		{
			if(p->year==year&&p->month==month&&p->day==day)
			{
				toxy(30,i);
				j++;
			    printf("%d: %d.%d.%-12d%c%-24f%s\n",j,p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
			    p->num=j;      //给p->num赋值，即给满足搜索要求的结点编号 
			    i++;
			}
			p=p->next;
		}
		if(j==0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{ 
			toxy(50,i);
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while(1)               //死循环是为了防止除0和1的其他按键干扰 
			{
				ch=getch();     
				if(ch=='0')
				{
					menu();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //如果输入的ch等于1，则结束本次循环 
			   continue;
		}
		while(1)
		{
			toxy(50,i);
			printf("请输入您要修改的信息的标号：");
			scanf("%d",&c);
			getchar();
			i++;  
			if(c<=j)              //如果c<=j，即输入正确 
			    break;
			else if(c>j)         //否则，输入错误 
			{
				toxy(50,i);
				printf("没有找到您所要修改的信息，请重新输入！");
				i++;
				Sleep(500);      //暂停0.5秒 
			}
		}
		p=head;      //让p重新指向head，即第一个结点 
		while(p!=NULL&&p->num!=c)    //遍历链表，寻找满足要求的结点 
		{
			p=p->next;
		}
		if(p!=NULL)      //如果寻找成功，进入修改部分 
		{
			system("cls");    //清屏 
			toxy(44,8);
			printf("请输入修改后的金额：");
			scanf("%d",&aie);getchar();p->iae=aie;
			toxy(44,10);
			printf("请输入收支类型（-代表支出，+代表收入）：");
			scanf("%c",&cc);getchar();p->ch=cc;
			toxy(44,12);
			printf("请输入时间（年 月 日）：");
			scanf("%d%d%d",&newyear,&newmonth,&newday);getchar();
			p->year=newyear;p->month=newmonth;p->day=newday;
			toxy(44,14);
			printf("请输入收入来源或支出目的：");
			gets(source_or_aim);
			strcpy(p->source_or_aim,source_or_aim);
			toxy(46,16);
			printf("-------------------------");
			toxy(46,17);
			printf("|                       |");
			toxy(46,18);
			printf("|     是否确认修改？    |");
			toxy(46,19);
			printf("| 1.确认         2.取消 |");
			toxy(46,20);
			printf("|                       |");
			toxy(46,21);
			printf("-------------------------");
			while(1)    //死循环为防止其他按键干扰 
			{
				t=getch();
				if(t=='1')
				   break;
				else if(t=='2')
				{
					menu();
				}
			 } 
			 if(t=='1')  //如果t等于1，则跳出循环 
			 {
			 	break; 
			 }
		}
	}while(1);
	p=head;     //p重新指向头节点 
	system("cls");
	toxy(44,12);
	printf("正在修改....");
	fp=fopen(_name,"wb");   //打开文件的同时清除文件内的内容 
	if(fp==NULL)
	{
		printf("cannot open file");
	}
	while(p!=NULL)
	{
		if(fwrite(p,M,1,fp)!=1)    //将p所指向的内容存入fp所指向的文件中 
		{
			printf("file write error\n");
		}
		p=p->next;
	}
	fclose(fp);     //关闭文件 
	Sleep(500);
	system("cls");
	toxy(44,12);
	printf("修改成功！正在自动跳转到主菜单....");
	Sleep(500);
	menu();
}


void save_information(IAEP p)    //保存信息 
{
	FILE *fp;       //文件指针 
	fp=fopen(_name,"ab");    //以追加的方式打开文件 
	if(fp==NULL)
	{
		printf("cannot open file\n");
		
	}
	if(fwrite(p,M,1,fp)!=1)    //将p所指向的1个大小为M的数据结构写入fp所指向的文件中 
	{
		printf("file write error\n");
	}
	fclose(fp);        //关闭文件
 } 
 
void over()       //退出软件 
{
	char t;
	toxy(48,11);
	printf("-----------------------");
	toxy(48,12);
	printf("|   您确定要退出吗？  |");
	toxy(48,14);
	printf("| 1.确定     2.取消   |");
	toxy(48,15);
	printf("-----------------------");
	while(1)
	{
		t=getch();         //输入t
		switch(t)
		{
			case '1':
			system("cls");
		    system("color 78");
			toxy(48,10);
			printf("正在安全退出....");
			Sleep(1000);     //暂停1秒 
			system("cls");
			system("color 75");
			toxy(48,10);
			printf("已安全退出软件");
			toxy(48,12);
			printf("谢谢使用！");
			toxy(48,14);
			printf("by-by^_^");
			exit(0);  break; //终止程序 
			case '2':
			menu(); break;   //调用函数，进入菜单 
			default :break;
		}
	}
}

main()      //简单明了的主函数^~^ 
{
	signin(); //调用函数 
}
