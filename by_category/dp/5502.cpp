// https://www.acmicpc.net/problem/5502
// 2023-09-07 00:12:21
#include"bits/stdc++.h"
using namespace std;

int ans(int s, int e, string& str)
{
    static vector<vector<int> > dp(e+1, vector<int>(e+1, -1));
    if(e<=s) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    int ret=INT32_MAX;

    // left
    ret=min(ret, ans(s+1, e, str)+1);
    // right
    ret=min(ret, ans(s, e-1, str)+1);
    // left+right
    if(str[s]==str[e])
        ret=min(ret, ans(s+1, e-1, str));
    return dp[s][e]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;
    printf("%d", ans(0, n-1, s));    
}

/*
    
*/