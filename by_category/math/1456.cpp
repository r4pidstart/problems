// https://www.acmicpc.net/problem/1456
// 2022-10-30 01:26:19
#include"bits/stdc++.h"
using namespace std;

using int = long;

int main(void)
{
    long a,b; scanf("%ld%ld", &a, &b);
    int cnt=0;
    vector<int> prime_table(10'000'000, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i<10'000'000; i++)
    {
        if(!prime_table[i]) continue;
        __int128_t tmp=(long)i*i;
        while(tmp<=b)
        {
            if(a <= tmp)
                cnt++;
            tmp*=i;
        }
        for(int j=i+i; j<10'000'000; j+=i)
            prime_table[j]=0;
    }
    printf("%d", cnt);
}

/*
    
*/