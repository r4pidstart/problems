// https://www.acmicpc.net/problem/30189
// 2023-09-27 22:49:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int ans=0;
    for(int i=0; i<=n+m; i++)
    {
        for(int x=0; x<=n; x++)
            for(int y=0; y<=m; y++)
                if(x+y==i) ans++;
    }
    printf("%d", ans);
}

/*
    0<=x<=a
    0<=y<=b
    x+y=c
*/