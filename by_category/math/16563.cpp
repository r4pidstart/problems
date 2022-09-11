// https://www.acmicpc.net/problem/16563
// 2022-09-12 01:03:13 924ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    vector<int> prime_table(5000001, 0);
    for(int i=2; i<=5000000; i++)
        if(!prime_table[i])
            for(int j=i; j<=5000000; j+=i)
                if(!prime_table[j])
                    prime_table[j]=i;

    int n; scanf("%d", &n);
    while(n--)
    {
        int k; scanf("%d", &k);
        while(k != 1)
        {
            printf("%d ", prime_table[k]);
            k/=prime_table[k];
        }
        printf("\n");
    }
}

/*
    
*/