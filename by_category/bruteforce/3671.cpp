// https://www.acmicpc.net/problem/3671
// 2023-03-03 02:51:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int c; scanf("%d", &c);

    vector<int> prime_table(10'000'000, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<10'000'000; i++)
        if(prime_table[i])
            for(int j=i+i; j<10'000'000; j+=i)
                prime_table[j]=0;
            
    vector<int> primes;
    for(int i=2; i<10'000'000; i++)
        if(prime_table[i])
            primes.push_back(i);

    vector<vector<int> > arr(c, vector<int>(10));
    vector<int> cnt(c);
    for(int i=0; i<c; i++)
    {
        string s; cin >> s;
        for(int it : s)
            arr[i][it-'0']++;
    }

    for(int prime : primes)
    {
        vector<int> tmp(10);
        while(prime) tmp[prime%10]++, prime/=10;
        for(int i=0; i<c; i++)
        {
            int flag=0;
            for(int j=0; j<10; j++)
                if(tmp[j]>arr[i][j])
                    flag=1;
            cnt[i]+=!flag;
        }
    }

    for(int i : cnt)
        printf("%d\n", i);
}

/*
    
*/