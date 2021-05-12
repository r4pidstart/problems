// https://www.acmicpc.net/problem/15927
// 2021-05-11 23:50:07 8ms
#include<bits/stdc++.h>
using namespace std;

char s[500001];

int main(void)
{
    scanf("%s", s);
    int p1=0, p2=strlen(s)-1;

    while(p1<p2)
    {
        if(s[p1++]!=s[p2--]) // 회문이 아니면
        {
            printf("%ld", strlen(s));
            return 0;
        }
    }
    int prev=s[0];
    for(int i=1, l=strlen(s); i<l; i++)
    {
        if(prev!=s[i])
        {
            printf("%d", l-1);
            return 0;
        }
    }
    printf("-1");
}