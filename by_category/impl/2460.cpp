// https://www.acmicpc.net/problem/2460
// 2022-03-24 23:59:57 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int cnt=0, ans=0;
    for(int i=0; i<10; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        cnt-=a;
        cnt+=b;
        ans=max(ans, cnt);
    }
    printf("%d", ans);
}

/*
    
*/