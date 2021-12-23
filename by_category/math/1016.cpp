// https://www.acmicpc.net/problem/1016
// 2021-12-24 05:01:47 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long s,e; scanf("%lld%lld", &s,&e);
    vector<int> prime(e-s+1, 1);

    // 2~sqrt(e)-1
    // i*i보다 작은 수로 나누어 떨어지면 !제곱ㄴㄴ수
    for(long long i=2; i*i<=e; i++)
    {
        long long m=s/(i*i)*(i*i);
        if(m<s) m+=i*i;
        for(; m<=e; m+=i*i)
            prime[m-s]=0;
    }

    printf("%d", accumulate(prime.begin(), prime.end(), 0));
}

/*

*/