// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cout.tie(NULL)->sync_with_stdio(false);
    int n,m; scanf("%d%d", &n, &m);
    vector<long> ans(n+m);
    for(int i=0; i<n; i++)
        scanf("%d", &ans[i]);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+m; j++)
        {
            int a; scanf("%d", &a);
            ans[i]-=a;
            ans[j]+=a;
        }
    }

    for(long i : ans)
        printf("%ld ", i);
}

/*
    
*/