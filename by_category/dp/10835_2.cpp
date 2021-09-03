// https://www.acmicpc.net/problem/10835
// 2021-09-04 00:55:09 140ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > memo;
vector<int> le,ri;
int ans=0,n;

int dp(int l, int r)
{
    if(l==n || r==n) return memo[l][r]=0;
    if(memo[l][r]!=-1) return memo[l][r];

    int ret=0;
    if(le[l]>ri[r]) ret=max(dp(l, r+1)+ri[r], ret);
    ret=max(dp(l+1, r), ret);
    ret=max(dp(l+1, r+1), ret);

    return memo[l][r]=ret;
}

int main(void)
{
    scanf("%d", &n);
    memo.assign(n+1, vector<int>(n+1,-1));
    le=ri=vector<int>(n+1,0);
    for(int i=0; i<n; i++)
        scanf("%d", &le[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &ri[i]);

    printf("%d", dp(0,0));
}

/*

*/