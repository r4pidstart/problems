// https://www.acmicpc.net/problem/18222
// 2022-02-06 00:17:23 0ms
#include<bits/stdc++.h>
using namespace std;

int ans(long long k, int cnt)
{
    if(k==1) return !printf("%d", cnt);
    // k보다 작으면서 가장 큰 2^n 찾기
    long long target=1;
    while(target*2 < k)
        target*=2;
    return ans(k-target, cnt^1);
}

int main(void)
{
    long long k; scanf("%lld", &k);
    ans(k, 0);
}

/*
    
*/