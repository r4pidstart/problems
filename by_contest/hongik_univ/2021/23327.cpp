// https://www.acmicpc.net/problem/23327
// 2021-11-04 03:31:46 H
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,q; scanf("%d%d", &n,&q);
    vector<long long> p_sum(n+1), square_p_sum(n+1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        p_sum[i+1]=p_sum[i]+a;
        square_p_sum[i+1]=square_p_sum[i]+a*a;
    }

    while(q--)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%lld\n", ((long long)(p_sum[b]-p_sum[a-1])*(p_sum[b]-p_sum[a-1])-square_p_sum[b]+square_p_sum[a-1])/2);
    }    
}

/*
    
*/