// https://www.acmicpc.net/problem/17208
// 2023-11-26 05:13:45
#include"bits/stdc++.h"
using namespace std;

int ans(int idx, int m, int k, vector<pair<int,int> >& arr)
{
    static vector<vector<vector<int> > > memo(arr.size()+1, vector<vector<int> >(m+1, vector<int>(k+1, -1)));
    
    if(idx == arr.size()) return 0;
    if(memo[idx][m][k] != -1)
        return memo[idx][m][k];

    int ret=0;
    if(m>=arr[idx].first and k>=arr[idx].second)
        ret=max(ret, ans(idx+1, m-arr[idx].first, k-arr[idx].second, arr)+1);
    
    return memo[idx][m][k]=max(ret, ans(idx+1, m, k, arr));
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);

    printf("%d", ans(0, m, k, arr));
}

/*
    
*/