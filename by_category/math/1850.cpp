// https://acmicpc.net/problem/1850
// 2021-12-19 04:47:32 84ms

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a,b; scanf("%lld%lld", &a, &b);
    long long n=gcd(a,b);
    for(int i=0; i<n; i++)
        printf("1");
}
