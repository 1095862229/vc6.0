#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h> 
#include<time.h>
#define N sizeof(struct Account)   //�궨�� 
#define M sizeof(struct income_and_expenditure)

struct income_and_expenditure      //��֧��� 
{
	float iae;     //�����֧�� 
	char ch;    //-�Ŵ���֧����+�Ŵ������� 
	int year;    //������ 
	int month;
	int day;
	int num;    //��� 
	char source_or_aim[50];    // ������Դ��֧��Ŀ�� 
	struct income_and_expenditure *next;       // ָ���� ����� 
	struct income_and_expenditure *pre;   //ǰ�� 
};
typedef struct income_and_expenditure IAE;   
typedef IAE *IAEP;


struct Account       //�˻���Ϣ 
{
	char name[10];       //�˺��ǳ� 
	char password[18];       //���� 
	struct Account *next;   //ָ���� 
};
typedef struct Account Acc;
typedef Acc *Accp;

//�ö��Զ��庯��~~
Accp ff();                     //�����˺ŵ��ļ�������������������
IAEP ss();                   //�����˵����ļ������������������� 
void signin();               //��½��ע�� 
void login();                 // ע���˺� 
void logon();                  // �˺ŵ�½  
void menu();                 //�˵� 
void over();                  //�˳�ϵͳ 
void color(short x);                 //������ɫ 
void HideCursor();          //���ع��
void toxy(int x, int y);    //������ƶ���X,Y���괦
void amend_password();         //�޸����� 
void add_information();       //�����Ϣ 
void print_information();     //�˵���ϸ 
void find_information();     //������Ϣ 
void delete_information();   //ɾ����Ϣ 
void amend_information();    //�޸���Ϣ 
void save_account(Accp p);    //�����˺�
void save_information(IAEP p); //������Ϣ 


char _name[20],_password[18];       //ȫ�ֱ�����ס��ǰ��½�˻� 


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

void HideCursor()     //���ع��
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //������ƶ���X,Y���괦
{
COORD pos = { x , y };
HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(Out, pos); 
}

Accp ff()               //�����˺ŵ��ļ�������������������
{
	FILE *fp;       //�ļ�ָ�� 
	int n=0;
	Accp head=NULL;
	Accp p2,p;
	fp=fopen("account","r");     //��ֻ���ķ�ʽ���ļ� 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
	   n++;
	   	p=(Accp)malloc(N);
	   fread(p,N,1,fp);
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //�������� 
	    {
	    	p2->next=p;
	    	p2=p;
		}
    }
    p2->next=NULL;
    fclose(fp);
    return head;
}


void menu()     //�˵� 
{
	system("cls");    //���� 
	system("color 70");
	do{
		char t;
		toxy(50,5);
		printf(" ���˲���������");
		toxy(50,6);
		printf("��ǰ�˻�Ϊ��%s",_name);
		toxy(48,8);
		printf("|     1.�����Ϣ      |");
		toxy(48,10);
		printf("|     2.�޸���Ϣ      |");
		toxy(48,12);
		printf("|     3.ɾ����Ϣ      |");
		toxy(48,14);
		printf("|     4.�˵���ϸ      |");
		toxy(48,16);
		printf("|     5.������Ϣ      |");
		toxy(48,18);
		printf("|     6.�޸�����      |"); 
		toxy(48,20);
		printf("|     7.�˳�ϵͳ      |");
		t=getch();                    //���ò����Ժ���������t�����Բ����ֶ����س��� 
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
    }while(1);       //��ԶΪ�� 
}

