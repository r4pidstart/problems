#include<stdio.h>
#include<string.h>

int main(void)
{
    int t; scanf("%d", &t);
    char tmp[51];
    while(t--)
    {   
        int check=0;
        scanf("%s", tmp);
        for(int i=0; i<strlen(tmp); i++)
        {
            if(tmp[i] == '(')
                check++;
            else if(tmp[i] == ')')
                check--;
            
            if(check<0)
                break;
        }
        printf("%s\n", check ? "NO":"YES");
    }
}
