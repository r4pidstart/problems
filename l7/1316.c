#include <stdio.h>
#include <string.h>

int main(void)
{   
    int N,n=0;
    scanf("%d", &N);
    while(N--!=0)
    {
        char s[101]={0,}, x[26]={0,};
        scanf("%s", s);
        int l=strlen(s), flag=0;
        for (int i=0; i<l; i++)
        {
            if(x[s[i]-'a']==0)
            {                                    
                x[s[i]-'a']++;
            }
            else if(s[i]!=s[i-1])
            {
                flag++;
                break;
            }

        }
        if (flag==0)
            n++;
    }
    printf("%d", n);
}