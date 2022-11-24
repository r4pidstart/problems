// https://www.acmicpc.net/problem/17245
// 2022-11-25 03:33:07
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<long> > table(n, vector<long>(n));
    long total=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%ld", &table[i][j]), total+=table[i][j];
    
    int lo=0, hi=10'000'000, ans=hi;
    while(lo<=hi)
    {
        long target=(lo+hi)/2;
        long tmp=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                tmp+=min(target, table[i][j]);
        
        if(tmp >= (total+1)/2)
            hi=target-1, ans=target;
        else
            lo=target+1;
    }
    printf("%d", ans);
}

/*
    
*/