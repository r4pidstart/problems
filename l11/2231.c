#include<stdio.h>

int main(void)
{
    int n, s[8]={0,},tmp=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {   
        int carry=1, i=0;
        while(carry)
        {
            if(s[i]==9)
                s[i++]=0;
            else
            {
                s[i]++;
                carry=0;
            }
        }

        tmp = s[0]+s[1]*10+s[2]*100+s[3]*1000+s[4]*10000+s[5]*100000+s[6]*1000000;
        if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+tmp==n)
            break;
        tmp=0;
    }
    printf("%d", tmp);
}

