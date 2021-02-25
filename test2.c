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

int main(void)
{
    char a[10002], b[10002];
    char ans[10003];
    scanf("%s%s",a,b);

    reverse(a);
    reverse(b);
    
    for(int i=0, n=strlen(a)>strlen(b) ? strlen(a):strlen(b); i<n; i++)
    {
        if(ans[i] + a[i]-'0' + b[i]-'0' > 9)
        {
            ans[i]+=a[i]-'0'+b[i]-'0'-10+1;
            ans[i+1]++;
        }
        else
        {
            if(a[i]==0 || b[i]==0)
            {
                if(ans[i] + a[i]-'0' + b[i] > 9)
                    {
                        ans[i]+=a[i]-'0'+b[i]-10+1;
                        ans[i+1]++;
                    }
                else
                    ans[i]+=a[i]-'0' + b[i]+1;
            }
            else
                ans[i]+=a[i]-'0' + b[i]-'0'+1;
        }
    }
    if (ans[strlen(ans)-1]==1)
        ans[strlen(ans)-1]++;

    for(int i=strlen(ans)-1; i>=0; i--)
    {
        int tmp=ans[i]-1;
        printf("%i", tmp);
    }
}