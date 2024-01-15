// https://www.acmicpc.net/problem/15965
// 2024-01-16 05:47:37
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    const int siz=10000000;
    vector<int> prime_table(siz+1, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i<siz; i++)
        if(prime_table[i]) {
            for(int j=i+i; j<siz; j+=i)
                prime_table[j]=0;
        }

    for(int i=0; i<siz; i++)
    {
        if(prime_table[i]) n--;
        if(!n) return !printf("%d", i);
    }
}

/*
    
*/