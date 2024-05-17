// https://www.acmicpc.net/problem/28706
// 2024-05-16 21:42:15
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;

        vector<vector<int> > dp(2, vector<int>(7));
        dp[1][1]=1;
        for(int i=0; i<n; i++)
        {
            char op[2];
            int v[2];
            cin >> op[0] >> v[0] >> op[1] >> v[1];

            fill(dp[i&1].begin(), dp[i&1].end(), 0);
            for(int k=0; k<2; k++)
                for(int j=0; j<7; j++)
                    if(dp[!(i&1)][j])
                    {
                        if(op[k]=='+')
                            dp[i&1][(j+v[k])%7]=1;
                        else   
                            dp[i&1][(j*v[k])%7]=1;
                    }
            
        }
        cout << (dp[(n-1)&1][0] ? "LUCKY\n":"UNLUCKY\n");
    }
}

/*
    
*/