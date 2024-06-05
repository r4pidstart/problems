// https://www.acmicpc.net/problem/16432
// 2024-06-05 22:30:12
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<vector<int> > dp(n+1, vector<int>(11));
    dp[0][10]=1;

    for(int i=1; i<=n; i++)
    {
        int m; cin >> m;
        while(m--)
        {
            int a; cin >> a;
            for(int j=0; j<11; j++)
            {
                if(j==a) continue;
                if(dp[i-1][j])
                    dp[i][a]=j;
            }
        }
    }

    for(int i=1; i<10; i++)
        if(dp[n][i])
        {
            vector<int> ans;
            int cur1=n, cur2=i;
            while(cur1)
            {
                ans.push_back(cur2);
                cur2=dp[cur1--][cur2];
            }
            reverse(ans.begin(), ans.end());
            for(int i : ans)
                cout << i << '\n';
            return 0;
        }
    cout << "-1";
}

/*
    
*/