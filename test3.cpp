
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp, prev;
    vector<vector<int> > cost(n, vector<int>(n));
    // dp[0] -> cost, dp[1] -> prev city
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &cost[i][j]);

    int ans=INT32_MAX;
    dp.assign(1<<n, INT32_MAX), prev.assign(1<<n, -1);
    for(int mask=0, l=1<<n; mask<l; mask++)
    {
        bitset<16> bit=mask;
        int city_count=bit.count();
        if(city_count == 0) // 첫 방문이면
        {
            for(int next=0; next<n; next++) // 다음으로 갈 도시
            {
                if(bit[next]==0)
                    dp[mask|(1<<next)]=0, prev[mask|1<<next]=next;
            }
        }
        else
        {
            for(int next=0; next<n; next++) // 다음으로 갈 도시
            {
                if(bit[next]==0 && cost[prev[mask]][next]!=0) // 아직 방문 안 헀다면
                {
                    if(dp[mask|(1<<next)] > dp[mask]+cost[prev[mask]][next])
                    {
                        dp[mask|(1<<next)]=dp[mask]+cost[prev[mask]][next];
                        prev[mask|1<<next]=next;
                    }
                }
            }
        }
    }

    printf("%d", dp[(1<<n)-1]);
}