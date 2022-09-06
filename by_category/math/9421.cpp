// https://www.acmicpc.net/problem/9421
// 2022-09-07 00:14:52 40ms
#include"bits/stdc++.h"
using namespace std;

int check(int now)
{
    static map<int,int> m;
    if(now == 1)
        return 2;
    if(m[now] == 1)
        return 1;
    else if(m[now] == 2)
        return 2;
    
    int next=0;
    int tmp=now;
    while(tmp)
        next+=(tmp%10) * (tmp%10), tmp/=10;
    m[now]=1;
    return m[now] = check(next);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> is_prime(n+1, 1);
    is_prime[0]=0, is_prime[1]=0;

    for(int i=2; i*i<=n; i++)
    {
        if(is_prime[i])
            for(int j=i*2; j<=n; j+=i)
                is_prime[j]=0;
    }

    for(int i=1; i<=n; i++)
    {
        if(is_prime[i])
            if(check(i) == 2)
                printf("%d\n", i);
    }
    
}

/*
    
*/