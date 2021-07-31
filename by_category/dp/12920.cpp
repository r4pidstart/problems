// https://www.acmicpc.net/problem/12920
// 2021-08-01 02:27:09 64ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> weigh(1,0), value(1,0);

    for(int i=1; i<=n; i++)
    {
        int w,v,q; scanf("%d%d%d", &w, &v, &q);
        int n=q, tmp=1;
        while(n-tmp > 0)
        {
            n-=tmp;
            weigh.push_back(tmp*w), value.push_back(tmp*v);
            tmp*=2;
        }        
        weigh.push_back(n*w), value.push_back(n*v);
    }
    vector<vector<int> > dp(weigh.size(), vector<int>(m+1, 0));

    for(int i=1; i<weigh.size(); i++)
        for(int j=1; j<=m; j++)
        {
            if(j<weigh[i]) 
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-weigh[i]]+value[i]);
        }
    printf("%d", dp[weigh.size()-1][m]);
}

/*

*/
