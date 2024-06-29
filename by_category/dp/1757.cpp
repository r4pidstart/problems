// https://www.acmicpc.net/problem/1757
// 2024-06-21 19:42:45
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, int health, int n, int m, const vector<int>& dist)
{
    static vector<vector<int> > dp(n+1, vector<int>(m+1, -1));
    if(health>m or now>n)
        return INT32_MIN/2;
    if(now==n)
        return health ? INT32_MIN/2:0; 
    if(dp[now][health] != -1)
        return dp[now][health];

    int ret=solution(now+1, health+1, n, m, dist)+dist[now];
    if(health)
        ret=max(ret, solution(now+health, 0, n, m, dist));
    else
        ret=max(ret, solution(now+1, 0, n, m, dist));

    return dp[now][health]=ret;    
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    vector<int> dist(n);
    for(int i=0; i<n; i++)
        cin >> dist[i];
    cout << solution(0, 0, n, m, dist);
}

/*
    
*/