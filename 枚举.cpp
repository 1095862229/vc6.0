#include<stdio.h> 
void main() 
{ 
    int a,b,c,d,e,f=4,g; 
    char s[7][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; 
    int i; 
        for(a=1;a<8;a++) 
        for(b=1;b<8;b++) 
        for(c=1;c<8;c++) 
        for(d=1;d<8;d++) 
        for(e=1;e<8;e++) 
        for(g=1;g<8;g++) 
        { 
            if((a==c+1)&&(d==e+2)&&(b==g-3)&&((f>b&&f<c)||(f<b&&f>c))&&(a!=b)&&(a!=c)&&(a!=d)&&(a!=e)&&(a!=f)&&(a!=g)&&(b!=c)&&(b!=d)&&(b!=e)&&(b!=f)&&(b!=g)&&(c!=d)&&(c!=e)&&(c!=f)&&(c!=g)&&(d!=e)&&(d!=f)&&(d!=g)&&(f!=g)) 
                { 
                    printf("Doctor A is on duty %s.\n",s[a-1]); 
                 printf("Doctor B is on duty %s.\n",s[b-1]); 
                printf("Doctor C is on duty %s.\n",s[c-1]); 
                 printf("Doctor D is on duty %s.\n",s[d-1]); 
                  printf("Doctor E is on duty %s.\n",s[e-1]); 
                printf("Doctor F is on duty %s.\n",s[f-1]); 
                printf("Doctor G is on duty %s.\n",s[g-1]); 
                } 
  
  
        } 
} 