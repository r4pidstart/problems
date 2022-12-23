// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long n, a, pa, b, pb; 
    scanf("%ld%ld%ld%ld%ld", &n, &a, &pa, &b, &pb);
    long tmpmax=-1;
    int ans1=0, ans2=0;
    for(int i=0; i*pa <= n; i++)
    {
        int remain = n - i*pa;
        long tmp=i*a + remain/pb*b;
        if(tmp > tmpmax)
            ans1=i, ans2=remain/pb, tmpmax=tmp;
    }
    printf("%d %d", ans1, ans2);
}

/*
    
*/