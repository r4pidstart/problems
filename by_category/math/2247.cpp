// https://www.acmicpc.net/problem/2247
// 2024-03-11 00:04:12
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    long ans=0;
    for(int i=2; i<=n/2; i++)
        ans=(ans+((n-i-i+1)+(i-1))/i*i)%int(1e6);


    printf("%ld", ans);
}

/*

*/