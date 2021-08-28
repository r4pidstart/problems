// https://www.acmicpc.net/problem/2240
// 2021-08-29 02:24:32 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,w; scanf("%d%d", &t,&w);
    vector<vector<int> > dp(t+1, vector<int>(w+1, 0));
    vector<int> data(t+1, 0);
    // dp[i][j][k] : i초까지 j번이동했을 때 받은 갯수

    for(int i=1; i<=t; i++)
        scanf("%d", &data[i]);

    dp[0][0]=(int)(data[0]==1);
    for(int i=0; i<t; i++)
        for(int j=0; j<=w; j++)
        {
            if(j&1)
            {
                dp[i+1][j]=max(dp[i+1][j], dp[i][j]+(int)(data[i+1]==2));
                if(j!=w) dp[i+1][j+1]=max(dp[i+1][j], dp[i][j]+(int)(data[i+1]==1));
            }
            else
            {
                dp[i+1][j]=max(dp[i+1][j], dp[i][j]+(int)(data[i+1]==1));
                if(j!=w) dp[i+1][j+1]=max(dp[i+1][j], dp[i][j]+(int)(data[i+1]==2));
            }
        }
    printf("%d", *max_element(dp[t].begin(), dp[t].end()));
}

/*
      
*/