// https://www.acmicpc.net/problem/1983
// 2022-03-19 03:35:18 328ms
#include<bits/stdc++.h>
using namespace std;

int dp(int i, int j, int k,  vector<int>& up, vector<int>& down,
    vector<vector<vector<int> > >& memo)
{
    if(i>k or j>k) return INT32_MIN;
    if(i==0 or j==0 or k==0) return 0;
    if(memo[i][j][k] != INT32_MIN/2) return memo[i][j][k];

    // i번째를 0이랑 곱하거나, j번째를 0이랑 곱하거나, i번째랑 j번째를 곱하거나.
    return memo[i][j][k]=max({dp(i-1, j, k-1, up, down, memo), 
        dp(i, j-1, k-1, up, down, memo), dp(i-1, j-1, k-1, up, down, memo) + up[i-1]*down[j-1]});
}

int main(void)
{
    // 수를 전부 밀어놓고 하나씩 가져와보자.
    int n; scanf("%d", &n);

    vector<int> up, down;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a) up.push_back(a);
    }
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a) down.push_back(a);
    }

    // dp[i][j][k] : 각각 i,j번째 수까지 사용하고, k번째 칸까지 사용했을 때의 최댓값
    vector<vector<vector<int> > > memo(n+1, vector<vector<int> >(n+1, vector<int>(n+1, INT32_MIN/2)));
    printf("%d", dp(up.size(), down.size(), n, up, down, memo));
}

/*
    
*/