// https://www.acmicpc.net/problem/2455
// 2022-03-16 00:14:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int cnt=0, ans=0;
    for(int i=0; i<4; i++)
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