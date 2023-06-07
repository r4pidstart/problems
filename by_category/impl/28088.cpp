// https://www.acmicpc.net/problem/28088
// 2023-06-08 02:14:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > arr(2, vector<int>(n));
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        arr[0][a]=1;
    }

    for(int t=0; t<k; t++)
    {
        for(int i=0; i<n; i++)
            arr[(t&1)^1][i]=arr[t&1][(i+1)%n] ^ arr[t&1][(i-1+n)%n];
    }

    printf("%d", accumulate(arr[k&1].begin(), arr[k&1].end(), 0));
}

/*
    
*/