// https://www.acmicpc.net/problem/1720
// 2023-07-15 00:01:48
#include"bits/stdc++.h"
using namespace std;

long total(int n)
{
    static vector<long> dp(n+1, -1);
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];

    long ret=0;
    ret+=total(n-1); // 1*2
    ret+=total(n-2)*2; // 2*1 and 2*2

    return dp[n]=ret;
}

long mirror(int n)
{
    static vector<long> dp(n+1, -1);
    if(n==0 || n==1) return 1;
    if(n==2) return 3;
    if(n<0) return 0;
    if(dp[n] != -1) return dp[n];

    long ret=0;
    ret+=mirror(n-2);
    ret+=mirror(n-4)*2;

    return dp[n]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long a=total(n), b=mirror(n);
    printf("%ld", (a-b)/2+b);
    #ifdef LOCAL
        printf("\n%d %d", total(n), mirror(n));
    #endif
}

/*
    
*/