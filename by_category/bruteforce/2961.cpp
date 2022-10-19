// https://www.acmicpc.net/problem/2961
// 2022-10-20 03:34:01 0ms
#include"bits/stdc++.h"
using namespace std;

long dfs(int now, int lim, vector<pair<int,int> >& arr, long sour, long bitter)
{
    if(now == lim)
        return !bitter ? LLONG_MAX : abs(sour-bitter);
    
    return min(dfs(now+1, lim, arr, sour*arr[now].first, bitter+arr[now].second),
               dfs(now+1, lim, arr, sour, bitter));
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    printf("%ld", dfs(0, n, arr, 1, 0));
}

/*
    
*/