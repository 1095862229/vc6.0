#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
int i, row = 0, line = 0,linenum = 0;
char a[1000];  //�ַ�
int number[1000][100];  //������
char mark[100][5];   //��ʶ����
char marknum[100][20];
int wordanalysis();
int main()
{
    int l = 0;
    int m = 0;
    i=0;
    FILE *fp;
    fp=fopen("D:\\text.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file!\n");
        exit(0);
    }
    while(!feof(fp))
    {
        a[l++] = fgetc(fp);
    }
    a[l] = '#';
    do
    {
        m=wordanalysis();
        switch(m)
        {
            case -1:i++;break;
            case 0 :i++;break;
            case 3 :i++;break;
        }
    }while(m!=0);
   
    _getch();
    return 0;
}
int wordanalysis()
{
    if((a[i]>='A' && a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
    {
        char word[10];
        char pro[100][100] = {"begin","if","then","while","do","end"};//������
        int n=0;
        word[n++] = a[i++];
        //���ַ�ΪA~Z��0~9���������ȡ
        while((a[i] >= 'A'&&a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9')||(a[i]>='a'&&a[i]<='z'))
        {
            word[n++] = a[i++];
        }
        word[n]='\0';
        i--;
        //�жϸñ�ʶ���Ƿ�Ϊ������
        for (n = 0; n < 100; n++)
        {
            if (strcmp(word, pro[n]) == 0)
            {
                printf("(%d,%s) ������\n",n+1,pro[n]);
                return 3;
            }
        }
       
        //�жϱ�ʶ�������Ƿ񳬳��涨
        if (strlen(word)>10)
        {
            printf("%s\tERROR\n",word);
            return 0;
        }
       
        //�жϸñ�ʶ���Ƿ���ڱ�ʶ������
        int m = 0;
        if (line != 0)
        {
            int q = 0;
            while (q<line)
            {
                if (strcmp(word, mark[q++]) == 0)
                {
                    printf("(11,%s) ��ʶ��\n", word);
                    return 3;
                }
            }
        }
        //���ñ�ʶ�����浽��ʶ������
        strcpy(mark[line], word);
        printf("(11, %s) ��ʶ��\n", word);
        line++;
        return 3;
    }
 else if (a[i] >= '0' && a[i] <= '9')  //��������
    {
  char x[100];
        int n = 0, sum;
        x[n++] = a[i++];
        //�ж��ַ��Ƿ���0~9
  while((a[i] >= 'A'&& a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9')||(a[i]>='a'&&a[i]<='z'))
        {
            x[n++] = a[i++];
        }
  x[n] = '\0';
        i--;
  //�жϸñ�ʶ���Ƿ���ڱ�ʶ������
        int m = 0;
        if (linenum != 0)
        {
            int q = 0;
            while (q<line)
            {
                if (strcmp(x, marknum[q++]) == 0)
                {
                    printf("(10,%s) ��ʶ��\n", x);
                    return 3;
                }
            }
        }
        //���ñ�ʶ�����浽��ʶ������
        strcpy(marknum[linenum], x);

        printf("(10,%s) ��ʶ��\n", x);
        linenum++;
        return 3;
    }
 else                      //��������
     
     switch (a[i])
    {
        case ' ':
        case '\n':
            return -1;
        case '#': return 0;
        case '=':printf("(10,=)\n"); return 3;
        case '<':
            i++;
            if (a[i] == '=')
            {
                printf("(22,<=)\n");
                return 3;
            }
            else if (a[i] == '>')
            {
                printf("(21,<>)\n");
                return 3;
            }
            else
            {
                i--;
                printf("(20,<)\n");
                return 3;
            }
        case '>':
            i++;
            if (a[i] == '=')
            {
                printf("(24,>=)\n");
                return 3;
            }
            else
            {
                i--;
                printf("(23,>)\n");
                return 3;
            }
        case '+': printf("(13,+)\n"); return 3;
        case '-': printf("(14,-)\n"); return 3;
        case '*': printf("(15,*)\n"); return 3;
        case '/': printf("(16,/)\n"); return 3;
        case ':': 
            i++;
            if(a[i]!='='){
                i--;
                printf("(17,:)\n"); return 3;
            }
            else
            {
                if(a[i++]=='\n')
                    return -1;
            }
                printf("(18,:=)\n");return 3;

            
        case ';': printf("(26,;)\n"); return 3;
        case '(': printf("(27,()\n"); return 3;
        case ')': printf("(28,))\n"); return 3;
    }   
}



 
