#include<stdio.h>
#include<string.h>

int reverse(char *s)
{
    for (int i=0, n=strlen(s); i<n/2; i++)
    {
        int tmp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=tmp;
    }
}

int main(void)
{
    char a[10002]={0,},b[10002]={0,},ans[10003]={0,};
    scanf("%s %s", a,b);
    reverse(a);
    reverse(b);
    int carry=0, n=strlen(a)>strlen(b)? strlen(a):strlen(b);
    for(int i=0; i<n; i++)
    {
        ans[i]=a[i]+b[i]+carry-2*'0';
        while(ans[i]<0)
            ans[i]+='0';
        if(ans[i]>9)
            carry=1;
        else
            carry=0;
        ans[i]=ans[i]%10+'0';
    }
    if(carry==1)
        ans[n]='1';
    reverse(ans);
    printf("%s", ans);
}