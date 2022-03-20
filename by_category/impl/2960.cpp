// https://www.acmicpc.net/problem/2960
// 2022-03-20 14:28:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);

    vector<int> prime_table(n+1, 1);
    int cnt=0;
    for(int i=2; i<=n; i++)
        for(int j=i; j<=n; j+=i)
            if(prime_table[j])
            {
                cnt++, prime_table[j]=0;
                if(cnt==k) printf("%d", j);
            }
}

/*
    
*/