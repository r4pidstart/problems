// https://www.acmicpc.net/problem/1173
// 2022-03-14 21:28:25 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int N,m,M,T,R; scanf("%d%d%d%d%d", &N,&m,&M,&T,&R);
    int t=0, h=m, cnt=0;
    if(h+T > M) return !printf("-1");
    while(cnt < N)
    {
        t++;
        if(h+T > M)
            h=max(m, h-R);
        else
        {
            cnt++;
            h+=T;
        }
    }
    printf("%d", t);
}

/*
    
*/