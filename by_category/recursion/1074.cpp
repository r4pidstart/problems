// https://www.acmicpc.net/problem/1074
// 2022-03-17 00:21:18 0ms
#include<bits/stdc++.h>
using namespace std;

long long dc(long long siz, int r, int c)
{
    if(siz==1) return 0;

    if(siz/2 > r and siz/2 > c) // left top
        return dc(siz/2, r, c);
    else if(siz/2 > r and siz/2 <= c) // right top
        return siz*siz/4 + dc(siz/2, r, c-siz/2);
    else if(siz/2 <= r and siz/2 > c) // left bot
        return 2*siz*siz/4 + dc(siz/2, r-siz/2, c);
    else
        return 3*siz*siz/4 + dc(siz/2, r-siz/2, c-siz/2);
}

int main(void)
{
    int N,r,c; scanf("%d%d%d", &N, &r, &c);
    int siz=1;
    while(N--) siz*=2;
    printf("%lld", dc(siz, r, c));
}

/*
    
*/