// https://www.acmicpc.net/problem/1222
// 2023-07-13 03:10:23
#include"bits/stdc++.h"
using namespace std;

// a^b
int logpow(int a, int b)
{
    if(b==0) return 1;

    int tmp=logpow(a, b/2);
    if(b&1) return tmp*tmp*a;
    return tmp*tmp;
}

void get_factor(int now, map<int,int>::iterator it, map<int,int>& prime_factor, 
    vector<int>& divisor_cnt)
{
    if(it == prime_factor.end())
    {
        divisor_cnt[now]++;
        return;
    }

    for(int i=0; i<=it->second; i++)
        get_factor(now*logpow(it->first, i), next(it), prime_factor, divisor_cnt);
}

int main(void)
{

#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    
    vector<int> prime_table(2000001,1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<2000001; i++)
        if(prime_table[i])
            for(int j=i+i; j<2000001; j+=i)
                prime_table[j]=0;
                
    vector<int> primes;
    for(int i=2; i<2000001; i++)
        if(prime_table[i]) primes.push_back(i);

    vector<int> divisor_cnt(2000001);

    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        map<int, int> prime_factor;
        for(auto p : primes)
        {
            if(prime_table[a]) prime_factor[a]++, a=1;
            int sq=sqrt(a);
            if(sq*sq==a and prime_table[a]) prime_factor[sq]+=2, a=1;
            while(!(a%p))
                prime_factor[p]++, a/=p;
            if(a<p) break;
        }

        get_factor(1, prime_factor.begin(), prime_factor, divisor_cnt);
    }

    long ans=0;
    for(long i=1; i<2000001; i++)
        if(divisor_cnt[i]>1)
            ans=max(ans, divisor_cnt[i]*i);
    printf("%ld", ans);
}

/*
    
*/