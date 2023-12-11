// https://www.acmicpc.net/problem/1709
// 2023-12-10 21:25:04
#include"bits/stdc++.h"
using namespace std;

long get_dist_0(long x, long y)
{
    return x*x + y*y;
}
int main(void)
{
#ifdef LOCAL
#endif
    long n; scanf("%ld", &n);

    long cnt=0;
    int x=0, y=n/2-1;

    while(x<n and y>=0)
    {
        cnt++;
        if(get_dist_0(x+1, y) < n*n/4) x++;
        else if(get_dist_0(x+1, y) > n*n/4) y--;
        else x++, y--;
    }

    printf("%ld", cnt*4);
}

/*
    
*/