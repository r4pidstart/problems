// https://www.acmicpc.net/problem/23250
// 2021-10-14 06:07:42 0ms
#include<bits/stdc++.h>
using namespace std;

void findK(int n, int s, int e, int v, long long k)
{
    long long tmp=1LL<<(n-1);

    if(tmp==k) printf("%d %d", s, e);
    else if(tmp>k) findK(n-1, s, v, e, k);
    else findK(n-1, v, e, s, k-tmp);
}

int main(void)
{ 
    long long n,k; scanf("%lld%lld", &n,&k);
    // n개를 옮기는데 필요한 횟수 -> 2^n -1
    findK(n, 1, 3, 2, k);
}

/*
    
*/