// https://www.acmicpc.net/problem/1009
// 2021-12-15 00:38:29 796ms
#include<bits/stdc++.h>
using namespace std;

int ans(int a, int b)
{
    int ret=1;
    while(b--) 
        ret=(ret*a)%10;
    return ret==0 ? 10:ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d\n", ans(a,b));
    }
}

/*
    
*/