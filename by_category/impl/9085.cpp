// https://www.acmicpc.net/problem/9085
// 2022-03-25 00:45:13 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        int a; scanf("%d", &a);
        int ans=0;
        while(a--)
        {
            int tmp; scanf("%d", &tmp);
            ans+=tmp;
        }
        printf("%d\n", ans);
    }
}

/*
    
*/