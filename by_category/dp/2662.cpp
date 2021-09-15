// https://www.acmicpc.net/problem/2662
// 2021-09-16 02:58:19 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > profit(m+1, vector<int>(n+1,0));
    // profit[i][j] : i기업에 j를 투자했을 때 얻는 이익
    for(int i=0; i<n; i++)
    {
        int v; scanf("%d", &v);
        for(int j=1; j<=m; j++)
            scanf("%d", &profit[j][v]);
    }
    vector<vector<pair<int, vector<int> > > > dp; 
    dp.assign(m+1, vector<pair<int, vector<int> > >(n+1, pair<int, vector<int> >({0, vector<int>(m+1, 0)})));
    // dp[i][j].first : i기업까지 j를 투자했을 때 얻는 최대이익

    // knapsack
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            for(int cost=0; cost<=j; cost++)
            {
                if(dp[i][j].first < dp[i-1][j-cost].first+profit[i][cost])
                {
                    dp[i][j].first=dp[i-1][j-cost].first+profit[i][cost];
                    dp[i][j].second=dp[i-1][j-cost].second;
                    dp[i][j].second[i]=cost;
                }
            }

    printf("%d\n", dp[m][n].first);
    for(int i=1; i<=m; i++)
        printf("%d ", dp[m][n].second[i]);
}

/*

*/