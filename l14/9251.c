#include<stdio.h>
#include<string.h>

#define big(x,y) ( (x)>(y)?(x):(y) )

int main(void)
{
    char s1[1001], s2[1001];
    scanf("%s", s1);
    scanf("%s", s2);

    int memo[1001][1001];
    for(int i=0, l1=strlen(s1); i<l1; i++)
        for(int j=0, l2=strlen(s2); j<l2; j++)
        {
            if(s1[i]==s2[j])
                memo[i+1][j+1]=memo[i][j]+1;
            else
                memo[i+1][j+1]=big(memo[i][j+1], memo[i+1][j]);
        }

    printf("%d", memo[strlen(s1)][strlen(s2)]);
}