void signin()       //��½��ע�� 
{
	system("cls");
	HideCursor();    //���ع��
	char t;
	color(2);
	toxy(50,5);
	printf("���˲���������");
	toxy(44,8);
	printf("****************************");
	toxy(45,10);
	printf("�����루1����½��2��ע��.)");
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

void logon()      // �˺ŵ�½ 
{
	system("cls");
	HideCursor();
	Accp p,head;
	head=ff();
    do{
    	HideCursor();       //���ع�� 
    	color(12);
	    p=head;
	    char t,c,k;
	    int i=0;
		toxy(50,5);
		printf("���˲���������");
		toxy(45,6);
		printf("--------------------------");
		toxy(45,8);
		printf("     ��½״̬       ");
		toxy(45,10);
		printf("*  �����������˺ţ�");
		gets(_name);
		toxy(45,12);
		printf("*  �������������룺");
		for(;;)              //�˴�Ϊ�������벻���Բ��� 
		{
			k=getch();       //����k 
			if(k=='\r')      //�������kΪ�س���������ѭ�� 
			{
				break;
			}
			else if(k=='\b')  //�������kΪɾ���� 
			{
				if(i>0)       //�������뻹û��ȫɾ�� 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
			{
				_password[i]=k;   //��k��ֵ����_password[i]; 
				printf("*");      //���*�ţ������û���˽ 
				i++;              //����λ����1 
			}
		}
		_password[i]='\0';
		while(p!=NULL&&strcmp(p->name,_name)!=0)   //��������Ѱ�ҵ�ǰ������˻����˺� 
		{
			p=p->next;
		}
		if(p!=NULL)   //���p��Ϊ�� 
		{
	    	if(strcmp(p->password,_password)==0)     //��������������ȷ 
			{
				toxy(48,16);
				printf("���ڵ�½....");
				Sleep(500);      //��ͣ0.5��
				system("cls");
				system("color 72");
				toxy(48,10);
				printf("��½�ɹ���");
				break;    //����ѭ��
			}
			else      //���������������
			{ 
				toxy(48,16);
				printf("���ڵ�½....");
				Sleep(500);
				system("cls");
				system("color 72");
				toxy(46,8);
				printf("-------------------------");
				toxy(46,9);
				printf("|                       |");
				toxy(46,10);
				printf("| ��������Ƿ������  |");
				toxy(46,12);
				printf("| 1.��             2.�� |");
				toxy(46,13);
				printf("|                       |");
				toxy(46,14);
				printf("-------------------------");
				while(1)
				{
					t=getch();  //����t    
					if(t=='1')          
					{
						system("cls");  //���� 
						system("color 72"); 
						break;
					}
					else if(t=='2')     //�������tΪn�����뿪ʼ���� 
					{
						signin();break;
					}
				}
			} 
	   }
	   else              //���pΪ�գ���������˺Ų���ȷ 
	   {
	   	    toxy(48,16);
	   	    printf("���ڵ�½....");
	   	    Sleep(500);
	   	    system("cls");
	   	    system("color 72");
	   	    toxy(46,8);
	   	    printf("-------------------------");
	   	    toxy(46,9);
	   	    printf("|                       |");
	   		toxy(46,10);
			printf("|  �˺Ŵ����Ƿ������ |");
			toxy(46,11);
			printf("|                       |");
			toxy(46,12);
			printf("|  1.��            2.�� |"); 
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
    }while(1);      //��ԶΪ�� 
   Sleep(500);      //��ͣ0.5�� 
   menu();         //�˺��������ȷ���������˵� 
}

void login()        //ע���˺� 
{
	system("cls");
	HideCursor();       //���ع�� 
	Accp p1;
	p1=(Accp)malloc(N);     //���ڴ�����һ�οռ� 
	do{
		HideCursor();
		color(11);
		char name[20],password[18],againpassword[18],c,k;
		int i=0;; 
		toxy(50,5);
		printf("���˲���������");
		toxy(45,6);
		printf("-------------------------");
		toxy(45,8);
		printf("   ����ע��");
		toxy(45,10);
		printf("*  �������˺ţ�");
		gets(name);
		toxy(45,12);
		printf("*  ���������룺");
		for(;;)              //�˴�Ϊ�������벻���Բ��� 
		{
			k=getch();       //����k 
			if(k=='\r')      //�������kΪ�س���������ѭ�� 
			{
				break;
			}
			else if(k=='\b')  //�������kΪɾ���� 
			{
				if(i>0)       //�������뻹û��ȫɾ�� 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
			{
				password[i]=k;   //��k��ֵ����_password[i]; 
				printf("*");      //���*�ţ������û���˽ 
				i++;              //����λ����1 
			}
		}
		password[i]='\0';
		i=0;
		toxy(45,14);
		printf("*  ��ȷ���������룺");
		for(;;)              //�˴�Ϊ�������벻���Բ��� 
		{
			k=getch();       //����k 
			if(k=='\r')      //�������kΪ�س���������ѭ�� 
			{
				break;
			}
			else if(k=='\b')  //�������kΪɾ���� 
			{
				if(i>0)       //�������뻹û��ȫɾ�� 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
			{
				againpassword[i]=k;   //��k��ֵ����_password[i]; 
				printf("*");      //���*�ţ������û���˽ 
				i++;              //����λ����1 
			}
		}
		againpassword[i]='\0';
		if(strcmp(password,againpassword)==0)        //�������������������ȷ 
		{
			strcpy(p1->name,name);
			strcpy(p1->password,password);
			toxy(48,16);
			printf("����ע��....");
			Sleep(500);
			system("cls");
			system("color 72");
			toxy(48,10);
			printf("ע��ɹ���");
			Sleep(500);         //��ͣ0.5�� 
			break;              //����ѭ�� 
		}
		else    //���������������벻ͬ 
		{
			toxy(48,16);
			printf("����ע��....");
			Sleep(500);
			system("cls");
			system("color 72");
			toxy(46,8);
			printf("-----------------------------");
			toxy(46,9);
			printf("|                           |");
			toxy(46,10);
			printf("|  ע��ʧ�ܣ��Ƿ����ע�᣿ |");
			toxy(46,11);
			printf("|                           |");
			toxy(46,12);
			printf("|  1.��               2.��  |"); 
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
	}while(1);    //��ԶΪ�� 
	save_account(p1);     //���ú�������p1��ָ������ݴ洢���ļ��� 
	toxy(48,12);
	printf("�����Զ�Ϊ����½....");
	Sleep(500);
	menu();    //ע��ɹ���������˵� 
}

/*�޸�����
�����Ƚϱ����������Ƚ��������ļ��е��˻���Ϣ
�����һ�������У���������Ѱ�ҵ�ǰ��½���˻��˺ţ��޸ĸýڵ��p->password��
�ٽ��޸ĺ������浽�ļ��У���Ҫע������޸�֮���ٴ浽�ļ�����Ҫ�����ļ��е�����
���*/ 
void amend_password()        //�޸����� 
{ 
	system("cls");         //���� 
	system("color 74");    //�����������ɫ 
	HideCursor();  
	Accp p,head;       //���ع�꣬���Ÿ���� 
	head=ff();
	FILE *fp;
    do
    {
    	HideCursor();       //���ع�꣬������� 
    	p=head;
    	char password[18],newpassword[18],t,k;
    	int i=0;
    	toxy(50,5);          //������ƶ�������Ϊ��50��5����λ�� 
		printf("���˲���������");
		toxy(50,8);
		printf("�޸�����");
		toxy(48,10);
		printf("����������룺");
		for(;;)              //�˴�Ϊ�������벻���Բ��� 
		{
			k=getch();       //����k 
			if(k=='\r')      //�������kΪ�س���������ѭ�� 
			{
				break;
			}
			else if(k=='\b')  //�������kΪɾ���� 
			{
				if(i>0)       //�������뻹û��ȫɾ�� 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
			{
				password[i]=k;   //��k��ֵ����_password[i]; 
				printf("*");      //���*�ţ������û���˽ 
				i++;              //����λ����1 
			}
		}
		password[i]='\0';
		i=0;
		toxy(48,12);
		printf("�����������룺");
		for(;;)              //�˴�Ϊ�������벻���Բ��� 
		{
			k=getch();       //����k 
			if(k=='\r')      //�������kΪ�س���������ѭ�� 
			{
				break;
			}
			else if(k=='\b')  //�������kΪɾ���� 
			{
				if(i>0)       //�������뻹û��ȫɾ�� 
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
			}
			else              //��������k�Ȳ���ɾ������Ҳ���ǻس��� 
			{
				newpassword[i]=k;   //��k��ֵ����_password[i]; 
				printf("*");      //���*�ţ������û���˽ 
				i++;              //����λ����1 
			}
		}
		newpassword[i]='\0';
		while(p!=NULL&&strcmp(p->name,_name)!=0)//��������Ѱ�ҵ�ǰ��½�˻����˺� 
		{
			p=p->next;
		}
		if(p!=NULL)                   //���p��Ϊ�� 
		{
			if(strcmp(p->password,password)==0)          //���������������ȷ 
			{
				strcpy(p->password,newpassword);         //���������Ϊ������ 
				break;                                   //����ѭ�� 
			}
			else                                         //���������������� 
			{
				system("cls");
				system("color 72");
				toxy(46,8);
				printf("--------------------------");
				toxy(46,9);
				printf("|                        |");
				toxy(46,10);
				printf("|  ��������Ƿ������  |");
				toxy(46,11);
				printf("|                        |");
				toxy(46,12);
				printf("|  1.��           2.��   |");
				toxy(46,13);
				printf("|                        |");
				toxy(46,14);
				printf("--------------------------");
				while(1)
				{
					t=getch();                              //����t 
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
	}while(1);                                //��ԶΪ�� 
	p=head->next;                           //ʹpָ��ڶ������ 
	fp=fopen("account","w");                  //�����ԭ�ļ������ٽ��޸ĺ����Ϣд���ļ� 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	if(fwrite(head,N,1,fp)!=1)                 //��head��ָ�������д��fp��ָ����ļ� 
	{
		printf("file write error\n");
	}
	fclose(fp);                         //�ر��ļ� 
	fp=fopen("account","a");          // ��account�ļ�����ʽΪ׷�� 
	while(p!=NULL)                    //p��Ϊ�վ�ִ��ѭ���� 
	{
		if(fwrite(p,N,1,fp)!=1)            //��p��ָ���1����СΪN�����ݽṹд��fp��ָ����ļ� 
	    {
		printf("file write error\n");
	    }
	    p=p->next;                     //ʹpָ����һ����� 
	}
	fclose(fp);              //�ر��ļ� 
	toxy(48,14);
	printf("�޸ĳɹ���������ת...");
	Sleep(500);       //��ͣ0.5�� 
}

 
void save_account(Accp p1)     //��p1��ָ������ݴ洢���ļ��� 
{
	FILE *fp;       //�ļ�ָ�� 
	fp=fopen("account","a");    //��׷�ӵķ�ʽ���ļ� 
	if(fp==NULL)
	{
		printf("cannot open file\n");
	}
	if(fwrite(p1,N,1,fp)!=1)    //��p1��ָ���1����СΪN�����ݽṹд��fp��ָ����ļ��� 
	{
		printf("file write error\n");
	}
	fclose(fp);        //�ر��ļ� 
}

IAEP ss()             //�����˵����ļ������������������� 
{
	FILE *fp;              //�ļ�ָ��
	int n=0; 
	IAEP head=NULL;
	IAEP p,p2,pr=NULL;
	fp=fopen(_name,"rb");//���ļ�����ʽΪֻ�� 
	if(fp==NULL)            //�����Ϊ�� 
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))         // feof�������Լ���ļ���дλ�ñ�־�Ƿ��ƶ����ļ�ĩβ��feof(fp)���fp��ָ����ļ��Ƿ����������� 
	{                        //����ֵΪ�棬����Ϊ�٣���"!feof(fp)"Ϊ�棬��whileѭ���м�� "!feof(fp)"Ϊ�棬��ִ��ѭ���� 
	   n++;
	   p=(IAEP)malloc(M);   //���ڴ�����һ�οռ� 
	   fread(p,M,1,fp);      //��fp��ָ����ļ�����1����СΪM�����ݣ��洢��p��ָ��Ŀռ��� 
	   if(n==1) 
	   {
	      head=p;
	      p2=p;
	      head->pre=NULL;
	      
	    }
	    else                //����˫������ 
	    {
	    	pr=p2;          //pr��p��ǰ����� 
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
 
void add_information()     //�����Ϣ 
{
	do
	{
		system("cls");              //���� 
		system("color 75");       //��ɫ 
		HideCursor();             //���ع�� 
		IAEP p;                    
		char t;            
		toxy(50,5); 
		printf("�����˻��������");
		p=(IAEP)malloc(M);         //����һ�δ�СΪM �Ŀռ� 
		toxy(44,8);
		printf("�������");
		scanf("%f",&p->iae);
		getchar();              //���ջس��� 
		toxy(44,10);
		printf("��������֧���ͣ�-����֧����+�������룩��"); 
		scanf("%c",&p->ch);
		getchar();
		toxy(44,12);
		printf("������ʱ�䣨�� �� �գ���");
		scanf("%d%d%d",&p->year,&p->month,&p->day);
		getchar();
		toxy(44,14);
		printf("������������Դ��֧��Ŀ�ģ�");
		gets(p->source_or_aim); 
		save_information(p);             //����p���ļ��� 
		toxy(44,16);
		printf("���ڱ���....");
		Sleep(500);               //��ͣ0.5�� 
		system("cls");
		system("color 73");
		toxy(46,8);
	    printf("-------------------------");
	    toxy(46,9);
		printf("|                       |");
		toxy(46,10);
		printf("| ����ɹ����Ƿ������  |");
		toxy(46,12);
		printf("| 1.��             2.�� |");
		toxy(46,13);
		printf("|                       |");
		toxy(46,14);
		printf("-------------------------");
		while(1)     
		{
			t=getch();  //����t    
			if(t=='1')          
			{ 
				break;
			}
			else if(t=='2')     //�������tΪ2������˵� 
			{
				menu();break;
			}
		}
	}while(1);  //��ԶΪ�� 
}

void print_information()     //����˵� 
{
	system("cls");         //���� 
	system("color 76");    //�����������ɫ 
	HideCursor();          //���ع�꣬���Ÿ���� 
	FILE *fp;              //�ļ�ָ�� 
	int n=0; 
	int i=12;
	char t;
	float sum=0,sum1=0,sum2=0;
	IAEP head=NULL;
	IAEP p,p2,pr=NULL;
	fp=fopen(_name,"rb");//���ļ�����ʽΪֻ�� 
	if(fp==NULL)            //�����Ϊ�� 
	{
		printf("cannot open file\n");
	}
	while(!feof(fp))         // feof�������Լ���ļ���дλ�ñ�־�Ƿ��ƶ����ļ�ĩβ��feof(fp)���fp��ָ����ļ��Ƿ����������� 
	{                        //����ֵΪ�棬����Ϊ�٣���"!feof(fp)"Ϊ�棬��whileѭ���м�� "!feof(fp)"Ϊ�棬��ִ��ѭ���� 
	   n++;
	   p=(IAEP)malloc(M);   //���ڴ�����һ�οռ� 
	   fread(p,M,1,fp);      //��fp��ָ����ļ�����1����СΪM�����ݣ��洢��p��ָ��Ŀռ��� 
	   if(n==1) 
	   {
	      head=p;
	      p2=p;
	      head->pre=NULL;
	      
	    }
	    else                //����˫������ 
	    {
	    	pr=p2;          //pr��p��ǰ����� 
	    	p->pre=p2;
	    	p2->next=p;
	    	p2=p;
		}
		//printf("%d.%d.%-12d%c%-24f%s\n",p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
    }
    fclose(fp);             //�ر�fp��ָ����ļ�
    toxy(50,5);
	printf("�����˻��������");
	toxy(54,7);
	printf("�˵���ϸ(��0����)");
	toxy(30,8);
	printf("----------------------------------------------------------------");
	toxy(30,9);
	printf("ʱ     ��          ��   ��                 ������Դ��֧��Ŀ��");
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
		printf("��   �ƣ� %f    ��֧���� %f    �����룺 %f",sum,sum2,sum1);
	}
	else if(pr==NULL)
	{
		toxy(50,11);
		printf("����û��¼�κ���ϢŶ~");
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

void find_information()     //������Ϣ
{
	
	system("cls");         //���� 
	system("color 77");    //�����������ɫ 
	HideCursor();          //���ع�꣬���Ÿ���� 
	int i=15;
	char t;
	int year,month,day;
	IAEP p;
	p=ss();
	toxy(50,5);
	printf("�����˻��������");
	toxy(54,7);
	printf("������Ϣ");
	toxy(40,9);
	printf("��������Ҫ���ҵ���Ϣ�����������գ��ո��������");
	toxy(50,10);
	scanf("%d%d%d",&year,&month,&day);
	getchar(); 
	toxy(30,12);
	printf("----------------------------------------------------------------");
	toxy(30,13);
	printf("ʱ     ��          ��   ��                 ������Դ��֧��Ŀ��");
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
		printf("û���ҵ���Ӧ����Ϣ~");
	}
	toxy(54,i+1);
	printf("��0�������˵���");
	while(1)
	{
		t=getch();
		if(t=='0')
		{
			menu();break;
		}
	}
 } 
 

void delete_information()    //ɾ����Ϣ 
{
	do{
		system("cls");
		system("color 79");
		HideCursor();                 //���ع�� 
		FILE *fp;           //�ļ�ָ�� 
		int year,month,day,i,j;
		int c;
		char t,k,ch; 
		IAEP p,head,pr=NULL;
		head=ss();                  //����ss()���������ú����ķ���ֵ����head 
		toxy(50,5);
		printf("�����˻��������");
		toxy(54,7);
		printf("ɾ����Ϣ");
		toxy(40,9);
		printf("��������Ҫ���ҵ���Ϣ�����������գ��ո��������");
		toxy(50,10);
		scanf("%d%d%d",&year,&month,&day);       //���������� 
		toxy(30,12);
		printf("----------------------------------------------------------------");
		toxy(30,13);
		printf("ʱ     ��          ��   ��                 ������Դ��֧��Ŀ��");
		toxy(30,14);
		printf("----------------------------------------------------------------");
		i=15;j=0;            //��i��j��ʼ�� 
		p=head;               //ע�⣬�ٴ�ʹp����ָ���һ����㣬��Ҫ���� 
		while(p!=NULL)
		{
			if(p->year==year&&p->month==month&&p->day==day)
			{
				toxy(28,i);
				j++;                        //j�Ǳ�Ǳ���������Ϣ 
			    printf("%d: %d.%d.%-12d%c%-24f%s\n",j,p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
			    p->num=j;                   //��j��ֵ��p->num 
			    i++;
			}
			p=p->next;
		}
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			toxy(50,i);
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			toxy(50,i);
			printf("��������Ҫɾ������Ϣ�ı�ţ�");
			scanf("%d",&c);
			getchar();
			i++;
			if(c<=j)              //���c<=j����������ȷ 
			    break;
			else if(c>j)         //����������� 
			{
				toxy(50,i);
				printf("û���ҵ�����Ҫɾ������Ϣ�����������룡");
				i++;
				Sleep(500);      //��ͣ0.5�� 
			}
		}
		toxy(46,16);
		printf("-------------------------");
		toxy(46,17);
		printf("|                       |");
		toxy(46,18);
		printf("|       ȷ��ɾ����      |");
		toxy(46,19);
		printf("| 1.ȷ��         2.ȡ�� |");
		toxy(46,20);
		printf("|                       |");
		toxy(46,21);
		printf("-------------------------");
		while(1)
		{
			p=head;               //ÿһ�α�������֮ǰ���ǵý�pָ��ͷ��� 
			pr=NULL;
			t=getch();             //����t 
			if(t=='1')                           //�������t=1����ѡ��ȷ��ɾ��ѡ�� 
			{
				while(p!=NULL&&p->num!=c)
				{
					pr=p;                     //pr��¼p��ǰ����� 
					p=p->next;               //pָ����һ�ڵ� 
				}
				if(p!=NULL)
				{
					if(pr==NULL)                //���pr=NULL����ɾ���Ľ��Ϊ��һ����� 
					{                                 
						head=p->next;
					}
					else                         //����ɾ��������� 
					{
						pr->next=p->next;
					}
				}
				free(p);                  //�ͷ�p 
				break;                   //����ѭ�� 
			}
			else if(t=='2')              //�������t=2����ѡ��ȡ��ɾ��ѡ�� 
			{
				system("cls");         //���� 
				toxy(46,8);
				printf("------------------------------");
				toxy(46,9);
				printf("|                            |");
				toxy(46,10);
				printf("|  ����ɾ�����滹�ǻ����˵�  |");
				toxy(46,11);
				printf("| 1.ɾ������      2.���˵�   |");
				toxy(46,12);
				printf("|                            |");
				toxy(46,13);
				printf("------------------------------");
				while(1)                    //��ѭ��Ϊ�˷�ֹ���������ĸ��� 
				{
					k=getch();               //����K 
					if(k=='1')
					    break;
					else if(k=='2')        //�������k=2���ص����˵� 
					    menu();
				}
				if(k=='1')
				   break;
			}
		}
		if(t=='1')                  
		{                            
			fp=fopen(_name,"wb");                  //�����ԭ�ļ������ٽ��޸ĺ����Ϣд���ļ� 
			if(fp==NULL)
			{
				printf("cannot open file\n");
			}
			if(fwrite(head,M,1,fp)!=1)                 //��head��ָ�������д��fp��ָ����ļ� 
			{
				printf("file write error\n");
			}
			fclose(fp);                         //�ر��ļ�
			if(head!=NULL)                        //���ͷָ�벻Ϊ�� 
			{
				p=head->next;                //ʹpָ��ڶ������ 
				fp=fopen(_name,"ab");          // ���ļ�����ʽΪ׷�� 
				while(p!=NULL)                    //p��Ϊ�վ�ִ��ѭ���� 
				{
					if(fwrite(p,M,1,fp)!=1)            //��p��ָ���1����СΪN�����ݽṹд��fp��ָ����ļ� 
				    {
					printf("file write error\n");
				    }
				    p=p->next;                     //ʹpָ����һ����� 
				}
				fclose(fp);              //�ر��ļ� 
			}
			system("cls");
			system("color 75");
			toxy(48,16);
			printf("����ɾ�������Ժ�....");
			Sleep(500);
			system("cls");
			toxy(48,16);
			printf("ɾ���ɹ����Զ���ת���˵�....");
			break;
		}
	}while(1);//��ԶΪ�� 
	Sleep(500);
	menu();
}


void amend_information()   //�޸���Ϣ 
{
	system("cls");         //���� 
	system("color 79");    //�����������ɫ 
	HideCursor();          //���ع�꣬���Ÿ����
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
		printf("�����˻��������");
		toxy(54,7);
		printf("�޸���Ϣ");
		toxy(40,9);
		printf("��������Ҫ�޸ĵ���Ϣ�����������գ��ո��������");
		toxy(50,10);
		scanf("%d%d%d",&year,&month,&day);
		getchar();
		toxy(30,12);
		printf("----------------------------------------------------------------");
		toxy(30,13);
		printf("ʱ     ��          ��   ��                 ������Դ��֧��Ŀ��");
		toxy(30,14);
		printf("----------------------------------------------------------------");
		i=15;j=0;
		while(p!=NULL)   //��ÿ������p->num����Ϊ0������������ݸ��� 
		{
			p->num=0;
			p=p->next;
		}
		p=head;      //������pָ��head 
		while(p!=NULL)
		{
			if(p->year==year&&p->month==month&&p->day==day)
			{
				toxy(30,i);
				j++;
			    printf("%d: %d.%d.%-12d%c%-24f%s\n",j,p->year,p->month,p->day,p->ch,p->iae,p->source_or_aim);
			    p->num=j;      //��p->num��ֵ��������������Ҫ��Ľ���� 
			    i++;
			}
			p=p->next;
		}
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			toxy(50,i);
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
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
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			toxy(50,i);
			printf("��������Ҫ�޸ĵ���Ϣ�ı�ţ�");
			scanf("%d",&c);
			getchar();
			i++;  
			if(c<=j)              //���c<=j����������ȷ 
			    break;
			else if(c>j)         //����������� 
			{
				toxy(50,i);
				printf("û���ҵ�����Ҫ�޸ĵ���Ϣ�����������룡");
				i++;
				Sleep(500);      //��ͣ0.5�� 
			}
		}
		p=head;      //��p����ָ��head������һ����� 
		while(p!=NULL&&p->num!=c)    //��������Ѱ������Ҫ��Ľ�� 
		{
			p=p->next;
		}
		if(p!=NULL)      //���Ѱ�ҳɹ��������޸Ĳ��� 
		{
			system("cls");    //���� 
			toxy(44,8);
			printf("�������޸ĺ�Ľ�");
			scanf("%d",&aie);getchar();p->iae=aie;
			toxy(44,10);
			printf("��������֧���ͣ�-����֧����+�������룩��");
			scanf("%c",&cc);getchar();p->ch=cc;
			toxy(44,12);
			printf("������ʱ�䣨�� �� �գ���");
			scanf("%d%d%d",&newyear,&newmonth,&newday);getchar();
			p->year=newyear;p->month=newmonth;p->day=newday;
			toxy(44,14);
			printf("������������Դ��֧��Ŀ�ģ�");
			gets(source_or_aim);
			strcpy(p->source_or_aim,source_or_aim);
			toxy(46,16);
			printf("-------------------------");
			toxy(46,17);
			printf("|                       |");
			toxy(46,18);
			printf("|     �Ƿ�ȷ���޸ģ�    |");
			toxy(46,19);
			printf("| 1.ȷ��         2.ȡ�� |");
			toxy(46,20);
			printf("|                       |");
			toxy(46,21);
			printf("-------------------------");
			while(1)    //��ѭ��Ϊ��ֹ������������ 
			{
				t=getch();
				if(t=='1')
				   break;
				else if(t=='2')
				{
					menu();
				}
			 } 
			 if(t=='1')  //���t����1��������ѭ�� 
			 {
			 	break; 
			 }
		}
	}while(1);
	p=head;     //p����ָ��ͷ�ڵ� 
	system("cls");
	toxy(44,12);
	printf("�����޸�....");
	fp=fopen(_name,"wb");   //���ļ���ͬʱ����ļ��ڵ����� 
	if(fp==NULL)
	{
		printf("cannot open file");
	}
	while(p!=NULL)
	{
		if(fwrite(p,M,1,fp)!=1)    //��p��ָ������ݴ���fp��ָ����ļ��� 
		{
			printf("file write error\n");
		}
		p=p->next;
	}
	fclose(fp);     //�ر��ļ� 
	Sleep(500);
	system("cls");
	toxy(44,12);
	printf("�޸ĳɹ��������Զ���ת�����˵�....");
	Sleep(500);
	menu();
}


void save_information(IAEP p)    //������Ϣ 
{
	FILE *fp;       //�ļ�ָ�� 
	fp=fopen(_name,"ab");    //��׷�ӵķ�ʽ���ļ� 
	if(fp==NULL)
	{
		printf("cannot open file\n");
		
	}
	if(fwrite(p,M,1,fp)!=1)    //��p��ָ���1����СΪM�����ݽṹд��fp��ָ����ļ��� 
	{
		printf("file write error\n");
	}
	fclose(fp);        //�ر��ļ�
 } 
 
void over()       //�˳���� 
{
	char t;
	toxy(48,11);
	printf("-----------------------");
	toxy(48,12);
	printf("|   ��ȷ��Ҫ�˳���  |");
	toxy(48,14);
	printf("| 1.ȷ��     2.ȡ��   |");
	toxy(48,15);
	printf("-----------------------");
	while(1)
	{
		t=getch();         //����t
		switch(t)
		{
			case '1':
			system("cls");
		    system("color 78");
			toxy(48,10);
			printf("���ڰ�ȫ�˳�....");
			Sleep(1000);     //��ͣ1�� 
			system("cls");
			system("color 75");
			toxy(48,10);
			printf("�Ѱ�ȫ�˳����");
			toxy(48,12);
			printf("ллʹ�ã�");
			toxy(48,14);
			printf("by-by^_^");
			exit(0);  break; //��ֹ���� 
			case '2':
			menu(); break;   //���ú���������˵� 
			default :break;
		}
	}
}

main()      //�����˵�������^~^ 
{
	signin(); //���ú��� 
}
