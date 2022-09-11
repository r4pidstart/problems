// https://www.acmicpc.net/problem/16563
// 2022-09-12 01:03:13 1084ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    vector<int> prime_table(5000001, 1), primes;
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<=5000000; i++)
        for(int j=i*2; j<=5000000; j+=i)
            prime_table[j]=0;
    for(int i=0; i<5000000; i++)
        if(prime_table[i])
            primes.push_back(i);

    int n; scanf("%d", &n);
    while(n--)
    {
        int k; scanf("%d", &k);

        for(auto i : primes)
        {
            if(prime_table[k])
                printf("%d ", k), k=1;
            int sq=sqrt(k);
            if(sq*sq == k and prime_table[sq])
                printf("%d %d", sq, sq), k=1;
            while(k%i==0)
            {
                k/=i;
                printf("%d ", i);
                if(k < i)
                    break;
            }
            if(k < i)
                break;
        }
        printf("\n");
    }
}

/*
    
*/