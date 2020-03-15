#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
int i, row = 0, line = 0,linenum = 0;
char a[1000];  //字符
int number[1000][100];  //常数表
char mark[100][5];   //标识符表
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
        char pro[100][100] = {"begin","if","then","while","do","end"};//保留字
        int n=0;
        word[n++] = a[i++];
        //若字符为A~Z或0~9，则继续读取
        while((a[i] >= 'A'&&a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9')||(a[i]>='a'&&a[i]<='z'))
        {
            word[n++] = a[i++];
        }
        word[n]='\0';
        i--;
        //判断该标识符是否为保留字
        for (n = 0; n < 100; n++)
        {
            if (strcmp(word, pro[n]) == 0)
            {
                printf("(%d,%s) 保留字\n",n+1,pro[n]);
                return 3;
            }
        }
       
        //判断标识符长度是否超出规定
        if (strlen(word)>10)
        {
            printf("%s\tERROR\n",word);
            return 0;
        }
       
        //判断该标识符是否存在标识符表中
        int m = 0;
        if (line != 0)
        {
            int q = 0;
            while (q<line)
            {
                if (strcmp(word, mark[q++]) == 0)
                {
                    printf("(11,%s) 标识符\n", word);
                    return 3;
                }
            }
        }
        //将该标识符保存到标识符表中
        strcpy(mark[line], word);
        printf("(11, %s) 标识符\n", word);
        line++;
        return 3;
    }
 else if (a[i] >= '0' && a[i] <= '9')  //分析常数
    {
  char x[100];
        int n = 0, sum;
        x[n++] = a[i++];
        //判断字符是否是0~9
  while((a[i] >= 'A'&& a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9')||(a[i]>='a'&&a[i]<='z'))
        {
            x[n++] = a[i++];
        }
  x[n] = '\0';
        i--;
  //判断该标识符是否存在标识符表中
        int m = 0;
        if (linenum != 0)
        {
            int q = 0;
            while (q<line)
            {
                if (strcmp(x, marknum[q++]) == 0)
                {
                    printf("(10,%s) 标识符\n", x);
                    return 3;
                }
            }
        }
        //将该标识符保存到标识符表中
        strcpy(marknum[linenum], x);

        printf("(10,%s) 标识符\n", x);
        linenum++;
        return 3;
    }
 else                      //分析符号
     
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



 
