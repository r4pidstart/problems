// https://www.acmicpc.net/problem/2749
// 2021-12-21 06:35:41 0ms
#include<bits/stdc++.h>
using namespace std;

// ( 1 1 ) n  ( f(n+1) f(n) )
// ( 1 0 )    ( f(n) f(n-1) )

const int MOD=1'000'000;
struct matrix{ long long a,b,c,d; };

inline matrix operator*(const matrix& A, const matrix& B)
{ return {(A.a*B.a+A.b*B.c)%MOD, (A.a*B.b+A.b*B.d)%MOD, (A.c*B.a+A.d*B.c)%MOD, (A.c*B.b+A.d*B.d)%MOD}; }

map<long long, matrix> dp;
matrix pow_matrix(long long n)
{
    if(n==1) return {1,1,1,0};
    if(dp.find(n) != dp.end()) return dp[n];

    if(n&1) return dp[n]=pow_matrix(n/2)*pow_matrix(n/2)*pow_matrix(1);
    else return dp[n]=pow_matrix(n/2)*pow_matrix(n/2);
}

int main(void)
{
    long long n; scanf("%ld", &n);
    printf("%d", pow_matrix(n).b);
}

/*
    
*/