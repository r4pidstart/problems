// https://www.acmicpc.net/problem/1476
// 2021-12-06 23:54:46 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int e,s,m; scanf("%d%d%d", &e,&s,&m);
    int ans=1, a=0, b=0, c=0;
    while(a!=e-1 or b!=s-1 or c!=m-1)
    {
        a=(a+1)%15, b=(b+1)%28, c=(c+1)%19;
        ans++;
    }
    printf("%d", ans);
}

/*
    
*/