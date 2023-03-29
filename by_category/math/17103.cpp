// https://www.acmicpc.net/problem/17103
// 2023-03-30 00:42:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    vector<int> prime_table(1000000, 1);
    prime_table[0]=prime_table[1]=0;
    for(long i=2; i*i<1000000; i++)
        for(int j=i+i; j<1000000; j+=i)
            prime_table[j]=0;
    while(t--)
    {
        int cnt=0, n;
        scanf("%d", &n);
        for(int i=2; i<=n/2; i++)
            if(prime_table[i] and prime_table[n-i]) cnt++;
        printf("%d\n", cnt);
    }
}

/*
    
*/