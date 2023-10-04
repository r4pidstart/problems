// https://www.acmicpc.net/problem/1322
// 2023-10-05 00:06:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long x,k; scanf("%ld%ld", &x, &k);
    
    bitset<64> X(x),Y(0),K(k);
    int k_cur=0;
    for(int i=0; i<64; i++)
        if(!X[i])   
            Y[i]=K[k_cur++];

#ifdef LOCAL
    cout << X << '\n' << Y << '\n' << K << '\n';
#endif
    printf("%ld", Y.to_ulong());
}

/*
    
*/