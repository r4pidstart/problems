// https://www.acmicpc.net/problem/11442
// 2023-03-17 22:23:25
#include"bits/stdc++.h"
using namespace std;

const int MOD=1'000'000'007;
struct matrix{ long long a,b,c,d; };

inline matrix operator*(const matrix& A, const matrix& B)
{ return { (A.a*B.a+A.b*B.c)%MOD, (A.a*B.b+A.b*B.d)%MOD, 
           (A.c*B.a+A.d*B.c)%MOD, (A.c*B.b+A.d*B.d)%MOD}; }

matrix pow_matrix(long long n)
{
    matrix ret=(n&1) ? matrix({1,1,1,0}):matrix({1,0,0,1});
    matrix dp={1,1,1,0};
    for(long long i=2; i<=n; i<<=1)
    {
        dp=dp*dp;
        if(n&i) ret=ret*dp;
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    long n; scanf("%ld", &n);
    printf("%ld", pow_matrix(n+(n&1)).b);
}

/*

*/