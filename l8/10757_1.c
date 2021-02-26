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
    return 0;
}

int check_over_10(int *x)
{
    if(*x>9)
    {
        *x-=10;
        x++;
        *x+=1;
    }
    else
        return 0;
}

int main(void)
{
    char a[10002]={0,}, b[10002]={0,};
    scanf("%s%s", a,b);
    int ans[10003]={0,}, nbig=strlen(a)>strlen(b) ? strlen(a):strlen(b), nsmall=strlen(a)<strlen(b) ? strlen(a):strlen(b);
    int n=nbig;
    reverse(a);
    reverse(b);

    for(int i=0, j=nbig; i<j; i++)
    {
        if(nsmall--==0)
        {
            if(strlen(a)>strlen(b))
            {
                while(nbig--!=0)
                {
                    if(a[i]!=0)
                        ans[i]+=a[i]-'0';
                    else
                        ans[i]+=0;
                    check_over_10(&ans[i]);
                    i++;
                }
                break;
            }
            else
                while(nbig--!=0)
                {
                    if(b[i]!=0)
                        ans[i]+=b[i]-'0';
                    else
                        ans[i]+=0;
                    check_over_10(&ans[i]);
                    i++;
                }
                break;
        }
        nbig--;
        if(a[i]==0 || b[i]==0)
        {
            if(a[i]+b[i]==0)
                ans[i]+=0;
            else
                ans[i]+=a[i]+b[i]-'0';
                if(nbig!=0)
                    check_over_10(&ans[i]);
        }
        else
            ans[i]+=a[i]+b[i]-2*'0';
        if(nbig!=0)
            check_over_10(&ans[i]);
    }

    if (ans[n]!=0)
        for(int i=0; i<n+1; i++)
            printf("%d", ans[n-i]);
    else if(ans[n-1]==0)
        for(int i=1; i<n; i++)
            printf("%d", ans[n-i-1]);
    else
        for(int i=0; i<n; i++)
            printf("%d", ans[n-i-1]);
}