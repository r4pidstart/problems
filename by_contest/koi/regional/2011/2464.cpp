// https://www.acmicpc.net/problem/2464
// 2022-05-08 14:24:55 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long long n; scanf("%lld", &n);

    //long long small=n, large=n;
    // int bitcnt=__builtin_popcountll(n);
    // while(__builtin_popcountll(--small) != bitcnt and small>0);
    // while(__builtin_popcountll(++large) != bitcnt);
    bitset<64> num=n;
    vector<int> small(64), large(64);
    for(int i=0; i<64; i++)
        small[63-i]=large[63-i]=num[i];
    prev_permutation(small.begin(), small.end());
    next_permutation(large.begin(), large.end());

    for(int i=0; i<64; i++)
        num[i]=small[63-i];
    
    if(num[63]) printf("0 ");
    else printf("%ld ", num.to_ullong());

    for(int i=0; i<64; i++)
        num[i]=large[63-i];
    
    printf("%ld", num.to_ullong());
}

/*
    
*/