// https://www.acmicpc.net/problem/2904
// 2022-06-28 00:03:07 48ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> prime_table(1000001, 1), arr(n), primes;
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<1'000'001; i++)
    {
        if(prime_table[i])
            for(int j=i*2; j<1'000'001; j+=i)
                prime_table[j]=0;
    }

    for(int i=0; i<1000001; i++)
        if(prime_table[i]) primes.push_back(i);
    
    vector<int> factorization(primes.size(), 0);
    vector<vector<int> > factor_cnt(n, vector<int>(primes.size()));
    for(int i=0; i<n; i++)
    {
        int tmp=arr[i], idx=0;
        while(tmp != 1)
        {
            if(!(tmp%primes[idx]))
                tmp/=primes[idx], factorization[idx]++, factor_cnt[i][idx]++;
            else idx++;
        }
    }

    for(auto &it : factorization)
        it/=n; // 각 소수를 최대한 분배

    int move_cnt=0;
    for(int i=0; i<n; i++)
        for(int idx=0; idx<primes.size(); idx++)
        {
            move_cnt+=max(0, factorization[idx]-factor_cnt[i][idx]);
            // 부족한 소수 갯수
        }

    int ans=1;
    for(int i=0; i<primes.size(); i++)
            ans*=pow(primes[i], factorization[i]);

    printf("%d %d", ans, move_cnt);
}

/*

*/