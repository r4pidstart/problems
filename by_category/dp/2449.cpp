// https://www.acmicpc.net/problem/2449
// 2021-09-24 04:22:39 12ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > memo;
vector<int> bulbs;

int dp(int l, int r)
{
    if(l==r) return 0;
    if(memo[l][r]!=-1) return memo[l][r];
    
    int ret=INT32_MAX;
    for(int i=0; l+i<r; i++)
        ret=min(ret, dp(l,l+i)+dp(l+i+1,r)+(bulbs[l]!=bulbs[l+i+1]));

    return memo[l][r]=ret;
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    memo.assign(n, vector<int>(n, -1));
    bulbs.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &bulbs[i]);
    printf("%d", dp(0,n-1));
}

/*
    
*/