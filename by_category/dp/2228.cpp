// https://www.acmicpc.net/problem/2228
// 2021-09-20 23:15:48 0ms
#include<bits/stdc++.h>
using namespace std;

const int INF=-9999999;
vector<int> arr, prefix_sum;
vector<vector<int> > memo;

// n개의 원소 중 m개의 구간 최대 합 구하기.
int dp(int n, int m)
{
    if(m==0) return 0;
    if(n<=0) return INF+1;
    if(memo[n][m] != INF) return memo[n][m];

    int ret=dp(n-1, m);
    for(int i=1; i<=n; i++) // 현재 구간 시작점
        ret=max(ret, dp(i-2, m-1)+prefix_sum[n]-prefix_sum[i-1]);
    return memo[n][m]=ret;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    memo.assign(n+1, vector<int>(m+1, INF));
    arr.assign(n+1, 0), prefix_sum.assign(n+1, 0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);

    for(int i=1; i<=n; i++)
        prefix_sum[i]=prefix_sum[i-1]+arr[i];

    printf("%d", dp(n,m));
    return 0;
}

/*
    
*/